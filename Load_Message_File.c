
/*********************************************************************************
	Load_Message_File() function reads the messages from the text file
	and stores them to message_entires array.

	Order of the text file will be:

	1. total number of messages from all users
	2. username of sender
	3. subject of message
	4. flag (1 = announcement, 0 = personal/group message)
	5. number of recipients
	6. username of recipient/s
	7. number of message lines
	8. contents of the message

************************************************************************************/	

void Load_Message_File(messageTag message_entries[MAX_MSSG_COUNT],int *msgCount){

	String100 tmpString;
	int i, j, k=0;
	
	FILE *file_ptr = fopen(MESSAGE_FILE, "rt");

	
	if (file_ptr != NULL)
	{
		/* Read the number of posts */
		fgets(tmpString,sizeof(tmpString),file_ptr);
		*msgCount = atoi(tmpString); // initializes the string digit value to an integer
		
		//Load the messages
		for (i = 0;i < *msgCount;i++)
		{
			// Read no. of lines for that entry:
			//Read message sender
			fgets(tmpString,sizeof(tmpString),file_ptr);
			clean(tmpString);
						
			strcpy(message_entries[i].Sender,tmpString);
			
			//Read message subject
			fgets(tmpString,sizeof(tmpString),file_ptr);
			
			clean(tmpString);			
			strcpy(message_entries[i].Subject,tmpString);
			
			fgets(tmpString,sizeof(tmpString),file_ptr);
			k = atoi(tmpString);			
			message_entries[i].ancFlag = k;

			fgets(tmpString,sizeof(tmpString),file_ptr);
			k = atoi(tmpString);			
			message_entries[i].numOfRecipients = k;
			
			//Loading the recipients of this message
			for(j=0;j<k;j++){
				fgets(tmpString,sizeof(tmpString),file_ptr);
				clean(tmpString);		
				strcpy(message_entries[i].Recipients[j],tmpString);
			}
			
			fgets(tmpString,sizeof(tmpString),file_ptr);
			k = atoi(tmpString);			
			message_entries[i].numOfMsgLines = k;
			
			//Loading the message lines
			for(j=0;j<k;j++){
				fgets(tmpString,sizeof(tmpString),file_ptr);
				clean(tmpString);			
				strcpy(message_entries[i].strMsgEntries[j],tmpString);
			}			
		}
		
	}
	else
		printf ("Error reading %s\n",MESSAGE_FILE);	
}
