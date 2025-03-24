void Load_User_File(User_Details user_entries[MAX_USERS],int *usrCount){
		int index=0;
		//int usrCount=0;
		
		FILE *user_fptr;
		user_fptr = fopen(USER_FILE, "rt");
		char delimiter[] = ";";
		char row[1000];
        strcpy(row,"");
					
		while(fgets(row,sizeof(row),user_fptr) >0 ){
			user_entries[index].User_Index=index;
			strcpy(user_entries[index].Username,strtok(row, delimiter));
			strcpy(user_entries[index].Full_Name, strtok(NULL, delimiter));
			strcpy(user_entries[index].Password, strtok(NULL, delimiter));
			strcpy(user_entries[index].Security_Question, strtok(NULL, delimiter));
			strcpy(user_entries[index].Security_Answer, strtok(NULL, delimiter));
			strcpy(user_entries[index].Description, strtok(NULL, delimiter));
			index++;
		}
	
	*usrCount = index;
	fclose(user_fptr);
	//printf("Load_User_File: %d\n",index);
}