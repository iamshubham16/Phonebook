#include <iostream.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <iomanip.h>
#include <fstream.h>
#include <dos.h>
#include <stdlib.h>
#include <ctype.h>

const int TRUE = 1;
const int FALSE = 0;
FILE *f1,*f2;

struct dob
{
 int dd;
 int mm;
 int yy;
};

struct phoneBook
{
 char name[15],addr[50],phone[12],gender,email[50];
 dob d;
};

struct Linked_List
{
 struct phoneBook ph;
 struct Linked_List *next;
};

typedef struct Linked_List node;

node *head = NULL,*New;

void phonebook();

void initialize(node *N)
{

 for(int i=1;i<79;++i)
 cprintf("-");
// printf("+");
for(i=0;i<80;++i)
{
 gotoxy(i,24);
 cprintf("-");
 }
 for(i=0;i<24;i++)
 {
  gotoxy(1,i);
  cprintf("-");
  gotoxy(80,i);
  cprintf("-");
 }
 for(i=2;i<80;++i)
 {
  gotoxy(i,5);
  cprintf("-");
 }
 gotoxy(32,3);
 cout<<"---";
 cout<<"P";
 delay(100);
 cout<<"H";
 delay(100);
 cout<<"O";
  delay(100);
 cout<<"N";
  delay(100);
 cout<<"E";
  delay(100);
 cout<<" ";
  delay(100);
 cout<<"B";
  delay(100);
 cout<<"O";
  delay(100);
 cout<<"O";
  delay(100);
 cout<<"K";
  delay(100);
  for(i=10;i<70;++i)
  {
   gotoxy(i,7);
   cout<<"-";
   gotoxy(i,22);
   cout<<"-";
  }
  for(i=7;i<22;++i)
  {
   gotoxy(10,i);
   cout<<"-";
   gotoxy(70,i);
   cout<<"-";
  }

 for(i=10;i<70;++i)
 {
  gotoxy(i,11);
  cout<<"-";
 }
 gotoxy(20,9);
 cout<<"CREATE NEW CONTACT";
 gotoxy(15,14);
 cout << "NAME : ";
 gets(N -> ph.name);
 gotoxy(15,15);
 cout << "ADDRESS : ";
 gets(N -> ph.addr);
 do
 {
  int j=0;
  gotoxy(15,16);
  cout << "PHONE NUMBER : ";
  cin >> N -> ph.phone;
  for(i=0;i<strlen(N->ph.phone);++i){
  if(isdigit(N->ph.phone[i]))
     j++;}
     if(j==strlen(N->ph.phone))
     {
      gotoxy(36,16);
      cout<<"                           ";
      break;}
     else
     {
      gotoxy(30,16);
      cout<<"             " ;
      gotoxy(36,16);
      cout<<"INVALID NUMBER";
      }
  }while(1);

 do
 {
  gotoxy(15,17);
  cout << "GENDER(M/F) : ";
  cin >>N->ph.gender;
  if(N->ph.gender=='M' || N->ph.gender=='m' || N->ph.gender=='F' || N->ph.gender=='f' )
  {
    gotoxy(32,17);
    cout<<"                  ";
    break;
   }
   else{
    gotoxy(30,17);
    cout<<" ";
    gotoxy(32,17);
    cout<<"Invalid Gender";}
  }while(1);

do
{
 int j=0;
 gotoxy(15,18);
 cout<<"E-MAIL : ";
 cin>>N->ph.email;
 for(int i=0;i<strlen(N->ph.email);i++)
 {
  if(N->ph.email[i]=='@')
  j++;
 }
 if(j==1) {
 gotoxy(40,18);
 cout<<"               " ;
 break;}
 else
 {
 gotoxy(24,18);
 cout<<"                                       ";
 gotoxy(40,18);
 cout<<"Invalid Email";
 }
  }while(1);
 gotoxy(15,19);
 cout<<"DATE OF BIRTH (dd/mm/yy) :   /  /   ";
  gotoxy(42,19);
  cin>>N->ph.d.dd;
  gotoxy(45,19);
  cin>>N->ph.d.mm;
  gotoxy(48,19);
  cin>>N->ph.d.yy;

}

void auto_layout()
{
// phonebook();

  for(int i=1;i<79;++i)
 cprintf("-");
// printf("+");
for(i=0;i<80;++i)
{
 gotoxy(i,24);
 cprintf("-");
 }
 for(i=0;i<24;i++)
 {
  gotoxy(1,i);
  cprintf("-");
  gotoxy(80,i);
  cprintf("-");
 }
 for(i=2;i<80;++i)
 {
  gotoxy(i,5);
  cprintf("-");
 }
 gotoxy(32,3);
 cout<<"---";
 cout<<"PHONE BOOK";

 cout<<"---";
/* for(i=10;i<70;++i)
 {
  gotoxy(i,8);
  cout<<"-";
  gotoxy(i,23);
  cout<<"-";
  gotoxy(i,12);
  }
 for(i=8;i<23;++i)
 {
  gotoxy(10,i);
  cout<<"-";
  gotoxy(70,i);
  cout<<"-";
  gotoxy(40,i);
  cout<<"-";
  }  */

 gotoxy(2,7);
 cout<<"NAME : ";
/* for(i=1;i<80;++i){
 gotoxy(i,8);
 cout<<"-";
 }*/
}





void auto_search()
{
// gotoxy(,7);
 auto_layout();
 node*temp=head;
 int i=0,d=0,e,j,x=0;
 char a,c[35000];


 do
  {
  // gotoxy(39+x,7);
   if(a=getch())
     {
      clrscr();
      auto_layout();
      i=0;
     }
    if(a==8)
     {
      x--;
      c[d--]='\0';
      for(i=0;i<d;++i)
      printf("%c",c[i]);
      printf("\n");
      for(temp=head,i=0;temp!=NULL;temp=temp->next,i++)
	{
	  e=strncmp(temp->ph.name,c,d);
	  if(e==0)
	   {
	    // gotoxy(j,++k);
	     printf("%s -->>",temp->ph.name);
	    // gotoxy(j+15,k);
	     printf("%s\n",temp->ph.phone);
	   /* if(k<14)
	    {
	     j=30;
	    }
	   else if(j>=14&&j<28)
	   {
	    gotoxy(25,j-6);
	    printf("%s",temp->ph.name);
	   }
	  else
	  {
	   gotoxy(5+k,8+j);
	   printf("%s",temp->ph.name);
	   } */

	   //  gotoxy(43,8+i);
	   // printf("%s ",temp->ph.phone);
	    }
	 }
      }
   else
    {
     x++;
     c[d++]=a;
     c[d]='\0';
     printf("%s \n",c);
     for(temp=head,i=0;temp!=NULL;temp=temp->next,i++)
	{
	  e=strncmp(temp->ph.name,c,d);
	  if(e==0)
	   {
    //	     gotoxy(13,8+i);
	     printf("%s -->>",temp->ph.name);
      //	     gotoxy(43,8+i);
	     printf("%s\n ",temp->ph.phone);
	   }
	}
      }
    }while(a!=13);
   // getch();
  }





int empty(node *n)
{
 if(strcmp(n -> ph.name,"") == 0 && strcmp(n -> ph.addr,"") == 0 && strcmp(n -> ph.name,"") == 0)
  return 1;
 else
  return 0;
}

void create()
{
 New = new node;
 strcpy(New -> ph.name,"");
 strcpy(New -> ph.addr,"");
 strcpy(New -> ph.phone,"");
 New -> next = NULL;
 if(head == NULL)
  head = New;
}

int insert()
{

 if(head == NULL)
  create();

 if(head -> next == NULL)
  if(empty(head))
     {
      initialize(New);
      return 1;
     }

 char ntmp[15];
 create();
 initialize(New);
 strcpy(ntmp,New -> ph.name);
 node *temp = head,*loc = head;
 if(strcmpi(ntmp,head -> ph.name) < 0)
 {
   New -> next = head;
   head = New;
 }

 else
  {
    while(temp -> next != NULL)
     {
       temp = temp -> next;
       if(strcmpi(ntmp,temp -> ph.name) > 0)
	loc = temp;
      }

    New -> next = loc -> next;
    loc -> next = New;
   }
 return 1;
}


void initialize_file(node*n,char a[],char b[],char c[],char d,char e[],int f,int g ,int h)
{
  strcpy(n->ph.name,a);
  strcpy(n->ph.addr,b);
  strcpy(n->ph.phone,c);
  n->ph.gender=d;
  strcpy(n->ph.email,e);
  n->ph.d.dd=f;
  n->ph.d.mm=g;
  n->ph.d.yy=h;
  printf("%s",n->ph.email);
 }
int insert_file(char a[],char b[],char c[],char d,char e[],int f,int g ,int h)
{
 if(head == NULL)
  create();

 if(head -> next == NULL)
  if(empty(head))
     {
      initialize_file(New,a,b,c,d,e,f,g,h);
      return 1;
     }

 char ntmp[15];
 create();
 initialize_file(New,a,b,c,d,e,f,g,h) ;
 strcpy(ntmp,New -> ph.name);
 node *temp = head,*loc = head;
 if(strcmpi(ntmp,head -> ph.name) < 0)
 {
   New -> next = head;
   head = New;
 }

 else
  {
    while(temp -> next != NULL)
     {
       temp = temp -> next;
       if(strcmpi(ntmp,temp -> ph.name) > 0)
	loc = temp;
      }

    New -> next = loc -> next;
    loc -> next = New;
   }
 return 1;
}

void searchsuccess()
{
  int i,j;
  for(i=20;i<60;++i)
  {
   gotoxy(i,10);
   delay(25);
   cout<<"-";
   delay(25);
   gotoxy(i,22);
   cout<<"-";
  }
  for(i=10;i<22;++i)
  {
   gotoxy(20,i);
   delay(25);
   cout<<"-";
   gotoxy(60,i);
   delay(25);
   cout<<"-";
  }

}

void search_no(char *n)
{
 node *temp = head;
 int found = FALSE;

 if(head == NULL)
   found = FALSE;

 else if(strcmp(n,temp -> ph.phone) == 0)
  found = TRUE;

 else
 {
  while(temp -> next != NULL)
  {
    temp = temp -> next;
    if(strcmp(n,temp -> ph.phone) == 0)
     {
       found = TRUE;
       break;
      }
   }
  }

 if(found)
  {
    phonebook();
    searchsuccess();
    gotoxy(30,13);
    cout << "Name : " << temp -> ph.name;
    gotoxy(30,14);
    cout << "Address : " << temp -> ph.addr;
    gotoxy(30,15);
    cout << "Phone NO. : " << temp -> ph.phone;
    gotoxy(30,16);
    cout << "E-Mail : " << temp->ph.email;
    gotoxy(30,17);
    cout << "Gender : " << temp->ph.gender;
    gotoxy(30,18);
   cout << "DOB : " <<temp->ph.d.dd<<"/"<<temp->ph.d.mm<<"/"<<temp->ph.d.yy;
   gotoxy(24,23);
   cout<<"Press Enter to continue.....";

   }

 else
  { searchsuccess();
    gotoxy(34,16);
    cout << "Data not found";
    gotoxy(29,17);
    cout << "Press any key to continue...";
   }
}


void search(char *n)
{
 node *temp = head;
 int found = FALSE;

 if(head == NULL)
   found = FALSE;

 else if(strcmp(n,temp -> ph.name) == 0)
  found = TRUE;

 else
 {
  while(temp -> next != NULL)
  {
    temp = temp -> next;
    if(strcmp(n,temp -> ph.name) == 0)
     {
       found = TRUE;
       break;
      }
   }
  }

 if(found)
  {
    phonebook();
    searchsuccess();
    gotoxy(30,13);
    cout << "Name : " << temp -> ph.name;
    gotoxy(30,14);
    cout << "Address : " << temp -> ph.addr;
    gotoxy(30,15);
    cout << "Phone NO. : " << temp -> ph.phone;
    gotoxy(30,16);
    cout << "E-Mail : " << temp->ph.email;
    gotoxy(30,17);
    cout << "Gender : " << temp->ph.gender;
    gotoxy(30,18);
   cout << "DOB : " <<temp->ph.d.dd<<"/"<<temp->ph.d.mm<<"/"<<temp->ph.d.yy;
   gotoxy(24,23);
   cout<<"Press Enter to continue.....";

   }

 else
  { searchsuccess();
    gotoxy(34,16);
    cout << "Data not found";
    gotoxy(29,17);
    cout << "Press any key to continue...";
   }
}


int remove(char *n)
{

 searchsuccess();
 char ch;

 if(head == NULL)
    return 0;

 node *temp = head,*loc = head;
 if(strcmp(n,temp -> ph.name) == 0)
    {
      gotoxy(30,13);
      cout << "Name : " << temp -> ph.name;
      gotoxy(30,14);
      cout << "Address : " << temp -> ph.addr;
      gotoxy(30,15);
      cout << "Phone NO. : " << temp -> ph.phone;
      gotoxy(30,16);
      cout << "E-Mail : " << temp->ph.email;
      gotoxy(30,17);
      cout << "Gender : " << temp->ph.gender;
      gotoxy(30,18);
      cout << "DOB : " <<temp->ph.d.dd<<"/"<<temp->ph.d.mm<<"/"<<temp->ph.d.yy;

     gotoxy(20,23);
     cout<<"Are you sure you want to delete the contact ?(Y/N) : ";
     cin >> ch;
     getch();
     if(ch=='Y'||ch=='y')
     {
      if(temp -> next == NULL)
	{
	   head = NULL;
	   delete temp;
	}
      else
       {
	 head = temp -> next;
	 delete temp;
       }
     return 1;
    }
  else
    return 2;
 }

 else
  {
    while(temp -> next != NULL)
     {
       temp = temp -> next;
       if(temp == NULL)
	 return 0;

     if(strcmpi(n,temp -> ph.name) == 0)
	{
	  gotoxy(30,13);
	  cout << "Name : " << temp -> ph.name;
	  gotoxy(30,14);
	  cout << "Address : " << temp -> ph.addr;
	  gotoxy(30,15);
	  cout << "Phone NO. : " << temp -> ph.phone;
	  gotoxy(30,16);
	  cout << "E-Mail : " << temp->ph.email;
	  gotoxy(30,17);
	  cout << "Gender : " << temp->ph.gender;
	  gotoxy(30,18);
	  cout << "DOB : " <<temp->ph.d.dd<<"/"<<temp->ph.d.mm<<"/"<<temp->ph.d.yy;

	  gotoxy(17,23);
	  cout<<"Are you sure you want to delete the contact ?(Y/N) ";
	  cin >> ch;
	  if(ch=='Y'||ch=='y')
	  {
	   if(temp -> next != NULL)
	    {
	     temp = loc -> next;
	     loc -> next = temp -> next;
	     delete temp;
	    }
	  else
	    loc -> next = NULL;
	    return 1;
	}
       else
	 return 2;
     }
      loc = loc -> next;
      }
  }
 return 0;
}

void modifysuccess()
{
    for(int i=10;i<70;++i)
  {
   gotoxy(i,10);
   delay(25);
   cout<<"-";
   delay(25);
   gotoxy(i,22);
   cout<<"-";
   gotoxy(i,13);
   delay(25);
   cout<<"-";
  }
  for(i=10;i<22;++i)
  {
   gotoxy(10,i);
   delay(25);
   cout<<"-";
   gotoxy(70,i);
   delay(25);
   cout<<"-";
   gotoxy(20,i);
   delay(25);
   cout<<"-";
   gotoxy(45,i);
   cout<<"-";
  }
}

void initialize_modify(node*N)
{
 gotoxy(48,14);
 cin >> N -> ph.name;
 gotoxy(48,15);
 cin >> N -> ph.addr;
 gotoxy(48,16);
 cin >> N -> ph.phone;
 gotoxy(48,17);
 cin >>N->ph.gender;
 gotoxy(48,18);
 cin>>N->ph.email;
 gotoxy(48,19);
 cin>>N->ph.d.dd;
 gotoxy(51,19);
 cout<<"/";
 gotoxy(52,19);
 cin>>N->ph.d.mm;
 gotoxy(55,19);
 cout<<"/";
 gotoxy(56,19);
 cin>>N->ph.d.yy;

}

int modify(char *n)
{
 node *temp = head;
 if(head == NULL)
  return 0;

 if(strcmpi(n,temp -> ph.name) == 0)
  {
    modifysuccess();
    gotoxy(23,11);
    cout << "Previous Data";
    gotoxy(12,14);
    cout << "Name";
    gotoxy(12,15);
    cout << "ADDRESS";
    gotoxy(12,16);
    cout << "Phone NO. ";
    gotoxy(12,17);
    cout<<"GENDER";
    gotoxy(12,18) ;
    cout<<"E-MAIL";
    gotoxy(12,19);
    cout<<"DOB";
    gotoxy(23,14);
    cout<< temp->ph.name;
    gotoxy(23,15);
    cout<< temp->ph.addr;
    gotoxy(23,16);
    cout<< temp->ph.phone;
    gotoxy(23,17);
    cout<< temp->ph.gender;
    gotoxy(23,18);
    cout<< temp->ph.email;
    gotoxy(23,19);
    cout<< temp->ph.d.dd <<"/"<< temp->ph.d.mm<<"/"<<temp->ph.d.yy;

    gotoxy(48,11);
    cout << "Enter New Data";
    initialize_modify(head);
    return 1;
   }

 else
 {
  while(temp -> next != NULL)
  {
    temp = temp -> next;
    if(temp == NULL)
     return 0;

    if(strcmpi(n,temp -> ph.name) == 0)
     {
      modifysuccess();
      gotoxy(23,11);
      cout << "Previous Data";
      gotoxy(12,14);
      cout << "Name";
      gotoxy(12,15);
      cout << "ADDRESS";
      gotoxy(12,16);
      cout << "Phone NO. ";
      gotoxy(12,17);
      cout<<"GENDER";
      gotoxy(12,18) ;
      cout<<"E-MAIL";
      gotoxy(12,19);
      cout<<"DOB";
      gotoxy(23,14);
      cout<< temp->ph.name;
      gotoxy(23,15);
      cout<< temp->ph.addr;
      gotoxy(23,16);
      cout<< temp->ph.phone;
      gotoxy(23,17);
      cout<< temp->ph.gender;
      gotoxy(23,18);
      cout<< temp->ph.email;
      gotoxy(23,19);
      cout<< temp->ph.d.dd <<"/"<< temp->ph.d.mm<<"/"<<temp->ph.d.yy;

      gotoxy(48,11);
      cout << "Enter New Data";
      initialize_modify(head);
      return 1;
     }
    }
  }
 return 0;
}

void dekho()
{
 phonebook();
 for(int i=20;i<60;++i)
 {
  gotoxy(i,8);
  cout<<"-";
  gotoxy(i,20);
  cout<<"-";
  gotoxy(i,10);
  cout<<"-";
 }
 for(i=8;i<20;++i)
 {
  gotoxy(20,i);
  cout<<"-";
  gotoxy(60,i);
  cout<<"-";
  gotoxy(40,i);
  cout<<"-";
 }
 gotoxy(27,9);
 cout<<"NAME";
 gotoxy(47,9);
 cout<<"PHONE NO.";

    for(i=60;i<80;++i)
      {
       gotoxy(i,22);
       cout<<"-";
       }
       for(i=22;i<24;++i)
       {
	gotoxy(60,i);
	cout<<"-";
       }
       gotoxy(63,23);
       cout<<"||| N |||--->>";
 }
void display()
{
 char ch;
 node *temp = head;
 int i=0;
 if(head == NULL)
  {
   clrscr();
   phonebook();
   gotoxy(30,11);
   cout << "CONTACT LIST IS EMPTY ";
   gotoxy(28,12);
   cout << "Press any key to continue...";
   return;
  }

  dekho();

 if(!empty(head))
  {
   gotoxy(25,12);
   cout << temp -> ph.name;
   gotoxy(45,12);
   cout << temp -> ph.phone;
  }

 while(temp -> next != NULL)
  {
   i++;
   gotoxy(25,12+i);
   temp = temp -> next;
   cout << temp -> ph.name;
   gotoxy(45,12+i);
   cout<< temp -> ph.phone;
   if(i%6==0&&i!=0)
   {
    gotoxy(30,22);
    cout<<"PRESS N TO CONTINUE";
    cin>>ch;
    if(ch=='N'||ch=='n')
    {
      clrscr();
      dekho();
      i=-1;
     }
   }
}
 }
int menu()
{

for(int i=1;i<79;++i)
 cprintf("-");
for(i=0;i<80;++i)
{
 gotoxy(i,24);
 cprintf("-");
 }
 for(i=0;i<24;i++)
 {
  gotoxy(1,i);
  cprintf("-");
  gotoxy(80,i);
  cprintf("-");
 }
 for(i=2;i<80;++i)
 {
  gotoxy(i,5);
  cprintf("-");
 }
 gotoxy(32,3);
 cout<<"---";
 cout<<"P";
 delay(100);
 cout<<"H";
 delay(100);
 cout<<"O";
  delay(100);
 cout<<"N";
  delay(100);
 cout<<"E";
  delay(100);
 cout<<" ";
  delay(100);
 cout<<"B";
  delay(100);
 cout<<"O";
  delay(100);
 cout<<"O";
  delay(100);
 cout<<"K";
  delay(100);
  gotoxy(0,10);
 for(i=0;i<80;++i)
 {
  gotoxy(i,10);
  cprintf("-");
  gotoxy(i,15);
  cprintf("-");
  gotoxy(i,20);
  cprintf("-");
 }
 for(i=5;i<20;++i)
 {
  gotoxy(40,i);
  cprintf("-");
 }
 gotoxy(20,6);
 cout<<"1";
 gotoxy(13,8);
 cout<<"ADD NEW CONTACT";
 gotoxy(60,6);
 cout<<"2";
 gotoxy(53,8);
 cout<<"SEARCH CONTACT";
 gotoxy(20,11);
 cout<<"3";
 gotoxy(13,13);
 cout<<"DELETE CONTACT";
 gotoxy(60,11);
 cout<<"4";
 gotoxy(53,13);
 cout<<"MODIFY CONTACT";
 gotoxy(20,16);
 cout<<"5";
 gotoxy(60,16);
 cout<<"6";
 gotoxy(13,18);
 cout<<"VIEW CONTACTS";
 gotoxy(59,18);
 cout<<"EXIT";
 gotoxy(30,22);
 cout<<"Enter your choice :";
 cout<<"_________";
 int ch;
 gotoxy(53,22);
 cin>>ch;
 return ch;
}

void welcome() //To display the welcome screen
{
  int i;
  textbackground(3);
  for(i=0;i<(80*24);++i)
   cprintf(" ");
 for(i=0;i<=50;++i)
 {
  textcolor(BLACK+BLINK);
  gotoxy(35,12);
  cprintf("Loading......");
  gotoxy(37,14);
  int x=2*i;
  textcolor(BLUE);
  cprintf("%d %", x );
  delay(150);
  }

 for( i=0;i<500;i+=10)
 {
  sound(i);
  delay(40);
  nosound();
  delay(40);
  }
  clrscr();
  for(i=0;i<79;++i)
  {
   textcolor(1);
   gotoxy(i,0);
   cprintf("*");
  delay(20);
  }
 for(i=0;i<79;++i)
  {
  gotoxy(i,24);
  cprintf("*");
  delay(20);
  }
  for(i=0;i<24;++i)
  {
   gotoxy(0,i);
   cprintf("*");
   gotoxy(80,i);
   cprintf("*");
   delay(50);
  }
  gotoxy(15,3);
   cprintf("****************************************************** ");
   gotoxy(22,4);
   cprintf("  PHONE BOOK PROJECT ( DSA ORIENTED)   " ) ;
   gotoxy(15,5);
   cprintf("******************************************************");
   gotoxy(20,6);
   cprintf ( " \n\n D E V E L O P E D   B Y  :- " ) ;
   gotoxy(20,8);
   cprintf ( "  \n\nShrishti Gupta, Shubham Guglani and Shubham Sharma " ) ;
   gotoxy(20,10);
   cprintf ( " \n\n II-SEMESTER " ) ;
   gotoxy(20,12);
   cprintf ( "  \n\nINDIAN INSTITUTE OF INFORMATION TECHNOLOGY,KOTA " ) ;
   gotoxy(15,16);
   cprintf("\n*******************************************************\n");;
  gotoxy(30,18);
  cprintf ( "\n Press Enter to continue   " );
  getch();
}

void phonebook()
{
for(int i=1;i<79;++i)
 cprintf("-");
for(i=0;i<80;++i)
{
 gotoxy(i,24);
 cprintf("-");
 }
 for(i=0;i<24;i++)
 {
  gotoxy(1,i);
  cprintf("-");
  gotoxy(80,i);
  cprintf("-");
 }
 for(i=2;i<80;++i)
 {
  gotoxy(i,5);
  cprintf("-");
 }
 gotoxy(32,3);
 cout<<"---";
 cout<<"P";
 delay(100);
 cout<<"H";
 delay(100);
 cout<<"O";
  delay(100);
 cout<<"N";
  delay(100);
 cout<<"E";
  delay(100);
 cout<<" ";
  delay(100);
 cout<<"B";
  delay(100);
 cout<<"O";
  delay(100);
 cout<<"O";
  delay(100);
 cout<<"K";
  delay(100);
  cout<<"---";
}


void filefromlist()
{
 node*temp=head;
 clrscr();
 f2=fopen("lol.txt","w");
 while(temp!=NULL)
 {
  fprintf(f2,"%s\n%s\n%s\n%c\n%s\n%d\n%d\n%d\n",temp->ph.name,temp->ph.addr,temp->ph.phone,temp->ph.gender,temp->ph.email,temp->ph.d.dd,temp->ph.d.mm,temp->ph.d.yy);
  temp=temp->next;
 }
 fclose(f2);
}

/*void listfromfile()
{ char a[100];
 node*temp=head;
  f1=fopen("lol.txt","r");
  char b;
  do
  {
 if(feof(f1))
 break;
  fgets(a,10000,f1);
  printf("%s",a);
  fscanf(f1,"%s",temp->ph.addr);
  fscanf(f1,"%s",temp->ph.phone);
  fscanf(f1,"%c",&temp->ph.gender);
  fscanf(f1,"%s",temp->ph.email);
  fscanf(f1,"%d",&temp->ph.d.dd);
  fscanf(f1,"%d",&temp->ph.d.mm);
  fscanf(f1,"%d",&temp->ph.d.yy);
  temp=temp->next;
  }while(1);
  //cout<<i;
} */

void listfromfile()
{
 node*temp=NULL;
 f1=fopen("lol.txt","r");
// temp=(node*)malloc(sizeof(node));
char a[15],b[50],c[12],d,e[50];
int f,g,h;
 while((fscanf(f1,"%s\n%s\n%s\n%c\n%s\n%d\n%d\n%d\n",a,b,c,&d,e,&f,&g,&h))!=EOF)
 {
  insert_file( a,b,c,d,e,f,g,h);
  printf("%s\n",a);
 // temp=temp->next;
 }
 fclose(f1);
 }



int main()
{
 clrscr();
 listfromfile();
 char name[15],num[15];
 welcome();
 do
 {
  clrscr();
  int choice = menu();
  int success;
  cout << "\n\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
  switch(choice)
   {
    case 1:
      clrscr();
      success = insert();
	 if(success)
	 {
	  for(int i=0;i<30;++i){
	  textcolor(RED+BLINK);
	  gotoxy(20,6);
	  cout<<"1";
	  gotoxy(13,8);
	  cout<<"ADD NEW CONTACT"; }
	  textcolor(BLUE);
	  clrscr();
	  gotoxy(28,12);
	  cout << "DATA INSERTED SUCCESSFULLY";
	  gotoxy(28,13);
	  cout << "PRESS ANY KEY TO CONTINUE....";
	  }
	 break;

    case 2:
       clrscr();
       phonebook();
       for(int i=1;i<80;++i)
       {
	gotoxy(i,7);
	cout<<"-";
       }
       gotoxy(35,6);
       cout<<"SEARCHING";
       gotoxy(39,7);

       for(i=7;i<12;++i){
       gotoxy(39,i);
       cout<<"-";}
       for(i=10;i<70;++i){
       gotoxy(i,10);
       cout<<"-";}
       for(i=10;i<=12;++i){
	gotoxy(10,i);
	cout<<"-";
	gotoxy(70,i);
	cout<<"-";}

       for(i=12;i<16;++i)
	{
	 gotoxy(3,i);
	 cout<<"-";
	 gotoxy(17,i);
	 cout<<"-";
	 gotoxy(63,i);
	 cout<<"-";
	 gotoxy(77,i);
	 cout<<"-";}
	 for(i=3;i<17;++i)
	 {
	  gotoxy(i,12);
	  cout<<"-";
	  gotoxy(60+i,12);
	  cout<<"-";
	  gotoxy(i,15);
	  cout<<"-";
	  gotoxy(60+i,15);
	  cout<<"-";
	  }
       for(i=19;i<59;++i){
       gotoxy(i,12);
       cout<<"-";}
       for(i=12;i<16;++i)
       {
	gotoxy(19,i);
	cout<<"-";
	gotoxy(59,i);
	cout<<"-";
       }
      for(i=10;i<28;++i)
      {
	gotoxy(i,16);
	cout<<"-";
	gotoxy(i+40,16);
	cout<<"-";
      }
      for(i=16;i<20;++i)
      {
	gotoxy(10,i);
	cout<<"-";
	gotoxy(50,i);
	cout<<"-";
	gotoxy(28,i);
	cout<<"-";
	gotoxy(68,i);
	cout<<"-";
       }
       for(i=10;i<29;++i)
       {
	gotoxy(i,20);
	cout<<"-";
	gotoxy(40+i,20);
	cout<<"-";
	}


      gotoxy(14,18);
      cout<<"1) BY NAME";
      gotoxy(53,18);
      cout<<"2) BY PHONE NO.";
      gotoxy(9,13);
      cout<<"(3)";
      gotoxy(5,14);
      cout<<"AUTO-SEARCH";
      gotoxy(69,13);
      cout<<"(4)";
      gotoxy(69,14);
      cout<<"EXIT";
      gotoxy(33,15);
      cout<<"YOUR CHOICE";
      gotoxy(35,19);
      for(i=33;i<45;++i)
       {gotoxy(i,16);
	cout<<"-";
	gotoxy(i,20);
	cout<<"-";
       }
      for(i=16;i<20;++i)
      { gotoxy(33,i);
      cout<<"-";
      gotoxy(44,i);
      cout<<"-";
      }
      int ch;
      gotoxy(38,18);
      cin>>ch;
      textcolor(BLUE);
       if(ch==1)
       {
	clrscr();
	phonebook();
	for(int i=1;i<80;++i)
	{
	 gotoxy(i,7);
	 cout<<"-";
	}
       gotoxy(35,6);
       cout<<"SEARCHING";
       gotoxy(30,9);
       cout << "Name : ";
       cin >> name;
       clrscr();
       search(name);
      }
     else if(ch==2)
     {
       clrscr();
       phonebook();
	for(int i=1;i<80;++i)
	{
	 gotoxy(i,7);
	 cout<<"-";
	}
       gotoxy(35,6);
       cout<<"SEARCHING";
       gotoxy(30,9);
       cout << "Phone Number : ";
       cin >> num;
       clrscr();
       search_no(num);
      }
    else if(ch==3)
    {
     clrscr();
     auto_search();
    }
   else if(ch==4)
    {
      clrscr();
	    choice =menu();
     }
    else
     {
       clrscr();
       gotoxy(32,12);
       cout<<"Enter a valid choice";
      }
   break;
    case 3:
     clrscr();
     phonebook();
       for(i=1;i<80;++i)
       {
	gotoxy(i,7);
	cout<<"-";
       }
       gotoxy(30,6);
       cout<<"DELETING CONTACT";
       gotoxy(30,9);
       cout << "Name : ";
       cin >> name;
       success = remove(name);
       if(success==1)
	  {
	     clrscr();
	     phonebook();
	     searchsuccess();
	    for(i=0;i<=30;++i)
	    {
	     textcolor(RED+BLINK);
	     gotoxy(35,16);
	     cprintf("DELETING....");
	    // gotoxy(37,14);
	     delay(150);
	    }
	    gotoxy(35,16);
	    gotoxy(35,11);
	    printf("DELETING....");
	    textcolor(RED);
	    gotoxy(32,16);
	    cout<<"DELETED SUCCESSFULLY";
	    textcolor(BLUE);
	  }
	 else if(success==2)
	   {
	     clrscr();
	     phonebook();
	     searchsuccess();
	     gotoxy(30,16);
	     cout<<"CONTACT IS NOT DELETED";
	   }
	 else
	  {
	    gotoxy(32,16);
	    cout<<"CONTACT NOT FOUND";

	  }
	  gotoxy(27,18);
	 cout<< "Press any key to continue...";
      break;

    case 4:
     clrscr();
     phonebook();
      for(i=1;i<80;++i)
       {
	gotoxy(i,7);
	cout<<"-";
       }
       gotoxy(28,6);
       cout<<"UPDATING CONTACT";
       gotoxy(30,9);
       cout << "Name : ";
       cin >> name;
       success = modify(name);
       if(success)
	 {
	    clrscr();
	    phonebook();
	    searchsuccess();
	    for(i=0;i<=30;++i)
	    {
	     textcolor(RED+BLINK);
	     gotoxy(35,16);
	     cprintf("UPDATING....");
	    // gotoxy(37,14);
	     delay(150);
	    }
	    gotoxy(35,16);
	    textcolor(RED);
	    cprintf("UPDATING....");
	    textcolor(RED);
	    gotoxy(28,16);
	    cout<<"UPDATED SUCCESSFULLY";
	    textcolor(BLUE);
	  }
       else
	 {
	    clrscr();
	    phonebook();
	    searchsuccess();
	    gotoxy(32,16);
	    cout<<"CONTACT NOT FOUND";
	  }

	 cout << "\n" << setw(53) << "Press any key to continue...";
      break;

    case 5:
      clrscr();
      display();
	 break;

    case 6:
	 clrscr();
	 filefromlist();
    //changecolor (  ) ;
    char line[ 80 ] ;
    fstream file ;
    file . open ( "bye.DAT", ios :: in ) ;
    while ( file )
    {
	file . getline ( line, 80 ) ;
	cout << line << endl ;
    }
    file.close ( );
	getch();
	clrscr();
	 cout << "\n\n\n\n\n\n\n\n";
	 cout << setw(46) << "  PHONEBOOK\n";
	 cout << setw(47) << "(Using Linked List)";
	 cout << "\n\n" << setw(31) << "A Program by Shrishti Gupta Shubham Guglani and Shubham Sharma";
	 cout << "\n\n\n\n\n" << setw(51) << "Press any key to halt...";
	 getch();
      return 0;

    default:
	 cout << endl << setw(58) << "Please select appropriate option\n";
	 cout << setw(55) << "Press any key to continue...";
   }

  getch();
 }while(1);
}
