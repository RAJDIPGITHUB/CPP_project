#include<iostream>
#include<conio.h>
#include<string>
#include"oop43.cpp"
#include"oop36.cpp"
using namespace std;

void showLoginScreen(){
	cout<<"\t\t\t\t\t**********GRAND HOTEL**********"<<endl;
		cout<<"\n\n\n\n\t\t\t\t\t\t1. GUEST"<<endl;
		cout<<"\t\t\t\t\t\t2. ADMIN"<<endl;
		cout<<"\t\t\t\t\t\t0. EXIT"<<endl;

}



int main(){
	

	int choice,ch,op,n=0,b,cp,rom;
	Hotel myHotel("Grand Hotel",100);
	
	
	do{
		ret:
	showLoginScreen();
	cout<<"\t\t\t\t\t\tEnter your choice : ";
	cin>>choice;
	
	
		if(choice==1){
			do{
			system("cls");
			n=Gpassword();
			if(n==0)
			{	cout<<"\n\t\t\t\t\t\t\tIncorrect password\n\n";
				cout<<"\t\t\t\t\t\tPress any key to Enter correct password";
				getch();
			}
		}while(n==0);
			n=0;
			system("cls");
				myHotel.showGuestScreen();// print rooms file on screen
			cout<<"\t\t\t\t\t\t\t\t\tWELCOME GUEST ";
				cout<<"\n\n\n\n\t\t\t\t\t\t1. For Booking room"<<endl;
				cout<<"\t\t\t\t\t\t2. For cancel room"<<endl;
				cout<<"\t\t\t\t\t\tEnter your choice: ";
				cin>>b;
				if(b==1){
			
		
			
			cout<<"\n\t\t\t\t\t\tEnter Room number for Booking: ";
			cin>>op;
			
			myHotel.update_room(op,1);// update room file status avalable to unavalable respect to room number
			system("cls");
			guestform();
			cout<<"\n\t\t\t\t\t\t\t********BOOKING SUCCESSFUL***********"<<"\n\n";
			cout<<"\n\t\t\t\t\t\t\t\t********THANK YOU***********"<<"\n\n";
			cout<<"\t\t\t\t\t\t\tPress any key to countinue ";
			getch();
			system("cls");
			
		}
		else{
					cout<<"\n\t\t\t\t\t\tEnter Room number for cancelling: ";
			cin>>cp;
			
			myHotel.update_room(cp,2);// update room file status unavalable to avalable respect to room number
			system("cls");
				cout<<"\n\t\t\t\t\t\t\t\t********THANK YOU***********"<<"\n\n";
					cout<<"\n\t\t\t\t\t\t\t\t********Please visit again***********"<<"\n\n";
					cout<<"\t\t\t\t\t\t\t\t\tPress any key to countinue ";
			getch();
					system("cls");
	}
		
		
			
			goto ret;
			
		}
		
		else if(choice==2){
		
				do{
			system("cls");
			n=Apassword();
				if(n==0)
			{	cout<<"\n\t\t\t\t\t\t\tIncorrect password\n\n";
				cout<<"\t\t\t\t\t\t\tPress any key to Enter correct password";
				getch();
			}
		}while(n==0);
			n=0;
			do{
			showAdminScreen(); // this fn should also show list of rooms wih booking info
			cout<<"\n\n\n\n\t\t\t\t\t\t1. for creat new room"<<endl;
    		cout<<"\t\t\t\t\t\t2. for update room"<<endl;
			cout<<"\t\t\t\t\t\t3. for delete room"<<endl;
			cout<<"\t\t\t\t\t\t4. for see guest booking file"<<endl;
			cout<<"\t\t\t\t\t\t5. for exit"<<endl;
			cout<<"\t\t\t\t\t\tEnter your choice: ";
			cin>>ch;
			switch(ch){
				case 1: 
				system("cls");
				myHotel.create_room(); 
					system("cls");
				break;
				case 2: 
					system("cls");
				cout<<"\n\t\t\tEnter room number for update : ";
				cin>>rom;
				myHotel.update_room(rom,3); 
					system("cls");
				break;
				case 3: 
					system("cls");
				myHotel.delete_room(); 
					system("cls");
				break;
				case 4:
						system("cls");
				guestformfile();
				break;
			}
		}while(ch!=5);
			system("cls");
			goto ret;
		}
			
	 
	
	
	}while(choice!=0);
		
	return 0;
}