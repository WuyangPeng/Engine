///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 13:17)

#ifndef RENDERING_RENDERERS_OPENGL_TEXTURE_1D_H
#define RENDERING_RENDERERS_OPENGL_TEXTURE_1D_H

#include "Rendering/RenderingDll.h"

#include "OpenGLTextureData.h"
#include "System/Windows/Flags/WindowsFlags.h"
#include "Rendering/Renderers/Detail/PlatformTexture1DImpl.h"
#include "Rendering/Resources/ResourcesFwd.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE OpenGLTexture1D : public PlatformTexture1DImpl
    {
    public:
        using ClassType = OpenGLTexture1D;
        using ParentType = PlatformTexture1DImpl;

    public:
        OpenGLTexture1D(Renderer* renderer, const Texture1D* texture);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        // �������
        void Enable(Renderer* renderer, int textureUnit) override;
        void Disable(Renderer* renderer, int textureUnit) noexcept override;
        NODISCARD void* Lock(int level, BufferLocking mode) noexcept override;
        void Unlock(int level) override;

    private:
        OpenGLTextureData<Texture1D> openGLTextureData;
    };
}

#endif  // RENDERING_RENDERERS_OPENGL_TEXTURE_1D_H
