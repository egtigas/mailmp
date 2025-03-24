
/***************************************************************************************

	Load_Users() function 

	@param user_index - integer containing the user's personal index
	
	@param Total_Users_Index - integer containing the total amount of 
	registered users

****************************************************************************************/

void Load_Users(int *index)
{
	*index = 1;
	char row[1000];
	char delimiter[] = ";";
	char *storeVar;
	strcpy(row,"");
	int i;
	
	FILE *file_pointer = fopen("user.txt", "r");
	
	if(file_pointer != NULL)
	{
		while(fgets(row,sizeof(row),file_pointer))
		{
			row[strcspn(row, "\n")] = 0;
			
			strcpy(user[*index].Username,strtok(row, delimiter));
			strcpy(user[*index].Full_Name, strtok(NULL, delimiter));
			strcpy(user[*index].Password, strtok(NULL, delimiter));
			strcpy(user[*index].Security_Answer, strtok(NULL, delimiter));
			strcpy(user[*index].Description, strtok(NULL, delimiter));
			strcpy(user[*index].Account_Status, strtok(NULL, delimiter));
		
			
			user[*index].num_Connections = 0;
			
			for(i = 0; i < 10; i++)
			{
				storeVar = strtok(NULL, delimiter);
				if(storeVar != NULL)
				{
					strcpy(user[*index].Connections[i], storeVar);
                    user[*index].num_Connections++;
				}
				else
				{
					strcpy(user[*index].Connections[i], "");
				}
			}
			(*index)++;
		}
		
		fclose(file_pointer);
	}
	else
	{
		printf("Error opening file\n");
	}

}

void Save_User_File(int Total_Users_Index)
{
    FILE *file_pointer = fopen("user.txt", "w");
    int i, j;

    if(file_pointer != NULL)
    {
	    for (i = 1; i < Total_Users_Index; i++)
        {
            
            fprintf(file_pointer, "%s;%s;%s;%s;%s;%s", user[i].Username, user[i].Full_Name, user[i].Password, user[i].Security_Answer, user[i].Description, user[i].Account_Status);
            
            if (user[i].num_Connections > 0) 
			{
                fprintf(file_pointer, ";"); 
                for (j = 0; j < user[i].num_Connections; j++) 
				{
                    fprintf(file_pointer, "%s", user[i].Connections[j]); 
                    
                    if(j < user[i].num_Connections - 1)
                    {
                    	fprintf(file_pointer, ";");
					}
                }
            }

            fprintf(file_pointer, "\n"); 
        }
        fclose(file_pointer);
    }
    else
    {
        printf("Error opening file\n");
    }

}

void Load_Secret_Password(char secret_password[])
{
    FILE *file_pointer;
    
    file_pointer = fopen("admin_password.txt", "r");
    
    if (file_pointer != NULL)
    {
        if (fgets(secret_password, 100, file_pointer) != NULL)
        {
            secret_password[strcspn(secret_password, "\n")] = '\0'; 
        }
        fclose(file_pointer);
    }
    else
    {
        printf("Error opening file\n");
    }
}

void Save_Secret_Password(char secret_password[])
{
    FILE *file_pointer;
    
    file_pointer = fopen("admin_password.txt", "w");
    
    if (file_pointer != NULL)
    {
        fprintf(file_pointer, "%s\n", secret_password); 
        fclose(file_pointer);
    }
    else
    {
        printf("Error opening file\n");
    }
}
