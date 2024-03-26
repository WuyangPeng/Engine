/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/04 21:48)

#ifndef SYSTEM_HELPER_GL_EXTENSIONS_MACRO_H
#define SYSTEM_HELPER_GL_EXTENSIONS_MACRO_H

#include "System/Helper/ConfigMacro.h"
#include "System/Helper/Platform.h"

#if defined(__gl_h_) || defined(__GL_H__) || defined(_GL_H) || defined(__gl_gl_h_) || defined(__X_GL_H)

    #error "gl.h������GLExtensionsMacro.h֮ǰ"

#endif  // defined(__gl_h_) || defined(__GL_H__) || defined(_GL_H) || defined(__gl_gl_h_) || defined(__X_GL_H)

#if defined(__gl2_h_)

    #error "gl2.h������GLExtensionsMacro.h֮ǰ"

#endif  // __gl2_h_

#if defined(__gltypes_h_)

    #error "gltypes.h������GLExtensionsMacro.h֮ǰ"

#endif  // __gltypes_h_

#if defined(__REGAL_H__)

    #error "Regal.h������GLExtensionsMacro.h֮ǰ"

#endif  // __REGAL_H__

#if defined(__glext_h_) || defined(__GLEXT_H_) || defined(__gl_glext_h_)

    #error "glext.h������GLExtensionsMacro.h֮ǰ"

#endif  // defined(__glext_h_) || defined(__GLEXT_H_) || defined(__gl_glext_h_)

#if defined(__gl_ATI_h_)

    #error "glATI.h������GLExtensionsMacro.h֮ǰ"

#endif  // __gl_ATI_h_

#define __gl_h_ static_cast<void>(0)
#define __gl2_h_ static_cast<void>(0)
#define __GL_H__ static_cast<void>(0)
#define _GL_H static_cast<void>(0)
#define __gl_gl_h_ static_cast<void>(0)
#define __gltypes_h_ static_cast<void>(0)
#define __REGAL_H__ static_cast<void>(0)
#define __X_GL_H static_cast<void>(0)
#define __glext_h_ static_cast<void>(0)
#define __GLEXT_H_ static_cast<void>(0)
#define __gl_glext_h_ static_cast<void>(0)
#define __gl_ATI_h_ static_cast<void>(0)

#if defined(SYSTEM_PLATFORM_WIN32) || defined(SYSTEM_PLATFORM_LINUX)

    #include <GL/glcorearb.h>

#endif  // defined(SYSTEM_PLATFORM_WIN32) || defined(SYSTEM_PLATFORM_LINUX)

#endif  // SYSTEM_HELPER_GL_EXTENSIONS_MACRO_H
