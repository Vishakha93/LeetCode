### Redundancy
* Duplicating the critical components/nodes of a system (in case one fails) for improving reliability
* Example - 2 instances of a service running in production (primary and secondary), primary fails failover to other one

### Replication 
* Replication is also redundancy as it involves duplication of nodes. But it also involves synchronizatio of states between redundant nodes, such as software and hardware components, to improve reliability/fault tolerance
* Used in DBMS/Message Queues where if one node in cluster fails, cluster survives
Active Replication - Message goes to each node so always in sync
Passive Replication - Master-slave architecture. Master receives updates and then it is rippled to slaves. Slaves acknowledge receiving and then get subsequent updates, thus eventually consistent.

https://peterdaugaardrasmussen.com/2018/03/26/difference-between-redundancy-and-replication/

