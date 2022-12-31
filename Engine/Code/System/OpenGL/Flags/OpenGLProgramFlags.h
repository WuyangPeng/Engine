///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.4 (2022/11/19 18:23)

#ifndef SYSTEM_OPENGL_OPENGL_PROGRAM_FLAGS_H
#define SYSTEM_OPENGL_OPENGL_PROGRAM_FLAGS_H

#include "System/Helper/EnumOperator.h"
#include "System/Helper/GLExtensionsMacro.h"

namespace System
{
    enum class ProgramStatus
    {
        Delete = GL_DELETE_STATUS,
        Link = GL_LINK_STATUS,
        Validate = GL_VALIDATE_STATUS,
    };

    enum class ProgramAttributes
    {
        InfoLogLength = GL_INFO_LOG_LENGTH,
        AttachedShaders = GL_ATTACHED_SHADERS,
        ActiveAttributes = GL_ACTIVE_ATTRIBUTES,
        ActiveAttributeMaxLength = GL_ACTIVE_ATTRIBUTE_MAX_LENGTH,
        ActiveUniforms = GL_ACTIVE_UNIFORMS,
        ActiveUniformMaxLength = GL_ACTIVE_UNIFORM_MAX_LENGTH,
        ComputeWorkGroupSize = GL_COMPUTE_WORK_GROUP_SIZE,
    };

    enum class ProgramInterface
    {
        Uniform = GL_UNIFORM,
        UniformBlock = GL_UNIFORM_BLOCK,
        AtomicCounterBuffer = GL_ATOMIC_COUNTER_BUFFER,
        ProgramInput = GL_PROGRAM_INPUT,
        ProgramOutput = GL_PROGRAM_OUTPUT,
        VertexSubroutine = GL_VERTEX_SUBROUTINE,
        TessControlSubroutine = GL_TESS_CONTROL_SUBROUTINE,
        TessEvaluationSubroutine = GL_TESS_EVALUATION_SUBROUTINE,
        GeometrySubroutine = GL_GEOMETRY_SUBROUTINE,
        FragmentSubroutine = GL_FRAGMENT_SUBROUTINE,
        ComputeSubroutine = GL_COMPUTE_SUBROUTINE,
        VertexSubroutineUniform = GL_VERTEX_SUBROUTINE_UNIFORM,
        TessControlSubroutineUniform = GL_TESS_CONTROL_SUBROUTINE_UNIFORM,
        TessEvaluationSubroutineUniform = GL_TESS_EVALUATION_SUBROUTINE_UNIFORM,
        GeometrySubroutineUniform = GL_GEOMETRY_SUBROUTINE_UNIFORM,
        FragmentSubroutineUniform = GL_FRAGMENT_SUBROUTINE_UNIFORM,
        ComputeSubroutineUniform = GL_COMPUTE_SUBROUTINE_UNIFORM,
        TransformFeedbackVarying = GL_TRANSFORM_FEEDBACK_VARYING,
        BufferVariable = GL_BUFFER_VARIABLE,
        ShaderStorageBlock = GL_SHADER_STORAGE_BLOCK,
        TransformFeedbackBuffer = GL_TRANSFORM_FEEDBACK_BUFFER,
    };

    enum class ProgramInterfaceName
    {
        ActiveResources = GL_ACTIVE_RESOURCES,
        MaxNameLength = GL_MAX_NAME_LENGTH,
        MaxNumActiveVariables = GL_MAX_NUM_ACTIVE_VARIABLES,
        MaxNumCompatibleSubroutines = GL_MAX_NUM_COMPATIBLE_SUBROUTINES,
    };

    enum class ProgramProperties
    {
        NameLength = GL_NAME_LENGTH,
        Type = GL_TYPE,
        Location = GL_LOCATION,
        ArraySize = GL_ARRAY_SIZE,
        ReferencedByVertexShader = GL_REFERENCED_BY_VERTEX_SHADER,
        ReferencedByGeometryShader = GL_REFERENCED_BY_GEOMETRY_SHADER,
        ReferencedByFragmentShader = GL_REFERENCED_BY_FRAGMENT_SHADER,
        ReferencedByComputeShader = GL_REFERENCED_BY_COMPUTE_SHADER,
        ReferencedByTessControlShader = GL_REFERENCED_BY_TESS_CONTROL_SHADER,
        ReferencedByTessEvaluationShader = GL_REFERENCED_BY_TESS_EVALUATION_SHADER,
        IsPerPatch = GL_IS_PER_PATCH,
        LocationComponent = GL_LOCATION_COMPONENT,
        LocationIndex = GL_LOCATION_INDEX,
        Offset = GL_OFFSET,
        BlockIndex = GL_BLOCK_INDEX,
        ArrayStride = GL_ARRAY_STRIDE,
        MatrixStride = GL_MATRIX_STRIDE,
        IsRowMajor = GL_IS_ROW_MAJOR,
        AtomicCounterBufferIndex = GL_ATOMIC_COUNTER_BUFFER_INDEX,
        BufferBinding = GL_BUFFER_BINDING,
        BufferDataSize = GL_BUFFER_DATA_SIZE,
        NumActiveVariables = GL_NUM_ACTIVE_VARIABLES,
        ActiveVariables = GL_ACTIVE_VARIABLES,
        CompatibleSubroutines = GL_COMPATIBLE_SUBROUTINES,
        TopLevelArraySize = GL_TOP_LEVEL_ARRAY_SIZE,
        TopLevelArrayStride = GL_TOP_LEVEL_ARRAY_STRIDE,
        TransformFeedbackBufferIndex = GL_TRANSFORM_FEEDBACK_BUFFER_INDEX,
        TransformFeedbackBufferStride = GL_TRANSFORM_FEEDBACK_BUFFER_STRIDE,
    };
}

#endif  // SYSTEM_OPENGL_OPENGL_PROGRAM_FLAGS_H
