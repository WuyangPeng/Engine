///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 13:17)

#ifndef RENDERING_RENDERERS_OPENGL_TEXTURE_3D_H
#define RENDERING_RENDERERS_OPENGL_TEXTURE_3D_H

#include "Rendering/RenderingDll.h"

#include "OpenGLTextureData.h"
#include "System/Windows/Flags/WindowsFlags.h"
#include "Rendering/Renderers/Detail/PlatformTexture3DImpl.h"
#include "Rendering/Resources/ResourcesFwd.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE OpenGLTexture3D : public PlatformTexture3DImpl
    {
    public:
        using ClassType = OpenGLTexture3D;
        using ParentType = PlatformTexture3DImpl;

    public:
        OpenGLTexture3D(Renderer* renderer, const Texture3D* texture);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        // �������
        void Enable(Renderer* renderer, int textureUnit) override;
        void Disable(Renderer* renderer, int textureUnit) noexcept override;
        NODISCARD void* Lock(int level, BufferLocking mode) noexcept override;
        void Unlock(int level) override;

    private:
        OpenGLTextureData<Texture3D> openGLTextureData;
    };
}

#endif  // RENDERING_RENDERERS_OPENGL_TEXTURE_3D_H
