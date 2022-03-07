///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/07 21:30)

#ifndef CORE_TOOLS_LOG_MANAGER_LOG_MANAGER_FLAGS_H
#define CORE_TOOLS_LOG_MANAGER_LOG_MANAGER_FLAGS_H

#include "System/Helper/EnumMacro.h"

#include <iostream>

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
        ArtificialIntellegence,  // 人工智能
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
        BlankSpace,  // 空格
        Newline,  // 换行
        Refresh,  // 刷新
        TriggerAssert,  // 触发断言
        AlwaysConsole,  // 总是输出至控制台
    };

    ENUM_LEFT_SHIFTABLE_OPERATOR_DEFINE(LogLevel);
    ENUM_RIGHT_SHIFTABLE_OPERATOR_DEFINE(LogLevel);
    ENUM_LEFT_SHIFTABLE_OPERATOR_WCHAR_DEFINE(LogLevel);
    ENUM_RIGHT_SHIFTABLE_OPERATOR_WCHAR_DEFINE(LogLevel);
    ENUM_INCREMENTABLE_OPERATOR_DEFINE(LogLevel);

    ENUM_LEFT_SHIFTABLE_OPERATOR_DEFINE(AppenderPrint);
    ENUM_RIGHT_SHIFTABLE_OPERATOR_DEFINE(AppenderPrint);
    ENUM_LEFT_SHIFTABLE_OPERATOR_WCHAR_DEFINE(AppenderPrint);
    ENUM_RIGHT_SHIFTABLE_OPERATOR_WCHAR_DEFINE(AppenderPrint);
    ENUM_ANDABLE_OPERATOR_DEFINE(AppenderPrint);
    ENUM_ORABLE_OPERATOR_DEFINE(AppenderPrint);
}

#endif  // CORE_TOOLS_LOG_MANAGER_LOG_MANAGER_FLAGS_H
