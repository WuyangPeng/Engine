///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.1 (2023/07/01 16:46)

#ifndef RENDERING_SHADERS_FWD_H
#define RENDERING_SHADERS_FWD_H

namespace Rendering
{
    enum class ShaderDataLookup;
    enum class ShaderAPIType;
    enum class ReferenceType;

    class ShaderData;
    class Shader;
    class VisualProgram;
    class ComputeProgram;
    class ProgramFactory;
    class ProgramDefines;
    class ProgramSources;

    class Reflection;
    class ReflectionUniform;
    class ReflectionDataBlock;
    class ReflectionAtomicCounterBuffer;
    class ReflectionBufferVariable;
    class ReflectionInput;
    class ReflectionOutput;
    class ReflectionSubroutineUniform;
    class ReflectionTransformFeedbackBuffer;
    class ReflectionTransformFeedbackVarying;
}

#endif  // RENDERING_SHADERS_FWD_H