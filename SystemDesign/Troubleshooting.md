What steps can you perform to troubleshoot an application?

1. Get an alert from fabrics

2. Look for external dependency failing by looking at the uniform Healthcheck API for any failing services
   It's a binary check, may be simple ping command. Checks for 2 things - whether its up and its operational
   
3. Look for internal dependency failing by looking at different metrics/dashboards which you have configured
   i)  Latency of each service
   ii) Throughput of your service
   
4. Monitoring Logs
   i) Web Server Logs - May be firewall issue
   ii) Application Server/Service Logs - May be some special character in file reading is failing, 3rd party services are failing, 
   iii) Database Logs - May be transaction logs are full, may be lot of exclusive locks, may be a long stored proc is running
