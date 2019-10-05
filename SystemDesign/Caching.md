Caching is based on locality of reference principle: Recently requested data is likely to be requested again
It is used in
1. Hardware
2. Operating System
3. Web Browser
4. Web Applications

### Application Server Cache
Cache on one request layer node could be located both in memory (which is very fast) and on the node's local disk 
(faster than going to network storage).

If you load balancer randomly distributes requests across the nodes, the same request will got to different nodes thus increasing cache misses.
2 ways to fix this is using Global Cache and Distributed Cache

### Content Distribution Network (CDN)
CDNs are a kind of cache that comes into play for sites that serving large amounts of static media.
Request -> CDN -> Backend servers
Future Planning - If the system we are building isn't yet large enough, we can put the static media files on a separate website
like static.mitesh.com and then later bring up CDN at that url.

### Cache Invalidation Schemes
If data is modified in the source of truth(database), cache must be invalidated.

#### Write Through Cache
Data is written into the cache and the corresponding database at the same time

Pros - DB and Cache are consistent always, No data lost in case of power crash, failures
Cons - Higher Latency for write operations

#### Write Around Cache
Data is not written into cache, just in the database
This can reduce the cache being flooded with write operations that will not be re-read.

#### Write Back Cache
Data is written only in the cache, leading to low latency and high throughput.
Cons - Risk of data loss in case of crash

### Cache Eviction Policies
FIFO, LIFO, LRU, MRU (Most Recently Used), LFU, RR(Random Replacement)

