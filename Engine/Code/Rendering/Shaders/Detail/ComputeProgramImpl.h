/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/26 14:57)

#ifndef RENDERING_SHADERS_COMPUTE_PROGRAM_IMPL_H
#define RENDERING_SHADERS_COMPUTE_PROGRAM_IMPL_H

#include "Rendering/RenderingDll.h"

#include "System/OpenGL/Using/OpenGLUsing.h"
#include "Rendering/Shaders/ShadersFwd.h"
#include "Rendering/Shaders/ShadersInternalFwd.h"

#include <memory>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE ComputeProgramImpl
    {
    public:
        using ClassType = ComputeProgramImpl;
        using FactoryType = ComputeProgramFactory;

        using OpenGLUInt = System::OpenGLUInt;
        using ShaderSharedPtr = std::shared_ptr<Shader>;
        using ConstShaderSharedPtr = std::shared_ptr<const Shader>;
        using ComputeProgramSharedPtr = std::shared_ptr<ComputeProgramImpl>;

    public:
        ComputeProgramImpl() noexcept;
        virtual ~ComputeProgramImpl() noexcept = default;
        ComputeProgramImpl(const ComputeProgramImpl& rhs) = default;
        ComputeProgramImpl& operator=(const ComputeProgramImpl& rhs) = default;
        ComputeProgramImpl(ComputeProgramImpl&& rhs) noexcept = default;
        ComputeProgramImpl& operator=(ComputeProgramImpl&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD ConstShaderSharedPtr GetComputeShader() const noexcept;
        NODISCARD ShaderSharedPtr GetComputeShader() noexcept;
        void SetComputeShader(const ShaderSharedPtr& shader);

        NODISCARD virtual Reflection GetReflector() const = 0;
        NODISCARD virtual ComputeProgramSharedPtr Clone() const = 0;
        NODISCARD virtual OpenGLUInt GetProgramHandle() const noexcept = 0;

        void CreateComputeShader();

    private:
        ShaderSharedPtr computeShader;
    };
}

#endif  // RENDERING_SHADERS_COMPUTE_PROGRAM_IMPL_H
