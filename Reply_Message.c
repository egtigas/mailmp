
/***************************************************************************************************************************
	Reply_Message() function allows the user to reply to a message they have receieved. 
	It returns the updated total number of messages

	@param message_entries - array of structures containing user's message details (sender, recipient, message, etc)

	@param msgCount - pointer to an integer containing the total number of messages of all users

	@param user_index - integer containing user's index 

	@param userCount - integer containing the total number of users

	@param num - integer containing the selected recipient they want to reply to

	@param numOfRecipients - integer containing total number of recipients of the selected message
	
	@param selectedMessage - integer containing the index of the selected message

****************************************************************************************************************************/

int Reply_Message(messageTag message_entries[MAX_MSSG_COUNT],int msgCount,int user_index,int num, int numOfRecipients, int selectedMessage)
{
	int i=-1, match;
	
	String100 tmpSubject; 
	String100 tmpMessage; 
	int EndOfMessage=0;  
	int numLines=0;
	
	fflush(stdin); 	
	strcpy(tmpSubject,"");
	strcpy(tmpMessage,"");
	
	printf("=====================================================\n");
	printf("\033[1;31m"); //red
	printf("                  COMPOSE YOUR MESSAGE\n");
	printf("\033[0m");
	printf("=====================================================\n");		
	
	/* asks user what the subject of their reply is */
	printf("\033[0;33m"); //yellow
	printf("Subject: ");
	printf("\033[0m");
	fgets(tmpSubject,sizeof(tmpSubject),stdin);

	printf("\033[0;33m"); //yellow
	printf("To:\n");
	printf("\033[0m");
	if(selectedMessage > -1) // if the user is replying to a message in their Inbox
	{
		/* displays the recipients of the selected message */
		if(numOfRecipients > 1) // if it is a group message
		{
			for(i=0; i<numOfRecipients;i++) //loops through the message's recipients
			{	
				if(strcmp(message_entries[selectedMessage].Recipients[i], user[user_index].Username)!=0) 
				{
					strcpy(message_entries[msgCount].Recipients[i], message_entries[selectedMessage].Recipients[i]);
					printf("%s\n", message_entries[selectedMessage].Recipients[i]); //displays the recipients excluding the user
				}
				else match = i; // gets the index of the User within the list of Recipients
			}
			/* switches the Sender of the message to become the Recipient*/
			strcpy(message_entries[msgCount].Recipients[match], message_entries[selectedMessage].Sender); 
		}
		
		printf("%s\n", message_entries[selectedMessage].Sender);
		strcpy(message_entries[msgCount].Recipients[i+1], message_entries[selectedMessage].Sender); // swithces the Recipient (the User) of the message to become the Sender
	}
	
	if(selectedMessage == -1) // runs when user messages someone from Browse User
	{
		printf("%s\n", user[num].Username);
		strcpy(message_entries[msgCount].Recipients[0], user[num].Username);
	}
	
	strcpy(message_entries[msgCount].Sender,user[user_index].Username); //user is set as the sender of message
	
	clean(tmpSubject);
	
	strcpy(message_entries[msgCount].Subject,tmpSubject);
	message_entries[msgCount].ancFlag=0; //initializes to 0 since this is not an announcement
	message_entries[msgCount].numOfRecipients=numOfRecipients;
	
	/* user inputs the contents of their message */
	printf("\033[0;33m"); //yellow
	printf("\nMessage (Write END to Finish):\n");
	printf("\033[0m");
	while ( !EndOfMessage ) {
		fgets(tmpMessage,sizeof(tmpMessage),stdin);
		clean(tmpMessage);
		if (!strcmp(tmpMessage,"END")) //if user inputs "END"
			EndOfMessage = 1;
		else {
			strcpy(message_entries[msgCount].strMsgEntries[numLines],tmpMessage); //else user continues to input their message
			numLines++;
			}
		}
	message_entries[msgCount].numOfMsgLines=numLines;
	
	msgCount++;	//adds to total number of messaages	
	
	return msgCount; //returns modified total number of messages
}