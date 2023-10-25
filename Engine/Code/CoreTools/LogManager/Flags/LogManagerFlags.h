///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/21 09:47)

#ifndef CORE_TOOLS_LOG_MANAGER_LOG_MANAGER_FLAGS_H
#define CORE_TOOLS_LOG_MANAGER_LOG_MANAGER_FLAGS_H

#include "System/Helper/EnumOperator.h"

namespace CoreTools
{
    enum class LogFilter
    {
        System = 0,  // 系统
        CoreTools,  // 核心工具
        Network,  // 网络
        Database,  // 数据库
        Script,  // 脚本
        Mathematics,  // 数学
        SoundEffect,  // 音效
        InputOutput,  // 输入输出
        ResourceManager,  // 资源管理
        Rendering,  // 渲染
        Physics,  // 物理
        Imagics,  // 图像分析
        Animation,  // 动画
        ArtificialIntelligence,  // 人工智能
        UserInterface,  // 界面
        AssistTools,  // 辅助工具
        Framework,  // 框架
        User,  // 用户自定义
        MaxLogFilter
    };

    enum class LogLevel
    {
        Disabled = 0,  // 禁用
        Trace,  // 跟踪信息
        Debug,  // 调试信息
        Info,  // 一般信息
        Warn,  // 警告信息
        Error,  // 错误信息
        Fatal,  // 致命错误信息
        MaxLogLevels
    };

    enum class AppenderType
    {
        None = 0,
        Console,
        File,
        FileConfiguration,
    };

    enum class AppenderPrint
    {
        None = 0x00,
        PrefixTimestamp = 0x01,
        PrefixLogLevel = 0x02,
        PrefixLogFilterType = 0x04,
        PostfixFunctionDescribed = 0x08,

        All = PrefixTimestamp | PrefixLogLevel | PrefixLogFilterType | PostfixFunctionDescribed,
    };

    enum class LogAppenderIOManageSign
    {
        TriggerAssert,  // 触发断言
        AlwaysConsole,  // 总是输出至控制台
    };
}

#endif  // CORE_TOOLS_LOG_MANAGER_LOG_MANAGER_FLAGS_H
