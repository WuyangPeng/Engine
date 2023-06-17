///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 13:49)

#ifndef RENDERING_RENDERERS_DX9_TEXTURE_1D_H
#define RENDERING_RENDERERS_DX9_TEXTURE_1D_H

#include "Rendering/RenderingDll.h"

#include "System/Windows/Flags/WindowsFlags.h"
#include "Rendering/Renderers/Detail/PlatformTexture1DImpl.h"
#include "Rendering/Renderers/RenderersFwd.h"
#include "Rendering/Resources/ResourcesFwd.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE Dx9Texture1D : public PlatformTexture1DImpl
    {
    public:
        using ClassType = Dx9Texture1D;
        using ParentType = PlatformTexture1DImpl;

    public:
        Dx9Texture1D(Renderer* renderer, const Texture1D* texture) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        // �������
        void Enable(Renderer* renderer, int textureUnit) noexcept override;
        void Disable(Renderer* renderer, int textureUnit) noexcept override;
        NODISCARD void* Lock(int level, BufferLocking mode) noexcept override;
        void Unlock(int level) noexcept override;
    };
}

#endif  // RENDERING_RENDERERS_DX9_TEXTURE_1D_H
