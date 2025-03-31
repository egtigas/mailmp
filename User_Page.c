
/***************************************************************************************

	User_Page() function prints User Page after logging-in that allows user to pick
	options such as:
	
		1. Composing, viewing messages and announcements
		2. Modifying user's certain details
		3. Browsing for other existing users

	@param user_index - integer that contains the index of the logged-in user
	
	@param userCount - interger that contains the total amount of registered users
	
****************************************************************************************/

void User_Page(int user_index,int userCount){
	
	int choice, choice2, flag = 0;
	int msgCount=0;	//Count of messages and announcements

	struct messageTag *message_entries = (struct messageTag *)malloc(MAX_MSSG_COUNT * sizeof(struct messageTag));
	
	if (message_entries == NULL) {
		printf("\033[0;31m"); //red
        printf("Memory allocation failed.\n");
		printf("\033[0m");
    }

	Load_Message_File(message_entries,&msgCount); //opens and reads messages.txt

	do
	{
		system("cls");
		printf("=====================================================\n");
		printf("\033[1;31m"); //red
		printf("                      USER PAGE                      \n");
		printf("\033[1;33m"); //yellow
		printf("Welcome: ");
		printf("\033[0m");
		printf("%s!\n",user[user_index].Full_Name);
		printf("=====================================================\n");
		printf("[1] Compose a Message\n");
		printf("[2] Inbox\n");
		printf("[3] View Sent Messages\n");
		printf("[4] View Announcements\n");
		printf("[5] Modify Personal Contents\n");
		printf("[6] Modify Account Security\n");
		printf("[7] Modify Personal Connection\n");
		printf("[8] Browse Users\n");
		printf("[9] Log Out\n");
		printf("=====================================================\n\n");
		printf("\033[0;33m");//yellow
		printf("Input: ");
		printf("\033[0m");
		scanf("%d", &choice);
				
		switch(choice)
		{
			case 1:
				system("cls");
				printf("=====================================================\n");
				printf("\033[1;31m"); //red
				printf("                  COMPOSE A MESSAGE                     \n");
				printf("\033[0m");
				printf("=====================================================\n");
				printf("[1] Compose Message\n");
				printf("[2] Compose Announcement\n");
				
				printf("\033[1;33m"); //yellow
				printf("Input: ");
				printf("\033[0m");
				scanf("%d", &choice2);
				
				switch(choice2){
					case 1: //if user chooses to compose message personally or to a group
						Compose_Message(message_entries,user[user_index].Username,&msgCount,0,userCount);											
						break;
					case 2: //if user chooses to compose an announcment
						Compose_Message(message_entries,user[user_index].Username,&msgCount,1,userCount);
						break;
					default: //if user's input is invalid
					printf("\033[0;31m"); //red
					printf("Invalid input. Please try again.\n\n");
					printf("\033[0m");
				}
				
				break;
			case 2: 
				//views the user's recieved messages from other users
				View_Inbox(message_entries,&msgCount,user_index,userCount);
				break;
			case 3:
				//views messages sent by user
				View_Sent_Messages(message_entries,&msgCount,user_index,userCount);
				break;
			case 4: 
				//views all anouncment made
				View_Annoucements(message_entries,&msgCount,user_index);
				break;
			case 5:
				//allows user to modify their Fullname and Description
				Modify_Personal_Contents(user_index);
				break;
			case 6: 
				//allows users to modify their Password and Security Answer
				Modify_Account_Security(user_index);
				break;
			case 7: 
				//allows users to modify their Personal Connections
				Modify_Personal_Connections(user_index);
				break;
			case 8: 
				//allows users to view all registered users and add or message them
				Browse_Users(message_entries,&msgCount,user_index, user_index);
				break;
			case 9:
				//messages are only saved into messages.txt after logging out
				Save_Message_File(message_entries,msgCount);
				flag = 1;
				break;
			default: 
				printf("\033[0;31m"); //red
				printf("Invalid input. Please try again.\n\n");
				printf("\033[0m");
		}
		system("cls");
	}
	while(flag == 0);
}
