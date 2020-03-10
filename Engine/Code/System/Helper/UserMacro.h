// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.0 (2020/01/02 15:13)

#ifndef SYSTEM_HELPER_USER_MACRO_H
#define SYSTEM_HELPER_USER_MACRO_H

#include "ConfigMacro.h"

#define CLOSE_OPENGL2_NORMAL_ATTRIBUTES (0x01)
#define CLOSE_GLUT (0x01 << 1)
#define CLOSE_ENABLE_GL_ERROR_CHECKING (0x01 << 2)
#define CLOSE_DIRECTX (0x01 << 3)
#define CLOSE_SYSTEM_MAX ((CLOSE_DIRECTX << 1) - 1)

// ������ԣ�Ĭ��Ϊ0�����ֵΪ0x0F��
#define COMPILE_SYSTEM_CLOSE 0x00

static_assert(0 <= COMPILE_SYSTEM_CLOSE, "COMPILE_SYSTEM_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_SYSTEM_CLOSE <= CLOSE_SYSTEM_MAX, "COMPILE_SYSTEM_CLOSE Must be less than or equal CLOSE_SYSTEM_MAX.");

// �Ƿ����Ϊ��̬��
#ifdef BUILDING_STATIC
	#define BUILDING_SYSTEM_STATIC
#endif // BUILDING_STATIC

// �Ƿ�ʹ��Windows��
#ifdef SYSTEM_PLATFORM_WIN32	 
	#define SYSTEM_USE_WINDOWS_MACRO
#endif // SYSTEM_PLATFORM_WIN32

// �Ƿ�ʹ��������
#ifdef TCRE_USE_GCC
	#define SYSTEM_USE_SPIN_COUNT_CRITICAL_SECTION  
#endif // TCRE_USE_GCC

// ��Щ��OpenGL 2.x������������ȷ���������ԡ�
// ����һ�����⣬��Ӧ��Ҫʹ�÷���ʸ����һ��4Ԫ�����Ϣ�����ݵ���ɫ����OpenGL 1.x��glNormalPointer�ٶ�������3Ԫ�顣
// �����֪�����Ŀ�������ȷ֧��OpenGL 2.x�ķ������ԣ����������#define��
// ������Ⱦ����ʹ��OpenGL 1.x��glNormalPointer��

// ��Macintosh�ϣ�������PowerPC����Ӣ�ض���NVIDIA�Կ�������ͨ�����Բ������á�
// ������Ϊ����ʹ��OpenGL 1.x����չ��ɫ����̡�������Ҫ���µ�OpenGL 2.x�����߰汾��

// �Ƿ�ʹ��OpenGL2��Ĭ��ʹ��
#if !defined(COMPILE_SYSTEM_CLOSE) || (COMPILE_SYSTEM_CLOSE & CLOSE_OPENGL2_NORMAL_ATTRIBUTES) != CLOSE_OPENGL2_NORMAL_ATTRIBUTES
	#define SYSTEM_USE_OPENGL2_NORMAL_ATTRIBUTES
#endif // !defined(COMPILE_SYSTEM_CLOSE) || (COMPILE_SYSTEM_CLOSE & CLOSE_OPENGL2_NORMAL_ATTRIBUTES) != CLOSE_OPENGL2_NORMAL_ATTRIBUTES

#if !defined(SYSTEM_USE_OPENGL2_NORMAL_ATTRIBUTES) &&  defined(SYSTEM_PLATFORM_MACOS)
	#define SYSTEM_USE_OPENGL2_NORMAL_ATTRIBUTES
#endif // !defined(SYSTEM_USE_OPENGL2_NORMAL_ATTRIBUTES) &&  defined(SYSTEM_PLATFORM_MACOS) 

// �Ƿ�ʹ��glut��Ĭ��ʹ��
#if !defined(COMPILE_SYSTEM_CLOSE) || (COMPILE_SYSTEM_CLOSE & CLOSE_GLUT) != CLOSE_GLUT
	#define SYSTEM_USE_GLUT
#endif //  !defined(COMPILE_SYSTEM_CLOSE) || (COMPILE_SYSTEM_CLOSE & CLOSE_GLUT) != CLOSE_GLUT

// �Ƿ���GL����
#if !defined(COMPILE_SYSTEM_CLOSE) || (COMPILE_SYSTEM_CLOSE & CLOSE_ENABLE_GL_ERROR_CHECKING) != CLOSE_ENABLE_GL_ERROR_CHECKING
	#ifdef _DEBUG
		#define SYSTEM_ENABLE_GL_ERROR_CHECKING
	#endif // _DEBUG
#endif //  !defined(COMPILE_SYSTEM_CLOSE) || (COMPILE_SYSTEM_CLOSE & CLOSE_ENABLE_GL_ERROR_CHECKING) != CLOSE_ENABLE_GL_ERROR_CHECKING

// �Ƿ�ʹ��DirectX
#if !defined(COMPILE_SYSTEM_CLOSE) || (COMPILE_SYSTEM_CLOSE & CLOSE_DIRECTX) != CLOSE_DIRECTX
	#ifdef SYSTEM_PLATFORM_WIN32	 
		#define SYSTEM_USE_DIRECT_X_9
		#define SYSTEM_USE_DIRECT_X_10
		#define SYSTEM_USE_DIRECT_X_11
	#endif // SYSTEM_PLATFORM_WIN32
#endif //  !defined(COMPILE_SYSTEM_CLOSE) || (COMPILE_SYSTEM_CLOSE & CLOSE_DIRECTX) != CLOSE_DIRECTX

#include "PragmaWarning/EngineDisable.h"
	  
#endif // SYSTEM_HELPER_USER_MACRO_H
