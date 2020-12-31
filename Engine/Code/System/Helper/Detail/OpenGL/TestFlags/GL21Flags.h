//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/21 17:38)

#ifndef SYSTEM_HELPER_GL_21_FLAGS_H
#define SYSTEM_HELPER_GL_21_FLAGS_H

#include "System/Helper/UserMacro.h"

namespace System
{
    enum class GL21Flags
    {
        UniformMatrix2x3fv,
        UniformMatrix3x2fv,
        UniformMatrix2x4fv,
        UniformMatrix4x2fv,
        UniformMatrix3x4fv,
        UniformMatrix4x3fv,
    };
}

#endif  // SYSTEM_HELPER_GL_21_FLAGS_H
