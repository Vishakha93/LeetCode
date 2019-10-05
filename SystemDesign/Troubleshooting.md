What steps can you perform to troubleshoot an application?

1. Look at the uniform Healthcheck API for any failing services
   It's a binary check, may be simple ping command. Checks for 2 things - whether its up and its operational
   
2. Look at different metrics/dashboards which you have configured
   i)  Latency of each service
   ii) Throughput of your service
   
3. Monitoring Logs
   i) Web Server Logs - May be firewall issue
   ii) Application Server/Service Logs - May be some special character in file reading is failing, 3rd party services are failing, 
   iii) Database Logs - May be transaction logs are full, may be lot of exclusive locks, may be a long stored proc is running
