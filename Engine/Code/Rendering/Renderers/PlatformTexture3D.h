///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 11:37)

#ifndef RENDERING_RENDERERS_PLATFORM_TEXTURE_3D_H
#define RENDERING_RENDERERS_PLATFORM_TEXTURE_3D_H

#include "Rendering/RenderingDll.h"

#include "RenderersFwd.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Rendering/Resources/Flags/BufferFlags.h"
#include "Rendering/Resources/ResourcesFwd.h"

RENDERING_NON_COPY_EXPORT_IMPL(PlatformTexture3DImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE PlatformTexture3D
    {
    public:
        NON_COPY_TYPE_DECLARE(PlatformTexture3D);
        using TextureType = Texture3D;

    public:
        PlatformTexture3D(Renderer* renderer, const Texture3D* texture3D);

        CLASS_INVARIANT_DECLARE;

        // �������
        void Enable(Renderer* renderer, int textureUnit);
        void Disable(Renderer* renderer, int textureUnit);
        NODISCARD void* Lock(int level, BufferLocking mode);
        void Unlock(int level);

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_RENDERERS_PLATFORM_TEXTURE_3D_H
