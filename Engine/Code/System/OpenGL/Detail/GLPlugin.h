//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.0 (2020/09/25 15:41)

#ifndef SYSTEM_OPENGL_GL_PLUGIN_H
#define SYSTEM_OPENGL_GL_PLUGIN_H

#include "System/SystemDll.h"

namespace System
{
    void SYSTEM_HIDDEN_DECLARE ReportNullFunction(const char* glFunction) noexcept;
    void SYSTEM_HIDDEN_DECLARE ReportGLError(const char* glFunction) noexcept;
}

#endif  // SYSTEM_OPENGL_GL_PLUGIN_H
