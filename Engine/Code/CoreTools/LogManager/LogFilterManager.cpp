///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/09/21 10:01)

#include "CoreTools/CoreToolsExport.h"

#include "LogFilterManager.h"
#include "Flags/LogManagerFlags.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"

#include <map>

using namespace std::literals;

System::String CoreTools::LogFilterManager::GetLogFilterDescribe(LogFilter logFilterType)
{
    static const std::map<LogFilter, String> describe{ { LogFilter::System, SYSTEM_TEXT("ϵͳ"s) },
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
                                                       { LogFilter::ArtificialIntelligence, SYSTEM_TEXT("�˹�����"s) },
                                                       { LogFilter::UserInterface, SYSTEM_TEXT("����"s) },
                                                       { LogFilter::AssistTools, SYSTEM_TEXT("��������"s) },
                                                       { LogFilter::Framework, SYSTEM_TEXT("���"s) },
                                                       { LogFilter::User, SYSTEM_TEXT("�û��Զ���"s) } };

    if (const auto iter = describe.find(logFilterType); iter != describe.cend())
    {
        return iter->second;
    }
    else
    {
        CORE_TOOLS_ASSERTION_2(false, "δ�ҵ���־�����������������");
        return SYSTEM_TEXT(""s);
    }
}

CoreTools::LogFilter CoreTools::LogFilterManager::GetLogFilterType(const String& describe)
{
    static const std::map<String, LogFilter> container{ { SYSTEM_TEXT("System"), LogFilter::System },
                                                        { SYSTEM_TEXT("CoreTools"), LogFilter::CoreTools },
                                                        { SYSTEM_TEXT("Network"), LogFilter::Network },
                                                        { SYSTEM_TEXT("Database"), LogFilter::Database },
                                                        { SYSTEM_TEXT("Script"), LogFilter::Script },
                                                        { SYSTEM_TEXT("Mathematics"), LogFilter::Mathematics },
                                                        { SYSTEM_TEXT("SoundEffect"), LogFilter::SoundEffect },
                                                        { SYSTEM_TEXT("InputOutput"), LogFilter::InputOutput },
                                                        { SYSTEM_TEXT("ResourceManager"), LogFilter::ResourceManager },
                                                        { SYSTEM_TEXT("Rendering"), LogFilter::Rendering },
                                                        { SYSTEM_TEXT("Physics"), LogFilter::Physics },
                                                        { SYSTEM_TEXT("Imagics"), LogFilter::Imagics },
                                                        { SYSTEM_TEXT("Animation"), LogFilter::Animation },
                                                        { SYSTEM_TEXT("ArtificialIntelligence"), LogFilter::ArtificialIntelligence },
                                                        { SYSTEM_TEXT("UserInterface"), LogFilter::UserInterface },
                                                        { SYSTEM_TEXT("AssistTools"), LogFilter::AssistTools },
                                                        { SYSTEM_TEXT("Framework"), LogFilter::Framework },
                                                        { SYSTEM_TEXT("User"), LogFilter::User } };

    if (const auto iter = container.find(describe);
        iter != container.cend())
    {
        return iter->second;
    }

    return LogFilter::MaxLogFilter;
}
