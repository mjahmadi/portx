#ifndef _PORTX_H
#define _PORTX_H


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <getopt.h>
#include <unistd.h>
#include <stdbool.h>
#include <ctype.h>

#if defined(_WIN32) || defined(_WIN64)

#elif defined(__linux__)
	#include <sys/socket.h>
	#include <netdb.h>
#else
	#error "Currently only Windows and Linux are supported!"
#endif


#define MIN_PORT_NUM 20
#define MAX_PORT_NUM 1024


#include "net.h"
#include "ports.h"
#include "helpers.h"
#include "about.h"


#endif //_PORTX_H

