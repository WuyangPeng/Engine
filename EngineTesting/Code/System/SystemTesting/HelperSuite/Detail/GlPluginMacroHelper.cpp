///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/01 09:43)

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
