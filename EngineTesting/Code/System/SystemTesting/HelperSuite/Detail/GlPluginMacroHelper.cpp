/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/08 16:06)

#include "GlPluginMacroHelper.h"
#include "System/Helper/Tools.h"

void System::ReportNullFunction(const char* glFunction) noexcept
{
    UnusedFunction(glFunction);
}

void System::ReportGLError(const char* glFunction) noexcept
{
    UnusedFunction(glFunction);
}

void System::GlFunction() noexcept
{
}
