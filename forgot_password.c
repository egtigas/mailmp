void forgot_password()
{
	//open the user.text file
	//ask user to enter their username
	//check if username exists, if not put a warning and make them input again
	//if user exists, ask user to answer the security question
	//if answer is correct, write their username in a seperate file
	//this will be the request file to be sent to admin module
	
	int index = 1;
	char row[1000];
	char Enter_Username[100];
	char Enter_Security_Answer[100];
	char delimiter[] = ";";
	strcpy(row,"");
	
	strcpy(Enter_Username,"");
	strcpy(Enter_Security_Answer, "");
	
	int i, found_username = 0, found_security_answer = 0;
	
	FILE *user_file;
	FILE *request_file;
	
	user_file = fopen("user.txt", "r");
	
	while(fgets(row,sizeof(row),user_file))
	{
		strcpy(user[index].Username,strtok(row, delimiter));
		strcpy(user[index].Full_Name, strtok(NULL, delimiter));
		strcpy(user[index].Password, strtok(NULL, delimiter));
		strcpy(user[index].Security_Question, strtok(NULL, delimiter));
		strcpy(user[index].Security_Answer, strtok(NULL, delimiter));
		index++;
	}
	fclose(user_file);
	
	do
	{
		printf("Enter username: "); //keeps prompting for username if invalid
		scanf("%s", Enter_Username);
		
		for(i = 0; i < index; i++) //goes through the list of users in the text file
		{
			if(strcmp(Enter_Username, user[i].Username) == 0) //confirms if username exists
			{
				found_username = 1; 
				do
				{
					printf("%s\n", user[i].Security_Question); // prints security question
					printf("Enter security answer: "); //keeps prompting for security answer if invalid
					scanf("%s", Enter_Security_Answer);
					
					if(strcmp(Enter_Security_Answer, user[i].Security_Answer) == 0) //confirms if security answer is valid
					{
						found_security_answer = 1;
					}
					else
					{
						printf("INVALID SECURITY ANSWER!\n");
					}
				}	
				while(found_security_answer == 0);
				
				request_file = fopen("request_password.txt", "a"); //opens up a request file to be sent to the admin module
				fprintf(request_file, "%s\n", user[i].Username); //inputs the username that sent the request 
				
				if(request_file) 
				{
					printf("Request succesfully sent!\n");
				}
				else
				{
					printf("Request falied to send!\n");
				}
				
				fclose(request_file);
			}

		}
		
		if(!found_username)
		{
			printf("INVALID USERNAME!\n");
		}
	}
	while(found_username == 0);

}

