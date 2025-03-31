
/***************************************************************************************

	Modify_Full_Name() function asks the user their new Fullname and modifies
	it according to their input.

	@param user_index - integer containing the user's personal index

****************************************************************************************/

void Modify_Full_Name(int user_index)
{
	char Enter_Modified_Name[100];
	
	system("cls");
	printf("\n=====================================================\n");
	printf("\033[1;31m"); //red
 	printf("                    MODIFY FULLNAME               \n");
	printf("\033[0m");
	printf("======================================================\n");
	
	printf("Enter new full name: ");
	fgets(Enter_Modified_Name, sizeof(Enter_Modified_Name), stdin);
	Enter_Modified_Name[strcspn(Enter_Modified_Name, "\n")] = '\0'; //replace newline with NULL
	
	strcpy(user[user_index].Full_Name, Enter_Modified_Name); //copies the new Fullname into the user structure
}

/***************************************************************************************

	Modify_Description() function asks the user their new Description and modifies
	it according to their input.

	@param user_index - integer containing the user's personal index

****************************************************************************************/

void Modify_Description(int user_index)
{
	char Enter_Modified_Description[100];
	
	system("cls");
	printf("\n=====================================================\n");
	printf("\033[1;31m"); //red
 	printf("                   MODIFY DESCRIPTION               \n");
	printf("\033[0m");
	printf("======================================================\n");
	
	printf("Enter new description: ");
	fgets(Enter_Modified_Description, sizeof(Enter_Modified_Description), stdin);
	Enter_Modified_Description[strcspn(Enter_Modified_Description, "\n")] = '\0'; //replace newline with NULL
	
	strcpy(user[user_index].Description, Enter_Modified_Description); //copies the new Description into the user structure
}

/***************************************************************************************

	Modify_Personal_Contents() function asks user to pick between modifying Fullname or Description,
	and calls Modify_Full_Name() or Modify_Description() to modify the user's contents

	@param user_index - integer containing the user's personal index

****************************************************************************************/

void Modify_Personal_Contents(int user_index)
{
	//Enter_Modified_Name and Enter_Description: stores the newly modified content
	
	
	int choice; //user input on which personal content to modify (Full name or Description)
	int Total_User_Index, flag = 0;
	
	
	Load_Users(&Total_User_Index); //opens and reads the user.txt
	
	system("cls");
	printf("\n=====================================================\n");
	printf("\033[1;31m"); //red
 	printf("                 MODIFY PERSONAL CONTENTS                   \n");
	printf("\033[0m");
	printf("======================================================\n");
		
	printf("[1] Full Name\n[2] Description\n");
	
	printf("\033[0;33m"); //yellow
	printf("\nInput: ");
	printf("\033[0m");
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
	else
	{
		printf("Invalid input!\n");
		flag = 1;
	}
	
	Save_User_File(Total_User_Index); //saves the modified information in user.txt
	//system("cls");
	if(flag == 0)
	{
		printf("=====================================================\n");
		printf("\033[1;33m"); //yellow
		printf("Successfully updated!\n");
		printf("\033[0m");
		printf("=====================================================\n");
	}
	
	system("pause");
	
	
}
