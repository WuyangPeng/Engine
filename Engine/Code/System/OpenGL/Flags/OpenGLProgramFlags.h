///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.1.6 (2021/06/27 1:57)

#ifndef SYSTEM_OPENGL_OPENGL_PROGRAM_FLAGS_H
#define SYSTEM_OPENGL_OPENGL_PROGRAM_FLAGS_H

#include "System/Helper/EnumMacro.h"
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
        ActiveUniformMaxLength = GL_ACTIVE_UNIFORM_MAX_LENGTH
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
        Location_Component = GL_LOCATION_COMPONENT
    };
}

#endif  // SYSTEM_OPENGL_OPENGL_PROGRAM_FLAGS_H
