//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.2 (2020/10/15 19:00)

#include "CoreTools/CoreToolsExport.h"

#include "LogFilterManager.h"
#include "Flags/LogManagerFlags.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"

using std::string;
using namespace std::literals;

System::String CoreTools::LogFilterManager::GetLogFilterDescribe(LogFilter logFilterType)
{
    switch (logFilterType)
    {
        case LogFilter::System:
            return SYSTEM_TEXT("系统"s);
        case LogFilter::CoreTools:
            return SYSTEM_TEXT("核心工具"s);
        case LogFilter::Network:
            return SYSTEM_TEXT("网络"s);
        case LogFilter::Database:
            return SYSTEM_TEXT("数据库"s);
        case LogFilter::Script:
            return SYSTEM_TEXT("脚本"s);
        case LogFilter::Mathematics:
            return SYSTEM_TEXT("数学"s);
        case LogFilter::SoundEffect:
            return SYSTEM_TEXT("音效"s);
        case LogFilter::InputOutput:
            return SYSTEM_TEXT("输入输出"s);
        case LogFilter::ResourceManager:
            return SYSTEM_TEXT("资源管理"s);
        case LogFilter::Rendering:
            return SYSTEM_TEXT("渲染"s);
        case LogFilter::Physics:
            return SYSTEM_TEXT("物理"s);
        case LogFilter::Imagics:
            return SYSTEM_TEXT("图像分析"s);
        case LogFilter::Animation:
            return SYSTEM_TEXT("动画"s);
        case LogFilter::ArtificialIntellegence:
            return SYSTEM_TEXT("人工智能"s);
        case LogFilter::UserInterface:
            return SYSTEM_TEXT("界面"s);
        case LogFilter::AssistTools:
            return SYSTEM_TEXT("辅助工具"s);
        case LogFilter::Framework:
            return SYSTEM_TEXT("框架"s);
        case LogFilter::User:
            return SYSTEM_TEXT("用户自定义"s);
        default:
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
    else LOG_FILTER_DESCRIBE_JUDGE(describe, ArtificialIntellegence);
    else LOG_FILTER_DESCRIBE_JUDGE(describe, UserInterface);
    else LOG_FILTER_DESCRIBE_JUDGE(describe, AssistTools);
    else LOG_FILTER_DESCRIBE_JUDGE(describe, Framework);
    else LOG_FILTER_DESCRIBE_JUDGE(describe, User);
    else return LogFilter::MaxLogFilter;
}
