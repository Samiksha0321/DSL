//============================================================================
// Name        : MiniPoject.cpp
// Author      : 21153
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<bits/stdc++.h>
#include<fstream>
#include<termios.h>
using namespace std;

static struct termios old, current;

/* Initialize new terminal i/o settings */
void initTermios(int echo)
{
  tcgetattr(0, &old);
  current = old;
  current.c_lflag &= ~ICANON;
  if (echo) {
      current.c_lflag |= ECHO;
  } else {
      current.c_lflag &= ~ECHO;
  }
  tcsetattr(0, TCSANOW, &current);
}
void resetTermios(void)
{
  tcsetattr(0, TCSANOW, &old);
}
char getch_(int echo)
{
  char ch;
  initTermios(echo);
  ch = getchar();
  resetTermios();
  return ch;
}
char getch(void)
{
  return getch_(0);
}
char getche(void)
{
  return getch_(1);
}

class customer
{
public:
	int custm_id;
	int custm_age;
	int check_inyear;
	int check_inmonth;
	int check_indate;
	char roomtype[20];
	char custm_name[30];
	int room_charge;
	int compare(char[]);
	char custm_occupation[20];
	void getdata();
	void putdata();

	long total; //variable for Generate Bill
	int food;
	long room;
	float ser;
	int t;
	int oc;
	int r_day;

public:
	void welcomescreen();
	void login_screen();
	void add_customer();
	void delete_customer();
	void update_customer();
	void search_customer();
	void main_screen();
	void display_customer();
	void checkout_customer();
	void room_detail();
	void generate_bill();
	void room_bill();
};
//#endif

void customer::welcomescreen()
{
    cout<<  endl;
	cout<<"                           HOTEL MANAGEMENT SYSTEM  "<<endl;
	cout<<"              ____________________________________________________  "<<endl;
	cout<<  endl << endl;
	cout<<"              Press Enter to continue...." << endl << endl << endl << endl;
    getch();
}


// LOGIN SCREEN.
void customer::login_screen()
{
	time_t t;


	t=time(NULL);
	cout<<"\n                                                        "<<ctime(&t);
	customer c;
	t -= 24L*60L*60L;
	char choice;
	cout<<  endl << endl << endl<< endl;
	cout<<"                            LOGIN SCREEN\n";
	cout<<"              ____________________________________________________  "<< endl;
	cout<<"                          1.Administrator Login\n";
	cout<<"                          2.customer Login\n";
	cout<<"                          3.Exit\n";
	cout<<"\n\n\n";
	cout<<"Enter Choice::   ";
	cin>>choice;
	switch(choice)
	{
	case'1':

		c.main_screen();
		break;
	case '2':
		search_customer();
		break;
	case'3':
		exit(0);
		break;
	default:
		cout<<"wrong choice entered";
	}
}


//ADD CUSTOMER
void customer::add_customer()
{
	customer c;
	ofstream outf;
    outf.open("customer.txt",ios::out|ios::app|ios::binary);
    c.getdata();
    outf.write((char*)&c,sizeof(c));
    outf.close();
    getch();

}

//SEARCH CUSTOMER
void customer::search_customer()
{
	fstream file;
    customer c;
    int i=1;
    char nam[25];
    file.open("customer.txt",ios::in);
	cout<<"\t\t\t\t    customer Detail \n";
    cout<<"\t\t\t_________________________________ \n\n";
    cout<<"\t\t\t\t\n Enter name to Search: ";
	cin>>nam;
    file.seekg(0,ios::beg);
    while(file.read((char *) &c, sizeof(customer)))
      {
         if(c.compare(nam))
     {
    cout<<"\t\t\t\t custm_id"<<"              "<<"custm_name \n"<<endl;
    cout<<"                      "<<c.custm_id<<"              "<<c.custm_name ;
    cout<<"\n\t\t\t_________________________________________ ";
	cout<<"\n\t\t\t     ...Thank you for using ^_^ ... ";
   i=0;
   break ;
  }
 }
 file.close() ;
 if(i)
 {
  cout<<"Sorry!!!! Record Not found";
 }
 getch();
}

//DELETE CUSTOMER
void customer::delete_customer()
{
	fstream file;
    fstream temp;
	temp.open("tempdata.txt",ios::out);
	customer c;
    int i=1;
    char nam[25];
    file.open("customer.txt",ios::in);
	cout<<"\t\t\t\t  All customer Detail \n";
    cout<<"\t\t\t_____________________________\n\n";
    cout<<"\t\t\t\t\n Enter name to Search: ";
	 cin>>nam;
     file.seekg(0,ios::beg);
     while(file.read((char *) &c, sizeof(customer)))
  {
         if(!c.compare(nam))
       {
		   cout<<"\t\t\t\t custm_id"<<"              "<<"custm_name\n"<<endl;
           cout<<"                               "<<c.custm_id<<"              "<<c.custm_name;

           i=0;
           temp.write((char *)&c,sizeof(customer));

      }
   }
	 file.close() ;
     temp.close();
     remove("customer.txt");
     rename("tempfile.txt","customer.txt");

 getch();
}


//CHECKOUT_CUSTOMER
void customer::checkout_customer()
{

	cout<<"\n\t\t\t_______________________________________"<<endl;
	cout<<"\n\t\t\t\t  HOTEL MANAGEMENT SYSTEM "<<endl;
	cout<<"\n\t\t\t_______________________________________\n\n"<<endl;
	cout<<"\t\t\t\t  All customer Detail \n";
}

//ROOM_DETAIL
{


	cout<<"\n\t\t\t____________________________________"<<endl;
	cout<<"\n\t\t\t\tHOTEL MANAGEMENT SYSTEM "<<endl;
	cout<<"\n\t\t\t____________________________________\n"<<endl;
	cout<<"\t\t\t\tAll customer Detail \n";
	cout<<left<<setw(10)<<"roomtype"<<left<<setw(15)<<"room_charge"<<endl;
}

//Generate Bill
class Generatebill:public customer
{
public :
	int r_charge;
	char custm_name[25];
	int b;

public:

	void calculate()
	{


		  cout<<"\n Enter Room type:";
						  cout<<"\n Select 1 for Super Luxary \n Select 2 for Luxary \n Select 3 for Delux \n";
					      cin>>b;
					      if(b==1)
					      {
							  r_charge=4000;
						  }
						  else
						  if(b==2)
						  {
							  r_charge=3000;
						  }
						  else
							  if(b==3)
							  {
								  r_charge=2000;
							  }
							  else{
					      cout<<"\n Wrong choice ...";
						  cout<<"\n ERROR: Room is not allocated.";
						cout<<"\n Bill cannot be created ";
							  }

	   cout<<"\n Enter the bill amount of restaurant:";
	   cin>>food;
	   cout<<"\n Enter other charges:";
	   cin>>oc;
	   cout<<"\n Enter customer name:";
	   cin>>custm_name;
		cout<<"\n Enter number of days:";
	   cin>>r_day;
		room= r_charge * r_day;
	   t=(int) room + food + oc;
	   ser=(int)(0.05*t);
	   total=t+ser;
	  }

	void display_bill()
	  {

	   cout<<"\n________________________________________________________________________________";
	   cout<<"\n                                  TAJ LUXURY HOTEL                       ";
	   cout<<"\n                        ____________________________________                  ";
	   cout<<"\n                               Pune , Maharashtra-007.                        ";
	   cout<<"\n                                  Tel :- 12345678                               ";
	   cout<<"\n--------------------------------------------------------------------------------";
	   cout<<"\n      Customer name : "<<custm_name<<endl;
	   cout<<"\n      Stayed for "<<r_day<<" days";
	   cout<<"\n      Room charges    : "<<r_charge<<"(Per day)";
	   cout<<"\n      Room charges    : "<<room<<"(total)";
	   cout<<"\n      Restaurant bill : "<<food;
	   cout<<"\n      Other charges   : "<<oc;
	   cout<<"\n                          Ser.tax % = 5%";
	   cout<<"\n                          Ser.tax   ="<<ser;
	   cout<<"\n      Bill Amount >>>>>> Rs "<<total;
	   cout<<"\n                              ";
	   cout<<"\n      THANK YOU !!!!!";
	   cout<<"\n      Visit Again !";
	  }

  };


void customer::generate_bill()
{
	Generatebill b;
	b.calculate();
	b.display_bill();

}

int main()
{
	customer view;
	view.welcomescreen();
	view.login_screen();
	return 0;
}