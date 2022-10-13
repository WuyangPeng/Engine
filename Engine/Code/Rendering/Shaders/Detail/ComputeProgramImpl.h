///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.1 (2022/08/20 16:17)

#ifndef RENDERING_SHADERS_COMPUTE_PROGRAM_IMPL_H
#define RENDERING_SHADERS_COMPUTE_PROGRAM_IMPL_H

#include "Rendering/RenderingDll.h"

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

    public:
        ComputeProgramImpl() noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD ConstShaderSharedPtr GetComputeShader() const noexcept;

        void SetComputeShader(const ShaderSharedPtr& shader);

    private:
        ShaderSharedPtr computeShader;
    };
}

#endif  // RENDERING_SHADERS_COMPUTE_PROGRAM_IMPL_H
