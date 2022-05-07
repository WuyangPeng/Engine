///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.6 (2022/04/23 21:16)

#ifndef RENDERING_RENDERERS_DX9_TEXTURE_3D_H
#define RENDERING_RENDERERS_DX9_TEXTURE_3D_H

#include "Rendering/RenderingDll.h"

#include "System/Windows/Flags/WindowsFlags.h"
#include "Rendering/Renderers/Detail/PlatformTexture3DImpl.h"
#include "Rendering/Renderers/RenderersFwd.h"
#include "Rendering/Resources/ResourcesFwd.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE Dx9Texture3D : public PlatformTexture3DImpl
    {
    public:
        using ClassType = Dx9Texture3D;
        using ParentType = PlatformTexture3DImpl;

    public:
        Dx9Texture3D(Renderer* renderer, const Texture3D* texture) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        // �������
        void Enable(Renderer* renderer, int textureUnit) noexcept override;
        void Disable(Renderer* renderer, int textureUnit) noexcept override;
        NODISCARD void* Lock(int level, BufferLocking mode) noexcept override;
        void Unlock(int level) noexcept override;
    };
}

#endif  // RENDERING_RENDERERS_DX9_TEXTURE_1D_H
