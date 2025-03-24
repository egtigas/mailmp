void Modify_Full_Name(int user_index)
{
	char Enter_Modified_Name[100];
	
	printf("Enter new full name: ");
	fgets(Enter_Modified_Name, sizeof(Enter_Modified_Name), stdin);
	Enter_Modified_Name[strcspn(Enter_Modified_Name, "\n")] = '\0'; 
	
	strcpy(user[user_index].Full_Name, Enter_Modified_Name);
}

void Modify_Description(int user_index)
{
	char Enter_Modified_Description[100];
	
	printf("Enter new description: ");
	fgets(Enter_Modified_Description, sizeof(Enter_Modified_Description), stdin);
	Enter_Modified_Description[strcspn(Enter_Modified_Description, "\n")] = '\0'; 
	
	strcpy(user[user_index].Description, Enter_Modified_Description);
}
void Modify_Personal_Contents(int user_index)
{
	//int choice: User input on which personal content to modify (Full name or Description)
	//flag_Name and flag_Description: boolean variables that allows the modification process to continue
	//Enter_Modified_Name and Enter_Description: stores the newly modified content
	
	
	int choice, Total_User_Index;
	
	
	Load_Users(&Total_User_Index);
	
	printf("[1] Full Name\n[2] Description\n");
	printf("Input choice to modify: ");
	scanf("%d", &choice);
	getchar(); //gets newline

	if(choice == 1) //if user chooses to modify their Full name
	{
		Modify_Full_Name(user_index);
	}
	else if(choice == 2) //if user chooses to modify their Description
	{
		Modify_Description(user_index);
	}
	
	Save_User_File(Total_User_Index);
	system("cls");
	
	printf("=====================================================\n");
	printf("Successfully updated!\n");
	printf("=====================================================\n");
	
	
}
