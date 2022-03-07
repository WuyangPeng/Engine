///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/07 22:52)

#include "CoreTools/CoreToolsExport.h"

#include "LogFilterManager.h"
#include "Flags/LogManagerFlags.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"

#include <map>

using std::map;
using std::string;
using namespace std::literals;

System::String CoreTools::LogFilterManager::GetLogFilterDescribe(LogFilter logFilterType)
{
    static const map<LogFilter, String> describe{ { LogFilter::System, SYSTEM_TEXT("ϵͳ"s) },
                                                  { LogFilter::CoreTools, SYSTEM_TEXT("���Ĺ���"s) },
                                                  { LogFilter::Network, SYSTEM_TEXT("����"s) },
                                                  { LogFilter::Database, SYSTEM_TEXT("���ݿ�"s) },
                                                  { LogFilter::Script, SYSTEM_TEXT("�ű�"s) },
                                                  { LogFilter::Mathematics, SYSTEM_TEXT("��ѧ"s) },
                                                  { LogFilter::SoundEffect, SYSTEM_TEXT("��Ч"s) },
                                                  { LogFilter::InputOutput, SYSTEM_TEXT("�������"s) },
                                                  { LogFilter::ResourceManager, SYSTEM_TEXT("��Դ����"s) },
                                                  { LogFilter::Rendering, SYSTEM_TEXT("��Ⱦ"s) },
                                                  { LogFilter::Physics, SYSTEM_TEXT("����"s) },
                                                  { LogFilter::Imagics, SYSTEM_TEXT("ͼ�����"s) },
                                                  { LogFilter::Animation, SYSTEM_TEXT("����"s) },
                                                  { LogFilter::ArtificialIntellegence, SYSTEM_TEXT("�˹�����"s) },
                                                  { LogFilter::UserInterface, SYSTEM_TEXT("����"s) },
                                                  { LogFilter::AssistTools, SYSTEM_TEXT("��������"s) },
                                                  { LogFilter::Framework, SYSTEM_TEXT("���"s) },
                                                  { LogFilter::User, SYSTEM_TEXT("�û��Զ���"s) } };

    const auto iter = describe.find(logFilterType);
    if (iter != describe.cend())
    {
        return iter->second;
    }
    else
    {
        CORE_TOOLS_ASSERTION_2(false, "δ�ҵ���־�����������������");
        return SYSTEM_TEXT(""s);
    }
}

#define LOG_FILTER_DESCRIBE_JUDGE(describe, filter) \
    if (describe == SYSTEM_TEXT(#filter))           \
    return SYSTEM_CONCATENATOR(LogFilter::, filter)

CoreTools::LogFilter CoreTools::LogFilterManager::GetLogFilterType(const String& describe)
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
