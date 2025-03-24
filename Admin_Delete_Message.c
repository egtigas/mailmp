int Admin_Delete_Message(User_Details user_entries[MAX_USERS],messageTag message_entries[MAX_MSSG_COUNT],int msgCount,int usrCount) 
{
	
	/*
	printf("Admin_View_Messages %d %d\n",msgCount,usrCount);
	
	printf("Admin_View_Messages %d %d\n",*msgCount,*usrCount);
	printf("Admin_View_Messages %d %d\n",&msgCount,&usrCount);
	system("pause");
	*/
	int i;
	
	int j=0, k=0, l;
    int select=1;
    //int num[30], count,m;
	


/*
    printf("=====================================================\n");
    printf("                ADMIN DELETE MESSAGE                      \n");
    printf("=====================================================\n");
	printf("No. \tSender\t\t\tSubject\n");
*/

	while(select>-1)
	{
		printf("=====================================================\n");
		printf("                ADMIN DELETE MESSAGE                      \n");
		printf("=====================================================\n");
		printf("No. \tSender\t\t\tSubject\n");
		for(i=0;i<msgCount;i++)
		{
			printf("[%d]\t%-20s\t%s\n", i+1, message_entries[i].Sender,message_entries[i].Subject);
			//num[j] = i;
			j++;
			k++;
			/*
			for(m=0;m<message_entries[i].numOfRecipients;m++)
			{
				printf("[%d]\t%-20s\t%s\n", i+1, message_entries[i].Sender,message_entries[i].Subject);
				num[j] = i;
				j++;
				k++;
			}
			*/
		}
	
		printf("\nDelete which message number (Enter 0 to Go Back): ");
		scanf("%d", &select);
		printf("=====================================================\n");
		select = select-1;
		//count = 0;
		
		if(select>-1)
		{
			printf("msgcnt:%d i:%d j:%d k:%d\n",msgCount,i,j,k);
		
			printf("> From: %s\n", message_entries[select].Sender);
			printf("> To:\n");
			for(l=0;l<message_entries[select].numOfRecipients;l++) 
			{
				printf("%s\t\t", message_entries[select].Recipients[l]);
			}
			printf("\n> Subject: %s\n", message_entries[select].Subject);
			for(i=0;i<message_entries[select].numOfMsgLines;i++)
			{
				printf("%s\n", message_entries[select].strMsgEntries[i]);
			}
			system("pause");
			system("cls");
			j=0;
			for(i=0;i<=msgCount;i++) 
			{
				if(i<select) 
				{
					printf("Ignore %d %s %s\n",i,message_entries[i].Sender,message_entries[i].Subject);
					j++;
				}
				else if(i==select) 
				{
					printf("Skip %d %s %s\n",i,message_entries[i].Sender,message_entries[i].Subject);
				}
				else
				{
					printf("Move %d to %d %s %s\n",i,j,message_entries[j].Sender,message_entries[j].Subject);
					j++;
				}
			}
		}
		/*
		for(j=0;j<k;j++)
		{
			if(select==num[j] && count==0)
			{
				if(select>-1)
				{
					printf("> From: %s\n", message_entries[select].Sender);
					printf("> To:\n");
					for(l=0;l<message_entries[select].numOfRecipients;l++)
					{
						printf("%s\t\t", message_entries[select].Recipients[l]);
						for(m=0;m<usrCount;m++) 
						{
							if(strcmp(message_entries[select].Recipients[l], user[m].Username)==0)
							{
								printf("%s\n", user[m].Full_Name);
							}
						}
					}
					printf("\n> Subject: %s\n", message_entries[select].Subject);
					for(i=0;i<message_entries[select].numOfMsgLines;i++)
					{
						printf("%s\n", message_entries[select].strMsgEntries[i]);
					}
					count = 1;
					system("pause");
					system("cls");
					printf("=====================================================\n");
					//TEST
					//strcpy(message_entries[select].Subject,"Arithmetic");
				}
			}
		}
		*/
		
		
		
	}

	return 1;




	
	
	
	
	
}