@ingroup group_EngineTesting_Documentation

----------------------------
引擎测试

----------------------------
ThreadingCoreRenderEngineTesting

----------------------------	
工程类型
	exe，控制台。

----------------------------
状态
	目前版本：1.0.2.0。

----------------------------
实现内容
	1.  复制必要的dll到测试工程运行目录。 
	2.  复制工程测试json到测试工程运行目录。 
	3.  复制工程的Testing.json到测试工程运行目录。 
	4.  复制工程的ProjectTesting.json到测试工程运行目录。
	5.  复制工程的EnvironmentVariable.json到测试工程运行目录。 
	6.  复制工程的EngineDirectory.json到测试工程运行目录。 
	7.  复制工程的Renderer.json到测试工程运行目录。 
	8.  版本号定义在Version.h中。
	9.  单元测试样例工程。
	10. 引擎单元测试总入口，可根据用户选择执行某个测试。

----------------------------