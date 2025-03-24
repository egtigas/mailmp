
/*************************************************************************************

	List_Users() function prints the list of existing users in the 
	program.

	@param index - integer containing the total nuber of users

***************************************************************************************/
void List_Users(int index)
{
	int i;
	
	printf("List of Users:\n");
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
	
	printf("\nFilter User: "); 
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
		printf("No Match Found.\n");
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

****************************************************************************************/

void Select_User(int *num, int index)
{
	do //will keep asking for user input until it is valid
    {
        printf("\nSelect User (Enter 0 to Go Back): "); //the user will input the user they are trying to find 
        scanf(" %d", num);

        if (*num < 0 || *num >= index)  //if user's input is invalid
        {
            if (*num != 0)
            {
                printf("Invalid input. Please try again.\n");
            }
        }
        else if (*num > 0) //if user's input is valid
        {
        	//then it will print the details of the user they are looking for
            printf("Username: %s\n", user[*num].Username);
            printf("Full Name: %s\n", user[*num].Full_Name);
            printf("Description: %s\n", user[*num].Description);
        }
    } while (*num < 0 || *num >= index);  
}

/***************************************************************************************

	Browse_Users() function calls the previous functions, allowing
	the program to view, filter, and select users

	@param user_index - integer containing the user's personal index

****************************************************************************************/

void Browse_Users(int user_index){
	
	int num=1, index = 1, match;
	int select;

	Load_Users(&index); //accesses the user text file which contains all the information about the users
	
	system("cls");
	
	printf("[1] List\n[2] Filter\n"); //user chooses their search method 
	printf("Search by: ");
	scanf("%d", &select);
	
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
            Select_User(&num, index); //user chooses from the list of usernames
        } 
		while (num > 0);
    }


}
