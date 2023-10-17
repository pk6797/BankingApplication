#include<iostream.h>
#include<conio.h>
#include<process.h>
#include<fstream.h>
static long int pw=1000;
static int sn=0;
class node
{
	long long int acc_num,bal;
	long int ph;
	//long double ph;
	//int *ph;
	//int ph[10];
	long int pww;
	char name[30];
	node *link;
	public:
	node()
	{
	acc_num=0;
	bal=0;
	ph=0;
	}
	friend class bank;
};
class bank
{
		node *first,*p,*n,*temp;
		int ch;
		//static long int pw;
		long int h,a;
		static int num;
		static long long int count;
		//static long int pw;
		public:
		bank();
		void login();
		void new_acc();
		void menu();
		void deposit(node *);
		void with_draw(node *);
		void check_bal(node *);
		void all_det(node *);
		void del_acc();
		node* check_acc();
		void loan();
		void loan_det(node *);
		void display();
}help;
long long int bank::count=160214060;
//int bank::pw=1000;
int bank::num=0;
bank::bank()
{
		first=NULL;
}
void bank::login()
{
		int ch,n;
		do
		{
		cout<<"\n\n\n\n1.CREATE AN ACCOUNT\n2.EXISTING ACCOUNT(OPERATIONS)-->next\n3.DELETE AN ACCOUNT\n";
		cout<<"\n4.DISPLAY\n5.EXIT\nEnter your choice:";
		cin>>ch;
		switch(ch)
		{
			case 1:         clrscr();
					help.new_acc();
					cout<<"\nOur bank provides different loans\nYou can opt for anytype of loan if u are required";
					cout<<"\n1.Loan Details\n2.Quit\nEnter your choice:";
					cin>>n;
					if(n==1)
					{
						clrscr();
						help.loan();break;
					}
					else
					{
					clrscr();
					cout<<"\nYou can opt for any loan if you are interested another time";break;
					}
			case 2: clrscr();
				help.menu();
					break;
			case 3: clrscr();
				help.del_acc();
					break;
			case 4: clrscr();
				cout<<"\nenter password";
				cin>>n;
				if(n==0000)
				{
				help.display();break;
				}
				else
				{
				cout<<"\nInvalid login";
				help.login();break;
				}

			case 5:// clrscr();
				cout<<"\tTHANKYOU";
					exit(0);
			default:cout<<"\n\n\n\tYou have entered invalid option!\tTry again";
					help.login();
					break;
		}
		}while(ch!=4);
}
void bank::new_acc()
{
		int a[10];
		int i;
		node *n;
		count=count+1;
		num++;
		pw++;
		n=new node;
		n->acc_num=count;
		n->bal=0;
		n->pww=pw;
		//n->ph=new int[10];
		cout<<"\nEnter your name:(account holder)";
		cin>>n->name;
		cout<<"\nEnter your contact number:(for message alert)";
		cin>>n->ph;
		cout<<"\n********** ACCOUNT IS RECORDED ***********";
		cout<<"\nYOUR DETAILS ARE:";
		cout<<"\nACCOUNT NUMBER:"<<n->acc_num;
		cout<<"\nACCOUNT HOLDER:"<<n->name;
		cout<<"\nBALANCE:"<<n->bal;
		cout<<"\nMOBILE NUMBER:";
		cout<<n->ph;
		ofstream outf("MY_PRA.txt",ios::app);
		outf<<"\nACCOUNT NUMBER:"<<n->acc_num;
		outf<<"\tACCOUNT HOLDER:"<<n->name;
		outf<<"\tMOBILE NUMBER:"<<n->ph;
		cout<<"\nYour Password is(dont reveal it is highly confidential):"<<n->pww;
		cout<<"\nIncase you want to change any of your details\nVisit Bank";
		n->link=NULL;
		if(first==NULL)
		{
			first=n;
		}
		else
		{
			p=first;
			while(p->link!=NULL)
			{
					p=p->link;
			}
			p->link=n;
		}
}
void bank::menu()
{
		//node *h;
		int ch;  long int n;
		p=help.check_acc();
		cout<<"\nEnter Your Pass word:";
		cin>>n;
		if(n==p->pww)
		{
		do
		{
		cout<<"\n\n\n\n\n1.DEPOSIT\n2.WITH DRAW\n3.CHECK BALANCE\n4.LOAN DETAILS(IN CASE YOU HAVE OPTED)\n5.YOUR ACCOUNT DETAILS\n6.PREVIOUS MENU(<---)";
		cout<<"\n7.NEW LOAN\n8.EXIT\nENTER YOUR CHOICE:";
		cin>>ch;
		switch(ch)
		{
			case 1: clrscr();
				help.deposit(p);
					break;
			case 2: clrscr();
				help.with_draw(p);
					break;
			case 3: clrscr();
				help.check_bal(p);
					break;
			case 4: clrscr();
				help.loan_det(p);
					break;
			case 5: clrscr();
				help.all_det(p);
					break;
			case 6: clrscr();
				help.login();
					break;
			case 7: clrscr();
				help.loan();
					break;
			case 8: //help.display();
				cout<<"\n\n\n\t********** THANKYOU **********";
					exit(0);
		}
		}while(ch!=7);
		}
		else
		{
		cout<<"\nInvalid Pass word! Try again:";
		help.login();
	       }
}
void bank::del_acc()
{
		//node *n,*temp;
		n=help.check_acc();
		p=first;
		while(p->acc_num!=n->acc_num)
		{
			temp=p;
			p=p->link;
		}
		temp->link=p->link->link;
		delete p;
		cout<<"\n\n\n\n\tYOUR ACCOUNT IS DELETED";
		num--;
}
void bank::deposit(node *e)
{
		long int a;
		//node *n;
		n=e;
		cout<<"\n\n\n\n\tEnter the amount you want to deposit:";
		cin>>a;
		n->bal=n->bal+a;
		clrscr();
		cout<<"\nSUCCESSFULLY DEPOSITED";
}
void bank::with_draw(node *e)
{
		long int a;
		//node *n;
		n=e;
		cout<<"\n\n\n\n\tEnter the amount you want to withdraw:";
		cin>>a;
		if(n->bal==0)
		{
			clrscr();
			cout<<"\n\n\nYour account balance is 0\nSo you can't withdraw cash!";
		}
		if(a>n->bal)
		{
			clrscr();
			cout<<"\n\n\n\n\tYou dont have enough balance to draw that amount";
		}
		if(a<=n->bal)
		{
			n->bal=n->bal-a;
			clrscr();
			cout<<"\n\n\n\tYOUR TRANSACTION IS SUCCESSFUL";
		}
}
void bank::check_bal(node *e)
{
		//node *n;
		n=e;
		cout<<"\n\n\n\n\tYour Account balance is:"<<n->bal;
}
void bank::all_det(node *e)
{
		//node *n;
		n=e;
		cout<<"\n\n\n\nYOUR ACCOUNT DETAILS RECORDED ARE:";
		cout<<"\nACCOUNT NUMBER:"<<n->acc_num;
		cout<<"\nACCOUNT HOLDER:"<<n->name;
		cout<<"\nBALANCE:"<<n->bal;
		cout<<"\nMOBILE NUMBER:";
		cout<<n->ph;
		/*for(int i=0;i<10;i++)
		{
		cout<<n->ph[i];
		} */
}
void bank::display()
{
		if(first==NULL)
		{
			cout<<"\nNo account is opened till now:";
		}
		else
		{
			cout<<"\nDetails of account holders are:";
			p=first;
			while(p->link!=NULL)
			{
			sn++;
			cout<<"\n"<<sn<<".";
			cout<<"ACCOUNT NUMBER:"<<p->acc_num;
			cout<<"\tACCOUNT HOLDER:"<<p->name;
			cout<<"\nBALANCE:"<<p->bal;
			cout<<"\tMOBILE NUMBER:";
			cout<<p->ph;
			/*for(int i=0;i<10;i++)
			{
			cout<<n->ph[i];
			} */
			cout<<"\n";
			p=p->link;
			}
			sn++;
			cout<<"\n"<<sn<<".";
			cout<<"\nACCOUNT NUMBER:"<<p->acc_num;
			cout<<"\tACCOUNT HOLDER:"<<p->name;
			cout<<"\nBALANCE:"<<p->bal;
			cout<<"\tMOBILE NUMBER:";
			cout<<p->ph;
			/*for(int i=0;i<10;i++)
			{
			cout<<n->ph[i];
			} */
		}
		help.login();
}
void bank::loan()
{
		int ch;
		cout<<"\nTypes of loans provided by our bank are:";
		cout<<"\n1.EDUCATION\n2.HOUSING\n3.BUSINESS\n4.GOLD\n5.CROP\n6.PERSONAL\n7.CAR OR VEHICLE\n8.MEDICAL OR EQUIPMENT LOAN\nEnter your choice:";
		cin>>ch;
		switch(ch)
		{
		case 1:

		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8: clrscr();
			cout<<"\n\n\n\tVisit any branch in your locality along with the following forms during bank working days for issue of loan:";
				cout<<"\nBANK BOOK\nAADHAR CARD\nALLOTMENT ORDER AND FEE PARTICULARS\n\t(incase of education loan)";
				cout<<"\nPASSPORT SIZE PHOTOS-2\nPROPERTY DOCUMENTS WHICH ARE VALUABLE EQUAL TO LOAN AMOUNT";
				cout<<"\nA PERSON FOR SHOORITY\n\t(HE SHOULD BE AN ACCOUNT HOLDER IN OUR BANK)";
				cout<<"\nFurthur details or any quiries contact number:040-*******";break;
		}
}
void bank::loan_det(node *e)
{
		cout<<"\nYour loan details will be updated by sending an message alert to your mobile number:";
		cout<<e->ph;
		cout<<"\nFurthur details contact:040-******";
}
node* bank::check_acc()
{
		long int n;
		//node *temp;
		do
		{
		cout<<"\nEnter your account number:";
		cin>>n;

		p=first;
		for(int i=0;i<num;i++)
		{
		if(p->acc_num==n)
		{
		temp=p;
		return temp;
		}
		else p=p->link;
		}
		cout<<"\nYou have entered invalid option";
		}while(p->acc_num!=n);
		/*while(p->link!=n)
		{
		p=p->link;
		}
		temp=p;
		return temp;
		for(;p->acc_num!=NULL;p=->link)acc_num
		{
		if(p->acc_num==n)
		{
		temp=p;
		return temp;
		}
		else
		{*/
}
void main()
{
		clrscr();

		cout<<"***********WELCOME***********";
		help.login();
		help.display();
		getch();
}
