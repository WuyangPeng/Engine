//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/21 17:38)

#ifndef SYSTEM_HELPER_GL_14_FLAGS_H
#define SYSTEM_HELPER_GL_14_FLAGS_H

#include "System/Helper/UserMacro.h"

namespace System
{
    enum class GL14Flags
    {
        BlendFuncSeparate,
        FogCoordd,
        FogCoorddv,
        FogCoordf,
        FogCoordfv,
        FogCoordPointer,
        MultiDrawArrays,
        MultiDrawElements,
        PointParameterf,
        PointParameterfv,
        PointParameteri,
        PointParameteriv,
        SecondaryColor3b,
        SecondaryColor3bv,
        SecondaryColor3d,
        SecondaryColor3dv,
        SecondaryColor3f,
        SecondaryColor3fv,
        SecondaryColor3i,
        SecondaryColor3iv,
        SecondaryColor3s,
        SecondaryColor3sv,
        SecondaryColor3ub,
        SecondaryColor3ubv,
        SecondaryColor3ui,
        SecondaryColor3uiv,
        SecondaryColor3us,
        SecondaryColor3usv,
        SecondaryColorPointer,
        WindowPos2d,
        WindowPos2dv,
        WindowPos2f,
        WindowPos2fv,
        WindowPos2i,
        WindowPos2iv,
        WindowPos2s,
        WindowPos2sv,
        WindowPos3d,
        WindowPos3dv,
        WindowPos3f,
        WindowPos3fv,
        WindowPos3i,
        WindowPos3iv,
        WindowPos3s,
        WindowPos3sv,
    };
}

#endif  // SYSTEM_HELPER_GL_14_FLAGS_H
