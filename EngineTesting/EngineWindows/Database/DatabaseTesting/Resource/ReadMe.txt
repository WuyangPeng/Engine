数据库单元测试

1.   HelperSuite 

对宏模块的单元测试，包括： 
（1）用户宏：UserMacroTesting。

2.  ConfigurationSuite 

对配置模块的单元测试，包括：
（1）配置策略：ConfigurationStrategyTesting。 
（2）配置解析：AnalysisDatabaseConfigurationTesting。

3.  SqlInterfaceSuite 

对Sql接口模块的单元测试，包括： 
（1） 数据对象：DatabaseObjectTesting。
（2） 会话：SessionTesting。
（3） 架构：SchemaTesting。
（4） 采集：CollectionTesting。
（5） 结果：ResultRowTesting、ResultTesting。
（6） 表：TableTesting。

4.  StatementSuite  

对语句模块的单元测试，包括：
（1） 语句。

5.	MySqlWrappers（MySQL C API 包装器）

对MySQL C API包装器模块的单元测试，包括： 
（1） 数据对象。
（2） 会话。
（3） 架构。
（4） 采集。
（5） 结果。
（6） 表。

6.  MysqlConnectorWrappersSuite 

对Mysql Connector 包装器模块的单元测试，包括： 
（1） 数据对象：MysqlConnectorDatabaseObjectTesting。
（2） 会话：MysqlConnectorSessionTesting。
（3） 架构：MysqlConnectorSchemaTesting。
（4） 采集：MysqlConnectorCollectionTesting。
（5） 结果：MysqlConnectorDocResultRowTesting、MysqlConnectorDocResultTesting、MysqlConnectorResultRowTesting、MysqlConnectorResultTesting。
（6） 表：MysqlConnectorTableTesting。

7.  SqlServerWrappersSuite  

对Sql Server 包装器模块的单元测试，包括： 
（1） Sql Server。

8.  SQLiteWrappersSuite 

对SQLite 包装器模块的单元测试，包括： 
（1） SQLite。

9.  PostgreSQLSuite   

对PostgreSQL包装器模块的单元测试，包括： 
（1） PostgreSQL。

10.  OracleSuite  

对Oracle包装器模块的单元测试，包括： 
（1） OracleSuite。

11.  FlatFileWrappersSuite  

对平面文件包装器模块的单元测试，包括：  
（1） 平面文件。