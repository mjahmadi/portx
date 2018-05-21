#ifndef _NET_H
#define _NET_H


void do_port_ping (char *the_name, int port_number)
{
	int                  my_socket;
	char               **pointer_pointer;
	char                 answer[INET_ADDRSTRLEN];
	struct hostent      *returned_host;
	struct sockaddr_in   outgoing_address;
	
	printf("\ndestination         : %s:%d\n", the_name, port_number);

	returned_host = gethostbyname(the_name);
	if (returned_host==NULL)
	{
		fprintf(stderr,"error %d\n", h_errno);

		return;
	}

	printf("host's official name: %s\n", returned_host->h_name);

	for (pointer_pointer=returned_host->h_aliases; *pointer_pointer; pointer_pointer++)
	{
		printf("alias               : %s\n", *pointer_pointer);
	}

	for (pointer_pointer=returned_host->h_addr_list; *pointer_pointer; pointer_pointer++)
	{
		inet_ntop(AF_INET, (void *)*pointer_pointer, answer, sizeof(answer));

		printf("IP address          : %s\n", answer);

		my_socket = socket(AF_INET, SOCK_STREAM,0);

		if (my_socket<0)
		{
			perror("socket()");
			return;
		}

		memset(&outgoing_address, 0, sizeof(outgoing_address));
		outgoing_address.sin_family = AF_INET;
		outgoing_address.sin_port = htons(port_number);

		memmove(&outgoing_address.sin_addr, *pointer_pointer, sizeof(&outgoing_address.sin_addr));

		if(connect(my_socket, (struct sockaddr*)&outgoing_address, sizeof(outgoing_address)))
		{
			perror("connect()");
			return ;
		}
	}


}



#endif //_NET_H
