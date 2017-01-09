#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <thread>

using namespace std;

struct sockaddr_in server;
void funct(string str , string str1,int i ){
    cout<<"inide thread";
	int sock;
        char server_reply[2000];
        //Create socket
        sock = socket(AF_INET , SOCK_STREAM , 0);
        if (sock == -1)
        {
         printf("Could not create socket");
        }
        puts("Socket created");

        server.sin_addr.s_addr = inet_addr("127.0.0.1");
        server.sin_family = AF_INET;
        server.sin_port = htons( 1234 );
         if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0)
        {
          perror("connect failed. Error");
          return; 
        }
	    string s ;
	    s += '\n' ;
	
       send(sock , str.data() , str.size() , 0) ;
	   send(sock , s.data() , s.size() , 0) ;
	   send(sock , str1.data() , str1.size() , 0);
	   send(sock , s.data() , s.size() , 0) ;
	   

    	recv(sock , server_reply , 2000 , 0);
	   printf("Server%d Reply : %s\n",i, server_reply);
}



int main(){
    int sock;
    
    
vector<string> A;
     string  mtx_b="";
    //save matrix a and b
    ifstream stream;
    string text;
    stream.open("text.txt");
    while( getline(stream,text))
    {
     if(text=="")
      break;
     A.push_back(text);
    }
    getline(stream,text);
    mtx_b=text;
    while( getline(stream,text))
    {
     mtx_b+=" "+text;
    }
    thread th[A.size()];
    cout<<"creating thread"<<endl;
    for(int i=0;i<A.size();i++){
        th[i]=thread(funct,A[i],mtx_b,i);
        cout<<"created "<<i<<endl;
    }

    for(int i=0;i<A.size();i++){
        th[i].join();
    }

     
    


return 0;
}
