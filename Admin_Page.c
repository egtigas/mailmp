int Enter_Secret_Password(char secret_password[])
{
    char enter_password[100];
    int c;

    printf("Enter TOP SECRET password: ");

    while ((c = getchar()) != '\n' && c != EOF);

    fgets(enter_password, sizeof(enter_password), stdin);
    enter_password[strcspn(enter_password, "\n")] = '\0'; 

	if(strcmp(enter_password, secret_password) == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
    
}

void Admin_Page(){
	
	int msgCount=0; //Count of messages and announcements	
	int usrCount=0;
	int choice, flag = 0, valid = 0;
	char secret_password[100];
	//printf("USERPAGE: Start %d\n",userCount);	
	//malloc(MAX_MSSG_COUNT * sizeof(message_entries));
	
	//messageTag message_entries[1000]; //Array of all messages from all users	
	struct messageTag *message_entries = (struct messageTag *)malloc(MAX_MSSG_COUNT * sizeof(struct messageTag));
	struct User_Details *user_entries = (struct User_Details *)malloc(MAX_USERS * sizeof(struct User_Details));
	
	Load_Message_File(message_entries,&msgCount);
	//Print_Message_File(message_entries,&msgCount);
	Load_User_File(user_entries,&usrCount);
	printf("Loaded users %d Messages %d\n",usrCount,msgCount);
	
	strcpy(secret_password, "");
	
	Load_Secret_Password(secret_password);
	valid = Enter_Secret_Password(secret_password);
	
	system("cls");
	
	if(valid)
		{
			do
			{
				printf("=====================================================\n");
				printf("                ADMIN MAIN MENU                      \n");
				printf("=====================================================\n");
				printf("[1] User Module\n");
				printf("[2] Messages Module\n");
				printf("[3] Change Admin Password\n");
				printf("[4] Exit\n");
				printf("=====================================================\n\n");
				printf("Input: ");
				scanf("%d", &choice);
				system("cls");
				
				switch(choice)
				{
					case 1:
						Admin_User_Page(user_entries,message_entries,&usrCount);
						printf("Select %d\n",choice);
						break;
					case 2:
						Admin_Messages_Page(user_entries,message_entries,&msgCount,&usrCount);
						printf("Returned users %d Messages %d\n",usrCount,msgCount);
						printf("Select %d\n",choice);
						break;
					case 3: 
						Change_Admin_Password(secret_password);
						break;
					case 4: 
						flag = 1; //exit
						printf("Select %d\n",choice);
						Save_Message_File(message_entries,msgCount);
						break;	
					default: 
						printf("Invalid input. Please try again.\n\n");
				}
				
			}
			while(flag == 0); 
		}
		else
		{
			printf("=====================================================\n");
			printf("INCORRECT PASSWORD!\n");
			printf("=====================================================\n");
		}
		
		  
	}