void Browse_Users(int user_index){
	
	int i, j;
	int num=1;
	int index = 1;
	int match = 0;
	int select;
	char filter[100];
	char row[1000];
	strcpy(row,"");
	strcpy(filter,"");
	
	FILE *file_pointer;
	
	file_pointer = fopen("user.txt", "rt");
	
	system("cls");
	while(fgets(row,sizeof(row),file_pointer)){
		index++;
	}
	printf("=====================================================\n");
	printf("                      USER PAGE                      \n");
	printf("Welcome: %s!\n",user[user_index].Full_Name);
	printf("=====================================================\n");
	printf("[1] List\n[2] Filter\n");
	printf("Search by: ");
	scanf("%d", &select);
	
	if(select==1){
	printf("List of Users:\n");
	
	for(i=1; i < index;i++){
		printf("[%d] %s\n", i, user[i].Full_Name);
	}
	
	while(num>0){
		printf("\nSelect User (Enter 0 to Go Back): ");
		scanf(" %d", &num);
			
		if(num>0){
			printf("Username: %s\n", user[num].Username);
			printf("Full Name: %s\n", user[num].Full_Name);
			printf("Description: %s\n", user[num].Description);
		}
	}
	}
	
	if(select == 2){
	printf("\nFilter User: ");
	scanf("%s", filter);
	
	for(j=1; j < index;j++){
		
		if(strstr(user[j].Full_Name, filter)!=0){
			printf("[%d]: %s\n", j, user[j].Full_Name);
			match++;
		}
		
		if(j==index-1 && match > 0){
			while(num>0){
				printf("\nSelect User (Enter 0 to Go Back): ");
				scanf(" %d", &num);
			
				if(num>0){
					printf("Username: %s\n", user[num].Username);
					printf("Full Name: %s\n", user[num].Full_Name);
					printf("Description: %s\n", user[num].Description);
				}
			}
		}
		
	}
	
	if(match==0)
		printf("No Match Found\n");
	}
	
	fclose(file_pointer);
	
}