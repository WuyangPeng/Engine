///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.0 (2023/01/12 22:41)

#ifndef SYSTEM_OPENGL_GL_PLUGIN_FWD_H
#define SYSTEM_OPENGL_GL_PLUGIN_FWD_H

namespace System
{
    void ReportNullFunction(const char* glFunction) noexcept;
    void ReportGLError(const char* glFunction) noexcept;
}

#endif  // SYSTEM_OPENGL_GL_PLUGIN_FWD_H