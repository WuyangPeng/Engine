/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.6 (2024/03/01 16:58)

#ifndef SYSTEM_OPENGL_GL_PLUGIN_FWD_H
#define SYSTEM_OPENGL_GL_PLUGIN_FWD_H

namespace System
{
    void ReportNullFunction(const char* glFunction) noexcept;
    void ReportGLError(const char* glFunction) noexcept;
}

#endif  // SYSTEM_OPENGL_GL_PLUGIN_FWD_H