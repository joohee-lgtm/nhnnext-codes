#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main (int ac, char* av[]) {
	    int socket_handle;
		    struct sockaddr_in socket_details;
			    char* input_buffer;
				    char httpget[] = "GET / HTTP/1.1\r\n\r\n";
					    
					    input_buffer = malloc (20000);
						    
						    socket_handle = socket (AF_INET, SOCK_STREAM, 0);
							    socket_details.sin_family = AF_INET;
								    socket_details.sin_addr.s_addr = inet_addr ("74.125.128.106");
									    socket_details.sin_port = htons(80);
										    
										    connect (socket_handle,(struct sockaddr*)&socket_details, sizeof ( struct sockaddr));
											    send (socket_handle , httpget, strlen(httpget), 0 );
												    recv (socket_handle , input_buffer , 20000, 0 );
													    printf ("%s\n", input_buffer );
														    
														    return 0 ;
}
