///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 13:49)

#ifndef RENDERING_RENDERERS_DX9_TEXTURE_CUBE_H
#define RENDERING_RENDERERS_DX9_TEXTURE_CUBE_H

#include "Rendering/RenderingDll.h"

#include "System/Windows/Flags/WindowsFlags.h"
#include "Rendering/Renderers/Detail/PlatformTextureCubeImpl.h"
#include "Rendering/Renderers/RenderersFwd.h"
#include "Rendering/Resources/ResourcesFwd.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE Dx9TextureCube : public PlatformTextureCubeImpl
    {
    public:
        using ClassType = Dx9TextureCube;
        using ParentType = PlatformTextureCubeImpl;

    public:
        Dx9TextureCube(Renderer* renderer, const TextureCube* texture) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        // �������
        void Enable(Renderer* renderer, int textureUnit) noexcept override;
        void Disable(Renderer* renderer, int textureUnit) noexcept override;
        NODISCARD void* Lock(int face, int level, BufferLocking mode) noexcept override;
        void Unlock(int face, int level) noexcept override;
    };
}

#endif  // RENDERING_RENDERERS_DX9_TEXTURE_CUBE_H
