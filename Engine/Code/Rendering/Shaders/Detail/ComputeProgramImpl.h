///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.1 (2022/08/20 16:17)

#ifndef RENDERING_SHADERS_COMPUTE_PROGRAM_IMPL_H
#define RENDERING_SHADERS_COMPUTE_PROGRAM_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Rendering/OpenGLRenderer/GLSL/GLSLReflection.h"
#include "Rendering/Shaders/ShadersFwd.h"

#include <memory>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE ComputeProgramImpl
    {
    public:
        using ClassType = ComputeProgramImpl;
        using ShaderSharedPtr = std::shared_ptr<Shader>;
        using ConstShaderSharedPtr = std::shared_ptr<const Shader>;
        using ComputeProgramSharedPtr = std::shared_ptr<ComputeProgramImpl>;
        using FactoryType = ComputeProgramImpl;
        using OpenGLUInt = System::OpenGLUInt;

    public:
        NODISCARD static ComputeProgramSharedPtr Create(OpenGLUInt programHandle, OpenGLUInt computeShaderHandle);
        ComputeProgramImpl() noexcept;
        virtual ~ComputeProgramImpl() noexcept = default;
        ComputeProgramImpl(const ComputeProgramImpl& rhs) = default;
        ComputeProgramImpl& operator=(const ComputeProgramImpl& rhs) = default;
        ComputeProgramImpl(ComputeProgramImpl&& rhs) noexcept = default;
        ComputeProgramImpl& operator=(ComputeProgramImpl&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD ConstShaderSharedPtr GetComputeShader() const noexcept;

        void SetComputeShader(const ShaderSharedPtr& shader);
        NODISCARD virtual GLSLReflection GetReflector() const;
        NODISCARD virtual ComputeProgramSharedPtr Clone() const;

    private:
        ShaderSharedPtr computeShader;
    };
}

#endif  // RENDERING_SHADERS_COMPUTE_PROGRAM_IMPL_H
