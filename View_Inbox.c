/*********************************************************************************************************************************
	View_Inbox function() views all the messages that the user has received. 

	@param message_entries - array of structures containing user's message details (sender, recipient, message, etc)

	@param msgCount - pointer to an integer containing the total number of messages of all users
	
	@param user_index - integer containing user's index 

	@param userCount - integer containing the total number of users

***********************************************************************************************************************************/

void View_Inbox(messageTag message_entries[MAX_MSSG_COUNT],int *msgCount,int user_index,int userCount)
{
	int i,j=0, k=0, l, m, noMessages;
	int select=1, count, reply;
	int num[30];
	
	system("cls");
	
	printf("=====================================================\n");
	printf("\033[1;31m"); //red
	printf("                  	 VIEW INBOX                      \n");
	printf("\033[0m");
	printf("=====================================================\n");

	while(select>-1)
	{
		noMessages = 1;
		for(i=0;i<*msgCount;i++) //goes through all the messages
		{
			for(m=0;m<message_entries[i].numOfRecipients;m++) //goes through the recipients of the message
			{
				if(strcmp(message_entries[i].Recipients[m], user[user_index].Username)==0)//if the user is one of the recipients
				{
					printf("[%d] %s\n", i+1, message_entries[i].Subject); //prints the subject of the message
					num[j] = i; //stores the index of message that the user has received
					j++;
					k++;
					noMessages = 0; 
				}
			}
		}
		
		if(noMessages == 1) //if user does not have any messages
		{
			printf("\033[0;31m"); //red
			printf("You have no messages!\n");
			printf("\033[0m");
		}
		printf("\033[1;33m"); //yellow
		printf("\nInput (Enter 0 to Go Back): ");
		printf("\033[0m");
		scanf("%d", &select);
		select = select-1; //since array starts at index 0
		count = 0;
		
		for(j=0;j<k;j++) //goes through the messages user has received
		{
			if(select==num[j] && count==0) //if selected message of user is found in the list
			{
				if(select>-1) //if user input is valid
				{	
					printf("=====================================================\n");
					
					/*prints message details*/
					printf("\033[0;33m"); //yellow
					printf("From: ");
					printf("\033[0m");
					printf("%s\n", message_entries[select].Sender);
					
					printf("\033[0;33m"); //yellow
					printf("To:\n");
					printf("\033[0m");
				
					for(l=0;l<message_entries[select].numOfRecipients;l++) //goes through the recipients of the selected message
					{
						printf("%s\t\t", message_entries[select].Recipients[l]); //prints the recipients' username 
						for(m=0;m<userCount;m++) //goes through all the users
						{
							if(strcmp(message_entries[select].Recipients[l], user[m].Username)==0) 
							{
								printf("%s", user[m].Full_Name); //prints the recipients' full name
							}
						}
						printf("\n");
					}
					printf("\033[0;33m"); //yellow
					printf("\nSubject: ");
					printf("\033[0m");
					printf("%s\n", message_entries[select].Subject); //prints the subject of message
					
					printf("\033[0;33m"); //yellow
					printf("Message:\n");
					printf("\033[0m");
					
					for(i=0;i<message_entries[select].numOfMsgLines;i++) //goes through the contents of message
					{
						printf("%s\n", message_entries[select].strMsgEntries[i]); //prints the contents of message
					}
					
					printf("\n[1] Reply\n");
					printf("[0] Back\n");
					printf("\033[1;33m"); //yellow
					printf("Input: ");
					printf("\033[0m");
					scanf("%d", &reply); //asks for user input
					if(reply==1)
					{	
						/* call function that allows the user to reply back to the message*/
						*msgCount = Reply_Message(message_entries,*msgCount,user_index,*num, message_entries[select].numOfRecipients, select);
						
					}
					
					count = 1;
					
					printf("=====================================================\n");
				}
			}
		}
	}
}
