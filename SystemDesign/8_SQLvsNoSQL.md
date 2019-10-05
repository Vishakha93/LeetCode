## SQL
Each row represents an entity and each column represents a data point about that entity. Each row has same structure.
Relational DB - MySQL, Oracle, SQLite, Postgres

## NoSQL

#### Key Value Stores
Data is stored in an array of key-value pairs. Ex - Redis, DynamoDB

#### Document Databases
Data is stored in documents. Group of documents is collections. Each document can have an entirely different structure.
Example - CouchDB and MongoDB

#### Columnar Database
* Stores data in column instead of rows
* Row Oriented DB - 1,Doe,John,8000;2,Smith,Jane,4000;3,Beck,Sam,1000; 
* Column Oriented - 1,2,3;Doe,Smith,Beck;John,Jane,Sam;8000,4000,1000; 
* Fast for column operations like AVG, MIN, MAX, COUNT
* We don't know all columns upfront and each row doesn't have same number of columns
* Cassandra and HBase

#### Graph Databases
* Data is stored in graph structure with nodes, entities and lines
* Neo4j, Infinte Graph

## SQL vs NoSQL

* Storage - Tables vs Documents/Graphs/Key-Values/Columnar
* Schema - Fixed Schema (adding/renamng a column requires to take DB offline) vs Dynamic Schema (columns are added on fly and each row does not need to have all columns)
* Query - Use SQL vs Query on documents
* Scalability - Vertically scalable(expensive) vs Horizonatally Scalable(handles more traffic)
Any cheap commodity hardware or cloud instances can host NoSQL Db, Can distribute data across servers automatically
* ACID(Atomicity, Consistency, Isolation, Durability) Compliancy - Provides data reliability and safe gurantee of performing transactions vs Provides scalabilty and performance

## Reasons to use SQL DB
* When you have to ensure ACID Compliance -  ACID reduces anomalies and protects integrity of data. E-Commerce and Financial Applications
* When your data is structured and unchangin - If business is not experiencing massive growth that would require more servers, then no need to build a system which supports high traffic volume

## Reasons to use NoSQL DB
* Storing large volume of data that have no structure. New types can be added easily.
* Making the most of computing and storage. Cloud based solutions are cost-effective. 
NoSQl databases like Cassandra are designed to be scaled across multiple servers, out of the box
* Rapid Development - NoSQL DBs do not require any preparation. If you are planning for quick iterations and it will involve changes to data structure often without a lot of downtime, NoSQL is better.




