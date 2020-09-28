//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.0 (2020/09/21 11:19)

#ifndef SYSTEM_HELPER_USER_MACRO_H
#define SYSTEM_HELPER_USER_MACRO_H

#include "ConfigMacro.h"

#define SYSTEM_ClOSE_BEGIN (0x01)

#define CLOSE_OPENGL2_NORMAL_ATTRIBUTES (SYSTEM_ClOSE_BEGIN)
#define CLOSE_GLUT (SYSTEM_ClOSE_BEGIN << 1)
#define CLOSE_ENABLE_GL_ERROR_CHECKING (SYSTEM_ClOSE_BEGIN << 2)
#define CLOSE_DIRECTX (SYSTEM_ClOSE_BEGIN << 3)

#define SYSTEM_ClOSE_END CLOSE_DIRECTX

#define CLOSE_SYSTEM_MAX ((SYSTEM_ClOSE_END << 1) - 1)

// ������ԣ�Ĭ��Ϊ0�����ֵΪ0x0F��
#define COMPILE_SYSTEM_CLOSE 0x00

static_assert(0 <= COMPILE_SYSTEM_CLOSE, "COMPILE_SYSTEM_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_SYSTEM_CLOSE <= CLOSE_SYSTEM_MAX, "COMPILE_SYSTEM_CLOSE Must be less than or equal CLOSE_SYSTEM_MAX.");

// �Ƿ�ʹ��Windows��
#ifdef SYSTEM_PLATFORM_WIN32
    #define SYSTEM_USE_WINDOWS_MACRO
#endif  // SYSTEM_PLATFORM_WIN32

// �Ƿ�ʹ��������
#ifdef TCRE_USE_GCC
    #define SYSTEM_USE_SPIN_COUNT_CRITICAL_SECTION
#endif  // TCRE_USE_GCC

// ��ЩOpenGL 2.x�����������޷���ȷ���������ԡ�
// �������ʹ�÷���������4Ԫ�����Ϣ���ݸ���ɫ����������һ�����⡣
// OpenGL 1.x��glNormalPointer�ٶ�������3Ԫ�顣
// ���֪��Ŀ��������ȷ֧��OpenGL 2.x�ķ������ԣ�����SYSTEM_USE_OPENGL2_NORMAL_ATTRIBUTES��
// ������Ⱦ����ʹ��OpenGL 1.x��glNormalPointer��

// ��Macintosh�ϣ�������PowerPC����Ӣ�ض���NVIDIA�Կ������ߵ�ͨ�����Ծ��������á�
// ������Ϊ��������ʹ��OpenGL 1.x����չ���������ɫ����̡�������Ҫ���µ�OpenGL 2.x�����߰汾��

#if !defined(COMPILE_SYSTEM_CLOSE) || (COMPILE_SYSTEM_CLOSE & CLOSE_OPENGL2_NORMAL_ATTRIBUTES) != CLOSE_OPENGL2_NORMAL_ATTRIBUTES
    #define SYSTEM_USE_OPENGL2_NORMAL_ATTRIBUTES
#endif  // !defined(COMPILE_SYSTEM_CLOSE) || (COMPILE_SYSTEM_CLOSE & CLOSE_OPENGL2_NORMAL_ATTRIBUTES) != CLOSE_OPENGL2_NORMAL_ATTRIBUTES

#if !defined(SYSTEM_USE_OPENGL2_NORMAL_ATTRIBUTES) && defined(SYSTEM_PLATFORM_MACOS)
    #define SYSTEM_USE_OPENGL2_NORMAL_ATTRIBUTES
#endif  // !defined(SYSTEM_USE_OPENGL2_NORMAL_ATTRIBUTES) && defined(SYSTEM_PLATFORM_MACOS)

// �Ƿ�ʹ��glut��Ĭ��ʹ��
#if !defined(COMPILE_SYSTEM_CLOSE) || (COMPILE_SYSTEM_CLOSE & CLOSE_GLUT) != CLOSE_GLUT
    #define SYSTEM_USE_GLUT
#endif  //  !defined(COMPILE_SYSTEM_CLOSE) || (COMPILE_SYSTEM_CLOSE & CLOSE_GLUT) != CLOSE_GLUT

#ifdef _DEBUG

    #if !defined(COMPILE_SYSTEM_CLOSE) || (COMPILE_SYSTEM_CLOSE & CLOSE_ENABLE_GL_ERROR_CHECKING) != CLOSE_ENABLE_GL_ERROR_CHECKING
        // �Ƿ���GL����
        #define SYSTEM_ENABLE_GL_ERROR_CHECKING
    #endif  //  !defined(COMPILE_SYSTEM_CLOSE) || (COMPILE_SYSTEM_CLOSE & CLOSE_ENABLE_GL_ERROR_CHECKING) != CLOSE_ENABLE_GL_ERROR_CHECKING

#endif  // _DEBUG

#ifdef SYSTEM_PLATFORM_WIN32

    #if !defined(COMPILE_SYSTEM_CLOSE) || (COMPILE_SYSTEM_CLOSE & CLOSE_DIRECTX) != CLOSE_DIRECTX
        // �Ƿ�ʹ��DirectX
        #define SYSTEM_USE_DIRECTX_9
        #define SYSTEM_USE_DIRECTX_10
        #define SYSTEM_USE_DIRECTX_11
    #endif  //  !defined(COMPILE_SYSTEM_CLOSE) || (COMPILE_SYSTEM_CLOSE & CLOSE_DIRECTX) != CLOSE_DIRECTX

#endif  // SYSTEM_PLATFORM_WIN32

// �Ƿ����Ϊ��̬��
#ifdef BUILDING_STATIC
    #define BUILDING_SYSTEM_STATIC static_cast<void>(0)
#endif  // BUILDING_STATIC

#include "PragmaWarning/EngineDisable.h"

#endif  // SYSTEM_HELPER_USER_MACRO_H
