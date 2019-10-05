Data Partitioning is a technique to break up a big database into many smaller parts across multiple machines.
After certain scale point, horizontal scaling is better than vertical scaling.

## Partitioning Schemes

#### Horizontal Partitioning/Range Based Partitioning/Data Sharding
* Put different rows(different ranges of data) in different tables.

* Example - Storing different locations
Table 1 - Locations with ZipCode less than 10000
Table 2 - Locations with ZipCode greater than 100000
Assumption - Places will be evenly distributed across the different zip codes

* Problems - Partitioning scheme may lead to unbalanced servers if the value whose range is used for partitioning has unbalanced data. Assumption is invalid. Manhattan has lots of places as compared to suburbs.

#### Vertical Partitioning
* Store tables related to a specific feature in their own server.
Example - Instagram - Profile info on o
ne DB, Friend lists on another, Photos on 3rd server

* Problems - If app experiences additional growth, it may be needed to further partition a feature specific DB across various servers. Single server cannot handle 10 billion photos by 140 million people.

#### Directory Based Partitioning
* To find our where a particular data entity resides, query the directory server that holds a mapping between each tuple key to its DB server. 
* It is better than above 2 because we can perform tasks like adding servers to the DB pool or changing the partioning scheme without any impact on the application
* Increases system complexity and becomes single point of failure

## Partitioning Criterias in case of Horizontal Partitioning

#### Hash Based Partitioning
100 DB Servers, Numeric ID Column
Server where we can stored recored with key ID1 = ID1 % 100
Problem: If new server is added, all records need to be rehashed -> redistribution of data -> downtime
Solution: Consistent Hashing

#### List Partitioning
Each partition is assigned a list of values. Ex - the ZipCode one, all users living in Iceland, Norway, Sweden, Finland and Denmark will be stored in the partition for Nordic Countries

#### Round Robin Partitioning
Tuple i stored at i%100

#### Composite Partitioning
Devise a new scheme. Ex - Consistant Hashing = Composite of Hash and List Partitioning

## Problems of Data Partitioning

#### Joins and Denormalization
Joins span acrossing multiple partitions is not feasible.
Solution - Denormalize the database so that joins are not needed. But this will lead to Data inconsistencies.

#### Referential Integrity
Enforcing data integrity constraints on a partitioned database can be extremely difficult.
Example - Most RDBMS do not support foreign key across DBs on different machines
Solution - Enforce it in application code


#### Rebalancing
* When data distribution is not uninform. Ex - ZipCode case
* When there is a lot of load on one partition. Ex - all photos on single DB

Solution: Rebalance(move data, thus downtime) or create more DB partitions. Use directory based partitioning.






