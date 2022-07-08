#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>




//---------------------------------------------------------------------------------------------------------------------

void mySockate1(int port1,  char *address1);


int main(int argc, char *argv[])
{

	
	
	if(argc < 2)
	{
		printf("****************************************************************************\n");
		printf("******Syntax*Error!*********************************************************\n");
		printf("**Try some like that:*******************************************************\n");
		printf("***~#./file 192.168.0.1*****************************************************\n");
		printf("****************************************************************************\n");
		exit(1);
		
	}
	
	
	
	else if(strcmp("--help", argv[1]) == 0)
	{
		printf("********************************************************************************\n");
		printf("******The help !****************************************************************\n");
		printf("**Try some like that:***********************************************************\n");
		printf("***~# [program] [options] [ip-address]******************************************\n");
		printf("Options:\n");
		printf("	 -p, --port		Set a port tcp or udp\n");
		printf("	 -r, --range		Set a range of port; [program] -r 1 23 | 1 to 23\n");
		exit(1);		
	}
	else if(strcmp("-p", argv[1]) == 0)
	{
		//--GETTING PARAMETERS VALUES
		char *optport;
		char *saddress;
		
		optport = argv[2];		
		saddress= argv[3];
		
		//-COnvert CHAR TO INT--------
		int sport = atoi(optport);
		
		//--SOCKET
		
		mySockate1(sport, saddress);

	
	
	}
	else if(strcmp("-r", argv[1]) == 0)
	{
		int x;
		int ini = atoi(argv[2]);
		int fin = atoi(argv[3]);
		
		
		for(x = ini; x <= fin; x++)
		{
			//--GETTING PARAMETERS VALUES
			char *saddress;	
			saddress= argv[4];
		
			//-COnvert CHAR TO INT--------
		
		
			//--SOCKET
			mySockate1(x, saddress);
		}
	}
	
	
		
	return(0);	
}







void mySockate1(int port1,  char *address1)
{


	int sport;
	char *saddress;
	
	sport = port1;		
	saddress = address1;
	
	//-COnvert CHAR TO INT--------
		


	int myconnect;
	int mysocket;
	struct sockaddr_in goal;
	
	
	mysocket = socket(AF_INET, SOCK_STREAM, 0);
	if(mysocket < 0)
	{
		printf("Error!\n");
		close(mysocket);
		exit(1);
	}
	
	goal.sin_family = AF_INET;
	goal.sin_port = htons(sport);
	goal.sin_addr.s_addr = inet_addr(saddress);
	bzero(&(goal.sin_zero), 8);
	
	
	myconnect = connect(mysocket,(struct sockaddr *)&goal, sizeof(goal));
	
	if(myconnect < 0)
	{
		printf("Port %d closed\n", sport);
		close(mysocket);
		
	}
	else
	{
		printf("Port %d open\n", sport);
		close(mysocket);
					
	}


}

