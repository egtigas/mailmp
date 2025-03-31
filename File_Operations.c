
/***************************************************************************************

	Load_Users() function opens and reads the user.txt file. strtok() splits the
	strings according to its delimiter which is set to ";"

	@param *index - pointer to integer containing the total nuber of users
	
****************************************************************************************/

void Load_Users(int *index)
{
	*index = 1;
	char row[1000];
	char delimiter[] = ";"; //delimiter is set to ";"
	char *storeVar;
	strcpy(row,"");
	int i;
	
	FILE *file_pointer = fopen("user.txt", "r"); //opens user.txt to read
	
	if(file_pointer != NULL)
	{
		while(fgets(row,sizeof(row),file_pointer))
		{
			row[strcspn(row, "\n")] = 0; //removes the new line
			
			strcpy(user[*index].Username,strtok(row, delimiter));
			strcpy(user[*index].Full_Name, strtok(NULL, delimiter));
			strcpy(user[*index].Password, strtok(NULL, delimiter));
			strcpy(user[*index].Security_Question, strtok(NULL, delimiter));
			strcpy(user[*index].Security_Answer, strtok(NULL, delimiter));
			strcpy(user[*index].Description, strtok(NULL, delimiter));
			strcpy(user[*index].Account_Status, strtok(NULL, delimiter));
		
			
			user[*index].num_Connections = 0; //declares value
			
			for(i = 0; i < 10; i++)
			{
				storeVar = strtok(NULL, delimiter); // personal connection
				if(storeVar != NULL) // if there is a personal connection
				{
					strcpy(user[*index].Connections[i], storeVar); // copies the personal connection to the user Structure
                    user[*index].num_Connections++; //increments based on how many personal connections user has
				}
				else // if there is no personal connection
				{
					strcpy(user[*index].Connections[i], "");
				}
			}
			(*index)++; //increments based on how many registered users there are
		}
		
		fclose(file_pointer); //closes user.txt
	}
	else
	{
		printf("Error opening file\n");
	}

}

/***************************************************************************************

	Save_User_File() function writes and saves every user into the user.txt file, including
	the delimiter ";"

	@param Total_Users_Index - integer containing the total amount of 
	registered users

****************************************************************************************/

void Save_User_File(int Total_Users_Index)
{
    FILE *file_pointer = fopen("user.txt", "w"); //opens user.txt to write
    int i, j;

    if(file_pointer != NULL)
    {
	    for (i = 1; i < Total_Users_Index; i++)
        {
            // writes each user and adds delimiter ";"
            fprintf(file_pointer, "%s;%s;%s;%s;%s;%s;%s", user[i].Username, user[i].Full_Name, user[i].Password, user[i].Security_Question, user[i].Security_Answer, user[i].Description, user[i].Account_Status);
            
            if (user[i].num_Connections > 0) // if user has any personal connections
			{
                fprintf(file_pointer, ";"); // adds delimiter 
                for (j = 0; j < user[i].num_Connections; j++) 
				{
                    fprintf(file_pointer, "%s", user[i].Connections[j]); //adds personal connection
                    
                    if(j < user[i].num_Connections - 1)
                    {
                    	fprintf(file_pointer, ";"); // adds delimiter 
					}
                }
            }

            fprintf(file_pointer, "\n"); // adds a newline after each user
        }
        fclose(file_pointer); //closes user.txt
    }
    else
    {
        printf("Error opening file\n");
    }

}

/***************************************************************************************

	Load_Secret_Password() function opens and reads the admin_password.txt file that
	contains the password to access admin moduel

	@param secret_password - 
	
****************************************************************************************/

void Load_Secret_Password(char secret_password[])
{
    FILE *file_pointer;
    
    file_pointer = fopen("admin_password.txt", "r"); //opens and reads admin_password.txt
    
    if (file_pointer != NULL)
    {
        if (fgets(secret_password, 100, file_pointer) != NULL)
        {
            secret_password[strcspn(secret_password, "\n")] = '\0'; //replaces newline with NULL
        }
        fclose(file_pointer); //closes admin_password.txt
    }
    else
    {
        printf("Error opening file\n");
    }
}

/***************************************************************************************

	Save_Secret_Password() function writes and saves the admin_password.txt file after
	a modification
	
****************************************************************************************/

void Save_Secret_Password(char secret_password[])
{
    FILE *file_pointer;
    
    file_pointer = fopen("admin_password.txt", "w"); // opens admin_password.txt to write
    
    if (file_pointer != NULL)
    {
        fprintf(file_pointer, "%s\n", secret_password);  //writes admin password into admin_password.txt
        fclose(file_pointer); //closes admin_password.txt
    }
    else
    {
        printf("Error opening file\n");
    }
}

/***************************************************************************************

	Load_Requests() function opens and reads the request_password.txt file that
	contains the list of users who requested a password reset
	
****************************************************************************************/

void Load_Requests()
{
	FILE *file_pointer;
	char row[1000];
	user_requests.num_requests = 0;
	
	file_pointer = fopen("request_password.txt", "r"); // opens request_password.txt to read
	if(file_pointer != NULL)
	{
		while(fgets(row, sizeof(row), file_pointer) != NULL)
		{
			row[strcspn(row, "\n")] = 0; //removes the new line
			
			if(user_requests.num_requests < MAX_USERS)
			{
				strcpy(user_requests.username[user_requests.num_requests], row); 
				user_requests.num_requests++; //increments based on number of password reset request
			}
			else  //if requests exceed 30 users
			{
				printf("Max requests reached!\n");
			}

		}
		fclose(file_pointer); // closes request_password.txt
	}
	else
	{
		printf("Error opening file\n");
	}
}

/***************************************************************************************

	Save_Requests() function writes and saves the request_password.txt file after
	a modification
	
****************************************************************************************/

void Save_Requests()
{
	FILE *file_pointer;
	int i;
	
	file_pointer = fopen("request_password.txt", "w"); //open request_password.txt to write
	
	if(file_pointer != NULL)
	{
		for(i = 0; i < user_requests.num_requests; i++)
		{
			//writes all users that requested into request_password.txt file
			fprintf(file_pointer, "%s\n", user_requests.username[i]); 
		}
		fclose(file_pointer); //closes request_password.txt
	}
	else
	{
		printf("Error opening file\n");
	}
}


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


/*****************************************************************************************************************************
	Save_Message_File() function saves all the messages made by the user to 
	the messages.txt file. 
	
	@param message_entries - array of structures containing user's message details (sender, recipient, message, etc)

	@param msgCount - pointer to an integer containing the total number of messages of all users

*******************************************************************************************************************************/

void Save_Message_File(messageTag message_entries[MAX_MSSG_COUNT],int msgCount){
	
	FILE *file_ptr = fopen("messages.txt", "wt");
	int i, j;
	

	if (file_ptr != NULL)
	{

		fprintf(file_ptr,"%d\n",msgCount); //total number of messages in the system
	
		for (i = 0;i < msgCount;i++){ //saves message details
			fprintf(file_ptr,"%s\n", message_entries[i].Sender);
			fprintf(file_ptr,"%s\n", message_entries[i].Subject);
			fprintf(file_ptr,"%d\n", message_entries[i].ancFlag);
			fprintf(file_ptr,"%d\n", message_entries[i].numOfRecipients);
			for (j = 0;j < message_entries[i].numOfRecipients;j++) {
				fprintf(file_ptr,"%s\n", message_entries[i].Recipients[j]);
			}
			fprintf(file_ptr,"%d\n", message_entries[i].numOfMsgLines); //saves message contents 
			for (j = 0;j < message_entries[i].numOfMsgLines;j++) {
				fprintf (file_ptr,"%s\n", message_entries[i].strMsgEntries[j]);
			}
		}
		
		fclose(file_ptr);
	}
	else
		printf ("Error generating %s\n","messages.txt");
}

/*****************************************************************************************************************************
	Load_User_File() function accesses the user text file
	
	@param user_entries - array of structure containing user details (username, password, full name, etc)
	@param usrCount - pointer to an integer containing the total number of registered users

*******************************************************************************************************************************/

void Load_User_File(User_Details user_entries[MAX_USERS],int *usrCount){
		int index=0;
		
		
		FILE *user_fptr;
		user_fptr = fopen(USER_FILE, "rt");
		char delimiter[] = ";";
		char row[1000];
        strcpy(row,"");
					
		while(fgets(row,sizeof(row),user_fptr) >0 ){
			user_entries[index].User_Index=index;
			strcpy(user_entries[index].Username,strtok(row, delimiter));
			strcpy(user_entries[index].Full_Name, strtok(NULL, delimiter));
			strcpy(user_entries[index].Password, strtok(NULL, delimiter));
			strcpy(user_entries[index].Security_Question, strtok(NULL, delimiter));
			strcpy(user_entries[index].Security_Answer, strtok(NULL, delimiter));
			strcpy(user_entries[index].Description, strtok(NULL, delimiter));
			strcpy(user_entries[index].Account_Status, strtok(NULL, delimiter));
			index++;
		}
	
	*usrCount = index;
	fclose(user_fptr);
	
}
