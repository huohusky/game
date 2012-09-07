#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
	int servfd, clifd, length = 0;
	struct sockaddr_in servaddr, cliaddr;
	socklen_t soclen = sizeof(servaddr);
	char buf[255];

	if(argc < 2)
	{
		printf("error \n");
		exit(1); 
	}

	if((clifd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		printf("socket error \n");
		exit(1);
	}

	bzero(&cliaddr, sizeof(cliaddr));
	cliaddr.sin_family = AF_INET;
	cliaddr.sin_port = htons(20002);
	cliaddr.sin_addr.s_addr = htons(INADDR_ANY);


	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	inet_aton(argv[1], &servaddr.sin_addr);
	servaddr.sin_port = htons(20000);
	//cliaddr.sin_addr.s_addr = htons(INADDR_ANY);

	if(bind(clifd, (struct sockaddr*)&cliaddr, sizeof(cliaddr)) < 0)
	{
		printf("bind error \n");
		exit(1);
	}

	if(connect(clifd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0)
	{
		exit(1);
	}

	length = recv(clifd, buf, 255, 0);

	if(length < 0)
	{
		exit(1);
	}
	
	printf("from server %s :\n \t %s", argv[1], buf);

	close(clifd);

	return 0;
}
