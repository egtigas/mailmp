void Admin_View_Filter(User_Details user_entries[MAX_USERS],messageTag message_entries[MAX_MSSG_COUNT],int msgCount,int usrCount)
{
	int filter, i, j, k;
	char search[100]; //the string contains the filter word to be inputted by the user
	int match = 0; //reset the number of matches to 0
	
	printf("=====================================================\n");
	printf("                FILTER USER MESSAGES                     \n");
	printf("=====================================================\n");
	
	printf("[1] Filter by Sender\n");
	printf("[2] Filter by Recipient\n");
	printf("\nInput: ");
	scanf("%d", &filter);
	
	if(filter == 1)
	{
		printf("=====================================================\n");
		printf("> Filter by Sender\n");
		/*printf("> Search By:\n");
		printf("[1] Username\n");
		printf("[2] Fullname\n");*/

		printf("\nFilter User: "); 
		scanf("%s", search);
		
		system("cls");
		printf("=====================================================\n");
		printf("               	    USER MESSAGES                     \n");
		printf("=====================================================\n");
	
		for(i = 1; i < usrCount; i++) //loops through the existing usernames of the program
		{
			
			if((strstr(message_entries[i].Sender, search) != 0)&& message_entries[i].ancFlag == 0) //if filter string is found in the existing sender
			{
				printf("> Sender: %s\n",message_entries[i].Sender);
				printf("> To:\n");
				for(j=0;j<message_entries[i].numOfRecipients;j++)
				{
					printf("%s\t\t",message_entries[i].Recipients[j]); //prints the recipient username
					
					for(k=0;k<usrCount;k++)
					{
						if(strcmp(message_entries[i].Recipients[j], user_entries[k].Username)==0)
						{
							printf("%s\n", user_entries[k].Full_Name); //prints the recipient full name
						}
					}
				}
				printf("\n> Subject: %s\n",message_entries[i].Subject);
				printf("> Message:\n");
				for(j=0;j<message_entries[i].numOfMsgLines;j++)
				{
					printf("%s\n", message_entries[i].strMsgEntries[j]);
				}
				
				printf("=====================================================\n");
				match++; //increments the count of users that matched with the filter string
			}
		}
		
		if(match == 0) //if match = 0, then there are no existing users that contain that specific filter word
		{
			printf("No Match Found.\n");
			system("pause");
		}
	}
	
	if(filter == 2)
	{
		printf("=====================================================\n");
		printf("> Filter by Recipient\n");
		printf("\nFilter User: "); 
		scanf("%s", search);
		
		system("cls");
		printf("=====================================================\n");
		printf("               	    USER MESSAGES                     \n");
		printf("=====================================================\n");
	
		for(i = 1; i < usrCount; i++) //loops through the existing usernames of the program
		{
			for(j = 0; j < usrCount; j++)
			{
				if((strstr(message_entries[i].Recipients[j], search) != 0)&& message_entries[i].ancFlag == 0) //if filter string is found in the existing recipients 
				{
					printf("> Sender: %s\n",message_entries[i].Sender);
					printf("> To:\n");
					for(j=0;j<message_entries[i].numOfRecipients;j++)
					{
						printf("%s\t\t",message_entries[i].Recipients[j]); //prints the recipient username
						
						for(k=0;k<usrCount;k++)
						{
							if(strcmp(message_entries[i].Recipients[j], user_entries[k].Username)==0)
							{
								printf("%s\n", user_entries[k].Full_Name); //prints the recipient full name
							}
						}
					}
					printf("\n> Subject: %s\n",message_entries[i].Subject);
					printf("> Message:\n");
					for(j=0;j<message_entries[i].numOfMsgLines;j++)
					{
						printf("%s\n", message_entries[i].strMsgEntries[j]);
					}
					
					printf("=====================================================\n");
					match++; //increments the count of users that matched with the filter string
				}
			}
		}
		
		if(match == 0) //if match = 0, then there are no existing users that contain that specific filter word
		{
			printf("No Match Found.\n");
			system("pause");
		}
	}
	
	printf("\n");
	system("pause");
}