#include <iostream>
#include <fstream> 
using namespace std;

struct contact
{
	char name[20];
	char email[20];
	char no[10];
};

int main()
{
	int choice;
	int count=0;
	struct contact p1;
	ofstream out("details.txt",ios::out|ios::binary);
	if(!out)
	{
		cout<<"Error in opening the file";
	}

	do{
	cout<<"Enter your name \n";
	cin>>p1.name;
	cout<<"Enter your email \n";
	cin>>p1.email;
	cout<<"Enter your no \n";
	cin>>p1.no;

	out.write((char*)&p1,sizeof(struct contact));
	 cout<<"do you wish to continue YES for 0 and No for 1";
	 cin>>choice;
	 count++;
	}
	 while(choice==0);
	out.close();


	ifstream in("details",ios::in|ios::binary);
	if(!in)
	{
		cout<<"Error in opening the file";
	}
   while(count!=0)
  {
	in.read((char*)&p1,sizeof(struct contact));
	cout<<"Your name is "<<p1.name<<" \n";
	cout<<"Your email is"<<p1.email<<" \n";
	cout<<"Your no is "<<p1.no<<" \n";
	count--;
}	
}