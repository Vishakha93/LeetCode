* Created for faster lookup/search queries on large datasets
* Created using one or more columns of a database table
* Ex - For a library catalog to search books by author and by title, we will create 2 index - one on title, other on author column
* Can be created using 
  * Ordered Map <column to be indexed, row pointer> - Will take O(lg(n)) to search as its sorted
  * B+ Tree better as you don't have to sort everytime you add a new record

* Lead to decrease in write performance - While insert, update and delete, we not only have to write the data, but also update the index.
Thus not needed for write heavy applications.

* Best Practices
  * Adding unnecessary index should be avoided
  * Indexes that are no longer used should be removed



