void Load_Message_File(messageTag message_entries[MAX_MSSG_COUNT],int *msgCount){

	String100 tmpString;
	int i, j, k=0;
	
	FILE *file_ptr = fopen(MESSAGE_FILE, "rt");

	
	if (file_ptr != NULL)
	{
		/* Read the number of posts */
		fgets(tmpString,sizeof(tmpString),file_ptr);
		*msgCount = atoi(tmpString); // ascii to int
		
		//Load the messages
		for (i = 0;i < *msgCount;i++)
		{
			// Read no. of lines for that entry:
			//Read message sender
			//printf("---- Reading message %d of %d\n",i+1,*msgCount);
			fgets(tmpString,sizeof(tmpString),file_ptr);
			clean(tmpString);
			//printf("Load_Message_File: Sender %s\n",tmpString);			
			strcpy(message_entries[i].Sender,tmpString);
			
			//Read message subject
			fgets(tmpString,sizeof(tmpString),file_ptr);
			//printf("Load_Message_File: Subject %s\n",tmpString);
			clean(tmpString);			
			strcpy(message_entries[i].Subject,tmpString);
			
			fgets(tmpString,sizeof(tmpString),file_ptr);
			//printf("Load_Message_File: ancFlag %s\n",tmpString);
			k = atoi(tmpString);			
			message_entries[i].ancFlag = k;

			fgets(tmpString,sizeof(tmpString),file_ptr);
			//printf("Load_Message_File: Recipients %s\n",tmpString);
			k = atoi(tmpString);			
			message_entries[i].numOfRecipients = k;
			
			//Loading the recipients of this message
			for(j=0;j<k;j++){
				fgets(tmpString,sizeof(tmpString),file_ptr);
				clean(tmpString);
				//printf("Load_Message_File: Recipient %d is %s\n",j+1,tmpString);			
				strcpy(message_entries[i].Recipients[j],tmpString);
			}
			
			fgets(tmpString,sizeof(tmpString),file_ptr);
			//printf("Load_Message_File: No of Message Lines %s\n",tmpString);
			k = atoi(tmpString);			
			message_entries[i].numOfMsgLines = k;
			//printf("Load_Message_File: No of Message Lines %d\n",k);
			
			//Loading the message lines
			for(j=0;j<k;j++){
				fgets(tmpString,sizeof(tmpString),file_ptr);
				clean(tmpString);
				//printf("Load_Message_File: Recipient %d is %s\n",j+1,tmpString);			
				strcpy(message_entries[i].strMsgEntries[j],tmpString);
			}			
		}
		
	}
	else
		printf ("Error reading %s\n",MESSAGE_FILE);	
}