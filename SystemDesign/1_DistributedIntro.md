# Scalability
Capability of a system, network or process to grow and manage increased demand

Performance of a system decreases with system size. Why?
1. Network speed may become slower because machines tend to be far apart from one another.
2. Some tasks may be inherently atomic, thus cannot be distributed.

Goal - Scale without performance loss

## Reasons for scaling
1. Increased Data Volume
2. Increased number of transactions per second

## Horizontal Scaling
1. Scale by adding more servers into your pool of resources
2. Scales dynamically
3. Ex. Cassandra and MongoDB - provide an easy way to add more machines to meet needs

## Vertical Scaling
1. Scale by adding more power (CPU, RAM, Storage, etc) to an existing server
2. Often has an upper limit on the capacity of server
3. Involves Downtime
4. Ex. MySQL  - provides an easy way to switch from smaller to bigger machines


# Reliability
Probability a system will fail in a given time period.
A system is reliable if it keeps delivering its services when one or several of its software/hardware components fail.

* How to make systems reliable?
By redundancy of software components and data (eliminating single point of failure). 
Ex - If a server carrying the user's shopping cart fails, another server that has the exact replica of the shopping cart should replace it.

# Avaliability
If a system is reliable, it is available. However if it's available, it is not necessarily reliable. It may be serving bad content.
Possible to achieve high A but low R by minimizing repair time and ensuring spares come online when needed.
Low availability (ex. fb going down) results in reputational and financial damage to the customers.


# Efficiency
2 Metrics - Latency (response time) & Throughput (Bandwidth)
Latency is the delay to obtain the first item.

At an atomic level, why is the throughput of a distributed system decreases?
1. Increased number of messages globally sent by the nodes of the system
2. Increased size of the message representing the volume of data exchanges

Ex - Searching for a specific key in a distributed data store uses above 2 operations

# Manageability
How easy is it to operate & mantain a system?
Goal: Helps in decresing downtime and improve developer productivity

1. Ease & Speed of diagonising the problems
2. Ease & Speed of making updates







