#include<fstream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
struct customer
{
 char name[51];
 float balance;
}c[10];
void main()
{
 clrscr();
 int n,i,count=0;
 fstream fin,fout;
 char acc[51];
 cout<<"Enter no. of entries (max 10): ";
 cin>>n;
 cout<<"\nENTRIES\n";
 fout.open("records.dat",ios::out);
 for (i=0;i<n;i++)
 {
  cout<<"\nCustomer Name: ";
  gets(c[i].name);
  cout<<"Current balance: Rs. ";
  cin>>c[i].balance;
  fout.write((char*)&c[i],sizeof(c[i]));
 }
 fout.close();
 clrscr();
 cout<<"Enter name to be searched for: ";
 gets(acc);
 fin.open("records.dat",ios::in);
 for (i=0;i<n;i++)
 {
  fin.read((char*)&c[i],sizeof(c[i]));
  if (!strcmpi(acc,c[i].name))
  {
   cout<<endl;
   cout<<c[i].name<<" has a balance of Rs. "<<c[i].balance;
   count++;
   break;
  }
  else
   continue;
 }
 fin.close();
 if (count==0)
  cout<<endl<<"NO MATCHING ENTRY FOUND";
 getch();
}