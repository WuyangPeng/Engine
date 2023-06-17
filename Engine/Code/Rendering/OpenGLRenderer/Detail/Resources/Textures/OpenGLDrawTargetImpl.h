///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 13:21)

#ifndef RENDERING_OPENGL_RENDERER_OPENGL_DRAW_TARGET_IMPL_H
#define RENDERING_OPENGL_RENDERER_OPENGL_DRAW_TARGET_IMPL_H

#include "Rendering/RenderingDll.h"

#include "System/OpenGL/Using/OpenGLUsing.h"
#include "Rendering/OpenGLRenderer/Resources/Textures/OpenGLTextureDepthStencil.h"
#include "Rendering/OpenGLRenderer/Resources/Textures/OpenGLTextureRenderTarget.h"
#include "Rendering/Resources/Textures/DrawTarget.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE OpenGLDrawTargetImpl
    {
    public:
        using ClassType = OpenGLDrawTargetImpl;

        using OpenGLInt = System::OpenGLInt;
        using OpenGLUInt = System::OpenGLUInt;
        using OpenGLSize = System::OpenGLSize;
        using OpenGLDouble = System::OpenGLDouble;
        using OpenGLTextureRenderTargetSharedPtr = std::shared_ptr<OpenGLTextureRenderTarget>;
        using ConstOpenGLTextureRenderTargetSharedPtr = std::shared_ptr<const OpenGLTextureRenderTarget>;
        using OpenGLTextureRenderTargetContainer = std::vector<OpenGLTextureRenderTargetSharedPtr>;
        using OpenGLTextureDepthStencilSharedPtr = std::shared_ptr<OpenGLTextureDepthStencil>;
        using ConstOpenGLTextureDepthStencilSharedPtr = std::shared_ptr<const OpenGLTextureDepthStencil>;

    public:
        OpenGLDrawTargetImpl(const DrawTargetSharedPtr& target,
                             const OpenGLTextureRenderTargetContainer& renderTargetTextures,
                             const OpenGLTextureDepthStencilSharedPtr& depthStencilTexture);
        ~OpenGLDrawTargetImpl() noexcept;
        OpenGLDrawTargetImpl(const OpenGLDrawTargetImpl& rhs) = default;
        OpenGLDrawTargetImpl& operator=(const OpenGLDrawTargetImpl& rhs) = default;
        OpenGLDrawTargetImpl(OpenGLDrawTargetImpl&& rhs) noexcept = default;
        OpenGLDrawTargetImpl& operator=(OpenGLDrawTargetImpl&& rhs) noexcept = default;

        CLASS_INVARIANT_DECLARE;

        NODISCARD ConstOpenGLTextureRenderTargetSharedPtr GetRenderTargetTexture(int index) const;

        NODISCARD ConstOpenGLTextureDepthStencilSharedPtr GetDepthStencilTexture() const noexcept;

        void Enable();
        void Disable();

    private:
        DrawTargetSharedPtr drawTarget;
        OpenGLTextureRenderTargetContainer renderTargetTextures;
        OpenGLTextureDepthStencilSharedPtr depthStencilTexture;

        OpenGLUInt frameBuffer;

        OpenGLInt saveViewportX;
        OpenGLInt saveViewportY;
        OpenGLSize saveViewportWidth;
        OpenGLSize saveViewportHeight;
        OpenGLDouble saveViewportNear;
        OpenGLDouble saveViewportFar;
    };
}

#endif  // RENDERING_OPENGL_RENDERER_OPENGL_DRAW_TARGET_IMPL_H
