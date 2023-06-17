///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 11:37)

#ifndef RENDERING_RENDERERS_PLATFORM_TEXTURE_2D_H
#define RENDERING_RENDERERS_PLATFORM_TEXTURE_2D_H

#include "Rendering/RenderingDll.h"

#include "RenderersFwd.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "System/OpenGL/Using/OpenGLUsing.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Rendering/Resources/Flags/BufferFlags.h"
#include "Rendering/Resources/ResourcesFwd.h"

RENDERING_NON_COPY_EXPORT_IMPL(PlatformTexture2DImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE PlatformTexture2D
    {
    public:
        NON_COPY_TYPE_DECLARE(PlatformTexture2D);
        using TextureType = Texture2D;
        using UInt = System::OpenGLUInt;

    public:
        PlatformTexture2D(Renderer* renderer, const Texture2D* texture2D);

        CLASS_INVARIANT_DECLARE;

        // 纹理操作
        void Enable(Renderer* renderer, int textureUnit);
        void Disable(Renderer* renderer, int textureUnit);
        NODISCARD void* Lock(int level, BufferLocking mode);
        void Unlock(int level);

        NODISCARD UInt GetTexture() const;

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_RENDERERS_PLATFORM_TEXTURE_2D_H
