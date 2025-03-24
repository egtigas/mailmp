void View_Annoucements(messageTag message_entries[MAX_MSSG_COUNT],int *msgCount,int user_index,int userCount){
	int i,j=0, k=0;
	int select=1, count;
	int num[30];

	printf("=====================================================\n");
	printf("                   VIEW ANNOUNCEMENTS                      \n");
	printf("=====================================================\n");
	
	while(select>-1){
		for(i=0;i<*msgCount;i++){
			if(message_entries[i].ancFlag==1){
				printf("[%d] %s\n", i+1, message_entries[i].Subject);
				num[j] = i;
				//printf("NUM %d IS %d\n",j, num[j]);
				j++;
				k++;
			}
		}
		
		printf("Input (Enter 0 to Go Back): ");
		scanf("%d", &select);
		select = select-1;
		count = 0;
		
		for(j=0;j<k;j++){
			if(select==num[j] && count==0){
				printf("select: %d\n", select);
				if(select>-1){
					printf("SELECT IS %d\n", select);
					printf("NUM IS %d\n", num[j]);
					printf("From: %s\n", message_entries[select].Sender);
					printf("Subject: %s\n", message_entries[select].Subject);
					for(i=0;i<message_entries[select].numOfMsgLines;i++){
						printf("%s\n", message_entries[select].strMsgEntries[i]);
					}
					
					printf("[1] Reply\n");
					printf("[0] Back\n");
					printf("Input: ");
					scanf("%d", &select);
					
					count = 1;
				
					if(select == 1){
						Compose_Message(message_entries,user[user_index].Username,msgCount,1,userCount);
					}
				}
			}
			/*if(select!=num[j] && count==0){
				printf("Invalid Input\n");
				count=1;
			}*/
		}
	}

}