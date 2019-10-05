## HTTP Protocol

1. Client opens a connection and requests data from the server
2. The server calculates the response
3. The server sends the response back to the client on the opened request

## Ajax Polling

Client repeatedly opens a connection, requests data from server (say every 0.5s) and closes the connection
Problem: A lot of responses from server are empty, creating HTTP overhead

## HTTP Long-Polling

1. Client opens a connection and requests data from server
2. Server holds the request until content available or timeout
3. Server sends the full response
4. Client immediately sends another request so that server always has a request to work on
5. All requests have timeout. Thus client has to keep on reconnecting.

## Web Sockets

* WebScoket provides a full deuples communication channel ove TCP
* Provides a persistant connection(initially Websocket handshake) between client and server such that both parties can start sending the data at any time
(real time data transfer from and to server)

## Server Sent Events (SSE)
Used when we have to send realtime traffic from server to the client. If a client wants to send data to the server, it would require
another technology or protocol.

1. Client requests data from a server using normal HTTP
2. The requested webpage opens a connection to the server
3. The server sends data to the client whenver there's new information available
