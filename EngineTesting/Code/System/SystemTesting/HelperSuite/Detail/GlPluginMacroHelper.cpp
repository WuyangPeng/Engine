/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/08 16:06)

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
