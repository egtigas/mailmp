
/***************************************************************************************

	Enter_Secret_Password() function asks user to input the password to Admin Module

	@param secret_password - string that contains the password to Admin Module
	
	@return 1 if the user sucessfully enters the correct password, granting access
	to the Admin Module
	
	@return 0 if user enters incorrect password, bringing them back to Main Module
	
****************************************************************************************/

int Enter_Secret_Password(char secret_password[])
{
    char enter_password[100];
    int c;
	
	while ((c = getchar()) != '\n' && c != EOF); //alternative to fflush

	printf("=====================================================\n");
    printf("             Enter ");
	printf("\033[0;31m"); // red
	printf("TOP SECRET");
	printf("\033[0m");	
	printf(" password! ");
	printf("\n=====================================================\n");

	printf("Password: ");
    fgets(enter_password, sizeof(enter_password), stdin); //asks for admin password
	enter_password[strcspn(enter_password, "\n")] = '\0'; //replaces newline with NULL
	
	if(strcmp(enter_password, secret_password) == 0) //allows access to admin module if correct
	{
		return 1;
	}
	else //exits if incorrect
	{
		return 0;
	}
    
}

/***************************************************************************************

	Admin_Page() function prints the Admin Page. User must enter the password before entering
	this page. The admin is given an option to open User Module, Messages Module, or Change
	Admin Password, which will call their respective functions

	@param secret_password - string that contains the password to Admin Module
	
	@return 1 if the user sucessfully enters the correct password, granting access
	to the Admin Module
	
	@return 0 if user enters incorrect password, bringing them back to Main Module
	
****************************************************************************************/

void Admin_Page(){
	
	int msgCount=0; //Count of messages and announcements	
	int usrCount=0;
	int choice, flag = 0, valid = 0;
	char secret_password[100];
	
	//allocates memory for the structure 
	struct messageTag *message_entries = (struct messageTag *)malloc(MAX_MSSG_COUNT * sizeof(struct messageTag)); 
	struct User_Details *user_entries = (struct User_Details *)malloc(MAX_USERS * sizeof(struct User_Details));
	Load_Message_File(message_entries,&msgCount);
	Load_User_File(user_entries,&usrCount);
	
	strcpy(secret_password, "");
	
	Load_Secret_Password(secret_password);
	valid = Enter_Secret_Password(secret_password); // determines if the entered password is correct or not
	
	system("cls");
	
	if(valid) // correct admin password
		{
			do
			{
				printf("=====================================================\n");
				printf("\033[1;31m"); //red
				printf("                ADMIN MAIN MENU                      \n");
				printf("\033[0m");
				printf("=====================================================\n");
				printf("[1] User Module\n");
				printf("[2] Messages Module\n");
				printf("[3] Change Admin Password\n");
				printf("[4] Exit\n");
				printf("=====================================================\n\n");
				printf("\033[1;33m"); //yellow
				printf("Input: ");
				printf("\033[0m");
				scanf("%d", &choice);
				system("cls");
				
				switch(choice)
				{
					case 1:
						// Opens User Page that contains complete user information and modification
						Admin_User_Page(user_entries,message_entries,msgCount,&usrCount);
						break;
					case 2:
						// Opens messages module that contains all messages and modification
						Admin_Messages_Page(user_entries,message_entries,&msgCount,&usrCount);
						printf("Returned users %d Messages %d\n",usrCount,msgCount);
						break;
					case 3: 
						// Opens change admin password that resets password
						Change_Admin_Password(secret_password);
						break;
					case 4: 
						flag = 1; //exit
						
						//Save to Message File upon exit of Admin Module
						Save_Message_File(message_entries,msgCount);
						break;	
					default: 
						printf("\033[0;31m"); //red
						printf("Invalid input. Please try again.\n\n");
						printf("\033[0m");
				}
				
			}
			while(flag == 0); 
		}
		else // incorrect admin password
		{
			printf("=====================================================\n");
			printf("\033[0;31m"); //red
			printf("INCORRECT PASSWORD!\n");
			printf("\033[0m"); 
			printf("=====================================================\n");
		}
		
		  
	}
