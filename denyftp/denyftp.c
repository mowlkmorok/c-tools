#include <stdio.h>
#include <stdlib.h>


void dosftp(int s_port, char *s_address);


int main(int argc, char *argv[])
{
	char *saddress;
	saddress = argv[2];
	
	int sport;
	
	sport = atoi(argv[1]);

//	printf("port %d address: %s\n", sport,saddress);

	dosftp(sport,saddress);	
		

}



void dosftp(int s_port, char *s_address)
{
	char *saddress;
	int sport;
	
	sport = s_port;
	saddress = s_address;
	
//	printf("port %d address: %s\n", sport,saddress);

//---	SOCKET --------------------------------------------------------------


	int mysocket;
	int myconnect;
	
	struct sockaddr_in goal;
	
	
	mysocket = socket(AF_INET, SOCK_STREAM, 0);
	if(mysocket < 0)
		printf("Error in connection!\n");
		exit(1);
		
		
	goal.sin_family = AF_INET;
	goal.sin_port = htons(sport);
	goal.sin_address.s_addr = inet_addr(saddress);
	bzero(&(goal.sin_zero),8);
	
	
	myconnect = connect(mysocket(struct sockaddr *)&goal, );
	if(myconnect < 0)
		printf("Error in connection!\n");
		exit(1);
	

//---	FIN SOCKET ----------------------------------------------------------

}



