///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/01 14:26)

#ifndef RENDERING_SHADERS_INTERNAL_FWD_H
#define RENDERING_SHADERS_INTERNAL_FWD_H

#include "ShadersFwd.h"

namespace Rendering
{
    class ShaderFactory;
    class ShaderImpl;

    class ReflectionUniformFactory;
    class ReflectionUniformImpl;

    class ReflectionDataBlockFactory;
    class ReflectionDataBlockImpl;

    class ReflectionBufferVariableFactory;
    class ReflectionBufferVariableImpl;

    class ReflectionAtomicCounterBufferFactory;
    class ReflectionAtomicCounterBufferImpl;

    class ReflectionInputFactory;
    class ReflectionInputImpl;

    class ReflectionOutputFactory;
    class ReflectionOutputImpl;

    class ReflectionSubroutineUniformFactory;
    class ReflectionSubroutineUniformImpl;

    class ReflectionTransformFeedbackBufferFactory;
    class ReflectionTransformFeedbackBufferImpl;

    class ReflectionTransformFeedbackVaryingFactory;
    class ReflectionTransformFeedbackVaryingImpl;

    class ReflectionFactory;
    class ReflectionImpl;

    class ComputeProgramFactory;
    class ComputeProgramImpl;
}

#endif  // RENDERING_SHADERS_INTERNAL_FWD_H