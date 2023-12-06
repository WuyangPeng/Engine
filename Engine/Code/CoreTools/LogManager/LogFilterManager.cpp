///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/21 10:01)

#include "CoreTools/CoreToolsExport.h"

#include "LogFilterManager.h"
#include "Flags/LogManagerFlags.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"

#include <map>

using namespace std::literals;

System::String CoreTools::LogFilterManager::GetLogFilterDescribe(LogFilter logFilterType)
{
    static const std::map<LogFilter, String> describe{ { LogFilter::System, SYSTEM_TEXT("系统"s) },
                                                       { LogFilter::CoreTools, SYSTEM_TEXT("核心工具"s) },
                                                       { LogFilter::Network, SYSTEM_TEXT("网络"s) },
                                                       { LogFilter::Database, SYSTEM_TEXT("数据库"s) },
                                                       { LogFilter::Script, SYSTEM_TEXT("脚本"s) },
                                                       { LogFilter::Mathematics, SYSTEM_TEXT("数学"s) },
                                                       { LogFilter::SoundEffect, SYSTEM_TEXT("音效"s) },
                                                       { LogFilter::InputOutput, SYSTEM_TEXT("输入输出"s) },
                                                       { LogFilter::ResourceManager, SYSTEM_TEXT("资源管理"s) },
                                                       { LogFilter::Rendering, SYSTEM_TEXT("渲染"s) },
                                                       { LogFilter::Physics, SYSTEM_TEXT("物理"s) },
                                                       { LogFilter::Imagics, SYSTEM_TEXT("图像分析"s) },
                                                       { LogFilter::Animation, SYSTEM_TEXT("动画"s) },
                                                       { LogFilter::ArtificialIntelligence, SYSTEM_TEXT("人工智能"s) },
                                                       { LogFilter::UserInterface, SYSTEM_TEXT("界面"s) },
                                                       { LogFilter::AssistTools, SYSTEM_TEXT("辅助工具"s) },
                                                       { LogFilter::Framework, SYSTEM_TEXT("框架"s) },
                                                       { LogFilter::User, SYSTEM_TEXT("用户自定义"s) } };

    if (const auto iter = describe.find(logFilterType); iter != describe.cend())
    {
        return iter->second;
    }
    else
    {
        CORE_TOOLS_ASSERTION_2(false, "未找到日志过滤器的相关描述！");
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
