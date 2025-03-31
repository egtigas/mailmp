
/************************************************************************************************************************

	View_Announcements() function allows the user to view or reply to the messages that was sent to every
	user 

	@param message_entries - array of structures containing user's message details (sender, recipient, message, etc)

	@param msgCount - pointer to an integer containing the total number of messages of all users

	@param user_index - integer containing user's index 

	@param userCount - integer containing the total number of users

**************************************************************************************************************************/

void View_Annoucements(messageTag message_entries[MAX_MSSG_COUNT],int *msgCount,int user_index,int userCount){
	int i,j=0, k=0, noAnnouncements;
	int select=1, count;
	int num[30];

	system("cls");
	printf("=====================================================\n");
	printf("\033[1;31m"); //red
	printf("                   VIEW ANNOUNCEMENTS                   \n");
	printf("\033[0m");
	printf("=====================================================\n");
	
	while(select>-1){
		noAnnouncements = 1;
		for(i=0;i<*msgCount;i++){ //loops through every single messages
			if(message_entries[i].ancFlag==1){ //if message is an announcement
				printf("[%d] %s\n", i+1, message_entries[i].Subject); //display the subject of announcement
				num[j] = i; //store its index in num
				noAnnouncements = 0;
				j++;
				k++;
			}
		}
		
		if(noAnnouncements == 1)
		{
			printf("\033[0;31m"); //red
			printf("No accouncements!\n");
			printf("\033[0m");
		}
		printf("\033[1;33m"); //yellow
		printf("\nInput (Enter 0 to Go Back): "); //user selects which announcement they want to display
		printf("\033[0m");
		scanf("%d", &select);
		select = select-1;
		count = 0;
		
		for(j=0;j<k;j++){ //loops through the announcements
			if(select==num[j] && count==0){ //if user's selected announcement
				if(select>-1){
					
					/*display announcment details */
					printf("\033[0;33m"); //yellow
					printf("\nFrom: ");
					printf("\033[0m");
					printf("%s\n", message_entries[select].Sender);
					
					printf("\033[0;33m"); //yellow
					printf("Subject: ");
					printf("\033[0m");
					printf("%s\n", message_entries[select].Subject);
					
					printf("\033[0;33m"); //yellow
					printf("Message: \n");
					printf("\033[0m");
					for(i=0;i<message_entries[select].numOfMsgLines;i++){ //display announcement contents
						printf("%s\n", message_entries[select].strMsgEntries[i]);
					}
					printf("\n=====================================================\n");
					/*allows user to reply to the announcement*/
					printf("[1] Reply\n");
					printf("[0] Back\n");
					
					printf("\033[1;33m"); //yellow
					printf("\nInput: ");
					printf("\033[0m");
					scanf("%d", &select);
					printf("=====================================================\n\n");
					
					count = 1;
				
					if(select == 1){ //function to reply to the announcement (every user can see the reply)
						Compose_Message(message_entries,user[user_index].Username,msgCount,1,userCount);
					}
				}
			}

		}
	}

}