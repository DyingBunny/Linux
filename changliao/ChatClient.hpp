#pragma once

#include<iostream>
#include<string>
#include"ProtocolUtil.hpp"
#include"Message.hpp"
#define TCP_PORT 8080
#define UDP_PORT 8888

class ChatClient
{
    private:
	int tcp_sock;
	int udp_sock;
	std::string peer_ip;

	unsigned int id;
	std::string passwd;
	std::string nick_name;
	std::string school;

	struct sockaddr_in server;
    public:
	ChatClient(std::string ip_):peer_ip(ip_)
	{
	    id=0;
	    tcp_sock=-1;
	    udp_sock=-1;
	    server.sin_family=AF_INET;
	    server.sin_port=htons(UDP_PORT);
	    server.sin_addr.s_addr=inet_addr(peer_ip.c_str());
	}
	void InitClient()
	{
	    tcp_sock=SocketApi::Socket(SOCK_STREAM);
	    udp_sock=SocketApi::Socket(SOCK_DGRAM);
	}
	bool ConnectServer()
	{
	    return SocketApi::Connect(tcp_sock,peer_ip,TCP_PORT);
	}
	bool Register()
	{
	    if(Util::RegisterEnter(nick_name,school,passwd)&&ConnectServer())
	    {
		Request rq;
		rq.method="REGISTER\n";

		Json::Value root;
		root["name"]=nick_name;
		root["school"]=school;
		root["passwd"]=passwd;
		
		Util::Seralizer(root,rq.text);

		rq.content_length="Content_Length";
		rq.content_length+=Util::IntToString((rq.text).size());
		rq.content_length+="\n";

		SocketApi::SendRequest(tcp_sock,rq);
		recv(tcp_sock,&id,sizeof(id),0);
		bool res=false;
		if(id>=10000)
		{
		    std::cout<<"Register Success!Your Login ID is :"<<id<<std::endl;    
		    res=true;
		}
		else
		{
		    std::cout<<"Register Failed! Code is:"<<id<<std::endl;
		}

		close(tcp_sock);
		return res;
	    }
	}
	bool Login()
	{ 
	    if(Util::LoginEnter(id,passwd) && ConnectServer())
	    {
		Request rq;
		rq.method="LOGIN\n";

		Json::Value root;
		root["id"]=id;
		root["passwd"]=passwd;
		
		Util::Seralizer(root,rq.text);

		rq.content_length="Content_Length";
		rq.content_length+=Util::IntToString((rq.text).size());
		rq.content_length+="\n";

		SocketApi::SendRequest(tcp_sock,rq);
		unsigned int result=0;
	    	recv(tcp_sock,&result,sizeof(result),0);
		bool res=false;
		//result=10000;
		if(result>=10000)
		{
		    res=true;
		    std::cout<<"Login Success!"<<std::endl;    
		}
		else
		{
		    std::cout<<"Login Failed! Code is:"<<result<<std::endl;
		}

		close(tcp_sock);
		return res;
	    }

	}
	void Chat()
	{
	    std::string n_;
	    std::string s_;
	    std::string text_;
	    std::cout<<"Please Enter Your Name:";
	    std::cin>>n_;

	    std::cout<<"Please Enter Your School:";
	    std::cin>>s_;
	    while(1)
	    {
		std::string text_;
		std::cout<<"Please Enter:";
		std::cin>>text_;
		Message msg(n_,s_,text_,id);
		std::string sendString;
		msg.ToSendString(sendString);
		Util::SendMessage(udp_sock,sendString,server);

		std::string recvString;
		struct sockaddr_in peer;
		Util::RecvMessage(udp_sock,recvString,peer);
		//std::cout<<"debug: "<<recvString<<std::endl;

		msg.ToRecvValue(recvString);
		
		std::cout<<"name:"<<msg.NickName()<<" school:"<<msg.School()<<std::endl;
		//std::cout<<"schoo:"<<msg.School()<<std::endl;
		std::cout<<msg.Text()<<std::endl;
		//std::cout<<"id:"<<msg.Id()<<std::endl;
	    }
	}
	~ChatClient()
	{}
};
