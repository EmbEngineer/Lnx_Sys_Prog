#define MSG_SZ   100
typedef struct USER_MSG
{
	int data_available;
	char msg[MSG_SZ];
}User_Msg;
