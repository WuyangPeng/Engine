/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/26 15:03)

#ifndef RENDERING_SHADERS_COMPUTE_PROGRAM_H
#define RENDERING_SHADERS_COMPUTE_PROGRAM_H

#include "Rendering/RenderingDll.h"

#include "System/OpenGL/Using/OpenGLUsing.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "Rendering/OpenGLRenderer/GLSL/GLSLProgramHandle.h"
#include "Rendering/OpenGLRenderer/GLSL/GLSLShaderHandle.h"
#include "Rendering/Shaders/ShadersFwd.h"

RENDERING_COPY_UNSHARED_EXPORT_IMPL(ComputeProgram, ComputeProgramImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE ComputeProgram
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(ComputeProgram);

        using OpenGLUInt = System::OpenGLUnsignedInt;
        using ShaderSharedPtr = std::shared_ptr<Shader>;
        using ConstShaderSharedPtr = std::shared_ptr<const Shader>;
        using ComputeProgramSharedPtr = std::shared_ptr<ComputeProgram>;

    public:
        NODISCARD static ComputeProgram Create();
        NODISCARD static ComputeProgramSharedPtr Create(const std::string& computeShaderSource, const std::string& version, const ProgramDefines& defines);
        ComputeProgram(const GLSLProgramHandle& programHandle, const GLSLShaderHandle& computeShaderHandle);
        virtual ~ComputeProgram() noexcept = default;
        ComputeProgram(const ComputeProgram& rhs) = default;
        ComputeProgram& operator=(const ComputeProgram& rhs) = default;
        ComputeProgram(ComputeProgram&& rhs) noexcept = default;
        ComputeProgram& operator=(ComputeProgram&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD ConstShaderSharedPtr GetComputeShader() const noexcept;
        NODISCARD ShaderSharedPtr GetComputeShader() noexcept;
        NODISCARD OpenGLUInt GetProgramHandle() const noexcept;

        void SetComputeShader(const ShaderSharedPtr& shader);
        NODISCARD Reflection GetReflector() const;

        void CreateComputeShader();

    protected:
        explicit ComputeProgram(CoreTools::DisableNotThrow disableNotThrow);

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_SHADERS_COMPUTE_PROGRAM_H
