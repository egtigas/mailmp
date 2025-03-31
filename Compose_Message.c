/******************************************************************************************
	Compose_Message() function allows the user to send a personal/group
	message or an announcement.

	@param message_entries - array of structures containing the contents of 
	the message 

	@param tmpUsername - string containing the username of the user

	@param msgCount - pointer to an integer containing the total number of messages 
	from all users

	@param ancFlag - flag to determine what type of message it is
	(1 = announcement, 0 = personal/group message)

	@param userCount - integer containing total number of users

********************************************************************************************/

void Compose_Message(messageTag message_entries[MAX_MSSG_COUNT],String100 tmpUsername,int *msgCount,int ancFlag,int userCount){
	//Load message file first
	int i,j=1,k=0,l=0, dupFlag =0;
	String100 tmpSubject; 
	String100 tmpMessage; 
	char SendToList[1000]; //string to store recipients
	char arrList[MAX_USERS][100]; // selected recipients
	int EndOfMessage=0; //End of Message Flag 
	int numLines=0; 
	

	fflush(stdin); //To clear garbage
	strcpy(tmpSubject,"");
	strcpy(tmpMessage,"");
	strcpy(SendToList,"");
	
	system ("cls");
	
	if(ancFlag){ //if user chose to compose an announcement
		printf("=====================================================\n");
		printf("\033[1;31m"); //red
		printf("                  COMPOSE AN ANNOUNCEMENT\n");
		printf("\033[0m");		
		printf("=====================================================\n");		

		printf("\033[0;33m"); //yellow

		printf("Subject: ");
		printf("\033[0m");

		fgets(tmpSubject,sizeof(tmpSubject),stdin);			

		//Enter Announcement
		printf("\033[0;33m"); //yellow
		printf("Announcement (Write END to Finish):\n");
		printf("\033[0m");
		
		/* stores the details of the announcement */
		strcpy(message_entries[*msgCount].Sender,tmpUsername); 
		clean(tmpSubject); //allows user to press enter without ending the input
		strcpy(message_entries[*msgCount].Subject,tmpSubject); 
		message_entries[*msgCount].ancFlag=1; 
		message_entries[*msgCount].numOfRecipients=1;
		strcpy(message_entries[*msgCount].Recipients[0],"ALL_USERS"); 
		strcpy(message_entries[*msgCount].strMsgEntries[0],"ANNOUNCEMENT"); 
		
		/* reads the contents of the announcement  */
		while ( !EndOfMessage ) {
			fgets(tmpMessage,sizeof(tmpMessage),stdin);
			clean(tmpMessage);
			if (!strcmp(tmpMessage,"END")) //reads the lines of message until user types "END"
				EndOfMessage = 1; 
			else {
				strcpy(message_entries[*msgCount].strMsgEntries[numLines],tmpMessage); //stores line of message to strMsgEntires
				numLines++; //moves to the next line of message
				}
			}
		message_entries[*msgCount].numOfMsgLines=numLines; //initializes total numebr of message lines

		}
	else {
		printf("=====================================================\n");
		printf("\033[1;31m"); //red
		printf("                  COMPOSE A MESSAGE\n");	
		printf("\033[0m");
		printf("=====================================================\n");	
		
		printf("\033[0;33m"); //yellow
		printf("Subject: ");
		printf("\033[0m");
		fgets(tmpSubject,sizeof(tmpSubject),stdin);	
		
		printf("\033[0;33m"); //yellow
		printf("Send To:\n");
		printf("\033[0m");
		
		for(i=1;i<userCount;i++) { //goes throught the list of usernames
			printf("[%2d] %-25s",i,user[i].Username);
			if((i%3)==0) printf("\n"); //groups the usernames into 3 columns
			
			}
		printf("%c[%d;%df", 0x1B, 22, 1); //moves cursor to row 1, column 22 (the newlines before the select user prompt)
		printf("\033[1;33m"); //yellow
		printf("Select User Number (Type 0 to End):\n");
		printf("\033[0m");

		scanf("%d",&j);
		while (j!=0) {		
			printf("%c[%d;%df", 0x1B, 23, 1);
			for(i=0;i<k+1;i++) { //goes through the list of recipients
		
				if(strcmp(arrList[i],user[j].Username)==0) { //if user inputted the recipient twice
					printf("%c[%d;%df", 0x1B, 23, 1);
					printf("\033[0;31m"); //red
					printf("User is already there. Try again.\n");
					printf("\033[0m");
					dupFlag=1;
				}
				if(strcmp(user[j].Username, tmpUsername)==0) { //if user inputted themselves
					printf("%c[%d;%df", 0x1B, 23, 1);
					printf("\033[0;31m"); //red
					printf("Cannot input yourself. Try again.\n");
					printf("\033[0m");
					dupFlag=1;
				}
			}
			if(dupFlag != 1) { //if valid recipients
			
			/* stores the message details/contents */
				strcpy(arrList[k],user[j].Username);
				strcat(SendToList,user[j].Username);
				strcpy(message_entries[*msgCount].Recipients[k], user[j].Username); 
				strcat(SendToList," ");
				printf("%c[%d;%df", 0x1B, 5, 10); //appends all recipients to the same row
				printf("%s\n",SendToList);
				printf("%c[%d;%df", 0x1B, 23, 1);
				printf("                                  ");
				printf("%c[%d;%df", 0x1B, 24, 1);
				printf("                                  ");
				printf("%c[%d;%df", 0x1B, 23, 1);				
				l++;
				k++;
			}
			dupFlag=0;
			scanf("%d",&j);
		}

		/* stores all message details to message_entires*/
		strcpy(message_entries[*msgCount].Sender,tmpUsername);
		clean(tmpSubject);
		strcpy(message_entries[*msgCount].Subject,tmpSubject);
		message_entries[*msgCount].ancFlag=0;
		message_entries[*msgCount].numOfRecipients=k;
		
		printf("\033[0;33m"); //yellow
		printf("Message (Write END to Finish):\n");
		printf("\033[0m");
		
		/* stores the contents of message */
		while ( !EndOfMessage) { //reads each line of message
			fgets(tmpMessage,sizeof(tmpMessage),stdin);
			clean(tmpMessage);
			if (!strcmp(tmpMessage,"END"))
				EndOfMessage = 1;
			else {
				
				strcpy(message_entries[*msgCount].strMsgEntries[numLines],tmpMessage);
				numLines++; //moves to next line
				}
			}
		message_entries[*msgCount].numOfMsgLines=numLines;
	}
				
			
	(*msgCount)++;	//increments total number of messages
	
	
}
