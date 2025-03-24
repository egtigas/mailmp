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

typedef char String100[101];

struct messageTag
{
	String100 Sender;
	String100 Subject;
	int ancFlag;
	int numOfRecipients;
	String100 Recipients[MAX_USERS];
	int numOfMsgLines;
	String100 strMsgEntries[MAX_LINES];
};

typedef struct messageTag messageTag;

struct User_Details
{
	int User_Index;
    char Username[100];
    char Full_Name[50];
    char Password[50];
	char Security_Question[100];
    char Security_Answer[50];
	char Description[100];
	char Connections[10][100];
	int num_Connections;
	char Account_Status[20];
} user[MAX_USERS];

typedef struct User_Details User_Details;

/*
struct Announcement_Details
{
	char Sender[100];
	char Subject[100];
	char Message[MAX_MSSG_CHAR];
} Announcement[MAX_MSSG_COUNT];
*/

// Common functions
void clean(String100 strTemp)
{
	int len = strlen(strTemp);
	int lastIndex = len-1;
	
	if (lastIndex >= 0 && strTemp[lastIndex] == '\n')
		strTemp[lastIndex] = '\0';
}


void User_Page();
void Browse_Users();
void forgot_password();
void Modify_Account_Security();
void Modify_Personal_Contents();
void Modify_Personal_Connections();
void Compose_Message();
void Save_Message_File();
void Load_Message_File();
void Load_User_File();
void Print_Message_File(); //For debugging only
void View_Annoucements();
void Admin_User_Page();
void Load_Users();
void Save_User_File();
void Change_Admin_Password();
void View_Sent_Messages();
void View_Inbox();
void Reply_Message();
void Admin_Messages_Page();
void Admin_View_Message();
int Admin_Delete_Message();
//int userCount; // fix?
int main();
