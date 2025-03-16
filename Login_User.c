void Login_User(){

	int j,k;
	int index = 1, match = 0;
	char row[1000];
	char Enter_Username[100];
	char Enter_Password[PASSWORD_LENGTH];
	char delimiter[] = ";";
	strcpy(row,"");
	strcpy(Enter_Password,"");
	strcpy(Enter_Username,"");


	FILE *file_pointer;
	
	file_pointer = fopen("user.txt", "rt");
	
		printf("=====================================================\n");
		printf("                      LOGIN PAGE                      \n");
		printf("=====================================================\n");
	// This gets the index of the user file. It counts how many rows there are (eg. 2 rows) so the index counts as 2 users.
	// fgets() opens the file.
	// strtok() separates / identifies the user through the delimiter ";".
	while(fgets(row,sizeof(row),file_pointer)){
				strcpy(user[index].Username,strtok(row, delimiter));
				strcpy(user[index].Full_Name, strtok(NULL, delimiter));
				strcpy(user[index].Password, strtok(NULL, delimiter));
				strcpy(user[index].Security_Question, strtok(NULL, delimiter));
				strcpy(user[index].Security_Answer, strtok(NULL, delimiter));
				strcpy(user[index].Description, strtok(NULL, delimiter));
				index++;
		}
			
	while(match == 0){ // it loops and checks if username is INVALID. if it is, it asks user to input again
		printf("Username: ");
		scanf("%s", Enter_Username);
	
			for(j=0;j<index;j++){ // it checks if username is VALID.
				if(strcmp(user[j].Username, Enter_Username)==0){
					
					while(strcmp(user[j].Password, Enter_Password)!=0){ // // it loops and checks if password is INVALID. if it is, it asks user to input again
						printf("Password: ");
						scanf("%s", Enter_Password);
						match++;
						
							for(k=0; k<strlen(Enter_Password); k++){ // it checks if password is VALID.
							Enter_Password[k] = Enter_Password[k]+1; // cyphers password by +1 to the character in ASCII
							}
							if(strcmp(user[j].Password, Enter_Password)==0){ // if username and password are VALID, it brings user into the User Page.
								fclose(file_pointer);
								User_Page(j);
							}
							
							else{ // prints if the input password doesnt exist.
							printf("INVALID PASSOWRD\n");
							}
							
					}
					
				}
			}
			
	if(match == 0){ // prints if the input username doesnt exist.
		printf("INVALID USERNAME\n");
	}
	}
	
	fclose(file_pointer);
	

}