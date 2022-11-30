///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.1 (2022/08/20 16:17)

#ifndef RENDERING_SHADERS_COMPUTE_PROGRAM_H
#define RENDERING_SHADERS_COMPUTE_PROGRAM_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "Rendering/OpenGLRenderer/GLSL/GLSLReflection.h"
#include "Rendering/Shaders/ShadersFwd.h"

RENDERING_COPY_UNSHARED_EXPORT_IMPL(ComputeProgram, ComputeProgramImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE ComputeProgram
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(ComputeProgram);
        using ShaderSharedPtr = std::shared_ptr<Shader>;
        using ConstShaderSharedPtr = std::shared_ptr<const Shader>;
        using OpenGLUInt = System::OpenGLUInt;

    public:
        explicit ComputeProgram(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow);
        ComputeProgram(OpenGLUInt programHandle, OpenGLUInt computeShaderHandle);
        virtual ~ComputeProgram() noexcept = default;
        ComputeProgram(const ComputeProgram& rhs) = default;
        ComputeProgram& operator=(const ComputeProgram& rhs) = default;
        ComputeProgram(ComputeProgram&& rhs) noexcept = default;
        ComputeProgram& operator=(ComputeProgram&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD ConstShaderSharedPtr GetComputeShader() const noexcept;

        void SetComputeShader(const ShaderSharedPtr& shader);
        NODISCARD GLSLReflection GetReflector() const;

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_SHADERS_COMPUTE_PROGRAM_H
