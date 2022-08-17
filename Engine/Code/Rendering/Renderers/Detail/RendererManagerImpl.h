///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/20 16:01)

#ifndef RENDERING_RENDERERS_RENDERER_MANAGE_IMPL_H
#define RENDERING_RENDERERS_RENDERER_MANAGE_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Renderers/RenderersFwd.h"
#include "Rendering/Resources/ResourcesFwd.h"
#include "Rendering/Shaders/ShadersFwd.h"

#include <map>
#include <memory>

namespace Rendering
{
    class RendererManagerImpl
    {
    public:
        using ClassType = RendererManagerImpl;
        using RendererSharedPtr = std::shared_ptr<Renderer>;
        using ConstVertexFormatSharedPtr = std::shared_ptr<const VertexFormat>;
        using ConstVertexBufferSharedPtr = std::shared_ptr<const VertexBuffer>;
        using ConstIndexBufferSharedPtr = std::shared_ptr<const IndexBuffer>;
        using ConstTexture1DSharedPtr = std::shared_ptr<const Texture1D>;
        using ConstTexture2DSharedPtr = std::shared_ptr<const Texture2D>;
        using ConstTexture3DSharedPtr = std::shared_ptr<const Texture3D>;
        using ConstTextureCubeSharedPtr = std::shared_ptr<const TextureCube>;
        using ConstDrawTargetSharedPtr = std::shared_ptr<const DrawTarget>;
        using ConstVertexShaderSharedPtr = std::shared_ptr<const VertexShader>;
        using ConstPixelShaderSharedPtr = std::shared_ptr<const PixelShader>;

    public:
        RendererManagerImpl() noexcept;

        CLASS_INVARIANT_DECLARE;

        int64_t Insert(const RendererSharedPtr& renderer);
        bool Erase(int64_t rendererID);

        void BindAll(const ConstVertexFormatSharedPtr& vertexFormat);
        void UnbindAll(const ConstVertexFormatSharedPtr& vertexFormat);

        void BindAll(const ConstVertexBufferSharedPtr& vertexBuffer);
        void UnbindAll(const ConstVertexBufferSharedPtr& vertexBuffer);
        void UpdateAll(const ConstVertexBufferSharedPtr& vertexBuffer);

        void BindAll(const ConstIndexBufferSharedPtr& indexBuffer);
        void UnbindAll(const ConstIndexBufferSharedPtr& indexBuffer);
        void UpdateAll(const ConstIndexBufferSharedPtr& indexBuffer);

        void BindAll(const ConstTexture1DSharedPtr& texture);
        void UnbindAll(const ConstTexture1DSharedPtr& texture);
        void UpdateAll(const ConstTexture1DSharedPtr& texture, int level);

        void BindAll(const ConstTexture2DSharedPtr& texture);
        void UnbindAll(const ConstTexture2DSharedPtr& texture);
        void UpdateAll(const ConstTexture2DSharedPtr& texture, int level);

        void BindAll(const ConstTexture3DSharedPtr& texture);
        void UnbindAll(const ConstTexture3DSharedPtr& texture);
        void UpdateAll(const ConstTexture3DSharedPtr& texture, int level);

        void BindAll(const ConstTextureCubeSharedPtr& texture);
        void UnbindAll(const ConstTextureCubeSharedPtr& texture);
        void UpdateAll(const ConstTextureCubeSharedPtr& texture, int face, int level);

        void BindAll(const ConstDrawTargetSharedPtr& renderTarget);
        void UnbindAll(const ConstDrawTargetSharedPtr& renderTarget);

        void BindAll(const ConstVertexShaderSharedPtr& vertexShader);
        void UnbindAll(const ConstVertexShaderSharedPtr& vertexShader);

        void BindAll(const ConstPixelShaderSharedPtr& pixelShader);
        void UnbindAll(const ConstPixelShaderSharedPtr& pixelShader);

    private:
        using RendererSet = std::map<int64_t, std::weak_ptr<Renderer>>;

    private:
        RendererSet renderers;
    };
}

#endif  // RENDERING_RENDERERS_RENDERER_MANAGE_IMPL_H
