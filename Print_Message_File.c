void Print_Message_File(messageTag message_entries[MAX_MSSG_COUNT], int *msgCount) {
	int i, j;

	//Debug only
	printf("*********************************\n");
	printf("Message count from Load_Message is %d\n",msgCount);
	for(i=0;i<*msgCount;i++) {
		printf("*********************************\n");
		printf("Message No %d of %d\n", i+1, msgCount);
		printf("Sender:%s\n", message_entries[i].Sender);
		printf("Subject:%s\n", message_entries[i].Subject);
		printf("Announcement Flag:%d\n", message_entries[i].ancFlag);
		
		for(j=0;j<message_entries[i].numOfRecipients;j++) {
			printf("Recipient [%d] %s\n",j+1,message_entries[i].Recipients[j]);
		}
		
		printf("Message: %d\n",message_entries[i].numOfMsgLines);
		
		
		for(j=0;j<message_entries[i].numOfMsgLines;j++) {
			printf("\t%s\n",message_entries[i].strMsgEntries[j]);
		}
		
	}
}