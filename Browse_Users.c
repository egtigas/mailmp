

/*************************************************************************************

	List_Users() function prints the list of existing users in the 
	program.

	@param index - integer containing the total nuber of users

***************************************************************************************/
void List_Users(int index)
{
	int i;
	
	printf("=====================================================\n");
	printf("\033[0;33m"); //yellow
	printf("                   LIST OF USERS:\n");
	printf("\033[0m");
	printf("=====================================================\n");
	
	for(i=1; i < index;i++)
	{
		//prints the username of the user
		printf("[%d] %s\n", i, user[i].Username);
	}
}

/*************************************************************************************

	Filter_Users() function filters or narrows down the users 
	given the inputted string by the user. If user inputted "ba", 
	the function will print the usernames that contain that exact 
	string.
	
	Given the string "ba" the output would be:
	[1] batmann
	[2] baby
	[3] barry

	@param index - integer containing the total nuber of users
	
	@param *match - pointer to an integer that contains the 
	total number of matched users

***************************************************************************************/

void Filter_Users(int index, int *match)
{
	*match = 0; //reset the number of matches to 0
	char filter[100]; //the string contains the filter word to be inputted by the user
	int j;
	
	printf("\033[0;33m"); //yellow
	printf("\nFilter User: "); 
	printf("\033[0m");
	scanf("%s", filter);
	
	for(j = 1; j < index; j++) //loops through the existing usernames of the program
	{
		
		if(strstr(user[j].Username, filter) != 0) //if filter string is found in the existing usernames
		{
			printf("[%d]: %s\n", j, user[j].Username); //then it will print the username
			(*match)++; //increments the count of users that matched with the filter string
		}
	}
	
	if(*match == 0) //if match = 0, then there are no existing users that contain that specific filter word
	{
		printf("\033[0;31m"); //red
		printf("No Match Found.\n");
		printf("\033[0m");
		system("pause");
	}
	
	
}

/**************************************************************************************

	Select_User() function allows the user to select the username
	that they are trying to look for. Once they have selected 
	the username, the function will display their details such
	as their username, full name, and description

	@param *num - pointer to an integer that contains the choice
	indicating which user they picked

	@param index - integer containing the total number of existing
	users
	
	@param user_index - integer containing the user's personal index
	
	@param message_entries[MAX_MSSG_COUNT] - the structure that contains all messages
	
	@param *msgCount - number of total existing messages

****************************************************************************************/

void Select_User(messageTag message_entries[MAX_MSSG_COUNT],int *msgCount,int user_index,int *num, int index)
{
	int reply, i, j, found = 0; //user input (1 = message, 0 = back)
	do //will keep asking for user input until it is valid
    {
		printf("\033[1;33m"); //yellow
        printf("\nSelect User (Enter 0 to Go Back): "); //the user will input the user they are trying to find 
        printf("\033[0m");
		scanf(" %d", num);
		printf("\n=====================================================\n");

        if (*num < 0 || *num >= index)  //if user's input is invalid
        {
            if (*num != 0)
            {
				printf("\033[0;31m"); //red
                printf("Invalid input. Please try again.\n");
				printf("\033[0m");
            }
        }
        else if (*num > 0) //if user's input is valid
        {
        	//then it will print the details of the user they are looking for
            printf("Username: %s\n", user[*num].Username);
            printf("Full Name: %s\n", user[*num].Full_Name);
            printf("Description: %s\n", user[*num].Description);
			
			printf("\n");
			if(strcmp(user[*num].Username, user[user_index].Username)!=0)
			{
				printf("[1] Message\n");
				printf("[2] Add as personal connection\n");
				printf("[0] Back\n");
				
				printf("\033[1;33m"); //yellow
				printf("Input: ");
				printf("\033[0m");
				scanf("%d", &reply); //asks for user input
			}
				
			
			if(reply==1)
			{
				//printf("1 MSSG COUNT %d\n", msgCount);
				//printf("Browse User:msgCount:%d user_index:%d index:%d num:%d\n",*msgCount,user_index,index,*num);
				*msgCount = Reply_Message(message_entries,*msgCount,user_index,*num, 1, -1);
			}
			else if(reply == 2)
			{
				for(j = 0; j < user[user_index].num_Connections; j++) //loops through the user's personal connections
	        	{
	        		if(strcmp(user[user_index].Connections[j], user[*num].Username) == 0) //if the user selected already exists in the user's personal connections
	        		{
	        			found = 1; 
					}
				}
	        
	        	i = user[user_index].num_Connections; //initializes i to the user's total number of personal connections
	            
	            if(found == 1) 
	            {
					printf("\033[0;33m"); //yellow
	            	printf("\n%s is already added to personal connections!\n", user[*num].Username);
					printf("\033[0m");
				}
	            else if (i < 10) //successfully adds the user to personal connections
	            {
	                strcpy(user[user_index].Connections[i], user[*num].Username); //initializes the added user to personal connections
	                user[user_index].num_Connections++; //increments user's total number of connections
	               
					printf("\033[0;33m"); //yellow
					printf("\n%s successfully added to personal connections!\n", user[*num].Username);
	                printf("\033[0m");
					Save_User_File(index);
	            }
	            else
	            {
					printf("\033[0;31m"); //red
	                printf("\nMAXIMUM OF 10 PERSONAL CONNECTIONS ONLY!\n"); //if user has exceeded the total number of personal connections
					printf("\033[0m");
				}
			}
        }
    } while (*num < 0 || *num >= index);  
}

/***************************************************************************************

	Browse_Users() function calls the previous functions, allowing
	the program to view, filter, and select users

	@param user_index - integer containing the user's personal index
	
	@param message_entries[MAX_MSSG_COUNT] - the structure that contains all messages
	
	@param *msgCount - number of total existing messages

****************************************************************************************/

void Browse_Users(messageTag message_entries[MAX_MSSG_COUNT],int *msgCount,int user_index){
	
	int num=1, index = 1, match;
	int select;

	Load_Users(&index); //accesses the user text file which contains all the information about the users
	
	system("cls");
	
	printf("=====================================================\n");
	printf("\033[1;31m"); //red
	printf("                  BROWSE USERS\n");
	printf("\033[0m");
	printf("=====================================================\n");		
	
	printf("[1] List\n[2] Filter\n"); //user chooses their search method
	
	printf("\033[1;33m"); //yellow	
	printf("Search by: ");
	printf("\033[0m");
	scanf("%d", &select);
	printf("\n");
	
	if(select==1) //if user chose to search for the user, given the list of existing users
	{
		List_Users(index);
		match = 1; //assumes that a match was found
	}
	else if(select == 2) //if user chose to search for the user by filtering their usernames
	{
		Filter_Users(index, &match); 
	}
	
	if (match > 0)  //if a match was found 
    {
        do //continues to ask user to select a username, until input is valid
        {
			Select_User(message_entries,msgCount,user_index,&num, index); //user chooses from the list of usernames
        } 
		while (num > 0);
    }
}
