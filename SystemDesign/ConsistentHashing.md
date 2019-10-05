Hash Table -> key, value, hash function
index = hashfunction(key)

## Design Distributed Cache, given 'n' cache servers

##### Intuitive Hash Function = Key%n
Drawbacks
1. If a new server is added, all existing mappings are broken, needs downtime and remapping
2. Keys may not be uniformly distributed. Some servers - hot and saturated while others - idle and empty

##### Choose Good Hash Function
This approach will solve problem 2 but not problem 1

##### Consistent Hashing
Uses
1. Distributed Caching System - Ex. While setting up memcache for an application on multiple servers
2. Distributed Hash Table
3. Content Delivery Networks

* Goal - Minimize reorganization when nodes are added or removed
* Only k/n keys needs to be remapped
* Objects are mapped to the same host if possible
* When a host is added, it takes its share from other hosts without touching other's shares
* When a host is removed, other nodes take up its shares

Implementation

* HashFunction: key -> [0, 256)
* Integers [0, 256) are mapped on a circle
* Given a list of cache servers(A, B, C), hash them to integers in the range
* To map a key to a server:
  * hash it to a single integer
  * Move clockwise on the ring until finding the first cache it encounters
  * that cache is the one which contains the key
* To add a new server, say D, 
  * Keys that were originally residing on C will be split
  * Some of them will be shifted to D while other keys will not be touched
* To remove a server, say A, 
  * All keys that were originally mapped to A will be mapped to B
* Instead of mapping a cache to a single point on the ring, add virtual replicas, thus associating each cache to multiple portion in the string

##### Follow Up Questions

* What's the best way to deal with servers of different sizes?
* How to add/remove more than one machine at a time?
* How to cope with replication and fault tolerance?
* How to migrate data when jobs are going on?
* How to backup a distributed dictionary in the best way?

  
  


