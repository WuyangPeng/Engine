// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/15 11:58)

// ���Ĺ��߿⣨CoreTools����װ������ĺ��Ĺ��ߡ���ʵ�� RAII����Դ��ȡ����ʼ������RRID����Դ�ͷż���������
// ���Ĺ��߿�λ������ĵڶ��㣬ֻ������������е�System�⣬��ʹ��boost��stlsoft���߿⡣
// ��Ҫ���಻��ʽ�����ԡ��������ࡢ�쳣���ļ�������־����͵�Ԫ���Կ�ܵȹ����ࡣ

// ���Ĺ��߿��������ģ�飺
// 1.   Helper��������
// 2.   ClassInvariant���಻��ʽ��
// 3.   Assert�����ԣ�
// 4.   ImplHelper��Impl������
// 5.   VersionInformation���汾��Ϣ��
// 6.   Base���������ܣ�
// 7.   DynamicLink����̬���ӿ⹤�ߣ�
// 8.   CharacterString���ַ�����
// 9.   Exception���쳣��
// 10.  Console������̨��
// 11.	Threading���̣߳� 
// 12.	FileManager���ļ�����
// 13.  TextParsing���ı�������
// 14.	LogManager����־���� 
// 15.	DataTypes���������ͣ�
// 16.	MemoryTools���ڴ湤�ߣ�
// 17.	ObjectSystems������ϵͳ��
// 18.	Time��ʱ�䣩
// 19.	ReportOutput�����������
// 20.	UnitTestSuite����Ԫ���ԣ�
// 21.	TemplateTools��ģ�幤�ߣ�
// 22.	Command�������У� 
// 23.	MainFunctionHelper��������������
// 24.	HandleManager���������
// 25.	ResourceManager����Դ����
// 26.	FrameMemorySystem��֡�ڴ�ϵͳ��
// 27.	BitArray��λ���飩
// 28.	ModuleInitializerTerminator��ģ���Զ�����ֹ��
// 29.	SyntacticParser���﷨��������
// 30.	PerformanceProfiler����������/ͳ�Ʋɼ���
// 31.	EngineConfiguration���������ã�
// 32.	Properties�����ԣ�
// 33.	CyclicRedundancyCheck��CRC��
// 34.	RegularExpression��������ʽ��
// 35.	MessageEvent����Ϣ�¼���
// 36.	StateMachineManager��״̬����
// 37.  Network�����磩 
// 38.  Zlib��zlib�� 
// 39.  Freetype��freetype�� 

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