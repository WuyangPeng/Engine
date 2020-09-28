//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/21 17:37)

#ifndef SYSTEM_HELPER_GL_EXTENSIONS_MACRO_H
#define SYSTEM_HELPER_GL_EXTENSIONS_MACRO_H

#include "System/Helper/ConfigMacro.h"

#if defined(__gl_h_) || defined(__GL_H__) || defined(_GL_H) || defined(__X_GL_H)
    #error "gl.h包含在GLExtensionsMacro.h之前"
#endif  // defined(__gl_h_) || defined(__GL_H__) || defined(_GL_H) || defined(__X_GL_H)

#if defined(__gl2_h_)
    #error "gl2.h包含在GLExtensionsMacro.h之前"
#endif  // __gl2_h_

#if defined(__gltypes_h_)
    #error "gltypes.h包含在GLExtensionsMacro.h之前"
#endif  // __gltypes_h_

#if defined(__REGAL_H__)
    #error "Regal.h包含在GLExtensionsMacro.h之前"
#endif  // __REGAL_H__

#if defined(__glext_h_) || defined(__GLEXT_H_)
    #error "glext.h包含在GLExtensionsMacro.h之前"
#endif  // defined(__glext_h_) || defined(__GLEXT_H_)

#if defined(__gl_ATI_h_)
    #error "glATI.h包含在GLExtensionsMacro.h之前"
#endif  // __gl_ATI_h_

#define __gl_h_
#define __gl2_h_
#define __GL_H__
#define __gltypes_h_
#define __REGAL_H__
#define __X_GL_H
#define __glext_h_
#define __GLEXT_H_
#define __gl_ATI_h_

#endif  // SYSTEM_HELPER_GL_EXTENSIONS_MACRO_H
