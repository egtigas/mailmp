/********************************************************************************************************************************
	Admin_Delete_Message() function allows the admin to delete any message from a user of their choosing.
	It returns an integer containing the updated total number of messages. 

	@param user_entries - array of structures containing user details (username, full name, password, etc)

	@param message_entries - array of structures containing user's message details (sender, recipient, message, etc)

	@param msgCount - pointer to an integer containing the total number of messages of all users

	@param usrCount - pointer to an integer containing the total number of users

********************************************************************************************************************************/
int Admin_Delete_Message(User_Details user_entries[MAX_USERS],messageTag message_entries[MAX_MSSG_COUNT],int msgCount,int usrCount) 
{
	
	int i;
	
	int j=0, l;
    int select=1;
    
	while(select>-1)
	{
		printf("=====================================================\n");
		printf("\033[1;31m"); //red
		printf("                ADMIN DELETE MESSAGE                      \n");
		printf("\033[0m");
		printf("=====================================================\n");
		printf("No. \tSender\t\t\tSubject\n");
		/* displays sender and subject of all messages*/
		for(i=0;i<msgCount;i++) 
		{
			printf("[%d]\t%-20s\t%s\n", i+1, message_entries[i].Sender,message_entries[i].Subject);
			j++; 

		}
		printf("\033[0;31m"); //red
		printf("\nDELETE ");
		printf("\033[0m");
		printf("which message number?\n");
		
		printf("\033[1;33m"); //yellow
		printf("Are you sure? (Enter 0 to Go Back): \n");
		printf("\033[0m");
		scanf("%d", &select);
		select = select-1;
	
		
		if(select>=0 && select < msgCount) //if valid selection
		{
			printf("=====================================================\n");
			/* prints the message details (sender, recepient/s, subject, contents of message)*/
			printf("\033[0;33m"); //yellow
			printf("From: ");
			printf("\033[0m");
			printf("%s\n", message_entries[select].Sender);
			printf("\033[0;33m"); //yellow
			printf("To:\n");
			printf("\033[0m");
			for(l=0;l<message_entries[select].numOfRecipients;l++) 
			{
				printf("%s\t\t", message_entries[select].Recipients[l]);
			}
			printf("\033[0;33m"); //yellow
			printf("\nSubject: ");
			printf("\033[0m");
			printf("%s\n", message_entries[select].Subject);
			
			for(i=0;i<message_entries[select].numOfMsgLines;i++)
			{
				printf("%s\n", message_entries[select].strMsgEntries[i]);
			}
			system("pause");
			system("cls");
		
			/* shifts the elements of message_entries, deleting the selected message*/
			for(i=select;i<msgCount - 1;i++) 
			{
				message_entries[i] = message_entries[i+1];

			}
			msgCount--; //decrements the total number of messages
		}
		else if(select != -1)
		{
			printf("\033[0;31m"); //red
			printf("\nInvalid input!\n");
			printf("\033[0m");
			
			printf("\n");
            system("pause");
            system("cls");
		}

	}
	return msgCount; //returns modidied message count
}



/************************************************************************************************************
	Admin_View_Filter() function allows the admin to filter out all the messages either by
	recipient or by sender. If a match is found, the admin is able to view the details of the 
	message such as its sender, recipients, subejct, and contents.
	
	@param user_entries - array of structures containing user details (username, full name, password, etc)

	@param message_entries - array of structures containing user's message details (sender, recipient, message, etc)

	@param msgCount - pointer to an integer containing the total number of messages of all users

	@param usrCount - pointer to an integer containing the total number of users

*************************************************************************************************************/

void Admin_View_Filter(User_Details user_entries[MAX_USERS],messageTag message_entries[MAX_MSSG_COUNT],int msgCount,int usrCount)
{
	int filter, i, j, k;
	char search[100]; //the string contains the filter word to be inputted by the user
	int match = 0; //reset the number of matches to 0
	
	printf("=====================================================\n");
	printf("\033[1;31m"); //red
	printf("                FILTER USER MESSAGES                     \n");
	printf("\033[0m");
	printf("=====================================================\n");
	
	printf("[1] Filter by Sender\n");
	printf("[2] Filter by Recipient\n");
	
	printf("\033[1;33m"); //yellow
	printf("\nInput: ");
	printf("\033[0m");
	scanf("%d", &filter);
	
	if(filter == 1) //if admin wants to filter by sender
	{
		printf("=====================================================\n");
		printf("Filter by Sender\n");

		printf("\033[1;33m"); //yellow
		printf("\nFilter User: "); 
		printf("\033[0m");
		scanf("%s", search);
		
		system("cls");
		printf("=====================================================\n");
		printf("\033[1;31m"); //red
		printf("               	    USER MESSAGES                     \n");
		printf("\033[0m");
		printf("=====================================================\n");
	
		for(i = 1; i < msgCount; i++) //loops through the existing usernames of the program
		{
			
			if((strstr(message_entries[i].Sender, search) != 0)&& message_entries[i].ancFlag == 0) //if filter string is found in the existing sender
			{
				printf("\033[0;33m"); //yellow
				printf("Sender: ");
				printf("\033[0m");
				printf("%s\n",message_entries[i].Sender);
				printf("\033[0;33m"); //yellow
				printf("To:\n");
				printf("\033[0m");
				for(j=0;j<message_entries[i].numOfRecipients;j++) //loops through through the recipients of message
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
				/* display contents of message*/
				printf("\033[0;33m"); //yellow
				printf("\nSubject: ");
				printf("\033[0m");
				printf("%s\n",message_entries[i].Subject);
				
				printf("\033[0;33m"); //yellow
				printf("Message:\n");
				printf("\033[0m");
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
			printf("\033[0;31m"); //red
			printf("No Match Found.\n");
			printf("\033[0m");
		}
	}
	
	if(filter == 2) //if admin wants to filter by recipient
	{
		printf("=====================================================\n");
		printf("Filter by Recipient\n");
		
		printf("\033[1;33m"); //yellow
		printf("\nFilter User: "); 
		printf("\033[0m");
		scanf("%s", search);
		
		system("cls");
		printf("=====================================================\n");
		printf("\033[1;31m"); //red
		printf("               	    USER MESSAGES                     \n");
		printf("\033[0m");
		printf("=====================================================\n");
	
		for(i = 1; i < msgCount; i++) //loops through the existing usernames of the program
		{
			for(j = 0; j < message_entries[i].numOfRecipients; j++)
			{
				if((strstr(message_entries[i].Recipients[j], search) != 0)&& message_entries[i].ancFlag == 0) //if filter string is found in the existing recipients 
				{
					printf("\033[0;33m"); //yellow
					printf("Sender: ");
					printf("\033[0m");
					printf("%s\n",message_entries[i].Sender);
					
					printf("\033[0;33m"); //yellow
					printf("To:\n");
					printf("\033[0m");

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
					/* displays message contents*/
					
					printf("\033[0;33m"); //yellow
					printf("\nSubject: ");
					printf("\033[0m");
					printf("%s\n",message_entries[i].Subject);
					
					printf("\033[0;33m"); //yellow
					printf("Message:\n");
					printf("\033[0m");
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
			printf("\033[0;31m"); //red
			printf("No Match Found.\n");
			printf("\033[0m");
		}
	}
	
	printf("\n");
	system("pause");
}


/************************************************************************************************************************** 
	Admin_View_Message() function allows admin to view all the messages in the system.

	@param user_entries - array of structures containing user details (username, full name, password, etc)

	@param message_entries - array of structures containing user's message details (sender, recipient, message, etc)

	@param msgCount - pointer to an integer containing the total number of messages of all users

	@param usrCount - pointer to an integer containing the total number of users
	
****************************************************************************************************************************/


void Admin_View_Message(User_Details user_entries[MAX_USERS],messageTag message_entries[MAX_MSSG_COUNT],int msgCount,int usrCount) 
{
	int i;
	
	int j=0, k=0, l, m;
    int select=1, count;
    int num[30];
	
    printf("=====================================================\n");
	printf("\033[1;31m"); //red
    printf("                ADMIN VIEW MESSAGES                      \n");
	printf("\033[0m");
    printf("=====================================================\n");

	while(select>-1) //while input is valid
	{
		printf("\033[0;33m"); //yellow
		printf("No. \tSender\t\t\tSubject\n");
		printf("\033[0m");
		
		for(i=0;i<msgCount;i++) //loops through exisiting messages
		{
			//displays subject and sender of message (where admin will choose)
			printf("[%d]\t%-20s\t%s\n", i+1, message_entries[i].Sender,message_entries[i].Subject); 
			num[j] = i;
			j++;
			k++;
		
		}
		printf("\033[1;33m"); //yellow
		printf("Input (Enter 0 to Go Back): ");
		printf("\033[0m");
		scanf("%d", &select);
		printf("=====================================================\n");
		select = select-1;
		count = 0;
		
		for(j=0;j<k;j++)
		{
			if(select==num[j] && count==0) //if admin's selection is found
			{
				if(select>-1)
				{
					/*displays the ddetails of the message */
					printf("\033[0;33m"); //yellow
					printf("From: ");
					printf("\033[0m");
					printf("%s\n", message_entries[select].Sender);
					
					printf("\033[0;33m"); //yellow
					printf("To:\n");
					printf("\033[0m");
					
					for(l=0;l<message_entries[select].numOfRecipients;l++)
					{
						printf("%s\t\t", message_entries[select].Recipients[l]);
						for(m=0;m<usrCount;m++) 
						{
							//displays recipient's full name
							if(strcmp(message_entries[select].Recipients[l], user_entries[m].Username)==0)
							{
								printf("%s", user_entries[m].Full_Name);
							}
						}
						printf("\n");
					}
					/* displays the contents of the message */
					printf("\033[0;33m"); //yellow
					printf("\nSubject: ");
					printf("\033[0m");
					printf("%s\n", message_entries[select].Subject);
					for(i=0;i<message_entries[select].numOfMsgLines;i++)
					{
						printf("%s\n", message_entries[select].strMsgEntries[i]);
					}
					count = 1;
					printf("\n");
					system("pause");
					printf("=====================================================\n");
				}
			}
		}
	}

	
	
}

/*********************************************************************************************************************
	Admin_Messages_Page() function helps the admin manage the users' messages.
	It includes features such as deleting a message, filtering a message, and viewing messages

	@param user_entries - array of structures containing user details (username, full name, password, etc)

	@param message_entries - array of structures containing user's message details (sender, recipient, message, etc)

	@param msgCount - pointer to an integer containing the total number of messages of all users

	@param userCount - pointer to an integer containing the total number of users

***********************************************************************************************************************/

void Admin_Messages_Page(User_Details user_entries[MAX_USERS],messageTag message_entries[MAX_MSSG_COUNT],int *msgCount,int *usrCount) 
{
	int flag=0, choice;

	do
	{
		system("cls");
		printf("=====================================================\n");
		printf("\033[1;31m"); //red
		printf("                MESSAGES ADMIN MENU                  \n");
		printf("\033[0m");
		printf("=====================================================\n");
		printf("[1] Delete Message\n");
		printf("[2] View by Filter\n");
		printf("[3] View Messages\n");
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
				if(*msgCount==0) 
				{
					printf("\nI'm sorry you deleleted all messages, nothing left to delete!!!\n\n");
				}
				else *msgCount = Admin_Delete_Message(user_entries,message_entries,*msgCount,*usrCount); //calls the function to delete a message
				break;
			case 2:
				Admin_View_Filter(user_entries,message_entries,*msgCount,*usrCount); //calls a function to filter message
				break;
			case 3: 
				Admin_View_Message(user_entries,message_entries,*msgCount,*usrCount); //calls a function to view all messages				
				break;
			case 4: 
				flag = 1; //exit
				break;	
			default: 
				printf("Invalid input. Please try again.\n\n");
		}
		
	}
	while(flag == 0);

}
