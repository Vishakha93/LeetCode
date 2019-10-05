Proxy Servers are used to filter requests, log requests, transform requests(add/remove headers, encrypt/decrypt, compress resource)

## Forward Proxy
* Sits in front of a group of client machines. User's home computer -> Forward Proxy -> Internet -> Website Origin
* Benefits
  * To avoid state or institutional browsing restrictions - Govs/Schools use firewall to provide limited access to internet content.
    You can use forward proxy like pidgin, tor to get around that
  * To block access to a certain content - A school network might be configured to connect to the web through proxy, thus refusing social media requests
  * To protect their identity online - If forward proxy is used to make a polictical comment on web forum, tracing IP back is harder
  
## Reverse Proxy

* Sits in front of one or more web server intercepting client requests. Ensure no client communicates to origin server directly
  User's home computer -> Internet -> Reverse Proxy -> Website Origin
* Benefits
  * Load Balancing - Use Apache in reverse proxy
  * Protection from attacks - A website never needs to reveal the IP address of origin server. Attackers cannot do DDoS attack on origin servers.
  * Global Server Load Balancing - Reverse proxy will send client to the server which is geographically closest
  * Caching - Cache content for subsequent access
  * SSL Encryption - Encrypting all outgoing responses and Decrypting all incoming requests (SSL communications) for each client can be expensive on origi server
