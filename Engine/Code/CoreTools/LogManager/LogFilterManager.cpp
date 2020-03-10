// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/20 11:03)

#include "CoreTools/CoreToolsExport.h"

#include "LogFilterManager.h"
#include "Flags/LogManagerFlags.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"

using std::string;

System::String CoreTools::LogFilterManager
	::GetLogFilterDescribe(LogFilter logFilterType)
{
	switch (logFilterType)
	{
		case LogFilter::System:
			return SYSTEM_TEXT("ϵͳ");
		case LogFilter::CoreTools:
			return SYSTEM_TEXT("���Ĺ���");
		case LogFilter::Network:
			return SYSTEM_TEXT("����");
		case LogFilter::Database:
			return SYSTEM_TEXT("���ݿ�");
		case LogFilter::Script:
			return SYSTEM_TEXT("�ű�");
		case LogFilter::Mathematics:
			return SYSTEM_TEXT("��ѧ");
		case LogFilter::SoundEffect:
			return SYSTEM_TEXT("��Ч");
		case LogFilter::InputOutput:
			return SYSTEM_TEXT("�������");
		case LogFilter::ResourceManager:
			return SYSTEM_TEXT("��Դ����");
		case LogFilter::Rendering:
			return SYSTEM_TEXT("��Ⱦ");
		case LogFilter::Physics:
			return SYSTEM_TEXT("����");
		case LogFilter::Imagics:
			return SYSTEM_TEXT("ͼ�����");
		case LogFilter::Animation:
			return SYSTEM_TEXT("����");
		case LogFilter::ArtificialIntellegence:
			return SYSTEM_TEXT("�˹�����");
		case LogFilter::UserInterface:
			return SYSTEM_TEXT("����");
		case LogFilter::AssistTools:
			return SYSTEM_TEXT("��������");
		case LogFilter::Framework:
			return SYSTEM_TEXT("���");
		case LogFilter::User:
			return SYSTEM_TEXT("�û��Զ���");
		default:
			CORE_TOOLS_ASSERTION_2(false, "δ�ҵ���־�����������������");
			return SYSTEM_TEXT("");
	}
}

#define LOG_FILTER_DESCRIBE_JUDGE(describe,filter) \
	    if(describe == SYSTEM_TEXT(#filter)) return SYSTEM_CONCATENATOR(LogFilter::,filter)

CoreTools::LogFilter CoreTools::LogFilterManager
	::GetLogFilterType(const String& describe)
{
	LOG_FILTER_DESCRIBE_JUDGE(describe, System);
	else LOG_FILTER_DESCRIBE_JUDGE(describe, CoreTools);
	else LOG_FILTER_DESCRIBE_JUDGE(describe, Network);
	else LOG_FILTER_DESCRIBE_JUDGE(describe, Database);
	else LOG_FILTER_DESCRIBE_JUDGE(describe, Script);
	else LOG_FILTER_DESCRIBE_JUDGE(describe, Mathematics);
	else LOG_FILTER_DESCRIBE_JUDGE(describe, SoundEffect);
	else LOG_FILTER_DESCRIBE_JUDGE(describe, InputOutput);
	else LOG_FILTER_DESCRIBE_JUDGE(describe, ResourceManager);
	else LOG_FILTER_DESCRIBE_JUDGE(describe, Rendering);
	else LOG_FILTER_DESCRIBE_JUDGE(describe, Physics);
	else LOG_FILTER_DESCRIBE_JUDGE(describe, Imagics);
	else LOG_FILTER_DESCRIBE_JUDGE(describe, Animation);
	else LOG_FILTER_DESCRIBE_JUDGE(describe, ArtificialIntellegence);
	else LOG_FILTER_DESCRIBE_JUDGE(describe, UserInterface);
	else LOG_FILTER_DESCRIBE_JUDGE(describe, AssistTools);
	else LOG_FILTER_DESCRIBE_JUDGE(describe, Framework);
	else LOG_FILTER_DESCRIBE_JUDGE(describe, User);
	else return LogFilter::MaxLogFilter;
}
