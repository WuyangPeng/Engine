// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/15 11:58)

// 核心工具库（CoreTools）封装了引擎的核心工具。以实现 RAII（资源获取即初始化）和RRID（资源释放即析构）。
// 核心工具库位于引擎的第二层，只允许调用引擎中的System库，并使用boost和stlsoft工具库。
// 主要有类不变式、断言、单例基类、异常、文件管理、日志管理和单元测试框架等工具类。

// 核心工具库包含以下模块：
// 1.   Helper（帮助）
// 2.   ClassInvariant（类不变式）
// 3.   Assert（断言）
// 4.   ImplHelper（Impl帮助）
// 5.   VersionInformation（版本信息）
// 6.   Base（基本功能）
// 7.   DynamicLink（动态链接库工具）
// 8.   CharacterString（字符串）
// 9.   Exception（异常）
// 10.  Console（控制台）
// 11.	Threading（线程） 
// 12.	FileManager（文件管理）
// 13.  TextParsing（文本解析）
// 14.	LogManager（日志管理） 
// 15.	DataTypes（数据类型）
// 16.	MemoryTools（内存工具）
// 17.	ObjectSystems（对象系统）
// 18.	Time（时间）
// 19.	ReportOutput（报告输出）
// 20.	UnitTestSuite（单元测试）
// 21.	TemplateTools（模板工具）
// 22.	Command（命令行） 
// 23.	MainFunctionHelper（主函数帮助）
// 24.	HandleManager（句柄管理）
// 25.	ResourceManager（资源管理）
// 26.	FrameMemorySystem（帧内存系统）
// 27.	BitArray（位数组）
// 28.	ModuleInitializerTerminator（模块自动及终止）
// 29.	SyntacticParser（语法分析器）
// 30.	PerformanceProfiler（性能剖析/统计采集）
// 31.	EngineConfiguration（引擎配置）
// 32.	Properties（属性）
// 33.	CyclicRedundancyCheck（CRC）
// 34.	RegularExpression（正则表达式）
// 35.	MessageEvent（消息事件）
// 36.	StateMachineManager（状态机）
// 37.  Network（网络） 
// 38.  Zlib（zlib） 
// 39.  Freetype（freetype） 

#include "CoreToolsExport.h"

#include "CoreTools.h"

#include "System/SystemLib.h"

#ifndef BUILDING_CORE_TOOLS_STATIC

	#include "DllLib.h"

#else // !BUILDING_CORE_TOOLS_STATIC

	namespace CoreTools
	{
		void StaticDllLib()
		{

		}
	}

#endif // BUILDING_CORE_TOOLS_STATIC