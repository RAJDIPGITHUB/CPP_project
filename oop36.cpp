#include<iostream>
#include<cstring>
#include<string>
#include<conio.h>
using namespace std;

int Gpassword(){
	string p="1111";
	char psw[10],ch,k[10];
	int i=0,l=0;
	do{
		k[l]=p[l];
		l++;
	}while(p[l]!='\0');
	k[l]='\0';
	
	cout<<"\n\n\n\n\t\t\t\t\t\tEnter password:";
	while( (ch=getch()) !='\r' ){
		psw[i]=ch;
		i++;
		
		system("cls");		
		cout<<"\n\n\n\n\t\t\t\t\t\tEnter password:";
		for(int j=0;j<i;j++)
			cout<<"*";
	
	}
	//psw[i]=ch;
	psw[i]='\0';
	system("cls");
	
	
	if(strcmp(k,psw)==0)
	{	return(1);
	}
	else
	{return 0;
	}
	
}

int Apassword(){
	string p="1234";
	char psw[10],ch,k[10];
	int i=0,l=0;
	do{
		k[l]=p[l];
		l++;
	}while(p[l]!='\0');
	k[l]='\0';
	
	cout<<"\n\n\n\n\t\t\t\t\t\tEnter password:";
	while( (ch=getch()) !='\r' ){
		psw[i]=ch;
		i++;
		
		system("cls");		
		cout<<"\n\n\n\n\t\t\t\t\t\tEnter password:";
		for(int j=0;j<i;j++)
			cout<<"*";
	
	}
	//psw[i]=ch;
	psw[i]='\0';
	system("cls");
	
	
	if(strcmp(k,psw)==0)
	{	return(1);
	}
		else
	{return 0;
	}

	
}