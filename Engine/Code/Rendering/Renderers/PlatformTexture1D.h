///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.6 (2022/04/21 18:56)

#ifndef RENDERING_RENDERERS_PLATFORM_TEXTURE_1D_H
#define RENDERING_RENDERERS_PLATFORM_TEXTURE_1D_H

#include "Rendering/RenderingDll.h"

#include "RenderersFwd.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Rendering/Resources/Flags/BufferFlags.h"
#include "Rendering/Resources/ResourcesFwd.h"

RENDERING_NON_COPY_EXPORT_IMPL(PlatformTexture1DImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE PlatformTexture1D
    {
    public:
        NON_COPY_TYPE_DECLARE(PlatformTexture1D);
        using TextureType = Texture1D;

    public:
        PlatformTexture1D(Renderer* renderer, const Texture1D* texture1D);

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

#endif  // RENDERING_RENDERERS_PLATFORM_TEXTURE_1D_H
