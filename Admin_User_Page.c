void Admin_User_Page(User_Details user_entries[MAX_USERS],messageTag message_entries[MAX_MSSG_COUNT],int *usrCount) 
{
	int choice, flag = 0, i;
	//printf("Admin_User_Page\n");

	system("cls");
	
	do
	{
		system("cls");
		printf("=====================================================\n");
		printf("                  USER ADMIN MODULE                  \n");
		printf("=====================================================\n");
		printf("[1] View Users\n");
		printf("[2] Refresh User Account Password\n");
		printf("[3] Delete User\n");
		printf("[4] Modify Users\n");
		printf("[5] Go back\n");
		printf("=====================================================\n");
		printf("Select\n");
		scanf("%d", &choice);
		//printf("Input: (last %d)",scanf("%d", &choice));
		//i = scanf("%d", &choice);
		//if(i == 0) choice = 98;
		//system("cls");
		
		switch(choice)
		{
			case 1:
				for(i=0;i<*usrCount;i++){
					printf("[%d]%s\t%s\t%s\n",i+1,user_entries[i].Username,user_entries[i].Full_Name,user_entries[i].Description);
				}
				system("pause");
			//printf("Select %d\n",userCount);
				break;
			case 2: 
				printf("Select %d\n",choice);
				break;
			case 3: 
				printf("Select %d\n",choice);
				break;
			case 4: 
				printf("Select %d\n",choice);
				break;	
			case 5:
				flag=1;
				system("cls");
				break;
			case 99:
				printf("Select\n");
				break;
			default: 
				//printf("Select %d\n",choice);
				printf("Invalid input. Please try again.\n\n");
				//scanf("%d", &choice);
		}
	}
	while(flag == 0);      
}  
