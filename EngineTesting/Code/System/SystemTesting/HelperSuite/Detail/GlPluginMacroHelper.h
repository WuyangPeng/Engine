///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.1 (2021/03/09 17:25)

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
