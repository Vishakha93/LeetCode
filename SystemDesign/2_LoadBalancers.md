Load Balancer improves the scalability(horizontal scaling), availability and responsiveness of an application by
1. Distributing the traffic
2. Track status of servers. Stop sending traffic to server which has elevated error rate or is not responding.

We can add LBs at 3 places
1. Between the user and the web server
2. Between the web server and an internal platform layer like application server or cache servers
3. Between the internal platform layer and database

### Benefits of Load Balancing

* Users - Experience faster(higher throuput) and uninteruppted(less downtime) service. Users won't have to wait for a single server to finish its previous tasks.
* Organization - Smart LBs provide predict traffic bottlenecks which are about to happen, providing actionable insights
* System Admins - Experience fewer failed and stressed components

### LB Algorithms

LBs only forward traffic to healthy backend servers. Different LB algorithms -
1. Least Connection Method - Direct traffic to the server with fewest active connections. Useful when there are large number of persistant connections

2. Least Response Time Method - Direct traffic to server with fewest active connections and lowest average response time.

3. Least Bandwidth Method - This method selects the server that is currently serving the least amount of traffic measured in megabits per second.

4. Round Robin Method - Used when servers are of equal specifiction and less persistant connections

5. Weighted Round Robin Method - To better handle servers with different processing capabilities. Servers with large capability receives larger traffic.

### Redundant Load Balancers

The LB can be a single point of failure. Thus we keep 2 LB, one active and other passive.Each LB looks at health check of each other. In case of failure detection, the main load balancer fails and second LB takes over.










