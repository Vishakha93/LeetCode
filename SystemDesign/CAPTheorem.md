## CAP Theorem
Impossible for a distributed system to simultaneously provide more than 2 out of the following 3 gurantees (CAP):
Consistency, Availability, Partition Tolerance

Consistency
All users see the same data at the same time. Consistency is achieved by updating several nodes before allowing further reads.

Availability
System continues to function even with node failures. Every request gets a response(success/failure). Availability is achieved by replicating the data across different servers.

Partition Tolerance
System continues to function even if the communication fails between the nodes.
Ex - A system that is partially tolerant can sustain any amount of network failure that doesn't result in failure of entire network.
This is achieved by replicating the data sufficiently across combination of nodes and networks such that it can survive intermittent outages

To be consistent, all nodes should see the same set of updates in same order. But if the network suffers a partition, updates in one partition
might not make it to the other partitions. A client may read stale data from the out-of-date partition. The only way to fix this is to stop serving
request from that partition. But then the system is not 100% available.

RDBMS -> Availability, Consistency
Cassandra, CouchDB -> Availability and Partition Tolerance
BigTable, HBase, MondoDB -> Consistency, Partition Tolerance

## Interesting Reads
https://stackoverflow.com/questions/39919815/whats-the-difference-between-bigquery-and-bigtable


