@ingroup group_DatabaseTesting_Documentation

----------------------------
数据库单元测试

1.   HelperSuite 

对宏模块的单元测试，包括： 
（1）用户宏：UserMacroTesting。

----------------------------
2.  ConfigurationSuite 

对配置模块的单元测试，包括：
（1）配置策略：ConfigurationStrategyTesting。 
（2）配置解析：AnalysisDatabaseConfigurationTesting。

----------------------------
3.  DatabaseInterfaceSuite 

对数据库接口模块的单元测试，包括： 
（1） 记录： BasisDatabaseTesting。
（2） 记录容器：BasisDatabaseContainerTesting、
			    BasisDatabaseManagerTesting。
（3） 记录修改：DatabaseEntityTesting、
			    EntityTesting、
				DatabaseFieldTesting。
（4） 数据对象： DatabaseEnvironmentTesting。
（5） 会话： DatabaseManagerTesting。
（6） 存储： DatabaseFlushTesting。 

----------------------------
4.  DatabaseGenerateSuite  

对数据库生成的单元测试，包括：
（1） 数据库生成。

----------------------------
5.  StatementSuite  

对语句模块的单元测试，包括：
（1） 语句：RedisStatementTesting、
		    SqlStatementTesting。

----------------------------
6.	MySqlWrappers（MySQL C API 包装器）

对MySQL C API包装器模块的单元测试，包括： 
（1） 会话。
（2） 存储。 

----------------------------
7.  MysqlConnectorWrappersSuite 

对Mysql Connector 包装器模块的单元测试，包括： 
（1） Mysql Connector：MysqlConnectorDatabaseFlushTesting。 

----------------------------
8.  MysqlBoostWrappersSuite  

对mysql boost包装器模块的单元测试，包括： 
（1） mysql boost：MysqlBoostDatabaseFlushTesting。

----------------------------
9.  SqlServerWrappersSuite  

对Sql Server 包装器模块的单元测试，包括： 
（1） Sql Server。

----------------------------
10.  SQLiteWrappersSuite 

对SQLite 包装器模块的单元测试，包括： 
（1） SQLite。

----------------------------
11.  PostgreSQLSuite   

对PostgreSQL包装器模块的单元测试，包括： 
（1） PostgreSQL。

----------------------------
12.  OracleSuite  

对Oracle包装器模块的单元测试，包括： 
（1） OracleSuite。

----------------------------
13.  FlatFileWrappersSuite  

对平面文件包装器模块的单元测试，包括：  
（1） 平面文件。

----------------------------
14.  MariaDBWrappersSuite  

对mariaDB包装器模块的单元测试，包括：  
（1） mariaDB。

----------------------------
15.  MongoWrappersSuite  

对mongo包装器模块的单元测试，包括：  
（1） mongo： MongoEnvironmentTesting、
			  MongoDatabaseFlushTesting。

----------------------------
16.  RedisWrappersSuite  

对redis包装器模块的单元测试，包括：  
（1） redis：RedisDatabaseFlushTesting。

----------------------------