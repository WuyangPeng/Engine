// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.0 (2020/01/02 15:36)

#ifndef SYSTEM_OPENGL_GL_PLUGIN_FWD_H
#define SYSTEM_OPENGL_GL_PLUGIN_FWD_H  

namespace System
{
	void ReportNullFunction(const char* glFunction) noexcept;
	void ReportGLError(const char* glFunction) noexcept;
}

#endif // SYSTEM_OPENGL_GL_PLUGIN_FWD_H