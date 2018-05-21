#ifndef _PORTS_H
#define _PORTS_H


typedef struct port {
	int port_num;
	char *name;
	char *protocol;
	char *description;
};

const struct port port_list[] = {
	{20, "FTP"},
	{21, "FTP Command"},
	{80, "HTTP"},
	
	{NULL, NULL}
};

#endif //_PORTS_H

