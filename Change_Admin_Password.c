void Change_Admin_Password(char secret_password[])
{
	/*
		1. Enter old password
		2. Enter new password
		3. Enter new password again
	*/
	
	
	
	char enter_password[100];
	char confirm_password[100];
	int valid = 0, flag = 0;
	

	
	valid = Enter_Secret_Password(secret_password);
	
	
	if(valid)
	{
		printf("Enter new password: ");
		fgets(enter_password, sizeof(enter_password), stdin);
		enter_password[strcspn(enter_password, "\n")] = '\0';
		
		printf("Enter new password again: ");
		fgets(confirm_password, sizeof(confirm_password), stdin);
		confirm_password[strcspn(confirm_password, "\n")] = '\0';
		
		while(strcmp(enter_password, confirm_password) != 0 && flag == 0)
		{
			printf("Passwords do no not match. Please try again (Enter 0 to exit): ");
			fgets(confirm_password, sizeof(confirm_password), stdin);
			confirm_password[strcspn(confirm_password, "\n")] = '\0';
			
			if(strcmp(confirm_password, "0") == 0)
			{
				flag = 1;
			}
		
		}
		system("cls");
		
		if(flag == 0)
		{
			printf("=====================================================\n");
			Save_Secret_Password(confirm_password);
			printf("Password successfully changed!\n");
			printf("=====================================================\n");
		}
		
	}
	else
	{
		printf("=====================================================\n");
		printf("INCORRECT PASSWORD!\n");
		printf("=====================================================\n");
	}
	
	
	
	
}