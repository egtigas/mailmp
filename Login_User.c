/*************************************************************************************

	List_Users() function checks if Username is in the list of registered users.

	@param *user_index - pointer to an integer containing the user's personal index
	
	@param Total_Users_Index - integer containing the total amount of registered users

***************************************************************************************/

void Find_User(int *user_index, int Total_Users)
{
	int i, match = 0;
	char c, Enter_Username[100];
	
	
	while ((c = getchar()) != '\n' && c != EOF); //alternative to fflush
	
	do // it loops and checks if username is INVALID. if it is, it asks user to input again
	{
		printf("Username: ");
		fgets(Enter_Username, sizeof(Enter_Username), stdin);
		Enter_Username[strcspn(Enter_Username, "\n")] = '\0'; //replaces newline with NULL
		
		match = 0;
		for(i = 1; i < Total_Users; i++) //loops through the users and their details in user.txt file
		{
			if(strcmp(user[i].Username, Enter_Username) == 0) // it checks if username is VALID.
			{
				match = 1; //indicates that a match has been found in the file
				*user_index = i; //stores the index of the user, for later use
			}
			
		}
		
		if(match == 0) // prints if the input username doesnt exist.
		{
			printf("\033[0;31m");
			printf("INVALID USERNAME!\n");
			printf("\033[0m");
		}
	}
	while(match == 0);
}
/*********************************************************************************************

	Login_User() function allows the user to login using the details they inputted 
	when they first created an account. Only when their username and password match 
	with the one they inputted, can they be able to access the next page. Otherwise,
	they will be sent back to the main page. 

	If the user has inputted the wrong password 3 times, their account will be 
	locked. They will be unable to log in to their account. They can only unlock
	their account by sending a request to the admin and using the temporary 
	password given to them. 

**********************************************************************************************/

void Login_User()
{

	
	int i,k;
	int index, invalid = 0, valid = 0, locked = 0, user_index;
	char temp_password[50];
	char Enter_Password[PASSWORD_LENGTH];
	
	
	strcpy(temp_password, "DEFAULT1PASS"); //temporary password
	
	printf("=====================================================\n");
	printf("\033[1;31m"); // red
	printf("                      LOGIN PAGE                     \n");
	printf("\033[0m");
	printf("=====================================================\n");
	
	Load_Users(&index); //accesses the user.txt that contains all user info.
	
	Find_User(&user_index, index);
	
	// if user's password request is accepted, they are given a temporary password
	if(strcmp(user[user_index].Password, "EFGBVMU2QBTT") == 0)
	{
		printf("\033[0;33m"); //yellow
	    printf("Your temporary password is ");
		printf("\033[0m");
		printf("DEFAULT1PASS");
		printf("\033[0;33m"); //yellow
		printf(". Please change this password.\n");
		printf("\033[0m");
		
	    for(i = 0; i < strlen(temp_password); i++)
	    {
	        temp_password[i] = temp_password[i] + 1; //encrypts the temporary password
	    }
	
	    
	    if(strcmp(user[user_index].Password, temp_password) == 0)
	    {
	        Modify_Password(index, user_index); //calls function that changes password
	        strcpy(user[user_index].Account_Status, "UNLOCKED"); // unlocks the account after creating new password
	        Save_User_File(index); // saves modified password
	    }
	}
	
	if(strcmp(user[user_index].Account_Status, "LOCKED") == 0) // if user's account if locked
	{
		printf("\033[0;33m"); // yellow
		printf("\nYour account is ");
		printf("\033[0m");
		printf("LOCKED");
		printf("\033[0;33m"); // yellow
		printf("! Please send a request to admin to change your password. \n");
		printf("\033[0m");
		locked = 1;
	}

	// it loops and checks if password is INVALID. if it is, it asks user to input again
	 //the user only gets 3 tries of inputting their password
	if(locked == 0)
	{
		while(valid == 0 && invalid < 3)  
		{
			printf("Password: ");
			scanf("%s", Enter_Password);
			
			for(k=0; k<strlen(Enter_Password); k++)
			{ 
				Enter_Password[k] = Enter_Password[k]+1; // cyphers password by +1 to the character in ASCII
			}
			
			if(strcmp(user[user_index].Password, Enter_Password) == 0)
			{
				valid = 1; //indicates that the inputted password is valid
			}
			else
			{
				printf("\033[0;31m"); //red
				printf("\nINVALID PASSWORD\n"); // prints if the input password doesnt exist.
				printf("\033[0m");

				invalid++; //counts the number of times the user inputted the wrong password
			}
		}
		
		//if user has reached the maximum attempts in entering password or if their account is LOCKED
		if(invalid > 2) //if they reached more than 3 tries of entering password
		{
			strcpy(user[user_index].Account_Status, "LOCKED"); //it will change their account status to "LOCK"
			printf("You have reached the maximum attempts to enter password. Your account is now ");
			printf("\033[0;31m"); //red
			printf("LOCKED.\n");
			printf("\033[0m");
			
			Save_User_File(index); //updates the user text file
		} 
		else
		{
			User_Page(user_index, index); // if username and password are VALID, it brings user into the User Page.
		}
	}
	
	printf("=====================================================\n");

}