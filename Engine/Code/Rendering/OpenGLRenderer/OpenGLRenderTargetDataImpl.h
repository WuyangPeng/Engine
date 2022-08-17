///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/22 21:45)

#ifndef RENDERING_RENDERERS_OPENGL_RENDER_TARGET_DATA_IMPL_H
#define RENDERING_RENDERERS_OPENGL_RENDER_TARGET_DATA_IMPL_H

#include "Rendering/RenderingDll.h"

#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "System/OpenGL/Using/OpenGLUsing.h"
#include "Rendering/DataTypes/Flags/TextureFormat.h"
#include "Rendering/Renderers/RenderersFwd.h"
#include "Rendering/Resources/ResourcesFwd.h"
#include "Rendering/Resources/Textures/Texture2D.h"

#include <array>
#include <vector>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE OpenGLRenderTargetDataImpl
    {
    public:
        using ClassType = OpenGLRenderTargetDataImpl;
        using UInt = System::OpenGLUInt;
        using Enum = System::OpenGLEnum;

    public:
        OpenGLRenderTargetDataImpl(Renderer* renderer, const DrawTarget* renderTarget);
        virtual ~OpenGLRenderTargetDataImpl() noexcept = default;
        OpenGLRenderTargetDataImpl(const OpenGLRenderTargetDataImpl& rhs) = delete;
        OpenGLRenderTargetDataImpl& operator=(const OpenGLRenderTargetDataImpl& rhs) = delete;
        OpenGLRenderTargetDataImpl(OpenGLRenderTargetDataImpl&& rhs) noexcept = delete;
        OpenGLRenderTargetDataImpl& operator=(OpenGLRenderTargetDataImpl&& rhs) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

        // 渲染目标的操作。
        virtual void Enable(Renderer* renderer) noexcept;
        virtual void Disable(Renderer* renderer) noexcept;
        NODISCARD virtual ConstTexture2DSharedPtr ReadColor(int index, Renderer* renderer);

    private:
        void CreateFramebufferObject() noexcept;
        NODISCARD UInt CreateDrawBuffers(Renderer* renderer, const DrawTarget* aRenderTarget);
        void CreateDepthStencilTexture(Renderer* renderer, const DrawTarget* aRenderTarget, UInt previousBind);
        void CheckFramebufferStatus() noexcept;

    private:
        int numTargets;
        int width;
        int height;
        DataFormatType format;
        bool hasMipmaps;
        bool hasDepthStencil;

        std::vector<UInt> colorTextures;
        UInt depthStencilTexture;
        UInt frameBuffer;
        std::vector<Enum> drawBuffers;
        std::array<int, 4> prevViewport;
        std::array<double, 2> prevDepthRange;
    };
}

#endif  // RENDERING_RENDERERS_OPENGL_RENDER_TARGET_DATA_IMPL_H
