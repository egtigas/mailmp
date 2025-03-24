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
	
		printf("\nDelete which message number \n");
		printf("Did you sure? (Enter 0 to Go Back): \n");
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
		
			for(i=0;i<msgCount;i++) 
			{
				if(i>=select) 
				{
					//printf("-----\n");
					//printf("Delete %d %s %s\n",i+1,message_entries[i].Sender,message_entries[i].Subject);
					//printf("Move %d to %d %s %s\n",i+2,i+1,message_entries[i+1].Sender,message_entries[i+1].Subject);
					//Replace message deleted with next in line
					strcpy(message_entries[i].Sender,message_entries[i+1].Sender);
					strcpy(message_entries[i].Subject,message_entries[i+1].Subject);
					message_entries[i].ancFlag = message_entries[i+1].ancFlag; 
					message_entries[i].numOfRecipients = message_entries[i+1].numOfRecipients;
					for(j=0;j<message_entries[i].numOfRecipients;j++) 
					{
						strcpy(message_entries[i].Recipients[j],message_entries[i+1].Recipients[j]);
					}
					message_entries[i].numOfMsgLines = message_entries[i+1].numOfMsgLines;
					for(j=0;j<message_entries[i].numOfMsgLines;j++) 
					{
						strcpy(message_entries[i].strMsgEntries[j],message_entries[i+1].strMsgEntries[j]);
					}					
					//printf("-----\n");
					
				}
				/* Visual representation
				if(i<select) 
				{
					printf("Ignore %d %s %s\n",i+1,message_entries[i].Sender,message_entries[i].Subject);
					j++;
				}
				else if(i>=select) 
				{
					printf("-----\n");
					printf("Delete %d %s %s\n",i+1,message_entries[i].Sender,message_entries[i].Subject);
					printf("Move %d to %d %s %s\n",i+2,i+1,message_entries[i+1].Sender,message_entries[i+1].Subject);
					printf("-----\n");
					j++;
				}
				*/ 


			}
			msgCount--;
		}

	}

	return msgCount;




	
	
	
	
	
}