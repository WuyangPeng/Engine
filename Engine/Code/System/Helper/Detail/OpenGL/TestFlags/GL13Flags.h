//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/21 17:38)

#ifndef SYSTEM_HELPER_GL_13_FLAGS_H
#define SYSTEM_HELPER_GL_13_FLAGS_H

#include "System/Helper/UserMacro.h"

namespace System
{
    enum class GL13Flags
    {
        ActiveTexture,
        ClientActiveTexture,
        MultiTexCoord1d,
        MultiTexCoord1dv,
        MultiTexCoord1f,
        MultiTexCoord1fv,
        MultiTexCoord1i,
        MultiTexCoord1iv,
        MultiTexCoord1s,
        MultiTexCoord1sv,
        MultiTexCoord2d,
        MultiTexCoord2dv,
        MultiTexCoord2f,
        MultiTexCoord2fv,
        MultiTexCoord2i,
        MultiTexCoord2iv,
        MultiTexCoord2s,
        MultiTexCoord2sv,
        MultiTexCoord3d,
        MultiTexCoord3dv,
        MultiTexCoord3f,
        MultiTexCoord3fv,
        MultiTexCoord3i,
        MultiTexCoord3iv,
        MultiTexCoord3s,
        MultiTexCoord3sv,
        MultiTexCoord4d,
        MultiTexCoord4dv,
        MultiTexCoord4f,
        MultiTexCoord4fv,
        MultiTexCoord4i,
        MultiTexCoord4iv,
        MultiTexCoord4s,
        MultiTexCoord4sv,
        LoadTransposeMatrixd,
        LoadTransposeMatrixf,
        MultTransposeMatrixd,
        MultTransposeMatrixf,
        SampleCoverage,
        CompressedTexImage1D,
        CompressedTexImage2D,
        CompressedTexImage3D,
        CompressedTexSubImage1D,
        CompressedTexSubImage2D,
        CompressedTexSubImage3D,
        GetCompressedTexImage,
    };
}

#endif  // SYSTEM_HELPER_GL_13_FLAGS_H
