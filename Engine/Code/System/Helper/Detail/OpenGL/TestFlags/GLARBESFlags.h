//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/21 17:39)

#ifndef SYSTEM_HELPER_GL_ARB_ES_FLAGS_H
#define SYSTEM_HELPER_GL_ARB_ES_FLAGS_H

#include "System/Helper/UserMacro.h"

namespace System
{
    enum class GLARBES2CompatibilityFlags
    {
        ClearDepthf,
        DepthRangef,
        GetShaderPrecisionFormat,
        ReleaseShaderCompiler,
        ShaderBinary,
    };

    enum class GLARBES3CompatibilityFlags
    {
        MemoryBarrierByRegion,
    };
}

#endif  // SYSTEM_HELPER_GL_ARB_ES_FLAGS_H
