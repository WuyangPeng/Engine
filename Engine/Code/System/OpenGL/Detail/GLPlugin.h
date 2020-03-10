// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.0 (2020/01/02 15:35)

#ifndef SYSTEM_OPENGL_GL_PLUGIN_H
#define SYSTEM_OPENGL_GL_PLUGIN_H

#include "System/SystemDll.h"  

namespace System
{
	void SYSTEM_HIDDEN_DECLARE ReportNullFunction(const char* glFunction) noexcept;
	void SYSTEM_HIDDEN_DECLARE ReportGLError(const char* glFunction) noexcept;
}

#endif // SYSTEM_OPENGL_GL_PLUGIN_H
