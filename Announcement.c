typedef char String[101];

void clean(String strTemp)
{
	int len = strlen(strTemp);
	int lastIndex = len-1;
	
	if (lastIndex >= 0 && strTemp[lastIndex] == '\n')
		strTemp[lastIndex] = '\0';
}



void Compose_Announcement(int user_index){
	
	int index = 1, bEnd = 0;
	char row[1000];
	char temp[1000]="";
	char strTemp[1000]="";
	char delm[]="\t";
	//char delimiter[] = ";";
	strcpy(row,user[user_index].Username);
	strcat(row,delm);
	
	FILE *annc_ptr;
	
	system("cls");
	annc_ptr = fopen("announcement.txt", "at");
	fflush(stdin); 
	printf("Announcement User Index %s\n",user[user_index].Username);
	
	//while(fgets(row,sizeof(row),annc_ptr)){
	//	index++;
	//}
	
	printf("=====================================================\n");
	printf("                     ANNOUNCEMENT                    \n");
	printf("=====================================================\n");
	
	printf("Subject: ");
	gets(temp);
	//gets(row);
	//printf(" %s:\n",row);
	
	strcat(row,temp);
	strcat(row,delm);
	printf("Announcement: ");
	
	while (!bEnd)
	{
		fgets(strTemp,sizeof(strTemp),stdin);
		//clean(strTemp);
		if (!strcmp(strTemp,"END\n"))
			bEnd = 1;
		else
		{
			//strcpy(blog_entries[*numPosts].strEntries[numLines],strTemp);
			// or strcpy(blog_entries[*numPosts].strEntries[blog_entries[*numPosts].numLines],strTemp)
			strcat(row,strTemp);
			//numLines++; // or blog_entries[*numPosts].numLines++;
		}
	}	
	
	
	
	
	
	
	
	//gets(temp);
	//strcat(row,temp);
	strcat(row,"\t\n");	
	
	
	fprintf(annc_ptr, row);
	
	
	fclose(annc_ptr);
}