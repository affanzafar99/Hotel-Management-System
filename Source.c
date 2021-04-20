#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct customer
{

	char name[30]; //string variable to store name of customer
	long long cell_number; //variable to store cell number of customer
	long long CNIC; //variable to store CNIC of customer
	int Customer_ID; //customer ID
	int number_of_rooms; //number of rooms taken by the customer
	int room_numbers[3]; //array to store rooms taken by the customer
};
typedef struct customer Customer; 

int room[3][20] = { 0 }; //array to display rooms

//function declarations
void mainmenu(); 
void about();
void roomdetails();
void room_allocation();
void RoomDeallocation();
int bill(int[], int);
void reset_details(char[]);
void CustomerDetails(int a);
void resetrooms(int [], int);
bool roomcheck(int);
bool RegistrationNumberValidation(int);


int main()
{
	mainmenu();
	getch();
	return 0;
}



//function definitions
void mainmenu()//function to display main menu of the program
{
	printf("\n\t\t\t\t_________________________________\n");
	printf("\t\t\t\t|\t\t\t\t|\n");
	printf("\t\t\t\t|\t     WELCOME    \t|\n");
	printf("\t\t\t\t|\t       TO       \t|\n");
	printf("\t\t\t\t|\t   SHAIDU INN   \t|\n");
	printf("\t\t\t\t|\t\t:)\t\t|\n");
	printf("\t\t\t\t|_______________________________|\n\n\n");

	printf("\t\t\t\t1)About\n");
	printf("\t\t\t\t2)Room Details\n");
	printf("\t\t\t\t3)Room allocation\n");
	printf("\t\t\t\t4)Room deallocation\n");
	printf("\t\t\t\t5)Customer details\n\n");
	printf("\t\t\t\t0)Exit\n\n\t\t\t\t");


	int choice;
	int c_id;
	scanf(" %d", &choice);
	switch (choice)
	{
	case 1:
		about();
		break;

	case 2:
		roomdetails();
		break;
	
	case 3:
		room_allocation();
		break;

	case 4:
		RoomDeallocation();
		break;

	case 5:
		printf("Enter registration number:\t");
		scanf("%d", &c_id);
		CustomerDetails(c_id);
		break;

	case 0:
		return 0;

	default:
		printf("Invalid entry");
		getch();
		system("cls");
		mainmenu();
		break;
	}


}


void about()//function to display hotel details and facilities
{
	system("cls");
	printf("\t\tSHAIDU INN\n\t\tABOUT:\n\n\n");
	printf("\t\tShaidu Inn is renowned for it's peaceful and close to nature environment.\n\t\tIf you want a weekend away from the loud chaos of the city or a vacation\n\t\twith your family, you don't have to look any further. Shaidu Inn is your \n\t\tvery own escape with many recreational activities to keep you busy during\n\t\tyour time here. These include:");
	printf("\n\n\t\t-Swimming pools\n\t\t-Shooting range\n\t\t-Free soaps and shampoos\n\t\t-Gym\n\t\t-Mini zoo\n\t\t-Room service\n\t\t-Restaurants (With cuisines from different parts of the world)\n\t\t-Cute cats (Motu)\n\t\t-Movie theatre\n\t\t-Good company\n\t\t-Souvenir shops\n\t\tand much much more");
	printf("\n\n\t\tPress any key to exit to mainmenu");

	getch();
	system("cls");
	mainmenu();
}


void roomdetails()//function to display description of all types of rooms
{
	system("cls");
	printf("ROOMS:");
	printf("\n\n1)Standard room");
	printf("\n2)Double room");
	printf("\n3)Coolerthantherest room");
	printf("\n\nEnter 0 to exit to mainmenu\n\n");

	int choice2;
	scanf("%d", &choice2);

	switch (choice2)
	{
	case 1:
		printf("\n\n");
		printf("Standard room:\nOur standard room consists of a single bed with an attached bath with hot water at all times unlike Zainab hostel");
		printf("\n24 hour room service and a mini zoo right outside your window. If you're an animal lover, this is your ideal \nroom.");
		printf("\nRent per night: Rs.3000");
		getch();
		system("cls");
		roomdetails();
		break;

	case 2:
		printf("\n\n");
		printf("Double room: \nThe Double room has a king-size bed with an attached bath. The swimming pool is only a few doors down\nand there's a peaceful nature walk trail right outside. Highly recommended for nature lovers");
		printf("\nRent per night: Rs.4500");
		getch();
		system("cls");
		roomdetails();
		break;

	case 3:
		printf("\n\n");
		printf("Coolerthantherest room: \nThis room comes with the most beautiful view. It has an outdoor entrance with your very own small garden.\n");
		printf("it also has its own dining space for when you invite your friends to eat");
		printf("\nRent per night: Rs.8000");
		getch();
		system("cls");
		roomdetails();
		break;

	case 0:
		system("cls");
		mainmenu();
		break;

	default:
		printf("Invalid entry");
		getch();
		system("cls");
		roomdetails();
		break;
	}
}


void room_allocation()//function for room allocation 
{
	system("cls");

	FILE *fptr = fopen("Customer details.csv", "a+"); //opens file Customer Details in append mode, meaning data is added to the end of the file
	FILE *roombooking = fopen("bookedrooms.txt", "a+"); 
	Customer A; //
	int c_id = 1;
	
	while (RegistrationNumberValidation(c_id) == true) 
	{
		c_id++;
	}

	A.Customer_ID = c_id; 


	printf("Your registration number is:\t%d\n", A.Customer_ID); 

	printf("Enter name: "); 
	getchar();
	fgets(A.name,sizeof(A.name),stdin);

	int len = strlen(A.name); 
	A.name[len - 1] = '\0';

	do
	{
		printf("\nEnter number of rooms (enter number between 1 to 3): "); //
		scanf("%d", &A.number_of_rooms);
	} while (A.number_of_rooms < 1 || A.number_of_rooms>3);


	printf("\nEnter cell number: ");
	scanf("%lld", &A.cell_number);

	printf("\nEnter CNIC: ");
	scanf("%lld", &A.CNIC);

	int a = 0; //total rooms booked by user
	int s_room = 0; //standard rooms
	int d_room = 0; //double roooms
	int d_del = 0; //coolerthantherest rooms

	do 
	{
		int type;
		printf("\n\n\n\nWhat type of room would you like? (1: Standard 2: Double 3: Coolerthantherest)   "); 
		scanf("%d", &type);

		if (type == 1) //if user selects standard room
		{
			if (s_room >= 20) //if all 20 rooms are booked already
			{
				printf("\nStandard Rooms are fully booked, sorry!");
			}

			while (s_room < 20) //runs as long as the 20 rooms aren't booked
			{
				room[0][s_room] = 101 + s_room; //assigns room number to the corresponding array element
				if (roomcheck(room[0][s_room]) == false) //if room is not booked
				{
					printf("\nBooked room: %d", room[0][s_room]); //display booked room number
					A.room_numbers[a] = room[0][s_room]; //stores booked room number in file
					s_room++;
					a++; //increments total rooms booked by user
					break;
				}
				else if (roomcheck(room[0][19]) == true) //if the 20th room is booked in this execution
				{
					printf("\nStandard Rooms are fully booked, sorry!");
					s_room++; //increments s_room, so if user presses 1 again, program doesn't enter while loop
					break;
				}
				else
					s_room++; 
			}
		}

		else if (type == 2) //if user selects double room
		{
			if (d_room >= 20) //if all 20 rooms are booked
			{
				printf("\nDouble Rooms are fully booked, sorry!");
			}

			while (d_room < 20) //runs as long as the 20 rooms aren't booked
			{
				room[1][d_room] = 201 + d_room; //assigns room number to the corresponding array element

				if (roomcheck(room[1][d_room]) == false) //if room not booked
				{
					printf("\nBooked room: %d", room[1][d_room]); //display booked room number
					A.room_numbers[a] = room[1][d_room]; //stores book room number in file
					d_room++;
					a++; //increments total rooms booked by user
					break;
				}

				else if (roomcheck(room[1][19]) == true) //if 20th room booked in this execution
				{
					printf("\nDouble Rooms are fully booked, sorry!");
					d_room++; //increments d_room, so if user presses 2 again, program doesn't enter while loop
					break;
				}
				else
					d_room++;
			}

		}

		else if (type == 3) //if user selects coolerthantherest room
		{
			if (d_del >= 20) //if all 20 rooms are booked
			{
				printf("\nCoolerthantherest Rooms are fully booked, sorry!");
			}
			while (d_del < 20) //runs as long as the 20 rooms aren't booked
			{
				room[2][d_del] = 301 + d_del; //assigns room number to corresponding array element
				if (roomcheck(room[2][d_del]) == false) //if room not booked
				{
					printf("\nBooked room: %d", room[2][d_del]); //prints booked room number
					A.room_numbers[a] = room[2][d_del]; //stores booked room number in file
					d_del++;
					a++; //increments total rooms booked by user
					break;
				}
				else if (roomcheck(room[2][19]) == true) //if 20th room booked in this execution
				{
					printf("\nCoolerthantherest Rooms are fully booked, sorry!");
					d_del++; //increments d_del, so if user presses 3 again, progra, doesn't enter while loop
					break;
				}
				else
					d_del++;
			}
		}

		
	} while (a < A.number_of_rooms); //do while runs according to the number of rooms requested by user

	fprintf(fptr, "%d,", A.Customer_ID); //saves user's information onto file
	fprintf(fptr, "%s,", A.name);
	fprintf(fptr, "%d,", A.number_of_rooms);
	fprintf(fptr, "%lld", A.cell_number);
	fprintf(fptr, ",%lld,", A.CNIC);

	for (int i = 0; i < A.number_of_rooms; i++)
	{
		fprintf(fptr, "%d,", A.room_numbers[i]);
		fprintf(roombooking, "%d,", A.room_numbers[i]);
	}
	fprintf(fptr, "\n");
	fclose(fptr); //closes files
	fclose(roombooking);


	getch();
	system("cls");
	mainmenu();

}


void reset_details(char a[])//function to reset customer details file after a customer checks out
{
	FILE *oldfile, *newfile;
	char line[1000];
	oldfile = fopen("Customer details.csv", "r");
	newfile = fopen("replica.csv", "w+");
	while (fgets(line, 1000, oldfile) != NULL)
	{
		if (strcmp(line, a) != 0)
		{
			fprintf(newfile, line);
		}
	}
	fclose(oldfile);
	fclose(newfile);
	remove("Customer details.csv");
	rename("replica.csv", "Customer details.csv");

}

int bill(int a[], int size)//function to generate customer's bill at the time of checkout
{
	int bill = 0;
	int nights;
	printf("\nEnter number of nights spent:  ");
	scanf("%d", &nights);
	for (int i = 0; i < size; i++)
	{

		if (a[i] < 200)
			bill = bill + (3000 * nights);

		else if (a[i] < 300 && a[i]>200)
			bill = bill + (4500 * nights);

		else if (a[i] < 400 && a[i]>300)
			bill = bill + (8000 * nights);

	}

	//printf("\nBill: %d", bill);
	return bill;
}


void RoomDeallocation()
{
	system("cls");


	struct customer c1;
	char line[1000], find[1000];
	FILE *fptr;
	fptr = fopen("Customer details.csv", "r");

	char *chrptr;
	int numval;
	int Reg_no = 0;
	int found = 0;
	printf("Enter the registration number you want to find.\n");
	scanf("%d", &Reg_no);
	fgets(line, sizeof line, fptr);
	while (fgets(line, sizeof line, fptr) != NULL)
	{
		strcpy(find, line);
		chrptr = strtok(line, ",");
		numval = atoi(chrptr);
		if (Reg_no == numval)
		{

			found = 1;
			c1.Customer_ID = Reg_no;
			strcpy(c1.name, strtok(NULL, ","));
			c1.number_of_rooms = atoi(strtok(NULL, ","));
			c1.cell_number = atoi(strtok(NULL, ","));
			c1.CNIC = atoi(strtok(NULL, ","));
			for (int i = 0; i < c1.number_of_rooms; i++)
			{
				c1.room_numbers[i] = atoi(strtok(NULL, ","));
			}

			break;
		}

	}
	fclose(fptr);

	if (found == 0)
	{
		printf("Registration Number not found!\n");
	}
	else if(found==1)
	{
		int amount=bill(c1.room_numbers, c1.number_of_rooms);
		printf("Bill:\tRs. %d", amount);
		getch();
		resetrooms(c1.room_numbers, c1.number_of_rooms);
		CustomerDetails(Reg_no);
		reset_details(find);
		return 0;
		
	}

	
	getch();
	system("cls");
	mainmenu();
}




void CustomerDetails(int a)
{

	system("cls");
	struct customer c1;
	char line[1000], find[1000];
	FILE *fptr;
	fptr = fopen("Customer details.csv", "r");

	//fprintf(fptr, "Reg.No,Name,No.ofRooms,Cell,CNIC,Rooms,");
	char *chrptr;
	int numval;
	int Reg_no = a;

	//printf("Enter the registration number you want to find.\n");
	//scanf("%d", &Reg_no);
	fgets(line, sizeof line, fptr);
	while (fgets(line, sizeof line, fptr) != NULL)
	{

		chrptr = strtok(line, ",");
		numval = atoi(chrptr);
		if (Reg_no == numval)
		{
			c1.Customer_ID = Reg_no;
			strcpy(c1.name, strtok(NULL, ","));
			c1.number_of_rooms = atoi(strtok(NULL, ","));
			c1.cell_number = atoi(strtok(NULL, ","));
			c1.CNIC = atoi(strtok(NULL, ","));
			for (int i = 0; i < c1.number_of_rooms; i++)
			{
				c1.room_numbers[i] = atoi(strtok(NULL, ","));
			}

			break;
		}
	}
	system("cls");
	printf("Customer Details are:\n");
	printf("Name: %s\nNumber of Rooms: %d\nCNIC: %d\n", c1.name, c1.number_of_rooms, c1.CNIC);
	for (int c = 0; c < c1.number_of_rooms; c++)
		printf("\n%d)Room Number: %d\n", c + 1, c1.room_numbers[c]);

	fclose(fptr);
	getch();
	system("cls");
	mainmenu();
}


void resetrooms(int arr[], int n)
{
	FILE *b;
	b = fopen("bookedrooms.txt", "r");
	char rooms[1000];
	fgets(rooms, sizeof(rooms), b);
	int roomnumber[60];

	int i = 1;
	char *room_str;
	room_str = strtok(rooms, ",");
	roomnumber[0] = atoi(room_str);
	while (room_str != NULL)
	{
		room_str = strtok(NULL, ",");
		if (room_str != NULL)
			roomnumber[i] = atoi(room_str);
		i++;
	}
	int l = 0;
	int newrooms[60];
	for (int j = 0; j < i - 2; j++)
	{
		for (int k = 0; k < n; k++)
		{
			if (roomnumber[j] == arr[k])
				break;
			else if (roomnumber[j] != arr[k] && k == n-1)
			{
				newrooms[l] = roomnumber[j];
				l++;
			}
		}
	}

	fclose(b);
	b = fopen("bookedrooms.txt", "w+");

	for (i = 0; i < l; i++)
	{
		
		fprintf(b, "%d,", newrooms[i]);
	}


}

bool RegistrationNumberValidation(int a)
{
	FILE *fptr;
	fptr = fopen("Customer details.csv", "r");

	char *chrptr; //pointer to store registration number from file in string format
	int numval, found = 0;//numval: numeric form of chrptr,found is variable to check whether the number exists
 	char line[1000];

	fgets(line, sizeof line, fptr);


	while (fgets(line, sizeof line, fptr) != NULL)
	{

		chrptr = strtok(line, ",");
		numval = atoi(chrptr);

		if (a == numval)
		{
			found = 1;
			break;
		}
	}
	if (found == 1)
	{
		return true;
	}
	else
	{
		//printf("Registration Number not found!\n");
		return false;
	}

}


bool roomcheck(int room)
{
	FILE *b;
	b = fopen("bookedrooms.txt", "r");
	char rooms[1000];
	fgets(rooms, sizeof(rooms), b);
	int roomnumber[60];

	int i = 1;
	char *room_str;
	room_str = strtok(rooms, ",");
	roomnumber[0] = atoi(room_str);
	while (room_str != NULL)
	{
		room_str = strtok(NULL, ",");
		if (room_str != NULL)
			roomnumber[i] = atoi(room_str);
		i++;
	}

	for (int j = 0; j < i - 1; j++)
	{
		if (room == roomnumber[j])
		{
			return true;
		}
	}

	return false;
}