/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2023/12/26 15:05)

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