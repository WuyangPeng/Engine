/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/04 21:48)

#ifndef SYSTEM_HELPER_GL_EXTENSIONS_MACRO_H
#define SYSTEM_HELPER_GL_EXTENSIONS_MACRO_H

#include "System/Helper/ConfigMacro.h"
#include "System/Helper/Platform.h"

#if defined(__gl_h_) || defined(__GL_H__) || defined(_GL_H) || defined(__gl_gl_h_) || defined(__X_GL_H)

    #error "gl.h包含在GLExtensionsMacro.h之前"

#endif  // defined(__gl_h_) || defined(__GL_H__) || defined(_GL_H) || defined(__gl_gl_h_) || defined(__X_GL_H)

#if defined(__gl2_h_)

    #error "gl2.h包含在GLExtensionsMacro.h之前"

#endif  // __gl2_h_

#if defined(__gltypes_h_)

    #error "gltypes.h包含在GLExtensionsMacro.h之前"

#endif  // __gltypes_h_

#if defined(__REGAL_H__)

    #error "Regal.h包含在GLExtensionsMacro.h之前"

#endif  // __REGAL_H__

#if defined(__glext_h_) || defined(__GLEXT_H_) || defined(__gl_glext_h_)

    #error "glext.h包含在GLExtensionsMacro.h之前"

#endif  // defined(__glext_h_) || defined(__GLEXT_H_) || defined(__gl_glext_h_)

#if defined(__gl_ATI_h_)

    #error "glATI.h包含在GLExtensionsMacro.h之前"

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
