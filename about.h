#ifndef _ABOUT_H
#define _ABOUT_H


#define APP_NAME 	"portx"
#define APP_VERSION "0.0.1"


void print_version(void)
{
	printf("%s %s\n"
			"Copyright (C) 2018.\n"
			"This is free software; see the source for copying conditions."
			"There is \nNO warranty; not even for MERCHANTABILITY or FITNESS"
			"FOR A PARTICULAR PURPOSE.\n", APP_NAME, APP_VERSION);
			
	printf("Written by Mohammad Javad Ahmadi.\n");
	
	exit(EXIT_SUCCESS);
}


void print_usage(int exit_code)
{
	printf("Usage: ./%s [ip address] [timeout/chunk/ping/start-from/end-to/description]\n\n", APP_NAME);
	exit(exit_code);
}


#endif //_ABOUT_H

