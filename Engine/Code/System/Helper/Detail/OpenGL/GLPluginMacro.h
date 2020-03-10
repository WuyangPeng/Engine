// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.0 (2020/01/02 15:05)

#ifndef SYSTEM_HELPER_GL_PLUGIN_MACRO_H
#define SYSTEM_HELPER_GL_PLUGIN_MACRO_H

#include "System/Helper/ConfigMacro.h"

// ��ÿ��OpenGL����ʱĬ����Ϊû�ж���Ĳ����������Ҫ�����һ���������塣

#define SYSTEM_ENTER_FUNCTION(glFunction)
#define SYSTEM_NONNULL_FUNCTION(glFunction)

#ifdef SYSTEM_ENABLE_GL_ERROR_CHECKING

	#include "System/OpenGL/Fwd/GLPluginFwd.h"

	// �����������������һ���պ���ʱ����Ⱦ��Ԥ�ƺ������ڡ�
	#define SYSTEM_NULL_FUNCTION(glFunction) System::ReportNullFunction(#glFunction)

	// ÿ�ε���OpenGL��������������glGetError��
	#define SYSTEM_EXIT_FUNCTION(glFunction) System::ReportGLError(#glFunction)

#else // !SYSTEM_ENABLE_GL_ERROR_CHECKING

	// ������һ������ô����顣
	#define SYSTEM_NULL_FUNCTION(glFunction)
	#define SYSTEM_EXIT_FUNCTION(glFunction)

#endif // SYSTEM_ENABLE_GL_ERROR_CHECKING
	  
#endif // SYSTEM_HELPER_GL_PLUGIN_MACRO_H
