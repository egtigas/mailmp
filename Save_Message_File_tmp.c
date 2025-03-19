void Save_Message_File(messageTag message_entries[MAX_MSSG_COUNT],int msgCount){
	printf("Entering Save Messages to File Function %d\n",msgCount);
	//system("pause");
	
	//FILE *ptr_File = fopen(FILENAME,"wt");
	FILE *file_ptr = fopen("messages.txt", "wt");
	int i, j;
	
	
	//
	//printf("Before exit %s %d\n",username,numPosts);
	// sender of the announcement
	
	if (file_ptr != NULL)
		{
		//Saves no. of messages on first line
		fprintf(file_ptr,"d\n",msgCount); 
		
		for (i = 0;i < msgCount;i++){
		fprintf(file_ptr,"%s\n",message_entries[i].Sender);
		fprintf(file_ptr,"%s\n",message_entries[i].Subject);
		fprintf(file_ptr,"%d\n",message_entries[i].ancFlag);
		fprintf(file_ptr,"%s\n",message_entries[i].numOfRecipients);
		fprintf(file_ptr,"%s\n",message_entries[i].Recipients[0]);
		fprintf(file_ptr,"%s\n",message_entries[i].numOfMsgLines);
		}
		
		
		// num of entries in your blog array
		//fprintf(pFile,"%d\n",numPosts);
		/*for (i = 0;i < msgCount;i++)
		{
			//fprintf (pFile,"%s\n",blog_entries[i].sender);
			//fprintf (pFile,"%s\n",username);
			//fprintf (pFile,"%d\n",blog_entries[i].numLines);
			for (j = 0;j < blog_entries[i].numLines;j++)
				fprintf (pFile,"%s\n",blog_entries[i].strEntries[j]);
		}*/
		/*
		fprintf(file_ptr,"%s\n", message_entries[msgCount-1].Sender);
		fprintf(file_ptr,"%s\n", message_entries[msgCount-1].Subject);
		fprintf(file_ptr,"%d\n", message_entries[msgCount-1].ancFlag);
		fprintf(file_ptr,"%d\n", message_entries[msgCount-1].numOfRecipients);
		fprintf(file_ptr,"%s\n", message_entries[msgCount-1].Recipients[0]);
		fprintf(file_ptr,"%d\n", message_entries[msgCount-1].numOfMsgLines);
		*/
		//printf("Message Lines %d\n", message_entries[msgCount-1].numOfMsgLines);
		//system("pause");		
		
		/*
		for (i = 0;i <= msgCount-1;i++){
			for (j = 0;j < message_entries[i].numOfMsgLines;j++)
				fprintf (file_ptr,"%s\n", message_entries[i].strMsgEntries[j]);
		}
		*/
		/*
		for (i = 0;i < msgCount;i++){
		printf("Message index %d\n", i);
		printf("%s\n", message_entries[i].Sender);
		printf("%s\n", message_entries[i].Subject);
		printf("%d\n", message_entries[i].ancFlag);
		printf("%d\n", message_entries[i].numOfRecipients);
		printf("%s\n", message_entries[i].Recipients[0]);
		printf("%d\n", message_entries[i].numOfMsgLines);
		}
		system("pause");
		*/
		
		fclose(file_ptr);
	}
	else {
		printf ("Error generating %s\n","messages.txt");
	}
		
	system("pause");
}