void View_Sent_Messages(messageTag message_entries[MAX_MSSG_COUNT],int *msgCount,int user_index,int userCount)
{
	int i,j=0, k=0, l, m;
	int select=1, count;
	int num[30];
	
	printf("=====================================================\n");
	printf("                  	 VIEW SENT                      \n");
	printf("=====================================================\n");

	while(select>-1)
	{
		for(i=0;i<*msgCount;i++)
		{
			if(strcmp(user[user_index].Username, message_entries[i].Sender)==0)
			{
				printf("[%d] %s\n", i+1, message_entries[i].Subject);
				num[j] = i;
				j++;
				k++;
			}
		}
		
		printf("Input (Enter 0 to Go Back): ");
		scanf("%d", &select);
		printf("=====================================================\n");
		select = select-1;
		count = 0;
		
		for(j=0;j<k;j++)
		{
			if(select==num[j] && count==0)
			{
				if(select>-1)
				{
					printf("> To:\n");
					for(l=0;l<message_entries[select].numOfRecipients;l++)
					{
						printf("%s\t", message_entries[select].Recipients[l]);
						for(m=0;m<userCount;m++) // FIX USERCOUNT!!
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
					printf("=====================================================\n");
				}
			}
		}
	}
}