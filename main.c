#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "email_def.h"
#include "Create_Account.c"
#include "Login_User.c"
#include "User_Page.c"
#include "Browse_Users.c"
#include "forgot_password.c"
#include "Modify_Account_Security.c"
#include "Modify_Personal_Contents.c"
#include "Modify_Personal_Connections.c"
#include "File_Operations.c"
#include "Compose_Message.c"
#include "Save_Message_File.c"
#include "Load_Message_File.c"
#include "Print_Message_File.c"
#include "Admin_Page.c"
#include "Load_User_File.c"
#include "View_Announcements.c"
#include "Admin_User_Page.c"
#include "Change_Admin_Password.c"
#include "View_Sent_Messages.c"
#include "View_Inbox.c"
#include "Reply_Message.c"
#include "Admin_Messages_Page.c"
#include "Admin_View_Message.c"
#include "Admin_Delete_Message.c"

int main()
{
	int choice;
	
	
	system("cls");
	do
	{
		printf("=====================================================\n");
	 	printf("                      MAIN MENU                      \n");
		printf("=====================================================\n");
		printf("[1] Login\n[2] Create New Account\n");
		printf("[3] Request Forgotten Password\n[4] Access Administrator Module\n");
		printf("=====================================================\n\n");
		printf("Input: ");
		scanf("%d", &choice);
		system("cls");
		
		switch(choice)
		{
			case 1:
				Login_User();
				break;
			case 2: 
				Create_Account();
				break;
			case 3: 
				forgot_password();
				break;
			case 4: 
				Admin_Page();
			default: 
				printf("Invalid input. Please try again.\n\n");
		}
		
	}
	while(choice > 0 || choice < 5);      
	
}
