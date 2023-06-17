///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 10:30)

#ifndef RENDERING_SHADERS_SHADER_MANAGE_IMPL_H
#define RENDERING_SHADERS_SHADER_MANAGE_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Shaders/Flags/ShaderFlags.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE ShaderManagerImpl
    {
    public:
        using ClassType = ShaderManagerImpl;
        using VertexShaderProfile = ShaderFlags::VertexShaderProfile;
        using PixelShaderProfile = ShaderFlags::PixelShaderProfile;

    public:
        ShaderManagerImpl() noexcept;

        CLASS_INVARIANT_DECLARE;

        void SetVertexProfile(VertexShaderProfile profile) noexcept;
        NODISCARD VertexShaderProfile GetVertexProfile() const noexcept;

        void SetPixelProfile(PixelShaderProfile profile) noexcept;
        NODISCARD PixelShaderProfile GetPixelProfile() const noexcept;

    private:
        VertexShaderProfile vertexShaderProfile;
        PixelShaderProfile pixelShaderProfile;
    };
}

#endif  // RENDERING_SHADERS_SHADER_MANAGE_IMPL_H
