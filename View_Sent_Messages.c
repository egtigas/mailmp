
/**************************************************************************************************************************

	View_Sent_Messages() function allows the user to view the messages they have already sent. 

	@param message_entries - array of structures containing user's message details (sender, recipient, message, etc)

	@param msgCount - pointer to an integer containing the total number of messages of all users

	@param user_index - integer containing user's index 

	@param userCount - integer containing the total number of users

**************************************************************************************************************************/

void View_Sent_Messages(messageTag message_entries[MAX_MSSG_COUNT],int *msgCount,int user_index,int userCount)
{
	int i,j=0, k=0, l, m, noSentMessages;
	int select=1, count;
	int num[30];
	
	system("cls");
	
	printf("=====================================================\n");
	printf("\033[1;31m"); //red
	printf("                  	 VIEW SENT                      \n");
	printf("\033[0m");
	printf("=====================================================\n");

	while(select>-1)
	{
		noSentMessages = 1;
		for(i=0;i<*msgCount;i++) //loops through all the messages
		{
			if(strcmp(user[user_index].Username, message_entries[i].Sender)==0) //finds the messages user has sent
			{
				printf("[%d] %s\n", i+1, message_entries[i].Subject); //prints the subject
				num[j] = i;
				j++;
				k++;
				noSentMessages = 0;
			}
		}
		
		if(noSentMessages == 1) //if user has not sent any messages
		{
			printf("\033[0;31m"); //red
			printf("You have not sent any messages!\n");
			printf("\033[0m");
		}
		printf("\033[1;33m"); //yellow
		printf("\nInput (Enter 0 to Go Back): "); //user selects which message they want to display
		printf("\033[0m");
		scanf("%d", &select);
		printf("=====================================================\n");
		select = select-1;
		count = 0;
		
		/* displays message details such as recipients, contents of the message */
		for(j=0;j<k;j++)
		{
			if(select==num[j] && count==0)
			{
				if(select>-1)
				{
					printf("\033[0;33m"); //yellow
					printf("To:\n");
					printf("\033[0m");
					for(l=0;l<message_entries[select].numOfRecipients;l++) //loop through the message's recipients
					{
						printf("%s\t\t", message_entries[select].Recipients[l]); //displays the recipients
						for(m=0;m<userCount;m++)
						{
							//displays recipient's full name
							if(strcmp(message_entries[select].Recipients[l], user[m].Username)==0)
							{
								printf("%s", user[m].Full_Name);
							}
						}
						printf("\n");
					}
					/*displays contents of message*/
					printf("\033[0;33m"); //yellow
					printf("\nSubject: ");
					printf("\033[0m");
					printf("%s\n", message_entries[select].Subject);
					
					printf("\033[0;33m"); //yellow
					printf("Message:\n");
					printf("\033[0m");
					for(i=0;i<message_entries[select].numOfMsgLines;i++)
					{
						printf("%s\n", message_entries[select].strMsgEntries[i]);
					}
					count = 1;
					
					printf("\n=====================================================\n");
					system("pause");
				}
			}
		}
	}
}