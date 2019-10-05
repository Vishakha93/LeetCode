Data Partitioning is a technique to break up a big database into many smaller parts across multiple machines.
After certain scale point, horizontal scaling is better than vertical scaling.

## Partitioning Schemes

1. Horizontal Partitioning/Range Based Partitioning/Data Sharding
Put different rows(different ranges of data) in different tables.

Example - Storing different locations
Table 1 - Locations with ZipCode less than 10000
Table 2 - Locations with ZipCode greater than 100000
Assumption - Places will be evenly distributed across the different zip codes

Problems - Partitioning scheme may lead to unbalanced servers if the value whose range is used for partitioning has unbalanced data. Assumption is invalid. Manhattan has lots of places as compared to suburbs.

2. Vertical Partitioning
Store tables related to a specific feature in their own server.
Example - Instagram - Profile info on one DB, Friend lists on another, Photos on 3rd server

Problems - If app experiences additional growth, it may be needed to further partition a feature specific DB across various servers. Single server cannot handle 10 billion photos by 140 million people.

3. Directory Based Partitioning
* To find our where a particular data entity resides, query the directory server that holds a mapping between each tuple key to its DB server. 
* It is better than above 2 because we can perform tasks like adding servers to the DB pool or changing the partioning scheme without any impact on the application






