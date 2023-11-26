/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o <abdeel-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 12:45:55 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/11/26 12:29:08 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Header guard
#pragma once

#include "Webserv.hpp"
#include "Location.hpp"

#define SOCKET int
#define ISVALIDSOCKET(s) ((s) != -1)
#define CLOSESOCKET(s) close(s)

#define REQUEST_BUFFER_SIZE 65536

class Server
{
	private:
	// proberties
		in_addr_t 						_host;
		uint16_t 						_port;
		std::vector<std::string> 		_serverNames;
		unsigned long 					_clientBodySizeLimit;
		std::string 					_root;
		std::string 					_index;
		bool 							_autoindex;
		struct sockaddr_in 				_server_address; 
		std::map<short, std::string>	_error_pages;
        SOCKET     						_listen_socket;
		std::vector<Location>			_locations;
		
	public:
	// Constructors
		Server( void );
		~Server( void );
	
	// Getters
	in_addr_t						getHost( void ) const;
	int 							getPort( void ) const;
	std::vector<std::string> 		getServerNames( void ) const;
	int 							getClientBodySizeLimit( void ) const;
	std::vector<Location>			getLocations( void ) const;
	Location						getLocation( int index ) const;
	std::string 					getRoot( void ) const;
	std::string 					getIndex( void ) const;
	bool 							getAutoindex( void ) const;
	int 							getListenFd( void ) const;
	std::map<short, std::string>	getErrorPages( void ) const;
	std::string 					getErrorPage( short number ) const;
	
	// Setters
	void	setHost( std::string );
	void	setPort( std::string );
	void	setServerNames( std::vector<std::string> );
	void	setClientBodySizeLimit( std::string );
	void	setLocations( std::vector<Location> );
	void	setLocation( Location );
	void	setRoot( std::string );
	void	setIndex( std::string );
	void	setAutoindex( bool );
	void	setErrorPage( std::vector<std::string> );
	void	setListenFd( int );
	
	// Operators
	Server &operator=( Server const &rhs );
	Server( Server const &rhs );
	
	// Methods
	void init( void ); // init server
	void acceptConnection( fd_set &set ); // accept connection
	void handleRequest( int fd ); // handle request

	// to be deleted
	void printErrorPages() ;
};
