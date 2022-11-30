///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.4 (2022/11/19 13:53)

#ifndef SYSTEM_HELPER_USER_MACRO_H
#define SYSTEM_HELPER_USER_MACRO_H

#include "ConfigMacro.h"

#define SYSTEM_ClOSE_BEGIN (0x01)

#define CLOSE_GLUT (SYSTEM_ClOSE_BEGIN)
#define CLOSE_GLFW (SYSTEM_ClOSE_BEGIN << 1)
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

    #define SYSTEM_USE_WINDOWS_MACRO static_cast<void>(0)

#endif  // SYSTEM_PLATFORM_WIN32

// �Ƿ�ʹ��������
#ifdef TCRE_USE_GCC

    #define SYSTEM_USE_SPIN_COUNT_CRITICAL_SECTION static_cast<void>(0)

#endif  // TCRE_USE_GCC

// �Ƿ�ʹ��glut
#if !defined(COMPILE_SYSTEM_CLOSE) || (COMPILE_SYSTEM_CLOSE & CLOSE_GLUT) != CLOSE_GLUT

    #define SYSTEM_USE_GLUT static_cast<void>(0)

#endif  //  !defined(COMPILE_SYSTEM_CLOSE) || (COMPILE_SYSTEM_CLOSE & CLOSE_GLUT) != CLOSE_GLUT

// �Ƿ�ʹ��glfw
#if !defined(COMPILE_SYSTEM_CLOSE) || (COMPILE_SYSTEM_CLOSE & CLOSE_GLFW) != CLOSE_GLFW

    #define SYSTEM_USE_GLFW static_cast<void>(0)

#endif  //  !defined(COMPILE_SYSTEM_CLOSE) || (COMPILE_SYSTEM_CLOSE & CLOSE_GLFW) != CLOSE_GLFW

#ifdef _DEBUG

    #if !defined(COMPILE_SYSTEM_CLOSE) || (COMPILE_SYSTEM_CLOSE & CLOSE_ENABLE_GL_ERROR_CHECKING) != CLOSE_ENABLE_GL_ERROR_CHECKING

        // �Ƿ���GL����
        #define SYSTEM_ENABLE_GL_ERROR_CHECKING static_cast<void>(0)

    #endif  //  !defined(COMPILE_SYSTEM_CLOSE) || (COMPILE_SYSTEM_CLOSE & CLOSE_ENABLE_GL_ERROR_CHECKING) != CLOSE_ENABLE_GL_ERROR_CHECKING

#endif  // _DEBUG

#ifdef SYSTEM_PLATFORM_WIN32

    #if !defined(COMPILE_SYSTEM_CLOSE) || (COMPILE_SYSTEM_CLOSE & CLOSE_DIRECTX) != CLOSE_DIRECTX

        // �Ƿ�ʹ��DirectX
        #define SYSTEM_USE_DIRECTX_12 static_cast<void>(0)

    #endif  //  !defined(COMPILE_SYSTEM_CLOSE) || (COMPILE_SYSTEM_CLOSE & CLOSE_DIRECTX) != CLOSE_DIRECTX

#endif  // SYSTEM_PLATFORM_WIN32

// �Ƿ����Ϊ��̬��
#ifdef BUILDING_STATIC

    #define BUILDING_SYSTEM_STATIC static_cast<void>(0)

#endif  // BUILDING_STATIC

#include "PragmaWarning/EngineDisable.h"

#endif  // SYSTEM_HELPER_USER_MACRO_H
