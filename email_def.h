
/*
Maximum no. of Characters for each message / announcements: 1000
Maximum no. of Messages that can exist in the program: 1000
Maximum no. of Users that can be registered: 30
Maximum no. of Characters for passwords: 20
Maximum no. of Characters for Security Questions & Answers: 100
*/


#define MAX_MSSG_CHAR 1000
#define MAX_MSSG_COUNT 1000
#define MAX_USERS 30
#define PASSWORD_LENGTH 30
#define SECURITY_QUESTION_LENGTH 100
#define SECURITY_ANSWER_LENGTH 100
#define MAX_LINES 100  // Max lines per message
#define MESSAGE_FILE "messages.txt"
#define USER_FILE "user.txt"

typedef char String100[100];

/********************************************************************************************

	Structure containing the message details of the program's messaging system. 

**********************************************************************************************/

struct messageTag
{
	String100 Sender; //string containing the username of the person sending the message 
	
	String100 Subject; //string containing the subject/title of the message 
	
	int ancFlag; //integer that determines if the message is an announcement (1) or a personal/group message (0)
	
	int numOfRecipients; //integer that stores the total number of recipients of the message 
	
	String100 Recipients[MAX_USERS]; //array of strings to store the usernames of the recipients per message
	
	int numOfMsgLines; //integer containing the total number of lines in the message 
	
	String100 strMsgEntries[MAX_LINES]; //array of strings containing the contents of the message
};

typedef struct messageTag messageTag;

/********************************************************************************************

	Structure containing all the personal details of the user. 

**********************************************************************************************/

struct User_Details
{
	int User_Index; //contains the index of the user
	
    char Username[100]; //contains the username of the user
    
    char Full_Name[50]; //contains the full name of the user
    
    char Password[50]; //string containing the password of the user
    
    char Security_Answer[50]; //contains the user's answer to security question
    
    char Security_Question[100]; //contains the user's security question
    
	char Description[100]; //contains the users' personal description
	
	char Connections[10][100]; //containins the usernames of the personal connections of the user
	
	int num_Connections; //contains the total number of user's personal connections
	
	char Account_Status[20]; //determines if user's account is "LOCKED" or "UNLOCKED"
	
} user[MAX_USERS]; //only a maximum of 30 users

typedef struct User_Details User_Details;

/********************************************************************************************

	Structure containing the users who have sent a request to the admin to have
	their passwords changed or to have their account unlocked

**********************************************************************************************/


struct Request_Details
{
	char username[MAX_USERS][100]; //array containing the usernames of those who have sent the request
	int num_requests; //total number of requests
} user_requests;

/********************************************************************************************

	clean() function removes the newline character at the end of the string. 
	This allows the user to press enter without ending their input. 

	@param strTemp - contains the string to be "cleaned"

**********************************************************************************************/

void clean(String100 strTemp)
{
	int len = strlen(strTemp);
	int lastIndex = len-1;
	
	if (lastIndex >= 0 && strTemp[lastIndex] == '\n') //if the last character of the string is a newline
		strTemp[lastIndex] = '\0'; //replace last character with null 
}


void forgot_password();
void Find_User();

void Load_Users();
void Save_User_File();
void Load_Requests();
void Save_Requests();
void Save_Message_File();
void Load_Message_File();
void Load_User_File();


void User_Page();
void Compose_Message();
void View_Inbox();
void View_Sent_Messages();
void View_Annoucements();
void Modify_Personal_Contents();
void Modify_Account_Security();
void Modify_Personal_Connections();
void Browse_Users();
int Reply_Message();
void User_Select();
void Modify_Password();
void Add_Personal_Connections();
void Remove_Personal_Connection();
void List_Users();
void Filter_Users();


void Change_Admin_Password();
void Admin_User_Page();
void Admin_Messages_Page();

