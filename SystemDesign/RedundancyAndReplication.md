Redundancy - Duplicating the critical components of a system for improving reliability
Example - 2 instances of a service running in production (primary and secondary), primary fails failover to other one

Replication - Sharing info to ensure consistency between redundant resources, such as software and hardware components, to improve reliability/fault tolerance
Used in DBMS with master-slave architecture. Master receives updates and then it is rippled to slaves. Slaves acknowledge receiving and then get subsequent updates.

