@ingroup group_Database_Documentation

----------------------------
数据库模块

数据库（Database）封装了引擎的数据库层调用。以实现数据库层的封装。
数据库位于引擎的第三层，只允许调用引擎中的System、CoreTools库，并且需要减少System库的依赖性。
并使用boost、mysqlclient、mysql connector c++、mongo cxx driver、和hiredis工具库。

----------------------------
1.	Helper（帮助）

数据库模块系统宏。
 
（1）用户宏：用于是否使用静态库、是否使用mysqlclient、mysql connector c++、mongo和hiredis等用户设定。 
（2）数据库宏：数据库模块所使用的宏，按需要添加。

----------------------------
2.  Configuration（配置）

封装了数据库的配置。
 
（1）配置策略：对数据库的相关策略进行封装，按需要后续添加。 
（2）配置解析：对数据库配置进行解析，返回配置的策略。

----------------------------
3.	DatabaseInterface（Database接口）

封装了数据库的统一接口。 处理模式使用策略类，分别代表使用哪种数据库。 
内部使用mysqlclient、mysql connector c++、Sql Server、SQLite、PostgreSQL、Oracle、mongo、hiredis或者平面文件。接口尽量保持同mysql connector c++一致。 

（1） 记录：逻辑层单条数据基类，与数据库层解耦。
（2） 记录容器：逻辑层多条数据基类，与数据库层解耦。
（3） 记录修改：记录和记录容器与数据库层的交互类。
（4） 数据对象：数据对象单例，返回相关信息。
（5） 会话：各种实现的会话类基类。
（6） 存储：各种实现的存储类基类。 

----------------------------
4.	DatabaseGenerate（Database代码生成）

封装了数据库代码生成的实现。

（1）代码生成：封装了数据库代码生成的实现。

----------------------------
5.	Statement（语句）

封装了sql语句的实现。

（1）语句：封装了sql语句的实现。

----------------------------
6.	MySqlWrappers（MySQL C API 包装器）

封装了MySQL C API的实现。

（1） 会话：MySQL C API的会话类。
（2） 存储：MySQL C API的存储类。 

----------------------------
7.	MysqlConnectorWrappers（mysql connector c++ 包装器）

封装了mysql connector c++的实现。它可以让程序连接到Mysql服务器。通过封装使程序更安全、更健壮，更易于使用。

（1） 会话：mysql connector c++的会话类。
（2） 存储：mysql connector c++的存储类。 

----------------------------
8.	MysqlBoostWrappers（mysql boost 包装器）

封装了mysql boost的实现。 

（1） 会话：mysql boost的会话类。
（2） 存储：mysql boost的存储类。 

----------------------------
9.	SqlServerWrappers（Sql Server 包装器）

封装了Sql Server的实现。

（1） 会话：Sql Server的会话类。
（2） 存储：Sql Server的存储类。 

----------------------------
10.	SQLiteWrappers（SQLite 包装器）

封装了SQLite的实现。

（1） 会话：SQLite的会话类。
（2） 存储：SQLite的存储类。  

----------------------------
11.	PostgreSQL（PostgreSQL 包装器）

封装了PostgreSQL的实现。

（1） 会话：PostgreSQL的会话类。
（2） 存储：PostgreSQL的存储类。  

----------------------------
12.	Oracle（Oracle 包装器）

封装了Oracle的实现。

（1） 会话：Oracle的会话类。
（2） 存储：Oracle的存储类。 

----------------------------
13.	FlatFileWrappers（平面文件包装器）

封装了平面文件的实现。

（1） 会话：平面文件的会话类。
（2） 存储：平面文件的存储类。  

----------------------------
14. mariaDB（mariaDB 包装器）

封装了mariaDB的实现。

（1） 会话：mariaDB的会话类。
（2） 存储：mariaDB的存储类。   

----------------------------
15. mongo（mongo 包装器）

封装了mongo的实现。

（1） 会话：mongo的会话类。
（2） 存储：mongo的存储类。   

----------------------------
16. Redis（Redis 包装器）

封装了Redis的实现。

（1） 会话：Redis的会话类。
（2） 存储：Redis的存储类。  

----------------------------

