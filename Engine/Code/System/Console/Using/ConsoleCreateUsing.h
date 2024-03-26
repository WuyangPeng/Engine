/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 19:33)

#ifndef SYSTEM_CONSOLE_CONSOLE_CREATE_USING_H
#define SYSTEM_CONSOLE_CONSOLE_CREATE_USING_H

/// 控制台重定向的路径和模式。
namespace System
{
    constexpr auto stdOutPath = "CONOUT$";
    constexpr auto stdInPath = "CONIN$";

    constexpr auto stdOutMode = "w+t";
    constexpr auto stdInMode = "r+t";
}

#endif  // SYSTEM_CONSOLE_CONSOLE_CREATE_USING_H
