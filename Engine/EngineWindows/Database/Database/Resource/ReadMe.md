@ingroup group_Database_Documentation

----------------------------
数据库模块

数据库（Database）封装了引擎的数据库层调用。以实现数据库层的封装。
数据库位于引擎的第三层，只允许调用引擎中的System、CoreTools库，并使用boost和其他数据库相关的工具库。

----------------------------
1.	Helper（帮助）

数据库模块系统宏。
 
（1）用户宏：用于是否使用静态库、是否使用mysql、sqlServer等用户设定。 
（2）数据库宏：数据库模块所使用的宏，按需要添加。

----------------------------
2.  Configuration（配置）

封装了数据库的配置。
 
（1）配置策略：对数据库的相关策略进行封装，按需要后续添加。 
（2）配置解析：对数据库配置进行解析，返回配置的策略。

----------------------------
3.	SqlInterface（Sql接口）

封装了数据库的统一接口。 处理模式使用策略类，分别代表使用哪种数据库。 
内部使用Mysql、SQL Connector/C++、Sql Server、SQLite、PostgreSQL、Oracle或者平面文件。接口尽量保持同SQL Connector/C++一致。 

（1） 数据对象：数据对象单例，返回相关信息。
（2） 会话：各种实现的会话类。
（3） 架构：各种实现的架构类。
（4） 采集：各种实现的采集类。
（5） 结果：各种实现的结果类。
（6） 表： 各种实现的表类。

----------------------------
4.	Statement（语句）

封装了sql语句的实现。

（1）语句：封装了sql语句的实现。

----------------------------
5.	MySqlWrappers（MySQL C API 包装器）

封装了MySQL C API的实现。

（1） 数据对象：MySQL C API对象单例，返回相关信息。
（2） 会话：MySQL C API的会话类。
（3） 架构：MySQL C API的架构类。
（4） 采集：MySQL C API的采集类。
（5） 结果：MySQL C API的结果类。
（6） 表： MySQL C API的表类。

----------------------------
6.	MysqlConnectorWrappers（Mysql Connector 包装器）

封装了SQL Connector/C++的实现。它可以让程序连接到Mysql服务器。通过封装使程序更安全、更健壮，更易于使用。

（1） 数据对象：SQL Connector/C++对象单例，返回相关信息。
（2） 会话：SQL Connector/C++的会话类。
（3） 架构：SQL Connector/C++的架构类。
（4） 采集：SQL Connector/C++的采集类。
（5） 结果：SQL Connector/C++的结果类。
（6） 表： SQL Connector/C++的表类。

----------------------------
7.	SqlServerWrappers（Sql Server 包装器）

封装了Sql Server的实现。

（1） 数据对象：Sql Server对象单例，返回相关信息。
（2） 会话：Sql Server的会话类。
（3） 架构：Sql Server的架构类。
（4） 采集：Sql Server的采集类。
（5） 结果：Sql Server的结果类。
（6） 表： Sql Server的表类。

----------------------------
8.	SQLiteWrappers（SQLite 包装器）

封装了SQLite的实现。

（1） 数据对象：SQLite对象单例，返回相关信息。
（2） 会话：SQLite的会话类。
（3） 架构：SQLite的架构类。
（4） 采集：SQLite的采集类。
（5） 结果：SQLite的结果类。
（6） 表： SQLite的表类。

----------------------------
9.	PostgreSQL（PostgreSQL 包装器）

封装了PostgreSQL的实现。

（1） 数据对象：PostgreSQL对象单例，返回相关信息。
（2） 会话：PostgreSQL的会话类。
（3） 架构：PostgreSQL的架构类。
（4） 采集：PostgreSQL的采集类。
（5） 结果：PostgreSQL的结果类。
（6） 表： PostgreSQL的表类。

----------------------------
10.	Oracle（Oracle 包装器）

封装了Oracle的实现。

（1） 数据对象：Oracle对象单例，返回相关信息。
（2） 会话：Oracle的会话类。
（3） 架构：Oracle的架构类。
（4） 采集：Oracle的采集类。
（5） 结果：Oracle的结果类。
（6） 表： Oracle的表类。

----------------------------
11.	FlatFileWrappers（平面文件包装器）

封装了平面文件的实现。

（1） 数据对象：平面文件对象单例，返回相关信息。
（2） 会话：平面文件的会话类。
（3） 架构：平面文件的架构类。
（4） 采集：平面文件的采集类。
（5） 结果：平面文件的结果类。
（6） 表：平面文件的表类。

----------------------------
12. mariaDB（mariaDB 包装器）

封装了mariaDB的实现。

（1） 数据对象：mariaDB对象单例，返回相关信息。
（2） 会话：mariaDB的会话类。
（3） 架构：mariaDB的架构类。
（4） 采集：mariaDB的采集类。
（5） 结果：mariaDB的结果类。
（6） 表： mariaDB的表类。

----------------------------
13. mongo（mongo 包装器）

封装了mongo的实现。

（1） 数据对象：mongo对象单例，返回相关信息。
（2） 会话：mongo的会话类。
（3） 架构：mongo的架构类。
（4） 采集：mongo的采集类。
（5） 结果：mongo的结果类。
（6） 表： mongo的表类。

----------------------------
14. Redis（Redis 包装器）

封装了Redis的实现。

（1） 数据对象：Redis对象单例，返回相关信息。
（2） 会话：Redis的会话类。
（3） 架构：Redis的架构类。
（4） 采集：Redis的采集类。
（5） 结果：Redis的结果类。
（6） 表： Redis的表类。

----------------------------

