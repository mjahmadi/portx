#include "portx.h"


int main(int argc, char *argv[])
{
	
    int sock, timeout=5, start_from=MIN_PORT_NUM, end_to=MAX_PORT_NUM, descriptive=false;
    char hostname[INET_ADDRSTRLEN];
   	struct hostent *host;
    struct sockaddr_in sa;
    
	int opt;
	
	const char *short_options = "h:t:s::p::d";
	const struct option long_options[] = {
		{"host",			1, NULL, 'h'},
		{"timeout",			1, NULL, 't'},
		{"scan",			2, NULL, 's'},
		{"ping",			2, NULL, 'p'},
		{"descriptive",		0, NULL, 'd'},
		{"help",			0, NULL, 'H'},
		{"version",			0, NULL, 'V'},
		{NULL,				0, NULL, 0}
	};
	
	while ((opt = getopt_long(argc, argv, short_options, long_options, NULL)) != -1) {
		switch (opt) {
				
			//--host
			case 'h':
				strcpy(hostname, argv[optind - 1]);
				
				//direct ip address, use it
				if (isdigit(hostname[0]))
				{
					sa.sin_addr.s_addr = inet_addr(hostname);
				}
				//Resolve hostname to ip address
				else if ( (host = gethostbyname(hostname)) != 0)
				{
					strncpy((char*)&sa.sin_addr , (char*)host->h_addr, sizeof sa.sin_addr);
				}
				else
				{
					herror(hostname);
					exit(EXIT_FAILURE);
				}
				break;
				
			//--timeout
			case 't':
				timeout = atoi(argv[optind - 1]);
				break;
				
			//--ping
			case 'p':
			
				for (int i=0; i<atoi(argv[optind + 1]); i++)
				{
					do_port_ping(hostname, atoi(argv[optind]));
					if (i < (atoi(argv[optind + 1]) - 1))
					{
						sleep(timeout);
					}
				}
				
				break;
				
			//--scan
			case 's':
				break;
			
			//--descriptive
			case 'd':
				descriptive = true;
				break;
				
			//--help
			case 'H':
				print_usage(EXIT_SUCCESS);
				break;

			//--version
			case 'V':
				print_version();
				break;
				
			default:
				print_usage(EXIT_FAILURE);
				break;
		}
	}
	
	/*
	if (optind < argc) {
		fprintf(stderr, "Expected argument after options.\n");
		exit(EXIT_FAILURE);
	}
	*/
	
	return EXIT_SUCCESS;
}

/*
int main(int argc , char **argv)
{
    //Initialise the sockaddr_in structure
    strncpy((char*)&sa , "" , sizeof sa);
    sa.sin_family = AF_INET;
     
    //direct ip address, use it
    if(isdigit(hostname[0]))
    {
        printf("Doing inet_addr...");
        sa.sin_addr.s_addr = inet_addr(hostname);
        printf("Done\n");
    }
    //Resolve hostname to ip address
    else if( (host = gethostbyname(hostname)) != 0)
    {
        printf("Doing gethostbyname...");
        strncpy((char*)&sa.sin_addr , (char*)host->h_addr , sizeof sa.sin_addr);
        printf("Done\n");
    }
    else
    {
        herror(hostname);
        exit(2);
    }
     
    //Start the port scan loop
    printf("Starting the portscan loop : \n");
    for( i = start ; i <= end ; i++) 
    {
        //Fill in the port number
        sa.sin_port = htons(i);
        //Create a socket of type internet
        sock = socket(AF_INET , SOCK_STREAM , 0);
         
        //Check whether socket created fine or not
        if(sock < 0) 
        {
            perror("\nSocket");
            exit(1);
        }
        //Connect using that socket and sockaddr structure
        err = connect(sock , (struct sockaddr*)&sa , sizeof sa);
         
        //not connected
        if( err < 0 )
        {
            //printf("%s %-5d %s\r" , hostname , i, strerror(errno));
            fflush(stdout);
        }
        //connected
        else
        {
            printf("%-5d open\n",  i);
        }
        close(sock);
    }
     
    printf("\r");
    fflush(stdout);
    return(0);
} 
*/

