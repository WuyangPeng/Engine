///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/28 16:12)

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
    else LOG_FILTER_DESCRIBE_JUDGE(describe, ArtificialIntelligence);
    else LOG_FILTER_DESCRIBE_JUDGE(describe, UserInterface);
    else LOG_FILTER_DESCRIBE_JUDGE(describe, AssistTools);
    else LOG_FILTER_DESCRIBE_JUDGE(describe, Framework);
    else LOG_FILTER_DESCRIBE_JUDGE(describe, User);
    else return LogFilter::MaxLogFilter;
}
