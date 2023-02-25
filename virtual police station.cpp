# virtual-police-station-record-system
A project that involve keeping record of adding ,deleting,or viewing  records of criminals in a police station.

#include<iostream.h> 
#include<fstream.h>
#include<stdio.h>
#include<string.h>      
#include<dos.h>   /*For Delay*/ 
#include<conio.h> /*For gotoxy and getch()*/
#include<process.h> /*For exit()*/

            
/*For Introduction Screen*/
char description()
{
clrscr();

delay(2000);

cout<<"\t\t THE VIRTUAL POLICE ASSISTANT \n\n";

delay(500);

cout<<"\t TO THE RESCUE OF THE POLICE OFFICERS ALWAYS COMMITED TO  \n\n";

delay(500);

cout<<"\t  THIS SOFTWARE HELPS TO MAINTAIN THE RECORDS OF \n\n";

delay(500);

cout<<"\t THE CRIMINALS AND COMES WITH A INBUILT PASSWORD PROTECTION \n\n";

delay(500);

cout<<"\t TO PROTECT THE DATA FROM INTRUDERS.";

delay(1500);

cout<<"\n\n\t\t\tPLEASE PRESS ENTER TO CONTINUE & Esc. TO EXIT\t";

char key;

for(;;)
{
key=getch();
if(key==13)
break;
else
if(key==27)
exit(-1);
else
cout<<"\n\n\t\t\t\a ! WRONG KEY ENTERED !";
delay(300);
cout<<"\n\n\n\n\t\t\t PRESS ENTER ";
}
return 0;
}


/*Password checking*/
int password()
{
char key;
int n=0;
char password[20];
for(;;)
{
clrscr();
gotoxy(20,20);
cout<<"Enter the password to verify your identity :";
n=0;
for(int i=0;;i++)
{
key=getch();

if(key==13)
{
password[n]='\0';
break;
}

if(key==8)
{

if(i>0)
{
cout<<key<<" "<<key;
i-=2;n--;
}
else
i--;
}
else
{
cout<<"*";
password[n]=key;
n++;
}
}
if(strcmp("police123",password)==0)
return 0;
else
{
cout<<"\n\n\t\t\a!! INVALID PASSWORD !!";
delay(300);
cout<<"\n\n\t\t--> TRY AGAIN";
getch();
}
}
}


/*All the functions are in this class*/
class crim_rec
{
    char name[20],criminal_number[20], sex, fathr_name[20], addrs[25], offense[20], blood[5], dob[9];
    int crim_code, reward;
    void disp();
public:
    void get();
    void wtf();
    void rff();
    void search();
    void del();
    void mod();
}c;


void crim_rec::get()
{
    puts("\nEnter name of criminal:");
    gets(name);
puts("\nEnter number of criminal:");
    gets(criminal_number);

    puts("\nsex (m/f):");
    cin>>sex;
    puts("\nEnter date of birth:");
    gets(dob);
    puts("Enter blood group (Ap/An/Bp/Bn/ABp/ABn/Op/On:");
    gets(blood);
    puts("\nenter father's name:");
    gets(fathr_name);
    puts("enter address:");
    gets(addrs);
    puts("\nEnter crime commited:");
    gets(offense);
    puts("\nEnter reward on criminal:");
    cin>>reward;
}


void crim_rec::disp()
{
    cout<<"The record of criminal:\n";
    cout<<"\nName of criminal: "<<name;
    cout<<"\nsex: "<<sex;
    cout<<"\nDOB: "<<dob;
    cout<<"\nBlood Group: "<<blood;
    cout<<"\nFather's name: "<<fathr_name;
    cout<<"\nAddress: "<<addrs;
    cout<<"\nCrime: "<<offense;
    cout<<"\nReward: "<<reward;

}


void crim_rec::wtf()
{
    ofstream ofile;
    ofile.open("CBI", ios::app);
    get();
    ofile.write((char*)&c, sizeof(c));
    ofile.close();
}


void crim_rec::rff()
{
    ifstream ifile;
    ifile.open("CBI");
    ifile.seekg(0, ios::beg);
    ifile.read((char*)&c, sizeof(c));
    while(ifile)
    {
disp();
ifile.read ((char*)&c, sizeof(c));
    }
    ifile.close();
}


void crim_rec::search()
{
    char m[20];
    ifstream ifile("CBI");
    puts("Enter number of criminal which has to be searched");
    gets(m);
    ifile.seekg (0, ios::beg);
    ifile.read((char*)&c, sizeof(c));
    while(ifile)
    {
if (strcmpi(m, criminal_number)==0)
    disp();
    ifile.read((char*)&c, sizeof(c));
    }
    ifile.close();
}


void crim_rec::del()
{
    char b[20];
    ifstream ifile;
    ifile.open("CBI", ios::app);
    ofstream ofile;
    ofile.open("new", ios::app);
    puts("Enter the number of the criminal whose records you want to del");
    gets(b);
    ifile.seekg (0, ios::beg);
    ifile.read((char*)&c, sizeof(c));
    while(ifile)
    {
if (strcmpi(b, criminal_number))
    ofile.write((char*)&c, sizeof(c));
ifile.read((char*)&c, sizeof(c));
    }
    ifile.close();
    ofile.close();
    remove ("CBI");
    rename("new", "CBI");
}


void crim_rec::mod()
{
    char d[20];
    int p;
    puts("\nEnter number of criminal whose record you want to modify\n");
    gets(d);
    fstream f;
    f.open("CBI", ios::in|ios::out);
    f.seekg(0, ios::beg);
    f.read((char*)&c, sizeof(c));
    int a=f.tellg();
    while(! f.eof())
    {
if (!strcmpi(d, criminal_number))
{
    puts("\nPress 1 to change name\nPress 2 to change sex\nPress 3 to change date of birth\nPress 4 to change blood group\nPress 5 to change father's name\nPress 6 to change address\nPress 7 to change crime committed\nPress 8 to change reward on criminal\n");
    cin>>p;
    switch(p)
    {
    case 1:
gets(name);
break;
    case 2:
cin>>sex;
break;
    case 3:
gets(dob);
break;
    case 4:
gets(blood);
break;
    case 5:
gets(fathr_name);
break;
    case 6:
gets(addrs);
break;
    case 7:
gets(offense);
break;
    case 8:
cin>>reward;
break;
    }
    f.seekg(a-sizeof(c), ios::beg);
    f.write((char*)&c, sizeof(c));
}
f.read((char*)&c, sizeof(c));
a=f.tellg();
    }
    f.close();
}


void main ()
{  

description();
password();
    int key;
    char choice;
    clrscr();
    do
    {
    clrscr();
    cout<<"\t THE POLICE ASSISTANT";
    cout<<"\n ********************************************";
    cout<<"\n\n *  1. View criminal details                 *";
    cout<<"\n\n *  2. Add new criminal details              *";
    cout<<"\n\n *  3. Search a criminal record              *";
    cout<<"\n\n *  4. Delete a criminal record              *";
    cout<<"\n\n *  5. Modify a criminal record              *";
    cout<<"\n ********************************************";
    cout<<"\n\n Enter your choice: ";
    cin>>key;


    switch(key)
    {
    case 1:
     clrscr();
     c.rff();
break;
    case 2:

    c.wtf();

    break;
    case 3:
    c.search();
    break;
    case 4:
c.del();
break;
    case 5:
c.mod();
break;
    default:
{
cout<<"\nerror!";
}
break;
    }
    cout<<"\ncontinue? (y/n)\n";
    cin>>choice;
    }
while(choice=='y');
    cout<<"\nGood bye";
    delay(1500);
}



