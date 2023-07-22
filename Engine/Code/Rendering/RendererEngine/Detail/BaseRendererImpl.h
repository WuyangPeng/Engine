///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.0 (2023/06/28 12:30)

#ifndef RENDERING_RENDERER_ENGINE_BASE_RENDERER_IMPL_H
#define RENDERING_RENDERER_ENGINE_BASE_RENDERER_IMPL_H

#include "Rendering/RenderingDll.h"

#include "RendererAdapter.h"
#include "RendererClear.h"
#include "Rendering/DataTypes/Colour.h"
#include "Rendering/LocalEffects/GlobalFont.h"
#include "Rendering/LocalEffects/LocalEffectsFwd.h"
#include "Rendering/RendererEngine/DepthRange.h"
#include "Rendering/RendererEngine/RendererEngineInternalFwd.h"
#include "Rendering/RendererEngine/Viewport.h"
#include "Rendering/Resources/ResourcesFwd.h"
#include "Rendering/SceneGraph/SceneGraphFwd.h"
#include "Rendering/Shaders/ShadersFwd.h"
#include "Rendering/State/GlobalState.h"

#include <string>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE BaseRendererImpl final
    {
    public:
        using ClassType = BaseRendererImpl;
        using FactoryType = RendererFactory;

        using Colour = Colour<float>;

        using FontSharedPtr = std::shared_ptr<Font>;
        using ComputeProgramSharedPtr = std::shared_ptr<ComputeProgram>;

        using GraphicsObjectSharedPtr = std::shared_ptr<GraphicsObject>;
        using RendererObjectSharedPtr = std::shared_ptr<RendererObject>;

        using BlendStateSharedPtr = std::shared_ptr<BlendState>;
        using DepthStencilStateSharedPtr = std::shared_ptr<DepthStencilState>;
        using RasterizerStateSharedPtr = std::shared_ptr<RasterizerState>;

        using BufferSharedPtr = std::shared_ptr<Buffer>;
        using TextureSingleSharedPtr = std::shared_ptr<TextureSingle>;
        using TextureArraySharedPtr = std::shared_ptr<TextureArray>;
        using StructuredBufferSharedPtr = std::shared_ptr<StructuredBuffer>;
        using ConstVertexBufferSharedPtr = std::shared_ptr<const VertexBuffer>;
        using ConstIndexBufferSharedPtr = std::shared_ptr<const IndexBuffer>;

        using DrawTargetSharedPtr = std::shared_ptr<DrawTarget>;
        using RendererDrawTargetSharedPtr = std::shared_ptr<RendererDrawTarget>;

        using VisualSharedPtr = std::shared_ptr<Visual>;
        using VisualContainer = std::vector<VisualSharedPtr>;
        using OverlayEffectSharedPtr = std::shared_ptr<OverlayEffect>;
        using ConstVisualEffectSharedPtr = std::shared_ptr<const VisualEffect>;

    public:
        BaseRendererImpl(RendererTypes rendererTypes, const RenderingEnvironment& renderingEnvironment);

        CLASS_INVARIANT_DECLARE;

        NODISCARD RendererTypes GetRendererType() const noexcept;

        NODISCARD int GetWidth() const noexcept;
        NODISCARD int GetHeight() const noexcept;
        NODISCARD DataFormatType GetColorFormat() const noexcept;
        NODISCARD DataFormatType GetDepthStencilFormat() const noexcept;
        NODISCARD int GetNumMultiSamples() const noexcept;

        void SetViewport(const Viewport& viewport);
        NODISCARD Viewport GetViewport() const;
        void SetDepthRange(const DepthRange& depthRange);
        NODISCARD DepthRange GetDepthRange() const;

        NODISCARD bool HasDepthRange01() const;
        NODISCARD std::string GetShaderName(const std::string& name) const;
        NODISCARD void Resize(int width, int height);
        void DisplayColorBuffer(int syncInterval);

        void SetClearColor(const Colour& clearColor) noexcept;
        NODISCARD Colour GetClearColor() const noexcept;
        void SetClearDepth(float clearDepth) noexcept;
        NODISCARD float GetClearDepth() const noexcept;
        void SetClearStencil(int clearStencil) noexcept;
        NODISCARD int GetClearStencil() const noexcept;

        void SetFont(const FontSharedPtr& font);
        NODISCARD FontSharedPtr GetFont() const noexcept;
        void SetDefaultFont();
        NODISCARD FontSharedPtr GetDefaultFont() const noexcept;

        void SetBlendState(const BlendStateSharedPtr& state);
        NODISCARD BlendStateSharedPtr GetBlendState() noexcept;
        NODISCARD BlendStateSharedPtr GetDefaultBlendState() noexcept;
        void SetDefaultBlendState();

        void SetDepthStencilState(const DepthStencilStateSharedPtr& state);
        NODISCARD DepthStencilStateSharedPtr GetDepthStencilState() noexcept;
        NODISCARD DepthStencilStateSharedPtr GetDefaultDepthStencilState() noexcept;

        void SetRasterizerState(const RasterizerStateSharedPtr& state);
        NODISCARD RasterizerStateSharedPtr GetRasterizerState() noexcept;
        NODISCARD RasterizerStateSharedPtr GetDefaultRasterizerState() noexcept;

        void InitDevice();
        void Release();
        void ResetSize();

        void ClearColorBuffer();
        void ClearDepthBuffer();
        void ClearStencilBuffer();
        void ClearBuffers();

        NODISCARD int64_t Draw(Visual& visual);
        NODISCARD int64_t Draw(const VisualContainer& visuals);
        NODISCARD int64_t Draw(int x, int y, const Colour& color, const std::string& message);
        NODISCARD int64_t Draw(const OverlayEffectSharedPtr& overlay);

        void SetAllowOcclusionQuery(bool allow) noexcept;

        void Enable(const DrawTargetSharedPtr& target);
        void Disable(const DrawTargetSharedPtr& target);

        RendererObjectSharedPtr Bind(const GraphicsObjectSharedPtr& graphicsObject);
        NODISCARD RendererDrawTargetSharedPtr Bind(const DrawTargetSharedPtr& target);
        NODISCARD RendererObjectSharedPtr Get(const GraphicsObjectSharedPtr& graphicsObject);
        NODISCARD RendererDrawTargetSharedPtr Get(const DrawTargetSharedPtr& target);

        void Unbind(const GraphicsObjectSharedPtr& object);
        void Unbind(const DrawTargetSharedPtr& object);

        NODISCARD TotalAllocation GetTotalAllocation();

        NODISCARD bool Update(const BufferSharedPtr& buffer);
        NODISCARD bool Update(const TextureSingleSharedPtr& texture);
        NODISCARD bool Update(const TextureSingleSharedPtr& texture, int level);
        NODISCARD bool Update(const TextureArraySharedPtr& textureArray);
        NODISCARD bool Update(const TextureArraySharedPtr& textureArray, int item, int level);

        NODISCARD bool CopyCpuToGpu(const BufferSharedPtr& buffer);
        NODISCARD bool CopyCpuToGpu(const TextureSingleSharedPtr& texture);
        NODISCARD bool CopyCpuToGpu(const TextureSingleSharedPtr& texture, int level);
        NODISCARD bool CopyCpuToGpu(const TextureArraySharedPtr& textureArray);
        NODISCARD bool CopyCpuToGpu(const TextureArraySharedPtr& textureArray, int item, int level);

        NODISCARD bool CopyGpuToCpu(const BufferSharedPtr& buffer);
        NODISCARD bool CopyGpuToCpu(const TextureSingleSharedPtr& texture);
        NODISCARD bool CopyGpuToCpu(const TextureSingleSharedPtr& texture, int level);
        NODISCARD bool CopyGpuToCpu(const TextureArraySharedPtr& textureArray);
        NODISCARD bool CopyGpuToCpu(const TextureArraySharedPtr& textureArray, int item, int level);

        NODISCARD bool GetNumActiveElements(const StructuredBufferSharedPtr& buffer);
        void Execute(const ComputeProgramSharedPtr& program, int numXGroups, int numYGroups, int numZGroups);
        void WaitForFinish();
        void Flush();

    private:
        NODISCARD int64_t DrawPrimitive(const ConstVertexBufferSharedPtr& vertexBuffer,
                                        const ConstIndexBufferSharedPtr& indexBuffer,
                                        const ConstVisualEffectSharedPtr& effect);

        void Bind(Font& font);
        void Unbind(Font* currentActiveFont) noexcept;
        void Update(Font& activeFont);
        NODISCARD int64_t SetState(Font& activeFont);

        NODISCARD static GlobalFont CreateGlobalFont(RendererTypes rendererTypes);

    private:
        RendererTypes rendererTypes;
        RendererAdapter rendererAdapter;
        RendererClear rendererClear;
        GlobalFont globalFont;
        GlobalState globalState;
        bool allowOcclusionQuery;
    };
}

#endif  // RENDERING_RENDERER_ENGINE_BASE_RENDERER_IMPL_H