//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/21 17:38)

#ifndef SYSTEM_HELPER_GL_15_FLAGS_H
#define SYSTEM_HELPER_GL_15_FLAGS_H

#include "System/Helper/UserMacro.h"

namespace System
{
    enum class GL15Flags
    {
        GenQueries,
        DeleteQueries,
        IsQuery,
        BeginQuery,
        EndQuery,
        GetQueryiv,
        GetQueryObjectiv,
        GetQueryObjectuiv,
        BindBuffer,
        DeleteBuffers,
        GenBuffers,
        IsBuffer,
        BufferData,
        BufferSubData,
        GetBufferSubData,
        MapBuffer,
        UnmapBuffer,
        GetBufferParameteriv,
        GetBufferPointerv,
    };
}

#endif  // SYSTEM_HELPER_GL_15_FLAGS_H
