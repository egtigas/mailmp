
/***************************************************************************************

	Change_Admin_Password() function allows the admin to change the admin password by asking
	the old password and entering the new password twice. If new password is incorrectly
	typed twice, admin is asked to try again.

	@param secret_password - string that contains the password to Admin Module
	
	@return 1 if the user sucessfully enters the correct password, granting access
	to the Admin Module
	
	@return 0 if user enters incorrect password, bringing them back to Main Module
	
****************************************************************************************/

void Change_Admin_Password(char secret_password[])
{
	char enter_password[100];
	char confirm_password[100];
	int valid = 0, flag = 0;
	
	valid = Enter_Secret_Password(secret_password); // admin is asked to enter old password
	
	if(valid)
	{
		printf("=====================================================\n");
		printf("\033[1;31m"); //red
		printf("              CHANGE ADMIN PASSWORD                      \n");
		printf("\033[0m");
		printf("=====================================================\n");		
		printf("Enter new password: ");
		fgets(enter_password, sizeof(enter_password), stdin);
		enter_password[strcspn(enter_password, "\n")] = '\0'; //replaces newline with NULL
		
		printf("Enter new password again: ");
		fgets(confirm_password, sizeof(confirm_password), stdin);
		confirm_password[strcspn(confirm_password, "\n")] = '\0'; //replaces newline with NULL
		
		// if passwords do not match
		// loops till re-entry of password is correct or admin exits by typing "0"
		while(strcmp(enter_password, confirm_password) != 0 && flag == 0)
		{
			printf("\033[1;33m"); //yellow
			printf("Passwords do no not match. Please try again (Enter 0 to exit): ");
			printf("\033[0m");
			fgets(confirm_password, sizeof(confirm_password), stdin);
			confirm_password[strcspn(confirm_password, "\n")] = '\0'; //replaces newline with NULL
			
			if(strcmp(confirm_password, "0") == 0)
			{
				flag = 1;
			}
		
		}
		system("cls");
		
		if(flag == 0) // if passwords match
		{
			printf("=====================================================\n");
			Save_Secret_Password(confirm_password); //saves modified password in admin_password.txt
			printf("Password successfully changed!\n");
			printf("=====================================================\n");
		}
		
	}
	else //if password is incorrect
	{
		printf("=====================================================\n");
		printf("\033[0;31m"); //red
		printf("INCORRECT PASSWORD!\n");
		printf("\033[0m");
		printf("=====================================================\n");
	}
	
}
