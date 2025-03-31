/***************************************************************************************

	View_Info() function prints the selected user's complete information

	@param user_index - integer containing the user's personal index

****************************************************************************************/

void View_Info(int user_index)
{
	int flag;
	printf("\n=====================================================\n");
	printf("Account Status: %s\n", user[user_index].Account_Status);
    printf("Username: %s\n", user[user_index].Username);
    printf("Full Name: %s\n", user[user_index].Full_Name);
    printf("Password: %s\n", user[user_index].Password);
    printf("Description: %s\n", user[user_index].Description);
    printf("Personal connections: \n");
	View_Personal_Connections(user_index, &flag); //prints all of the user's personal connections
}

/***************************************************************************************

	Admin_View_Users() function asks the admin to select a user to view their information

	@param Total_Users - integer containing the total amount of registered users
	
	@param *choice - pointer to an integer containing the admin's choice of user

****************************************************************************************/

void Admin_View_Users(int Total_Users, int *choice)
{
	printf("\033[1;33m"); //yellow
    printf("\nSelect User ");
	printf("\033[0m");
	printf("(Enter 0 to Go Back): "); //the admin will input the user they are trying to find 
    scanf(" %d", choice);

    if (*choice < 0 || *choice >= Total_Users)  //if admin's input is invalid
    {
		printf("\033[0;31m"); //red
        printf("Invalid input. Please try again");
		printf("\033[0m");
        
    }
    else if (*choice > 0) //if admin's input is valid
    {
    	//then it will print the details of the user they are looking for
    	View_Info(*choice);
        
    }
}

/***************************************************************************************

	Modify_Username() function allows admin to change the selected user's Username

	@param user_index - integer containing the user's personal index

****************************************************************************************/

void Modify_Username(int user_index)
{
	char Enter_Modified_Username[100];
	
	printf("Enter new username: ");
	fgets(Enter_Modified_Username, sizeof(Enter_Modified_Username), stdin);
	Enter_Modified_Username[strcspn(Enter_Modified_Username, "\n")] = '\0'; //replace newline with NULL
	
	strcpy(user[user_index].Username, Enter_Modified_Username); //copies the new Username into the user structure
	
}

/***************************************************************************************

	Modify_Connections() function asks admin to pick between adding or removing selected
	user's personal connections, and calls Add_Personal_Connections() or Remove_Personal_Connection()

	@param Total_Users - integer containing the total amount of registered users
	
	@param user_index - integer containing the user's personal index

****************************************************************************************/

void Modify_Connections(int Total_Users, int user_index)
{
	int choice; 
	
	printf("[1] Add personal connection\n[2] Remove personal connection\n");
	printf("\033[1;33m"); //yellow
	printf("Input: ");
	printf("\033[0m");
	scanf(" %d", &choice);
	
	if(choice == 1) //if admin chooses to add personal connected to user
	{
		Add_Personal_Connections(Total_Users, user_index);
	}
	else if(choice == 2) //if admin chooses to remove personal connected to user
	{
		Remove_Personal_Connection(user_index, Total_Users);
	}
}

/***************************************************************************************

	Admin_Modify_Users() function asks admin to pick between modifying selected
	user's Username, Fullname, Description, or Personal Connections, and calls their
	respective functions.

	@param Total_Users - integer containing the total amount of registered users
	
****************************************************************************************/

void Admin_Modify_Users(int Total_Users)
{
	int view_choice; //admin's selected user
	int modify_choice;
	char c;
	
	Admin_View_Users(Total_Users, &view_choice); //calls function that asks admin to pick a User to modify

	if(view_choice != 0)
	{
		printf("\033[0;33m"); //yellow
		printf("\nModify:");
		printf("\033[0m");
		printf("\n[1] Username\n[2] Full name\n[3] Description\n[4] Personal connection\n[5] Exit\n");
		printf("\033[1;33m"); //yellow
		printf("Input: ");
		printf("\033[0m");
		scanf(" %d", &modify_choice);
	
		while ((c = getchar()) != '\n' && c != EOF); //alternative to fflush
		system("cls");
		
		
		switch(modify_choice)
		{
			case 1:
				// Change user's Username
				Modify_Username(view_choice);
				printf("\033[0;33m"); //yellow
				printf("Successfully updated username!\n");
				printf("\033[0m");
				system("pause");
				break;
			case 2: 
				// Change user's Fullname
				Modify_Full_Name(view_choice);
				printf("\033[0;33m"); //yellow
				printf("Successfully updated full name!\n");
				printf("\033[0m");
				system("pause");
				break;
			case 3: 
				// Change user's Description
				Modify_Description(view_choice);
				printf("\033[0;33m"); //yellow
				printf("Successfully updated description!\n");
				printf("\033[0m");
				system("pause");
				break;
			case 4: 
				// Change user's Personal Connections
				printf("\033[0;33m"); //yellow
				Modify_Connections(Total_Users, view_choice);
				printf("\033[0m");
				break;
			case 5:
				//Exit
				break;
			default: 
				printf("\033[0;31m"); //red
				printf("Invalid input. Please try again.\n\n");
				printf("\033[0m");
				system("pause");
		}
		
		
		Save_User_File(Total_Users); //saves the modified information into user.txt file
	}
	
	
}

/***************************************************************************************

	Delete_User() function asks admin to choose a user to delete and deletes them from
	the user.txt file

	@param Total_Users - integer containing the total amount of registered users
	
****************************************************************************************/

void Delete_User(int *Total_Users,messageTag message_entries[MAX_MSSG_COUNT],int msgCount)
{
	//shift the elements of array to the left?
	
	int i, j, x, user_index;
	String100 deleted_user;
	
	printf("Choose which user to ");
	printf("\033[0;31m"); //red
	printf("DELETE");
	printf("\033[0m");
	printf(": ");
	scanf(" %d", &user_index);

	strcpy(deleted_user,user[user_index].Username);
	
	if(user_index > 0 && user_index < *Total_Users) //if valid user index
	{
		for(i = user_index; i < *Total_Users - 1; i++)
		{
			//shifts the elements to the left starting from the user to be deleted
			//this overwrites the user and "deletes" them
			user[i] = user[i + 1]; 
		}
		
		(*Total_Users)--; //decrements the total number of users
		printf("User %s successfully deleted!\n",deleted_user);
		Save_User_File(*Total_Users); //saves the modified information into user.txt file
		//Replaces the deleted user with "DELETED USER"
		for(i=0;i<msgCount;i++)
		{
			if((strcmp(message_entries[i].Sender,deleted_user)==0))
			{
				//printf("%s is sender on %s\n",message_entries[i].Sender,message_entries[i].Subject);
				strcpy(message_entries[i].Sender,"DELETED USER");
			}
		}
		
		for(i=0;i<msgCount;i++)
		{
			for(j=0;j<message_entries[i].numOfRecipients;j++)
			{
				if((strcmp(message_entries[i].Recipients[j],deleted_user)==0))
				{
					strcpy(message_entries[i].Recipients[j],"DELETED USER");
				}
			}
		}
		
		for(i = 1; i < *Total_Users; i++)
		{
			for(j = 0; j < user[i].num_Connections; j++)
			{
				if(strcmp(deleted_user, user[i].Connections[j]) == 0)
				{
					for(x = j; x < user[i].num_Connections -1; x++)
					{
						strcpy(user[i].Connections[x], user[i].Connections[x+1]);
					}
					user[i].num_Connections--;
					j--;
				}
				
			}
		}
		Save_User_File(*Total_Users); //saves the modified information into user.txt file
		system("pause");
		
	
	}
	else
	{
		printf("\033[0;31m"); //red
		printf("Invalid input!\n"); //error if user index is not valid
		printf("\033[0m");
	}
	
	
	
	
}

/***************************************************************************************

	Refresh_Password() function prints list of users who requested a password reset. Admin
	can accept requests and the user is sent a temporary password so they may login and
	change their password.

	@param Total_Users - integer containing the total amount of registered users
	
****************************************************************************************/

void Refresh_Password(int Total_Users)
{
    int select, i, j;
    char temp_password[50];
    strcpy(temp_password, "DEFAULT1PASS"); //temporary password given to the user to unlock their account/change their password
    
    Load_Requests(); //calls function that reads request_password.txt containing users with password reset request
    
	printf("\033[1;33m"); //yellow
    printf("List of requests:\n");
	printf("\033[0m");
	

    
    if(user_requests.num_requests > 0)
    {
    	for(i = 0; i < user_requests.num_requests; i++)// prints all users with password rest request
	    {
	        printf("[%d] %s\n", i+1, user_requests.username[i]);
	    }
	    do
	    {
	        printf("Choose account to refresh: ");
	        scanf(" %d", &select);
	        
	        select = select - 1;
	        
	        if(select < 0 || select >= user_requests.num_requests) //if admin input is invalid
	        {
				printf("\033[0;31m"); //red
	            printf("Invalid input\n");
				printf("\033[0m");
	        }
	    }
	    while(select < 0 || select >= user_requests.num_requests); //loops while input in valid
	
	    for(i = 1; i < Total_Users; i++) //goes through all the program's users
	    {
	        if(strcmp(user[i].Username, user_requests.username[select]) == 0) //finds the user who sent the request in the main user text file
	        {
	            
	            for(j = 0; j < strlen(temp_password); j++)
	            {
	                temp_password[j] = temp_password[j] + 1; //ciphers the temporary password
	            }
	
	            strcpy(user[i].Password, temp_password); //sets the user's password into the temporary password
				printf("\033[0;33m"); //yellow
				printf("Successfully refreshed account!\n");
				printf("\033[0m");
	            
	            for(j = select; j < user_requests.num_requests - 1; j++)
	            {
	                strcpy(user_requests.username[j], user_requests.username[j + 1]); //removes the user from list of password reset request
	            }
	            user_requests.num_requests--; //decrements the number of requests
	            select--;
	        }
	    }
	    Save_Requests(); //saves the modified information into request_password.txt file
	    Save_User_File(Total_Users); //saves the modified information into user.txt file
	}
	else
	{
		printf("No requests!\n");
	}
	
	system("pause");
    
    
}

/***************************************************************************************

	Admin_User_Page() function prints Admin User Page that allows admin to pick options
	like view and modify user's contents, refresh user password, and delete user

	@param user_entries[MAX_USERS] - structure containing User information
	
	@param message_entries[MAX_MSSG_COUNT] - structure containing all messages and announcments,
	and it's sender and recipient
	
	@param *usrCount- pointer to an integer containing the total amount of registered users
	
****************************************************************************************/
						
void Admin_User_Page(User_Details user_entries[MAX_USERS],messageTag message_entries[MAX_MSSG_COUNT],int msgCount, int *usrCount)
{
	int choice, Total_Users,flag = 0;
	int num; // admin's selected user
	
	Load_Users(&Total_Users); //opens and reads the user.txt
	
	do
	{
		system("cls");
		printf("\n=====================================================\n");
		printf("\033[1;31m"); //red
	 	printf("                     ADMIN USER PAGE                   \n");
		printf("\033[0m");
		printf("======================================================\n");
		printf("[1] View Users\n[2] Modify Users\n");
		printf("[3] Refresh User Account Password\n[4] Delete Users\n[5] Exit\n");
		printf("=====================================================\n\n");
		printf("\033[1;33m"); //yellow
		printf("Input: ");
		printf("\033[0m");
		scanf("%d", &choice);
		system("cls");
		
		
		switch(choice)
		{
			case 1:
				//Prints list of all registered users
				List_Users(Total_Users);
				do
				{
					Admin_View_Users(Total_Users, &num);
				}
				while(num != 0);
				
				break;
			case 2:
				//Modifies user's personal contents
				List_Users(Total_Users);
				Admin_Modify_Users(Total_Users);
				break;
			case 3: 
				//Refresh user's account password
				Refresh_Password(Total_Users);
				break;
			
			case 4: 
				//Delete users
				List_Users(Total_Users);
				Delete_User(&Total_Users,message_entries,msgCount);
				break;
			case 5: 
				//Exit
				flag = 1;
				break;
			default: 
				printf("\033[0;31m"); //red
				printf("Invalid input. Please try again.\n\n");
				printf("\033[0m");
		}
		
	}
	while(flag == 0); //loops unless admin selects '5' (Exit)  
}  
