
/*********************************************************************************************************
This is to certify that this project is our own work, based on our personal efforts in studying and applying
the concepts learned. We have constructed the functions and their respective algorithms and corresponding
code by ourselves. The program was run, tested, and debugged by our own efforts. We further certify that We
have not copied in part or whole or otherwise plagiarized the work of other students and/or persons.
Sidney Tigas, DLSU ID# 12415391
*********************************************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <windows.h>

/* header file*/
#include "email_def.h"

/*includes the create account, login, and forgot password functions*/
#include "Main_Menu.c" 

/*includes all load and save functions */
#include "File_Operations.c" 

/* contains all the functions in the user module */
#include "User_Page.c"
#include "Compose_Message.c"
#include "View_Inbox.c"
#include "View_Sent_Messages.c"
#include "View_Announcements.c"
#include "Modify_Personal_Contents.c"
#include "Modify_Account_Security.c"
#include "Modify_Personal_Connections.c"
#include "Browse_Users.c"
#include "Reply_Message.c"

/* contains all the functions in admin module*/
#include "Admin_Page.c"
#include "Admin_User_Page.c"
#include "Admin_Messages_Page.c"
#include "Change_Admin_Password.c"


int main()
{
	int choice, flag = 0;
	
	// Path to the WAV file
    const char *wavFilePath = "TwinkleInTheSky.wav";

    // Play the WAV file
	if (PlaySound(wavFilePath, NULL, SND_FILENAME | SND_ASYNC)) 
		printf("Playing sound: %s\n", wavFilePath);
	else 
		printf("Failed to play sound: %s\n", wavFilePath);
	
	do
	{
		printf("\n======================================================\n");
	 	printf("                        MAIN MENU                      \n");
		printf("======================================================\n");
		printf("[1] Login\n[2] Create New Account\n");
		printf("[3] Request Forgotten Password\n[4] Access Administrator Module\n[5] Exit\n");
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
				break;
			case 5: 
				printf("\033[0;31m"); // red
				printf("Exiting...");
				printf("\033[0m");
				flag = 1;
				break;
			default: 
				printf("\033[0;31m"); // red
				printf("Invalid input. Please try again.\n\n");
				printf("\033[0m");
		}
		
	}
	while(flag == 0);      
	
}
