void Modify_Personal_Contents(int user_index)
{
	//int choice: User input on which personal content to modify (Full name or Description)
	//flag_Name and flag_Description: boolean variables that allows the modification process to continue
	//Enter_Modified_Name and Enter_Description: stores the newly modified content
	
	
	int choice, i = 1, flag_Name = 0, flag_Description = 0; 
	char row[10000];
	
	char Enter_Modified_Name[100];
	char Enter_Description[100];
	
	FILE *user_file;
	FILE *temp_file;
	
	user_file = fopen("user.txt", "r"); 
	temp_file = fopen("temp.txt", "w");
	
	printf("[1] Full Name\n[2] Description\n");
	printf("Input choice to modify: ");
	scanf("%d", &choice);
	getchar(); //gets newline

	if(choice == 1) //if user chooses to modify their Full name
	{
		printf("Enter updated full name: ");
		fgets(Enter_Modified_Name, sizeof(Enter_Modified_Name), stdin);
		Enter_Modified_Name[strcspn(Enter_Modified_Name, "\n")] = '\0'; 
		flag_Name = 1; 
	}
	else if(choice == 2) //if user chooses to modify their Description
	{
		printf("Enter updated description: ");
		fgets(Enter_Description, sizeof(Enter_Description), stdin);
		Enter_Description[strcspn(Enter_Description, "\n")] = '\0';
		flag_Description = 1;
	}

	while(fgets(row, sizeof(row), user_file) != NULL) //looks for user's row of details
	{
		if(user_index == i) //once the user is found, it will replace the certain content that they modified and store it in a temporary file
		{
			if(flag_Name) //modifies the user full name 
			{
				strcpy(user[i].Full_Name, Enter_Modified_Name);
				fprintf(temp_file, "%s;%s;%s;%s;%s;%s;\n", user[i].Username, user[i].Full_Name, user[i].Password, user[i].Security_Question, user[i].Security_Answer, user[i].Description);
			}
			else if(flag_Description) //modifies the user description
			{
				strcpy(user[i].Description, Enter_Description);
				fprintf(temp_file, "%s;%s;%s;%s;%s;%s;\n", user[i].Username, user[i].Full_Name, user[i].Password, user[i].Security_Question, user[i].Security_Answer, user[i].Description);
			}
		}
		else
		{
			
			fputs(row, temp_file); //if user is not found yet, it will copy the contents of the user text file to a temporary file
		}
		i++;
	}
	//reset the flag variables
	flag_Name = 0; 
	flag_Description = 0;
	
	fclose(user_file); 
	fclose(temp_file);
	
	remove("user.txt"); //delete the original file 
	rename("temp.txt", "user.txt"); //replace it with the temporary file and rename it "user.txt"
		
	
}