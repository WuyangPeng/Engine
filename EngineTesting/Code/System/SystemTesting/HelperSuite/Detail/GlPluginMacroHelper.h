/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/08 16:06)

#ifndef SYSTEM_TESTING_HELPER_SUITE_GL_PLUGIN_MACRO_HELPER_H
#define SYSTEM_TESTING_HELPER_SUITE_GL_PLUGIN_MACRO_HELPER_H

#include "System/Helper/ConfigMacro.h"

namespace System
{
    void ReportNullFunction(const char* glFunction) noexcept;
    void ReportGLError(const char* glFunction) noexcept;
    void GlFunction() noexcept;
}

#endif  // SYSTEM_TESTING_HELPER_SUITE_GL_PLUGIN_MACRO_HELPER_H
