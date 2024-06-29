#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
	char name[50];
	int bus_num;
	int num_of_seats;
}pd;
void reservation(void);
void viewdetails(void);
void printticket(char name[],int,int,float);
void specificbus(int);
float charge(int,int);
void login();
int main()

{
	system("cls");
	system("color 3");
	printf("\t\t=================================================\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|       ----------------------------------      |\n");
	printf("\t\t|             BUS TICKET RESERVATION            |\n");
	printf("\t\t|                    SYSTEM                     |\n");
	printf("\t\t|       ----------------------------------      |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t=================================================\n\n\n");


	printf(" \n Press any key to continue:");
	getch();
           system("cls");
	login();
	int menu_choice,choice_return;
	start:
	system("cls");
	printf("\n=================================\n");
	printf("     BUS RESERVATION SYSTEM");
	printf("\n=================================");
	printf("\n1>> BOOK TICKET");
	printf("\n------------------------");
	printf("\n2>> AVAILABLE BUSES LIST");
	printf("\n------------------------");
	printf("\n3>> Exit");
	printf("\n-->");
	scanf("%d",&menu_choice);
	switch(menu_choice)
	{
		case 1:
			reservation();
			break;
		

                           case 2: 
			viewdetails();
			printf("\n\nPress any key to go to Main Menu..");
			getch();
			break;
		case 3:
			return(0);
		default:
			printf("\nInvalid choice");
	}
	goto start;
	return(0);
}


void viewdetails(void)
{
	system("cls");
printf("---------------------------------------------------------------------------------------");
printf("\nBus.No\tName\t\t\tDestinations  \t\tCharges  \t\tTime\n");
printf("---------------------------------------------------------------------------------------");
printf("\n111\tGaruda Plus\tHanmakonda to Hyderabad\tRs.600\t\t9:00  AM");
printf("\n112\tSuper Deluxe\tHanamkonda to Chennai\tRs.400\t\t12:00 PM");
printf("\n113\tSuper Luxury\tBanglore to Warangal\tRs.1500\t\t1:50  PM");
printf("\n114\t Venkatadhri Express\tWarangal to Adilabad\tRs.800\t\t11:00 AM");
printf("\n115\tOrange Travels\tJagital to Bhopalpelli\tRs.750\t\t7:05  AM");
printf("\n116\tRajdhani Express\tMaharastra to Andhrapradesh \tRs.600\t\t9:30  AM");
printf("\n117\tKaveri Travels\tVijaywada to Vizag\tRs.350\t\t1:00  PM");
printf("\n118\tGreenline Travels\tWarangal to Nalgonda\tRs.400\t\t4:00  PM"); 
printf("\n119\tIntricity Smartbus\tHanamkonda to Tamilnadu\tRs.600\t\t5:35  PM");
printf("\n120\tNational Travels\tTamilnadu to Kerla\tRs.600\t\t4:15  PM");

}


void reservation(void)
{
	char confirm;
	int i=0;
	float charges;
	pd passdetails;
	FILE *fp;
	fp=fopen("seats_reserved.txt","a");
	system("cls");

	printf("\nEnter Your Name:> ");
	fflush(stdin);
	gets(passdetails.name);
	printf("\nEnter Number of seats:> ");
	scanf("%d",&passdetails.num_of_seats);
	printf("\n\n>>Press Enter To View AVAILABLE BUS LIST<< ");
	getch();
	system("cls");
	viewdetails();
	printf("\n\nEnter bus number:> ");
	start1:
	scanf("%d",&passdetails.bus_num);
	if(passdetails.bus_num>=111 && passdetails.bus_num<=156)
	{
		charges=charge(passdetails.bus_num,passdetails.num_of_seats);
		printticket(passdetails.name,passdetails.num_of_seats,passdetails.bus_num,charges);
	}
	else
	{
		printf("\nInvalid bus Number! Enter again--> ");
		goto start1;
	}

	printf("\n\nConfirm Ticket (y/n):>");
	start:
	scanf(" %c",&confirm);
	if(confirm == 'y')
	{
		fprintf(fp,"%s\t\t%d\t\t%d\t\t%.2f\n",&passdetails.name,passdetails.num_of_seats,passdetails.bus_num,charges);
		printf("==================");
		printf("\n Reservation Done\n");
		printf("==================");
		printf("\nPress any key to go back to Main menu");
	}
	else
	{
		if(confirm=='n'){
			printf("\nReservation Not Done!\nPress any key to go back to  Main menu!");
		}
		else
		{
			printf("\nInvalid choice entered! Enter again-----> ");
			goto start;
		}
	}
	fclose(fp);
	getch();
}

float charge(int bus_num,int num_of_seats)
{

	if (bus_num==111)
	
	{
		return(600*num_of_seats);
	}
	if (bus_num==112)
	{
		return(400*num_of_seats);
	}
	if (bus_num==113)
	{
		return(1500*num_of_seats);
	}
	if (bus_num==114)
	{
		return(800*num_of_seats);
	}
	if (bus_num==115)
	{
		return(750*num_of_seats);
	}
	if (bus_num==116)
	{
		return(600*num_of_seats);
	}
	if (bus_num==117)
	{
		return(350*num_of_seats);
	}
	if (bus_num==118)
	{
		return(400*num_of_seats);
	}
	if (bus_num==119)
	{
		return(600*num_of_seats);
	}
	if (bus_num==120)
	{
		return(600*num_of_seats);
	}
}

void printticket(char name[],int num_of_seats,int bus_num,float charges)
{
	system("cls");
	printf("-------------------\n");
	printf("\tTICKET\n");
	printf("-------------------\n\n");
	printf("Name:\t\t\t%s",name);
	printf("\nNumber Of Seats:\t%d",num_of_seats);
	printf("\nbus Number:\t\t%d",bus_num);
	specificbus(bus_num);
	printf("\nCharges:\t\t%.2f",charges);
}


void specificbus(int bus_num)
{

	if (bus_num==111)
	{
		printf("\nbus:\t\t\tGarudaplus");
		printf("\nDestination:\t\t Hanamkonda to Hyderabad");
		printf("\nDeparture:\t\t9am ");
	}
	if (bus_num==112)
	{
		printf("\nbus:\t\t\tSuperdeluxe ");
		printf("\nDestination:\t\t Hanamkonda to Chennai");
		printf("\nDeparture:\t\t12pm");
	}
	if (bus_num==113)
	{
		printf("\nbus:\t\t\tSuperluxury");
		printf("\nDestination:\t\t Banglore to Warangal");
		printf("\nDeparture:\t\t8am");
	}
	if (bus_num==114)
	{
		printf("\nbus:\t\t\t Venkatadhri Express");
		printf("\nDestination:\t\t Warangal to Adilabad");
		printf("\nDeparture:\t\t11am ");
	}
	if (bus_num==115)
	{
		printf("\nbus:\t\t\tOrange travels");
		printf("\nDestination:\t\t Jagital to Bhopalpelli ");
		printf("\nDeparture:\t\t7am");
	}
	if (bus_num==116)
	{
		printf("\nbus:\t\t\tRajdhani Express");
		printf("\nDestination:\t\t Maharastra to Andhrapradesh");
		printf("\nDeparture:\t\t9.30am ");
	}
	if (bus_num==117)
	{
		printf("\nbus:\t\t\tkaveritravels");
		printf("\nDestination:\t\t Vijaywada to Vizag ");
		printf("\nDeparture:\t\t1pm ");
	}
	if (bus_num==118)
	{
		printf("\nbus:\t\t\tGreenlinetravels");
		printf("\n Destination:\t\tHanamkonda to Nalgonda");
		printf("\nDeparture:\t\t4pm ");
	}
	if (bus_num==119)
	{
		printf("\nbus:\t\t\tIntricitysmartbus");
		printf("\nDestination:\t\t Hanamkonda to Tamilnadu");
		printf("\nDeparture:\t\t3.35pm ");
	}
	if (bus_num==120)
	{
		printf("\nbus:\t\t\tNationaltravels");
		printf("\nDestination:\t\tTamilnadu to Kerla");
		printf("\nDeparture:\t\t1.15 ");
	}
}

void login()
{
	int a=0,i=0;
    char uname[10],c=' ';
    char pword[10],code[10];
    char user[10];
    char pass[10];
    do
{

    printf("\n  =======================  LOGIN FORM  =======================\n  ");
    printf(" \n                       ENTER USERNAME:-");
	scanf("%s", &uname);
	printf(" \n                       ENTER PASSWORD:-");
	while(i<10)
	{
	    pword[i]=getch();
	    c=pword[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	pword[i]='\0';
	i=0;
		if(strcmp(uname,"USER")==0 && strcmp(pword,"PASS")==0)
	{
	printf("  \n\n\n       WELCOME TO OUR  BUS RESERVATION SYSTEM !! YOUR LOGIN IS SUCCESSFUL");
	printf("\n\n\n\t\t\t\tPress any key to continue...");
	getch();
	break;
	}
	else
	{
		printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
		a++;

		getch();
		system("cls");
	}
}
	while(a<=2);
	if (a>2)
	{
		printf("\nSorry you have entered the wrong username and password for four times!!!");

		getch();

		}
		system("cls");
}
