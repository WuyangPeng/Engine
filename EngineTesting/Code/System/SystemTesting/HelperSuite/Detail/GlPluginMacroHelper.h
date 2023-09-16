///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/31 17:28)

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
