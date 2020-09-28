//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.0 (2020/09/21 17:37)

#ifndef SYSTEM_HELPER_GL_EXTENSIONS_MACRO_H
#define SYSTEM_HELPER_GL_EXTENSIONS_MACRO_H

#include "System/Helper/ConfigMacro.h"

#if defined(__gl_h_) || defined(__GL_H__) || defined(_GL_H) || defined(__X_GL_H)
    #error "gl.h������GLExtensionsMacro.h֮ǰ"
#endif  // defined(__gl_h_) || defined(__GL_H__) || defined(_GL_H) || defined(__X_GL_H)

#if defined(__gl2_h_)
    #error "gl2.h������GLExtensionsMacro.h֮ǰ"
#endif  // __gl2_h_

#if defined(__gltypes_h_)
    #error "gltypes.h������GLExtensionsMacro.h֮ǰ"
#endif  // __gltypes_h_

#if defined(__REGAL_H__)
    #error "Regal.h������GLExtensionsMacro.h֮ǰ"
#endif  // __REGAL_H__

#if defined(__glext_h_) || defined(__GLEXT_H_)
    #error "glext.h������GLExtensionsMacro.h֮ǰ"
#endif  // defined(__glext_h_) || defined(__GLEXT_H_)

#if defined(__gl_ATI_h_)
    #error "glATI.h������GLExtensionsMacro.h֮ǰ"
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
