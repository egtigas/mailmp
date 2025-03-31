/***************************************************************************************

	forgot_password() function allows users to request for a password reset to the admin
	after getting their account LOCKED when entering their password wrong 3 times.
	
	They are asked to input their Username and are shown their Security Question. User
	must answer the correct Security Answer to send password reset request.
	
****************************************************************************************/

void forgot_password()
{
	int i, user_index, Total_Users, found = 0;
	char Enter_Security_Answer[100];
	
	Load_Users(&Total_Users); //accesses the user.txt that contains all user info.
	Load_Requests(); //accesses request_password.txt that contain all users who sent password reset request
	
	Find_User(&user_index, Total_Users); //checks if Username is in the list of registered users
	
	
	for(i = 0; i < user_requests.num_requests; i++)
	{
		if(strcmp(user[user_index].Username, user_requests.username[i]) == 0) //if user is already in request_password.txt
		{
			printf("\033[0;31m"); //red
			printf("You have already sent a request!\n");
			printf("\033[0m");
			found = 1;
		}
	}
	
	if(found == 0)
	{
		printf("Security Question: %s\n", user[user_index].Security_Question);
		
		printf("\033[0;33m"); //yellow
		printf("Input answer: ");
		printf("\033[0m");
		fgets(Enter_Security_Answer, sizeof(Enter_Security_Answer), stdin);
		Enter_Security_Answer[strcspn(Enter_Security_Answer, "\n")] = '\0'; //replaces newline with NULL
		
		if(strcmp(Enter_Security_Answer, user[user_index].Security_Answer) == 0) //if Security Answer is correct
		{
			//adds Username to list of password request
			strcpy(user_requests.username[user_requests.num_requests], user[user_index].Username);
			user_requests.num_requests++; //increments based number of password requests
			
			printf("\033[1;33m"); //yellow
			printf("Request successfully sent!\n");
			printf("\033[0m");
			Save_Requests(); //saves modification in request_password.txt
		}
		else
		{
			printf("\033[0;31m"); //red
			printf("INVALID ANSWER!\n");
			printf("\033[0m");
		}
	}
	
}