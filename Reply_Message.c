void Reply_Message(messageTag message_entries[MAX_MSSG_COUNT],int *msgCount,int *user_index,int index, int *num)
{
	int k=0;
	
	// int j=1, l=0, dupFlag =0;
	String100 tmpSubject; 
	String100 tmpMessage; 
	//char SendToList[1000];
	//char arrList[MAX_USERS][100];
	int EndOfMessage=0; //End of Message Flag 
	int numLines=0;
	
	printf("=====================================================\n");
	printf("                  COMPOSE YOUR REPLY\n");
	printf("=====================================================\n");		
	
	//printf("mssg_count %d; user_index %d; index %d; num %d", *msgCount, *user_index, index, *num);
	
	printf("Subject: ");
	fgets(tmpSubject,sizeof(tmpSubject),stdin);	
	/*
	if recipient > 1
	printf("To: %s\n", user[*num].Username);
	
	else
	printf("To: 
	all recipients
	sender);
	
	*/
	
	/*for(i=1;i<userCount;i++)
	{
		printf("[%d] %s\n",user[i].User_Index,user[i].Username);
	}
	printf("%c[%d;%df", 0x1B, 25, 1);
	printf("Select user number or select 0 to end\n");

	scanf("%d",&j);
	while (j!=0)
	{		
		printf("%c[%d;%df", 0x1B, 26, 1);
		for(i=0;i<k+1;i++)
		{
			if(strcmp(arrList[i],user[j].Username)==0)
			{
				printf("%c[%d;%df", 0x1B, 26, 1);
				printf("Duplicate\n");
				dupFlag=1;
			}
		}
		if(dupFlag != 1)
		{
			strcpy(arrList[k],user[j].Username);
			strcat(SendToList,user[j].Username);
			strcpy(message_entries[*msgCount].Recipients[k], user[j].Username); //here!
			strcat(SendToList," ");
			printf("%c[%d;%df", 0x1B, 7, 10);
			printf("%s\n",SendToList);
			printf("%c[%d;%df", 0x1B, 26, 1);
			printf("                 ");
			printf("%c[%d;%df", 0x1B, 27, 1);
			printf("                 ");
			printf("%c[%d;%df", 0x1B, 26, 1);				
			l++;
			k++;
		}
		dupFlag=0;
		scanf("%d",&j);
	}
	*/
	
	//Updated this
	//strcpy(message_entries[*msgCount].Sender,user[user_index].Username);
	strcpy(message_entries[*msgCount].Sender,user[*user_index].Username);
	//
	clean(tmpSubject);
	strcpy(message_entries[*msgCount].Subject,tmpSubject);
	message_entries[*msgCount].ancFlag=0;
	message_entries[*msgCount].numOfRecipients=k;
	printf("Message: Write END to Finish\n");

	while ( !EndOfMessage ) {
		fgets(tmpMessage,sizeof(tmpMessage),stdin);
		clean(tmpMessage);
		if (!strcmp(tmpMessage,"END"))
			EndOfMessage = 1;
		else {
			strcpy(message_entries[*msgCount].strMsgEntries[numLines],tmpMessage);
			numLines++;
			}
		}
	message_entries[*msgCount].numOfMsgLines=numLines;

	(*msgCount)++;		
	Print_Message_File(message_entries,msgCount);
	
	system("pause");
}