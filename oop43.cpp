#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
using namespace std;

class Room{
	public:
		int roomno;
		float rate;
		int noOfBeds;
		string status;	
};

class Hotel{
	public:
		string name;
		int maxRooms;
		int roomCount;
		void create_room();
		void update_room(int,int);
		void delete_room();	
		void showGuestScreen();
		 Hotel(string s,int m){
			name=s;
			maxRooms=m;
			roomCount=0;
			ofstream file4,file5;
			file4.open("Hotel.txt");
			file4<<"\t\t\t\t\t\t******************"<<name<<"****************"<<"\n";
			file4<<"\t\t\t\t\t\tRoomNo."<<"\t"<<"BHK"<<"\t"<<"Price"<<"\t"<<"status"<<"\n";
			file4.close();
			file5.open("Hotelguest.txt");
			file5<<"\t\t\t\t\t\t*******************"<<name<<"***********************"<<"\n";
			file5<<"\t\t\t\t\t\tGuest Name"<<"\t"<<"          Address       "<<"\t"<<"Phone No."<<"\n";
			file5.close();
		}	
		
				
};

Room r[100];	
void Hotel::create_room( ){
	fstream file;
	file.open("Hotel.txt");
	file.seekg(0,ios::end);
	int i,n;
	cout<<"\n\t\t\tEnter how many rooms are you want to added : ";
	cin>>n;
	if(roomCount<maxRooms){
		for(i=roomCount;i<(roomCount+n);i++)
		{
	cout<<"\n\t\t\tEnter the room number : ";
	cin>>r[i].roomno;
	cout<<"\t\t\tEnter the room rent : ";
	cin>>r[i].rate;
	cout<<"\t\t\tEnter the no.of beds : ";
	cin>>r[i].noOfBeds;
	r[i].status="Available";
	file<<"\t\t\t\t\t\t"<<r[i].roomno<<"\t"<<r[i].noOfBeds<<"\t"<<r[i].rate<<"\t"<<r[i].status<<"\n";
		}
	
		}	
	roomCount=roomCount+n;
	cout<<"\n\t\t\t*************"<<n<<" Rooms added Successfully****************"<<"\n\n";
	cout<<"\t\t\tPress any key to countinue ";
	getch();

	file.close();
}

void Hotel::update_room(int rn,int a){
	fstream file;
	file.open("Hotel.txt");
	file.seekg(0);
	file.close();
	ofstream file7;
	file7.open("Hotel.txt");
	int m;
	for(int i=0;i<roomCount;i++)
	{	
			if(r[i].roomno==rn)
				{	m=i;
					break;
				}
	}
	
	if(a==1)
	{	r[m].status="Booked";
	}
	
	else if(a==2){
	
	r[m].status="Available";
	}
	
	else {
		cout<<"\n\t\t\tEnter Rate for update : ";
					cin>>r[m].rate;
					cout<<"\t\t\tEnter BHK for update : ";
					cin>>r[m].noOfBeds;
					cout<<"\n\t\t\t************* Room is update Successfully****************"<<"\n\n";
	cout<<"\t\t\tPress any key to countinue ";
	getch();
				
	}
	
	file7<<"\t\t\t\t\t\t******************"<<name<<"****************"<<"\n";
	file7<<"\t\t\t\t\t\tRoomNo."<<"\t"<<"BHK"<<"\t"<<"Price"<<"\t"<<"status"<<"\n";
	
	for(int i=0;i<roomCount;i++)
		{	file7<<"\t\t\t\t\t\t"<<r[i].roomno<<"\t"<<r[i].noOfBeds<<"\t"<<r[i].rate<<"\t"<<r[i].status<<"\n";
		}
		file7.close();
		
	
}

void Hotel::delete_room(){
	
	fstream file;
	file.open("Hotel.txt");
	file.seekg(0);
	file.close();
	ofstream file8;
	file8.open("Hotel.txt");
	int rno,j;
	cout<<"\n\t\t\tEnter room number for delete : ";
	cin>>rno;
	
		for(int i=0;i<roomCount;i++)
	{	
			if(r[i].roomno==rno)
				{	roomCount=roomCount-1;
					for(j=i;j<roomCount;j++)
						{	r[j].roomno=r[j+1].roomno;
							r[j].rate=r[j+1].rate;
							r[j].noOfBeds=r[j+1].noOfBeds;
							r[j].status=r[j+1].status;
						}
					break;
				}
	}
	
		file8<<"\t\t\t\t\t\t******************"<<name<<"****************"<<"\n";
	file8<<"\t\t\t\t\t\tRoomNo."<<"\t"<<"BHK"<<"\t"<<"Price"<<"\t"<<"status"<<"\n";
	for(int i=0;i<roomCount;i++)
	{		
			file8<<"\t\t\t\t\t\t"<<r[i].roomno<<"\t"<<r[i].noOfBeds<<"\t"<<r[i].rate<<"\t"<<r[i].status<<"\n";
	}
	file8.close();
	cout<<"\n\t\t\t************* Room deleted Successfully****************"<<"\n\n";
	cout<<"\t\t\tPress any key to countinue ";
	getch();
	
		
}

void Hotel::showGuestScreen(){
		char ch;
	ifstream file6;
	file6.open("Hotel.txt");
	file6.seekg(0);
	while(file6)
	{		file6.get(ch);
			cout<<ch;
	}
	file6.close();
}

void showAdminScreen(){
	char ch;
	ifstream file1;
	file1.open("Hotel.txt");
	file1.seekg(0);
	while(file1)
	{		file1.get(ch);
			cout<<ch;
	}
	file1.close();
}

void guestform(){

	fstream file2;
	file2.open("Hotelguest.txt");
	file2.seekg(0,ios::end);
	string name,add;
	long long int phn;

	
		cout<<"\t\t\t\t\t\tPlease Fill up this form\n";

	
		cout<<"\t\t\t\t\t\tENTER NAME: ";
		cin.ignore();
		getline(cin,name);
		cout<<" "<<endl;
		
		cout<<"\t\t\t\t\t\tENTER ADDRESS: ";
		getline(cin,add);
		cout<<" "<<endl;
		
		cout<<"\t\t\t\t\t\tENTER PHONE NUMBER: ";
		cin>>phn;
		cout<<" "<<endl;
		file2<<"\t\t\t\t\t\t"<<name<<" \t"<<add<<" \t"<<phn<<"\n";
		
		
	

file2.close();

}

void guestformfile(){
	char ch;
	ifstream file3;
	file3.open("Hotelguest.txt");
	file3.seekg(0);
	while(file3)
	{	file3.get(ch);
			cout<<ch;
	}
	file3.close();
	
}