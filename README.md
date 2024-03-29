CS487 Project Part 1:

  I chose to install a local copy of Postgres 11 on a virtual Windows Server. I chose this system so that I could have full control over the underlying files and settings of the database. While cloud seemed appealing, full raw control of the backend is not as easily accessible as a local database.
  
  Data generation is done using the algorithms' described in the Wisconsin Benchmark paper, as well as some contributions from the class. Primarily, the paper contains pseudocode, such that an exact copy and paste nearly works but not quite. It's a C program that generates tuples with the same data types as required by the tables. These are generated into a .CSV file, then imported into the database.
  
  Issues were encountered in regards to the installation of Postgres. Configuring a new DBMS from scratch required more than just clicking next until it's done. After overcoming initial misconfigurations and successfully setting up a database, connecting the Admin console also proved difficult. I believe most of this was a side effect of installing the DBMS on a virtual machine, but was solved after some configuration changes (such as the fact that MS server 2016 comes with Internet Explorer, which had a ton of security issues and blocks).
  
  Attached image shows 100 tuples loaded into a table.
