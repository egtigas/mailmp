void Compose_Message(messageTag message_entries[MAX_MSSG_COUNT],String100 tmpUsername,int *msgCount,int ancFlag,int userCount){
	//Load message file first
	int i,j=1,k=0,l=0, dupFlag =0;
	String100 tmpSubject; 
	String100 tmpMessage; 
	char SendToList[1000];
	char arrList[MAX_USERS][100];
	int EndOfMessage=0; //End of Message Flag 
	int numLines=0; 
	
	//Compose_Message(messageTag message_entries[MAX_MSSG_COUNT], select, int *msgCount, int ancFlag)
	//Compose_Message(message_entries,user[user_index].Username,&msgCount,1);
	
	fflush(stdin); //To clear garbage	
	strcpy(tmpSubject,"");
	strcpy(tmpMessage,"");
	strcpy(SendToList,"");
	
	system ("cls");
	if(ancFlag){
		printf("=====================================================\n");
		printf("                  COMPOSE AN ANNOUNCEMENT\n");
		printf("Username: %s\n",tmpUsername);
		printf("Message Count %d\n",*msgCount);		
		printf("=====================================================\n");		

		printf("Subject: ");
		fgets(tmpSubject,sizeof(tmpSubject),stdin);			
		//printf("Subject Entered: %s \n",tmpSubject);

		//Enter Announcement
		printf("Announcement: Write END to Finish\n");
		
		strcpy(message_entries[*msgCount].Sender,tmpUsername);
		clean(tmpSubject);
		strcpy(message_entries[*msgCount].Subject,tmpSubject);
		message_entries[*msgCount].ancFlag=1;
		message_entries[*msgCount].numOfRecipients=1;
		strcpy(message_entries[*msgCount].Recipients[0],"ALL_USERS");		
		strcpy(message_entries[*msgCount].strMsgEntries[0],"ANNOUNCEMENT");
		
	
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

		}
	else {
		printf("=====================================================\n");
		printf("                  COMPOSE A MESSAGE\n");
		printf("Username: %s\n",tmpUsername);
		printf("Message Count %d\n",*msgCount);		
		printf("=====================================================\n");		
		printf("Subject: ");
		fgets(tmpSubject,sizeof(tmpSubject),stdin);		
		printf("Send To:\n");
		//printf("test1 %d", userCount);
		for(i=1;i<userCount;i++) {
			printf("[%d] %s\n",user[i].User_Index,user[i].Username);
			//printf("test2");
			}
		printf("%c[%d;%df", 0x1B, 25, 1);
		printf("Select user number or select 0 to end\n");

		scanf("%d",&j);
		while (j!=0) {		
			printf("%c[%d;%df", 0x1B, 26, 1);
			for(i=0;i<k+1;i++) {
				//printf("%s -- %s\n",arrList[i],user[j].Username);
				if(strcmp(arrList[i],user[j].Username)==0) {
					printf("%c[%d;%df", 0x1B, 26, 1);
					printf("Duplicate\n");
					dupFlag=1;
				}
			}
			if(dupFlag != 1) {
				//clean(user[j].Username);
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

		
		//printf("Message Count %d\n",*msgCount);
		
		//for(i=0;i<k;i++) {
			//printf("%d recipients %d-%s\n",k,i,arrList[i]);
			//printf("%d recipients %d-%s\n",k,i,message_entries[*msgCount].Recipients[k]);
		//}
		strcpy(message_entries[*msgCount].Sender,tmpUsername);
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
				//printf("Line %d %s\n", numLines,tmpMessage);
				strcpy(message_entries[*msgCount].strMsgEntries[numLines],tmpMessage);
				numLines++;
				}
			}
		message_entries[*msgCount].numOfMsgLines=numLines;
	}
				
			
	(*msgCount)++;		
	/*		
	printf("Going out Mssg:%d From:%s Subject:%s Lines:%d\n",*msgCount,
		message_entries[*msgCount].Sender,
		message_entries[*msgCount].Subject,
		numLines);
	*/
	Print_Message_File(message_entries,msgCount);
	//system("pause");
}
