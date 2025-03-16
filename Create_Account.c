void Create_Account()
{
	//fprintf(file,"%s\n","hello");
	
	int i;
	int index = 1;
	char row[1000];
	char delimiter[] = ";";
	strcpy(row,"");
	
	FILE *file_pointer;
	
	file_pointer = fopen("user.txt", "rt");
	
	// This gets the index of the user file. It counts how many rows there are (eg. 2 rows) so the index counts as 2 users.
	// fgets() opens the file.
	// strtok() separates / identifies the user through the delimiter ";".
	while(fgets(row,sizeof(row),file_pointer)){
			strcpy(user[index].Username,strtok(row, delimiter));
			index++;
	}
	
	/***********************
	Information will be sent to user.txt file
	************************/
	
	fclose(file_pointer);
	
	file_pointer = fopen("user.txt", "at");
    if(file_pointer == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }


	fflush(stdin); //To clear garbage
	
	// This makes sure that the registered users dont exceed 30.
	if(index <= 30){
	
	strcpy(row, "");
	
	printf("Username: ");
	gets(user[index].Username);

	// Checks if username is unique.
	for(i=0;i<index;i++){
		while(strcmp(user[index].Username, user[i].Username)==0){
			printf("USERNAME HAS BEEN TAKEN\n");
			printf("Username: ");
			gets(user[index].Username);
		}
	}
	
	strcat(row,user[index].Username);
	strcat(row,";");
	
/***** FULL NAME *****/	

	printf("Full Name: ");
	gets(user[index].Full_Name);
	
	strcat(row,user[index].Full_Name);
	strcat(row,";");
	
/**** PASSWORD ****/	

	printf("Password: ");
	gets(user[index].Password);
	
	// cyphers password by +1 to the character in ASCII
	for(i=0; i<strlen(user[index].Password); i++){
		user[index].Password[i] = user[index].Password[i]+1;
	}
	
	strcat(row,user[index].Password);
	strcat(row,";");
	
/**** SECURITY QUESTION ****/

	printf("Security_Question: ");
	gets(user[index].Security_Question);
	
	strcat(row,user[index].Security_Question);
	strcat(row,";");
	
/**** SECURITY ANSWER ****/

	printf("Security_Answer: ");
	gets(user[index].Security_Answer);
	
	strcat(row,user[index].Security_Answer);
	strcat(row,";");
	
/**** DESCRIPTION ****/
	
	strcpy(user[index].Description, "DEFAULT USER");
	strcat(row,user[index].Description);
	strcat(row,";");
	strcat(row,"\n");
	printf("\nACCOUNT SUCESSFULLY CREATED\n\n");
	
	}
	
	else printf("SORRY\n WE HAVE EXCEEDED MAX USERS\n");
	
/**** ROW ****/

	//printf("ROW %s\n",row);
	fwrite(&row, strlen(row), 1, file_pointer);

    fclose(file_pointer);

}
