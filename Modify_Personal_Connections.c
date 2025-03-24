
/***************************************************************************************

	User_Select() function allows the user to select a user to be added
	to their personal connections

	@param *num - pointer to an integer containing the user's choice of user

	@param Total_Users_Index - integer containing the total amount of 
	registered users

	@param user_index - integer containing the user's personal index

****************************************************************************************/

void User_Select(int *num, int Total_Users_Index, int user_index)
{

    int i, x, flag = 0, found;  

    do //continues to prompt user until they choose to exit or has attempted to add a user to their personal connections
    {
    	found = 0; //1 = user being added is already in the personal connections; 0 = user being added is not yet in the connections
    	
        printf("\nSelect User (Enter 0 to Go Back): ");
        scanf(" %d", num);
    
		printf("=====================================================\n");
        if (*num == 0) //if user selected 0, it will exit this function
        {
            flag = 1; 
        }
        else if (*num < 0 || *num >= Total_Users_Index)  //if invalid input
        {
            printf("\nInvalid input. Please try again.\n");
        }
        else 
        {
        	for(x = 0; x < user[user_index].num_Connections; x++) //loops through the user's personal connections
        	{
        		if(strcmp(user[user_index].Connections[x], user[*num].Username) == 0) //if the user selected already exists in the user's personal connections
        		{
        			found = 1; 
				}
			}
        
        	i = user[user_index].num_Connections; //initializes i to the user's total number of personal connections
            
            if(found == 1) 
            {
            	printf("\n%s is already added to personal connections!\n", user[*num].Username);
			}
            else if (i < 10) //successfully adds the user to personal connections
            {
                strcpy(user[user_index].Connections[i], user[*num].Username); //initializes the added user to personal connections
                user[user_index].num_Connections++; //increments user's total number of connections
                printf("\n%s successfully added to personal connections!\n", user[*num].Username);
            }
            else
            {
                printf("\nMAXIMUM OF 10 PERSONAL CONNECTIONS ONLY!\n"); //if user has exceeded the total number of personal connections
            }
            flag = 1; //exits the function once user has attempted to add a personal connection
            
        }
        printf("=====================================================\n");
    } 
	while (flag == 0); 
    
    Save_User_File(Total_Users_Index); //updates the user text file
}


/***************************************************************************************

	Add_Personal_Connections() function allows the user to choose how they want 
	to add their personal connection, whether through viewing a list of registered
	users or filtering their usernames.

	@param Total_Users_Index - integer containing the total amount of 
	registered users

	@param user_index - integer containing the user's personal index

****************************************************************************************/

void Add_Personal_Connections(int Total_Users_Index, int user_index)
{
    int choice, match = 0, num; 

	//allows user to choose how they want to add a personal connection
    printf("Add a personal connection:\n[1] View list of users\n[2] Filter username\n");
    printf("Input: ");
    scanf(" %d", &choice); 
    
	printf("\n");
    if (choice == 1)
    {
        List_Users(Total_Users_Index);  //if user chooses first choice, it will display the list of registered users (function was called from the Browse_Users file)
        match = 1; 
    }
    else if (choice == 2)
    {
        Filter_Users(Total_Users_Index, &match); //if user chooses second option, it will allow the user to filter out the usernames (function was called from the Browse_Users file)
    }

    if (match > 0)  
    {
    	User_Select(&num, Total_Users_Index, user_index); //calls the function that allows the user to add a personal connection
    }
}


/***************************************************************************************

	View_Personal_Connections() function allows user to view a list of all their 
	personal connections

	@param user_index - integer containing the user's personal index
	
	@param *flag - pointer to an integer containing a value that indicates if a 
	user has any personal connections (0 = no connections; 1 = has connections)

****************************************************************************************/


void View_Personal_Connections(int user_index, int *flag)
{
	int i;
	
	*flag = 0;
	
	if(user[user_index].num_Connections > 0) //if user has personal connections
	{
		for(i = 0; i < user[user_index].num_Connections; i++) //loops through the user's personal connections
		{
			printf("[%d] %s\n", i + 1, user[user_index].Connections[i]); //prints out the usernames of the connections
		}
		*flag = 1; //intializes to 1, indicating that user does have connections
	}
	else
	{
		printf("\nNo personal connections!\n\n");
	}
	
	
}

/***************************************************************************************

	Remove_Personal_Connection() function allows user to remove someone from their
	personal connections

	@param user_index - integer containing the user's personal index
	
	@param Total_Users_Index - integer containing the total amount of 
	registered users

****************************************************************************************/

void Remove_Personal_Connection(int user_index, int Total_Users_Index)
{
	int num, flag = 0, valid = 0, i;
	
	View_Personal_Connections(user_index, &valid); //calls the function that views a list of the user's personal connections
	
	if(valid == 1) //if user has existing personal connections, it will allow the user to remove one 
	{
		do
		{
			printf("\nSelect User (Enter 0 to Go Back): ");
	    	scanf(" %d", &num);
	    	
	    	if (num == 0)  
	        {
	            flag = 1; //exits the function
	        }
	        else if (num < 1 || num > user[user_index].num_Connections)  //if invalid input
	        {
	            printf("\nInvalid input. Please try again.\n"); 
	        }
	        else
	        {
	        	//goes through the user's personal connections, starting from the index of the user to be removed
	        	for(i = num - 1; i < user[user_index].num_Connections - 1; i++) 
	        	{
	        		//shifts the elements of the array to the left, "removing" the intended user
	        		strcpy(user[user_index].Connections[i], user[user_index].Connections[i + 1]); 
				}
	        	
	        	//ensures that the last element after the removal of the connection is empty
	        	strcpy(user[user_index].Connections[user[user_index].num_Connections - 1], "");
                user[user_index].num_Connections--; //decrements the total number of personal connections

                printf("\nUser removed successfully from personal connections!\n");
			}
		}
		while(flag == 0);
	}
	
	Save_User_File(Total_Users_Index); //updates user text file
}


/***************************************************************************************

	View_User_Connections() function allows user to view the list of those who
	has the said user as their personal connection

	@param user_index - integer containing the user's personal index
	
	@param Total_Users_Index - integer containing the total amount of 
	registered users

****************************************************************************************/

void View_User_Connections(int Total_Users_Index, int user_index)
{
	int i, x, found, flag = 0; 
	
	
	for(i = 1; i < Total_Users_Index; i++) //loops through the registered users
	{
		found = 0; //user is not yet found in anyone's personal connections
		for(x = 0; x < user[i].num_Connections; x++)
		{
			if(strcmp(user[user_index].Username, user[i].Connections[x]) == 0)
			{
				found = 1; //user has been found in someone's connections list
			}
		}
		if(found == 1) //if user has been added to someones personal connections
		{
			printf("[%d] %s\n", i, user[i].Username); //then it will print out the username of the one who added the user
			flag = 1; //indicates that the user has been added as someone's personal connection
		}
	}
	
	if(flag == 0)
	{
		printf("No one has added you as their personal connection\n");
	}
	

	
}

/***************************************************************************************

	Modify_Personal_Connections() function calls the functions that allow the user
	to add, view, or remove personal connections. 

	@param user_index - integer containing the user's personal index

****************************************************************************************/

void Modify_Personal_Connections(int user_index)
{
	int choice, Total_Users_Index = 1, flag = 0, valid;
	
	Load_Users(&Total_Users_Index); //accesses the details of all registered users
	
	do
	{
		printf("\n=====================================================\n");
	 	printf("             MODIFY PERSONAL CONNECTIONS             \n");
		printf("=====================================================\n");
		printf("[1] Add personal connections\n[2] View personal connections\n[3] Remove personal connection\n[4] View user connections\n[5] Exit\n");
		printf("=====================================================\n\n");
		printf("Input: ");
		scanf("%d", &choice);
		
		system("cls");
		
		switch(choice)
		{
			case 1: 
					printf("=====================================================\n");
					printf("               ADD PERSONAL CONNECTIONS              \n");
					printf("=====================================================\n");
					Add_Personal_Connections(Total_Users_Index, user_index);
					
					break;
			case 2: 
					printf("=====================================================\n");
					printf("             LIST OF PERSONAL CONNECTIONS            \n");
					printf("=====================================================\n");
					View_Personal_Connections(user_index, &valid);
					printf("=====================================================\n");
					break;
			case 3: 
					printf("=====================================================\n");
					printf("              REMOVE PERSONAL CONNECTIONS            \n");
					printf("=====================================================\n");
					Remove_Personal_Connection(user_index, Total_Users_Index);
					printf("=====================================================\n");
					break;
			case 4: 
					printf("=====================================================\n");
					printf("           LIST OF USERS THAT HAS ADDED YOU          \n");
					printf("=====================================================\n");
					View_User_Connections(Total_Users_Index, user_index);
					printf("=====================================================\n");
					break;
			case 5: 
					flag = 1;
					break;
			default: 
					printf("Invalid input! PLease try again.\n\n");
		}

	}
	while(flag == 0);
	

}