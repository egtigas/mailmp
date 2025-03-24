
/*************************************************************************************

	Create_Account() function allows the user to create an account which will
	require them to input their username, full name, password, security question 
	and answer, and description.

***************************************************************************************/

void Create_Account()
{
	
	int i;
	int index, notFound;
	char Security_Question[100];
	
	Load_Users(&index); //accesses the details in user.txt file
	
	/***********************
	Information will be sent to user.txt file
	************************/
	
	fflush(stdin);
	
	printf("=====================================================\n");
	printf("                   CREATE ACCOUNT                    \n");
	printf("=====================================================\n");
	
	if(index <= 30) // This makes sure that the registered users dont exceed 30.
	{
		notFound = 0; //determines if username already exists among the registered users
	
		do
		{
			printf("Input username: ");
			fgets(user[index].Username, sizeof(user[index].Username), stdin);
			user[index].Username[strcspn(user[index].Username, "\n")] = '\0';
			
			for(i = 0; i < index; i++)
			{
				if(strcmp(user[index].Username, user[i].Username) == 0)
				{
					//if the username inputted by the user is already taken by another user
					printf("USERNAME HAS BEEN TAKEN\n"); 
				}
				else
				{
					//if username is unique
					notFound = 1;
				}

			}
		}
		while(notFound == 0); //will keep prompting the user for their username until they input a unique username
		
		
	/***** FULL NAME *****/	
	
		printf("Input full name: ");
		fgets(user[index].Full_Name, sizeof(user[index].Full_Name), stdin);
		user[index].Full_Name[strcspn(user[index].Full_Name, "\n")] = '\0';
		
		
	/**** PASSWORD ****/	
	
		printf("Input password: ");
		fgets(user[index].Password, sizeof(user[index].Password), stdin);
		user[index].Password[strcspn(user[index].Password, "\n")] = '\0';
		
		// cyphers password by +1 to the character in ASCII
		for(i=0; i<strlen(user[index].Password); i++){
			user[index].Password[i] = user[index].Password[i]+1;
		}
		
	/**** SECURITY QUESTION ****/
	
		printf("Input any security question (ex. What is your favorite color?): ");
		fgets(Security_Question, sizeof(Security_Question), stdin);
		Security_Question[strcspn(Security_Question, "\n")] = '\0';
	
	/**** SECURITY ANSWER ****/
	
		printf("Input security answer: ");
		fgets(user[index].Security_Answer, sizeof(user[index].Security_Answer), stdin);
		user[index].Security_Answer[strcspn(user[index].Security_Answer, "\n")] = '\0';
		
	/**** DESCRIPTION ****/
	
		strcpy(user[index].Description, "DEFAULT USER"); //initializes it to a default description
		
	/**** ACCOUNT STATUS ****/
		strcpy(user[index].Account_Status, "UNLOCKED"); //initialies the user's account as unlocked
		
		index++; //increments the index of the total number of users
		
		Save_User_File(index); //adds the new user and their details to the user text file 
		
	}
	else 
	{
		printf("SORRY\n WE HAVE EXCEEDED MAX USERS\n"); //if the total number of users has exceeded 30
	}
		
	printf("=====================================================\n");

}
