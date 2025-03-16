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
} user[MAX_USERS];

struct Announcement_Details
{
	char Sender[100];
	char Subject[100];
	char Message[MAX_MSSG_CHAR];
} Announcement[MAX_MSSG_COUNT];

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
void Compose_Message();
void Save_Message_File();
int main();
