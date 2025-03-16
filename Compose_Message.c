//void Compose_Message(String100 tmpUsername, int *msgCount, int ancFlag){
void Compose_Message(messageTag message_entries[MAX_MSSG_COUNT],String100 tmpUsername, int *msgCount, int ancFlag){
	//Load message file first
	String100 tmpSubject;
	String100 tmpMessage;
	int EndOfMessage=0; //End of Message Flag
	int numLines=0;
	
	fflush(stdin); //To clear garbage	
	strcpy(tmpSubject,"");
	strcpy(tmpMessage,"");

	
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
		strcpy(message_entries[*msgCount].Subject,tmpSubject);
		message_entries[*msgCount].ancFlag=1;
		message_entries[*msgCount].numOfRecipients=MAX_USERS;
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
				//strcpy(blog_entries[*numPosts].strEntries[numLines],tmpMessage);
				// or strcpy(blog_entries[*numPosts].strEntries[blog_entries[*numPosts].numLines],tmpMessage)
				//msgCount++; // or blog_entries[*numPosts].numLines++;
				}
			}
			message_entries[*msgCount].numOfMsgLines=numLines;
		
		}
	else {
		printf("Composing Message for %s\n",tmpUsername);
		printf("Message Count %d\n",*msgCount);
	}
	
	
	printf("Going out Mssg:%d From:%s Subject:%s Lines:%d\n",*msgCount,
		message_entries[*msgCount].Sender,
		message_entries[*msgCount].Subject,
		numLines);
	(*msgCount)++;
}
