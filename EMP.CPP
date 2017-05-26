	/* Welcome to the Office Management Department of the
			   Aey Gee Pvt. Ltd.
	This project is designed by NITESH GUPTA of class XII A. */

//--------------------------------------------------------------------------------------------------------------
#include<fstream.h>
#include<iostream.h>
#include<conio.h>
#include<process.h>
#include<ctype.h>
#include<iomanip.h>
#include<string.h>
#include<stdio.h>
#include<dos.h>
const int MAX=20;

class office_mngmnt
{
	  private:
	       long code;
	       char hno[MAX];
	       char fname[80];
	       char gender[MAX];
	       char language[MAX];
	       char street[MAX];
	       char city[MAX];
	       double zcode;
	       char country[MAX];
	       double telephone;
	       char salutation[MAX];
	  public:
		void get_data();
		void display_data();
		void display_record();
		void append_record();
		void search_record(int code);
		void salary_slip();
		int found_code(int ccode);
		void delete_record(int dcode);
		int count();
		int retcode()
		{
		return code;
		}

 };

 //***********************************************************************
 //		TO CHECK WHETHER THE ENTERED RECORD EXISTS....
 //***********************************************************************

 int office_mngmnt::found_code(int ccode)
 {      office_mngmnt office;
	fstream file;
	file.open("office.dat",ios::in);
	file.seekg(0);
	int flag=0;
	while(!file.eof())
		{
			file.read((char*)&office,sizeof(office));
			if(code==ccode)
			{
				flag=1;
				break;
			}
		}
	file.close();
	if(flag==1)
		{
			return code;
		}
	else
		{
			return 0;
		}
 }

  //*************************************************************************
 //			TO GET THE DATA FROM THE USER
 //*************************************************************************
 void office_mngmnt::get_data()
 { textcolor(12);
   cout<<"\n\tENTER USER NUMBER   :";
   cin>>code;
   cout<<"\n";
   cout<<"\tENTER THE FULL NAME OF THE EMPLOYEE     :";
   gets(fname);
   cout<<"\n";
   cout<<"\tENTER GENDER...(M/F)       :";
   cin>>gender;
   cout<<"\n";
   cout<<"\tENTER LANGUAGE             :";
   cin>>language;
   cout<<"\n";
   cout<<"\tENTER SALUTATION(MR.,MRS.,MS.) :";
   gets(salutation);
   cout<<"\n";
   cout<<"\n";
   cout<<"         ENTER THE EMPLOYEE'S ADDRESS         :";
   cout<<"\n"<<"\n";
   delay(500);
   cout<<"         ENTER HOUSE NUMBER 	         :";
   cin>>hno;
   cout<<"         ENTER STREET                  :";
   gets(street);
   cout<<"         ENTER CITY                    :";
   gets(city);
   cout<<"         ENTER ZIP CODE                :";
   cin>>zcode;
   cout<<"         ENTER COUNTRY                 :";
   gets(country);
   cout<<"    	 ENTER TELEPHONE NUMBER        :";
   cin>>telephone;

   }	//get_data()
//*************************************************************************
//			TO DISPLAY THE INPUT DATA....
//*************************************************************************
void office_mngmnt::display_data()
   {    textcolor(BLUE);
	cout<<"                   EMPLOYEES DATA :                   "<<endl;
	cout<<"\n";
		cout<<"\n\tUSER NUMBER       :"<<code<<endl;
		cout<<"\n\tNAME              :";cout.write(salutation,strlen(salutation)); cout.write(fname,strlen(fname));
		cout<<"\n\tGENDER            :"<<gender<<endl;
		cout<<"\n\tLANGUAGE          :";cout.write(language,strlen(language))<<endl;
	cout<<"\n                 ADDRESS                            "<<endl;
	cout<<"\n";
		cout<<"\n\tHOUSE NO.         :"<<hno<<endl;
		cout<<"\n\tSTREET            :";  cout.write(street,strlen(street));
		cout<<"\n\tCITY              :";cout.write(city,strlen(city))<<endl;
		cout<<"\n\tZIP CODE          :"<<zcode<<endl;
		cout<<"\n\tCOUNTRY           :";cout.write(country,strlen(country))<<endl;
		cout<<"\n\tTELEPHONE NUMBER    :"<<telephone;
  }         //display_data()

 //*************************************************************************
 //*************************************************************************
 //		      VOID MAIN()- EXECUTION OF THE PROGRAM
 //*************************************************************************
 //*************************************************************************
 void main()
 {             clrscr();
	       office_mngmnt office;
	       int ans;

	       do
	       {
		 int choice;
		 const int ans=0;
		 int dcode, ccode;
	      d10:  clrscr();
	      textcolor(15);
	      cout<<"\a";
	      cout<<"\n\n\n\n";
cout<<"\t   *********** AEY GEE PVT. LTD.***********    "<<endl;
cout<<"\n";
cout<<"\t                MAIN MENU                             "<<endl;
cout<<"\n";
cout<<"\t              1.ADD RECORD.                         "<<endl;
cout<<"\n";
cout<<"\t              2.SEARCH RECORD. 		     "<<endl;
cout<<"\n";
cout<<"\t              3.DELETE RECORD.                      "<<endl;
cout<<"\n";
cout<<"\t              4.DISPLAY RECORDS.                    "<<endl;
cout<<"\n";
cout<<"\t              5.SALARY SLIP.                        "<<endl;
cout<<"\n";
cout<<"\t              6.EXIT.                               "<<endl;
cout<<"\n"<<"\n";
		cout<<"\t\t";
		cout<<"ENTER YOUR CHOICE...(1-6)..  : ";
		cin>>choice;
 switch(choice)
 {
   case 1: 	   office.append_record();
		   getch();
		   goto d10;

   case 2:         clrscr();
		   cout<<"\n\n\tENTER CODE NO. TO BE SEARCHED :";
		   cin>>ccode;
		   office.search_record(ccode);
		   goto d10;

   case 3:         clrscr();
		   cout<<"\n\n\tENTER CODE TO BE DELETED :";
		   cin>>dcode;
		   office.delete_record(dcode);

   case 4:         office.display_record();
		   goto d10;

   case 5:         office.salary_slip();
		   goto d10;

   case 6:         break;

   default:       cout<<"\n\t\t\tWRONG ENTRY !!!"<<endl;
		  cout<<"\n\t\tPRESS ANY KEY TO CONTINUE....."<<endl;
		  getch();
		  goto d10;
     }         //switch
   }  while(ans==7);  //do
}   //main()

//***************************************************************************
//			TO ENTER NEW RECORDS......
//***************************************************************************

void office_mngmnt::append_record()
 {       clrscr();
	 office_mngmnt office;
	 fstream file;
	 file.open("office.dat",ios::app|ios::in);
	 char c;
	 do
	 {
	   office.get_data();
	   file.write((char*)&office,sizeof(office));
	   cout<<"DO YOU WANT TO CONTINUE......(Y/N)"<<endl;
	   cin>>c;
	 }while(c=='y'||c=='Y');   //do
	 file.close();
 }    //append_record
//***************************************************************************
//			TO SEARCH FOR THE ENTERED RECORD......
//***************************************************************************

void office_mngmnt::search_record(int ccode)
 {
   fstream file;
   fstream nfile;
   int nfound=0;
   office_mngmnt office;
   clrscr();
   file.open("office.dat",ios::in);
   while(file.read((char*)&office,sizeof(office)))
   {
    if(retcode()==ccode)
    office.display_data();
    else
    nfound=1;
   }
    if(nfound==1)
    cout<<"Record not found........";
    getch();
 }
//***************************************************************************
//			TO DELETE THE ENTERED RECORD......
//***************************************************************************

void office_mngmnt::delete_record(int deletion)
{  fstream file,nfile;
   office_mngmnt office;
   clrscr();
   file.open("office.dat",ios::in);
   nfile.open("new.dat",ios::out);
   int flag=0;
   while(file.read((char*)&office,sizeof(office)))
   {
    if(office.retcode()!=deletion)
     file.write((char*)&office,sizeof(office));
    else
     flag++;
   }
       if (flag==0)
	cout<<"No record matched, so no record was deleted.......";
	remove("office_data.dat");
	rename("new.dat","office.dat");
     file.close();
     nfile.close();
  }
//***************************************************************************
//			TO DISPLAY THE RECORDS......
//***************************************************************************
 void office_mngmnt::display_record()
 {  clrscr();
    office_mngmnt office;
    fstream file;
    file.open("office.dat",ios::in);
   while(!file.eof())
   {
      clrscr();
      file.read((char*)&office,sizeof(office));
      office.display_data();
      getch();
   }
   file.close();
}
//***************************************************************************
//	   	 CALCULATES SALARY SLIP OF AN EMPLOYEE
//***************************************************************************
void  office_mngmnt:: salary_slip()
{   clrscr();
    get_data();
    int leaves,lea;
    long basic_sal,hra,ta,pf,net,enet,allow;
    clrscr();
    cout<<"\nENTER BASIC SALARY : Rs.";
    cin>>basic_sal;
    cout<<"LEAVES TAKEN DURING THE MONTH :";
    cin>>leaves;
      hra=(5*basic_sal)/100;
      ta=(5*basic_sal)/100;
      pf=(2*basic_sal)/100;
      allow =hra+ta;
      net=(basic_sal+allow)-pf;
      lea=(leaves*150);
      enet=(net-lea);
      clrscr();
      delay(300);
      cout<<"\n\n";
      cout<<"\t             	    AEY GEE PVT. LTD.                      "<<endl;
      cout<<"\n";
      cout<<"\t                        SALARY SLIP                         "<<endl;
      cout<<"\n";
      display_data();
      cout<<"\n\n";
      cout<<"\t!!!!!!!!!!!!!!!!!!!!!!!!!!ALLOWANCE!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
      cout<<"\n";
      cout<<"\tHOUSE RENT ALLOWANCE(H.R.A): Rs."<<setw(7)<<hra <<"\t\t     "<<endl;
      cout<<"\tTRAVEL ALLOWANCE (T.A)     : Rs."<<setw(7)<<ta  <<"\t\t     "<<endl;
      cout<<"\n";
      cout<<"\t!!!!!!!!!!!!!!!!!!!!!!!!!DEDUCTIONS!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
      cout<<"\n";
      cout<<"\tPROVIDENT FUND (P.F)       : Rs."<<setw(7)<<pf  <<"\t\t     "<<endl;
      cout<<"\tLEAVES TAKEN               : "<<leaves          <<"\t\t     "<<endl;
      cout<<"\n"<<"\n";
      cout<<"--------------------------------------------------------------------------"<<endl;
      cout<<"\tNET SALARY                 : Rs."<<setw(7)<<enet<<"\t\t     "<<endl;
      cout<<"\n";
      cout<<"\n\n\n\t\tPRESS ANY KEY TO CONTINUE............";
      getch();
  } //salary_slip

//**************************************************************************************
//				THANK YOU
//**************************************************************************************


