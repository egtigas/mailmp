void User_Page(int user_index){
	
	int choice, choice2;
	//char opt='1';
	int msgCount=0; //Count of messages and announcements


	printf("USERPAGE \n");	
	//malloc(MAX_MSSG_COUNT * sizeof(message_entries));
	messageTag message_entries[100]; //Array of all messages from all users
	
	//do
	while(1)
	{
		//system("cls");
		printf("=====================================================\n");
		printf("                      USER PAGE                      \n");
		printf("Welcome: %s!\n",user[user_index].Full_Name);
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
		printf("Input: ");
		scanf("%d", &choice);
		//opt = getchar();
		
		//system("cls");
				
		switch(choice)
		{
			case 1:
				system("cls");
				printf("=====================================================\n");
				printf("                  COMPOSE A MESSAGE                     \n");
				printf("=====================================================\n");
				printf("[1] Compose Message\n");
				printf("[2] Compose Announcement\n");
				
				printf("Input: ");
				scanf("%d", &choice2);
				
				switch(choice2){
					case 1:
						//Load message file here
						//Compose_Message(user[user_index].Username,&msgCount,0);
						printf("Exit from Compose Message.\n\n");					
						break;
					case 2:
						//Load message file here
						Compose_Message(message_entries,user[user_index].Username,&msgCount,1);
						printf("Exit from Compose Announcement.\n\n");
						printf("%d:%s:%s:\n",msgCount,message_entries[msgCount-1].Sender,message_entries[0].Subject);
						break;
					default: 
					printf("Invalid input. Please try again.\n\n");
				}
				
				break;
			case 2: 
				break;
			case 3: 
				break;
			case 4: 
				break;
			case 5:
				Modify_Personal_Contents(user_index);
				break;
			case 6: 
				Modify_Account_Security(user_index);
				break;
			case 7: 
				break;
			case 8: 
				Browse_Users(user_index);
				break;
			case 9:
				//Close and save message file
				//fopen function in load
				printf("User_Page:Will now save %d messages\n",msgCount);
				//system("pause");
				Save_Message_File(message_entries,msgCount);
				main();
				break;
			default: 
				printf("Invalid input. Please try again.\n\n");
				//system("pause");
			
		}
		
		
	}
	//while(1);   
}