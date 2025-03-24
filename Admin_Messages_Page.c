void Admin_Messages_Page(User_Details user_entries[MAX_USERS],messageTag message_entries[MAX_MSSG_COUNT],int *msgCount,int *usrCount) 
{
	int flag=0, choice;
/*
	printf("Admin_Messages_Page:%d %d\n",msgCount,usrCount);
	printf("Admin_Messages_Page**:%d %d\n",*msgCount,*usrCount);
	printf("Admin_Messages_Page&&:%d %d\n",&msgCount,&usrCount);
	
	
	Admin_View_Messages(user_entries,message_entries,&msgCount,&usrCount);
	printf("Returned Admin_View_Messages %d Messages %d\n",usrCount,msgCount);

	printf("Admin_Messages_Page:%d %d\n",*msgCount,*usrCount);
	printf("Admin_Messages_Page**:%d %d\n",*msgCount,*usrCount);
	printf("Admin_Messages_Page&&:%d %d\n",&msgCount,&usrCount);
*/	
	
	
	do
			{
				printf("=====================================================\n");
				printf("                MESSAGES ADMIN MENU                  \n");
				printf("=====================================================\n");
				printf("[1] Delete Message\n");
				printf("[2] View by Filter\n");
				printf("[3] View Messages\n");
				printf("[4] Exit\n");
				printf("=====================================================\n\n");
				printf("Input: ");
				scanf("%d", &choice);
				system("cls");
				
				switch(choice)
				{
					case 1:
						if(*msgCount==0) 
						{
							printf("\nI'm sorry you deleleted all messages, nothing left to delete!!!\n\n");
						}
						else *msgCount = Admin_Delete_Message(user_entries,message_entries,*msgCount,*usrCount);
						break;
					case 2:
						printf("Select %d\n",choice);
						break;
					case 3: 
						Admin_View_Message(user_entries,message_entries,*msgCount,*usrCount);
						//printf("Admin_Messages_Page: Return %d %d\n",*msgCount,*usrCount);
						printf("Select %d\n",choice);					
						break;
					case 4: 
						flag = 1; //exit
						printf("Select %d\n",choice);
						break;	
					default: 
						printf("Invalid input. Please try again.\n\n");
				}
				
			}
			while(flag == 0);

}