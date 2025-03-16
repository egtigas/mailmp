void Compose_Announcement(int user_index){
	
	int index = 1;
	char row[1000];
	//char delimiter[] = ";";
	strcpy(row,user[user_index].Username);
	strcat(row,";");
	
	FILE *annc_ptr;
	
	system("cls");
	annc_ptr = fopen("announcement.txt", "at");
	fflush(stdin); 
	printf("Announcement User Index %s\n",user[user_index].Username);
	
	while(fgets(row,sizeof(row),annc_ptr)){
		index++;
	}
	
	printf("=====================================================\n");
	printf("                     ANNOUNCEMENT                    \n");
	printf("=====================================================\n");
	
	printf("Subject: ");
	gets(Announcement[index].Subject);
	//gets(row);
	//printf(" %s:\n",row);
	
	strcat(row,Announcement[index].Subject);
	strcat(row,";");
	printf("Announcement: ");
	gets(Announcement[index].Message);
	strcat(row,Announcement[index].Message);
	strcat(row,";\n");	
	
	
	fprintf(annc_ptr, row);
	
	
	fclose(annc_ptr);
}