/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/26 14:57)

#ifndef RENDERING_SHADERS_COMPUTE_PROGRAM_FACTORY_H
#define RENDERING_SHADERS_COMPUTE_PROGRAM_FACTORY_H

#include "Rendering/RenderingDll.h"

#include "System/OpenGL/Using/OpenGLUsing.h"
#include "Rendering/OpenGLRenderer/GLSL/GLSLProgramHandle.h"
#include "Rendering/OpenGLRenderer/GLSL/GLSLShaderHandle.h"
#include "Rendering/Shaders/ShadersInternalFwd.h"

#include <memory>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE ComputeProgramFactory
    {
    public:
        using ClassType = ComputeProgramFactory;

        using OpenGLUInt = System::OpenGLUnsignedInt;
        using ComputeProgramSharedPtr = std::shared_ptr<ComputeProgramImpl>;

    public:
        NODISCARD static ComputeProgramSharedPtr Create(const GLSLProgramHandle& programHandle, const GLSLShaderHandle& computeShaderHandle);
        NODISCARD static ComputeProgramSharedPtr Create();

        CLASS_INVARIANT_DECLARE;
    };
}

#endif  // RENDERING_SHADERS_COMPUTE_PROGRAM_FACTORY_H
