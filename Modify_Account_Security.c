/************************************************************************************************************************

	Modify_Password() function allows the user to change their password after entering their old password,
	and typing their new password twice

	@param Total_Users - array of structures containing user's message details (sender, recipient, message, etc)

	@param user_index - integer containing user's index 
	
**************************************************************************************************************************/
void Modify_Password(int Total_Users, int user_index)
{
    char old_password[PASSWORD_LENGTH];
    char new_password1[PASSWORD_LENGTH];
    char new_password2[PASSWORD_LENGTH];
	
	fflush(stdin);

    int i, match = 0;

	printf("\n=====================================================\n");
	printf("\033[1;31m"); //red
	printf("                 CHANGE PASSWORD                     \n");
	printf("\033[0m");
	printf("=====================================================\n");
	
    while(match == 0)
    {
        printf("Enter Old Password: ");
        fgets(old_password, sizeof(old_password), stdin);
        old_password[strcspn(old_password, "\n")] = '\0'; // Remove newline

        // Decrypt stored password (shifting by -1)
        char decrypted_password[PASSWORD_LENGTH];
        strcpy(decrypted_password, user[user_index].Password);
        for(i = 0; i < strlen(decrypted_password); i++)
        {
            decrypted_password[i] = decrypted_password[i] - 1;
        }

        // Compare decrypted password with user input
        if(strcmp(decrypted_password, old_password) == 0) //checks if User typed old password correctly
        {
            printf("Enter New Password: ");
            fgets(new_password1, sizeof(new_password1), stdin);
            new_password1[strcspn(new_password1, "\n")] = '\0';

            printf("Enter New Password Again: ");
            fgets(new_password2, sizeof(new_password2), stdin);
            new_password2[strcspn(new_password2, "\n")] = '\0';

            if(strcmp(new_password1, new_password2) == 0) //checks if the new password is entered twice correctly
            {
                // Encrypt new password before storing (shifting by +1)
                for(i = 0; i < strlen(new_password1); i++)
                {
                    new_password1[i] = new_password1[i] + 1;
                }

                strcpy(user[user_index].Password, new_password1);
				
                printf("\033[1;33m"); //yellow
                printf("Password changed successfully!\n");
				printf("\033[0m");
                match = 1;

                Save_User_File(Total_Users); // Save updated password to file
            }
            else
            {
				printf("\033[0;31m"); //red
                printf("MISMATCH OF NEW PASSWORD\n");
				printf("\033[0m");
            }
        }
        else
        {
			printf("\033[0;31m"); //red
            printf("INVALID OLD PASSWORD\n");
			printf("\033[0m");
        }
    }
}

/************************************************************************************************************************

	Modify_Security_Answer() function prints User's security question and asks them to enter their new security question
	twice

	@param message_entries - array of structures containing user's message details (sender, recipient, message, etc)

	@param msgCount - pointer to an integer containing the total number of messages of all users

	@param user_index - integer containing user's index 

**************************************************************************************************************************/

void Modify_Security_Answer(int Total_Users, int user_index)
{
	char new_answer1[SECURITY_ANSWER_LENGTH];
	char new_answer2[SECURITY_ANSWER_LENGTH];
	
	fflush(stdin);
	
	printf("\n=====================================================\n");
	printf("\033[1;31m"); //red
	printf("                CHANGE SECURITY ANSWER                      \n");
	printf("\033[0m");
	printf("=====================================================\n");
	
	printf("%s\n", user[user_index].Security_Question);
	printf("Enter New Security Answer: ");
	fgets(new_answer1, sizeof(new_answer1), stdin);
	
	printf("Enter New Security Answer Again: ");
	fgets(new_answer2, sizeof(new_answer2), stdin);

	if(strcmp(new_answer1, new_answer2)==0) //checks if the security answer is entered twice correctly
	{
		new_answer1[strcspn(new_answer1, "\n")] = '\0'; //replace newline with NULL
		strcpy(user[user_index].Security_Answer, new_answer1);
		
		printf("\033[1;33m"); //yellow
        printf("Security Answer changed successfully!\n");
		printf("\033[0m");
	}
	else
	{
		printf("\033[0;31m"); //red
		printf("MISMATCH OF NEW SECURITY ANSWER");
		printf("\033[0m");
	}
	
}

/************************************************************************************************************************

	Modify_Account_Security() function allows the user to choose if they want to modify their password or
	security answer

	@param user_index - integer containing user's index 

**************************************************************************************************************************/

void Modify_Account_Security(int user_index)
{
	
	int select, Total_Users;
	
	Load_Users(&Total_Users);
	
	system("cls");
	printf("=====================================================\n");
	printf("\033[1;31m"); //red
	printf("                MODIFY ACCOUNT SECURITY                      \n");
	printf("\033[0m");
	printf("=====================================================\n");
	
	printf("[1] Change Password\n[2] Change Security Answer\n");
	printf("\033[1;33m"); //yellow
	printf("Search by: ");
	printf("\033[0m");
	scanf("%d", &select);

	if(select == 1)
	{
		Modify_Password(Total_Users, user_index);
	}
	else if(select == 2)
	{
		Modify_Security_Answer(Total_Users, user_index);
	}
	
	Save_User_File(Total_Users);
	
}