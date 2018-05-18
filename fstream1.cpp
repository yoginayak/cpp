#include <iostream>
#include <fstream> 
using namespace std;

struct contact
{
	char name[20];
	char email[20];
	long int no;
};

int main()
{
	int i;
	struct contact p1;
	for(i=0;i<2;i++)
	{
	cout<<"Enter your name \n";
	cin>>p1.name;
	cout<<"Enter your email \n";
	cin>>p1.email;
	cout<<"Enter your no \n";
	cin>>p1.no;
}
	
	ofstream out("Details",ios::out|ios::binary);
	if(!out)
	{
		cout<<"Error in opening the file";
	}
	out.write((char*)&p1,sizeof(struct contact));
	out.close();

	ifstream in("Details",ios::in|ios::binary);
	if(!in)
	{
		cout<<"Error in opening the file";
	}
    for(i=0;i<2;i++)
  {
	in.read((char*)&p1,sizeof(struct contact));
	cout<<"Your name is "<<p1.name<<" \n";
	cout<<"Your email is"<<p1.email<<" \n";
	cout<<"Your no is "<<p1.no<<" \n";
}	
}