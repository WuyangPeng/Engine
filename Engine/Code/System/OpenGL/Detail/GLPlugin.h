///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.4 (2022/11/19 18:17)

#ifndef SYSTEM_OPENGL_GL_PLUGIN_H
#define SYSTEM_OPENGL_GL_PLUGIN_H

#include "System/SystemDll.h"

namespace System
{
    void SYSTEM_HIDDEN_DECLARE ReportNullFunction(const char* glFunction) noexcept;
    void SYSTEM_HIDDEN_DECLARE ReportGLError(const char* glFunction) noexcept;
}

#endif  // SYSTEM_OPENGL_GL_PLUGIN_H
