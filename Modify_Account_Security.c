void Modify_Account_Security(int user_index){
	
	int select, num, i, match = 0, run = 0, index = 1;
	char old_password[PASSWORD_LENGTH];
	char new_password1[PASSWORD_LENGTH];
	char new_password2[PASSWORD_LENGTH];
	char old_answer[SECURITY_ANSWER_LENGTH];
	char new_answer1[SECURITY_ANSWER_LENGTH];
	char new_answer2[SECURITY_ANSWER_LENGTH];
	char row[1000];
	strcpy(row,"");
	strcpy(old_password,"");
	strcpy(old_answer,"");
	strcpy(new_password1,"");
	strcpy(new_answer1,"");
	strcpy(new_password2,"");
	strcpy(new_answer2,"");
	
	FILE *file_pointer; // original file
	FILE *temp_file_pointer; // temporary file
	
	file_pointer = fopen("user.txt", "rt");
	
	system("cls");
	printf("=====================================================\n");
	printf("                      USER PAGE                      \n");
	printf("Welcome: %s!\n",user[user_index].Full_Name);
	printf("=====================================================\n");
	
	printf("[1] Change Password\n[2] Change Security Answer\n");
	printf("Search by: ");
	scanf("%d", &select);
	
/*********
CHANGE PASSWORD

We need to rewrite the entire user.txt into a temporary file to "edit" it. We will copy every row of the user.txt file
into the temporary one, except for the user's row, which we have to change.

**********/
	
	match = 0;
	if(select == 1){
		while(match == 0){
		printf("\nChange Password\n");
		printf("Enter Old Password: ");
		scanf("%s", old_password);
		
		// decrpyts password
		if(run == 0){
			for(i=0; i<strlen(user[user_index].Password); i++){
				user[user_index].Password[i] = user[user_index].Password[i]-1;
				run++;
			}
		}
		
		// asks user to enter new password
		if(strcmp(user[user_index].Password, old_password)==0){
			printf("Enter New Password: ");
			scanf("%s", new_password1);
			printf("Enter New Password Again: ");
			scanf("%s", new_password2);
	
			// encrypts password again
			if(strcmp(new_password1, new_password2)==0){
				for(i=0; i<strlen(new_password1); i++){
					new_password1[i] = new_password1[i]+1;
				}
				
				// CREATES NEW TEMPORARY FILE
				temp_file_pointer = fopen("user_temp.txt", "wt");
				while(fgets(row,sizeof(row),file_pointer)){
					if(index == user_index){ // finds the user whos row we need to change
						// WE HAVE TO TYPE THE WHOLE ROW OF THE USER AGAIN
						strcpy(row,"");
						strcat(row, user[user_index].Username);
						strcat(row, ";");
						strcat(row, user[user_index].Full_Name);
						strcat(row, ";");
						strcat(row, new_password1); // we replace the user[user_index].Password with the new password
						strcat(row, ";");
						strcat(row, user[user_index].Security_Answer);
						strcat(row, ";");
						strcat(row, user[user_index].Description);
						strcat(row, ";\n");
						printf("row %s", row);
					}
				fwrite(&row, strlen(row), 1, temp_file_pointer);
				index++; // goes through all of the rows, rewritting each one into user_temp.txt
				}
				// we need to close both files
				fclose(file_pointer);
				fclose(temp_file_pointer);
				
				remove("user.txt"); // delete the user.txt
				rename("user_temp.txt", "user.txt"); // rename the temporary file into the user.txt
			}
			else
				printf("MISMATCH OF NEW PASSWORD");
			match++;
		}
		
		if(strcmp(user[user_index].Password, old_password)!=0)
			printf("INVALID\n");
		}
	}
	
/*********
CHANGE SECURITY

Exact same logic as change password, but with the security answer instead.

**********/

	if(select == 2){
		printf("%s\n", user[user_index].Security_Question);
		printf("Enter New Security Answer: ");
		scanf("%s", new_answer1);
		printf("Enter New Security Answer: ");
		scanf("%s", new_answer2);

		if(strcmp(new_answer1, new_answer2)==0){
			temp_file_pointer = fopen("user_temp.txt", "wt");
			while(fgets(row,sizeof(row),file_pointer)){
				if(index == user_index){
					strcpy(row,"");
					strcat(row, user[user_index].Username);
					strcat(row, ";");
					strcat(row, user[user_index].Full_Name);
					strcat(row, ";");
					strcat(row, user[user_index].Password);
					strcat(row, ";");
					strcat(row, new_answer1);
					strcat(row, ";");
					strcat(row, user[user_index].Description);
					strcat(row, ";\n");
					printf("row %s", row);
				}
			fwrite(&row, strlen(row), 1, temp_file_pointer);
			index++;
			}
			fclose(file_pointer);
			fclose(temp_file_pointer);
			
			remove("user.txt");
			rename("user_temp.txt", "user.txt");
		}
		else
			printf("MISMATCH OF NEW SECURITY ANSWER");
	}
	
	printf("\nEnter Any Key to Go Back ");
	scanf(" %d", &num);
}