///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.0 (2022/08/04 13:49)

#ifndef RENDERING_BASE_RENDERER_H
#define RENDERING_BASE_RENDERER_H

#include "Rendering/RenderingDll.h"

#include "Rendering/DataTypes/Colour.h"
#include "Rendering/Renderers/DepthRange.h"
#include "Rendering/Renderers/RendererBasis.h"
#include "Rendering/Renderers/RenderersFwd.h"
#include "Rendering/Renderers/Viewport.h"
#include "Rendering/Resources/ResourcesFwd.h"

#include <string>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE BaseRenderer
    {
    public:
        using ClassType = BaseRenderer;
        using Colour = Colour<float>;
        using FontSharedPtr = std::shared_ptr<Font>;
        using BlendStateSharedPtr = std::shared_ptr<BlendState>;
        using DepthStencilStateSharedPtr = std::shared_ptr<DepthStencilState>;
        using RasterizerStateSharedPtr = std::shared_ptr<RasterizerState>;
        using BufferSharedPtr = std::shared_ptr<Buffer>;
        using TextureSharedPtr = std::shared_ptr<Texture>;

    public:
        explicit BaseRenderer(const RendererBasis& basis);
        virtual ~BaseRenderer() noexcept = default;
        BaseRenderer(const BaseRenderer& rhs) = delete;
        BaseRenderer& operator=(const BaseRenderer& rhs) = delete;
        BaseRenderer(BaseRenderer&& rhs) noexcept = delete;
        BaseRenderer& operator=(BaseRenderer&& rhs) noexcept = delete;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        // 访问构造函数的输入。
        NODISCARD int GetWidth() const noexcept;
        NODISCARD int GetHeight() const noexcept;
        NODISCARD TextureFormat GetColorFormat() const noexcept;
        NODISCARD TextureFormat GetDepthStencilFormat() const noexcept;
        NODISCARD int GetNumMultisamples() const noexcept;

        // 视口管理。 视口以右手屏幕坐标指定。 原点是屏幕的左下角，y轴指向上方，x轴指向右侧。
        virtual void SetViewport(const Viewport& viewport) = 0;
        NODISCARD virtual Viewport GetViewport() const = 0;
        virtual void SetDepthRange(const DepthRange& depthRange) = 0;
        NODISCARD virtual DepthRange GetDepthRange() const = 0;

        NODISCARD virtual bool HasDepthRange01() const = 0;

        NODISCARD virtual std::string GetShaderName(const std::string& name) const = 0;

        NODISCARD virtual void Resize(int width, int height) = 0;

        // 访问颜色，深度和模板缓冲区的当前清除参数。 颜色缓冲区是后缓冲区。
        void SetClearColor(const Colour& aClearColor) noexcept;
        NODISCARD Colour GetClearColor() const noexcept;
        void SetClearDepth(float aClearDepth) noexcept;
        NODISCARD float GetClearDepth() const noexcept;
        void SetClearStencil(int aClearStencil) noexcept;
        NODISCARD int GetClearStencil() const noexcept;

        virtual void DisplayColorBuffer(int syncInterval) = 0;

        virtual void SetFont(const FontSharedPtr& font);
        NODISCARD FontSharedPtr GetFont() const noexcept;
        void SetDefaultFont();
        NODISCARD FontSharedPtr GetDefaultFont() const noexcept;

        virtual void SetBlendState(const BlendStateSharedPtr& state) = 0;
        NODISCARD BlendStateSharedPtr GetBlendState() const noexcept;
        void SetDefaultBlendState();
        NODISCARD BlendStateSharedPtr GetDefaultBlendState() const noexcept;

        virtual void SetDepthStencilState(const DepthStencilStateSharedPtr& state) = 0;
        NODISCARD DepthStencilStateSharedPtr GetDepthStencilState() const noexcept;
        void SetDefaultDepthStencilState();
        NODISCARD DepthStencilStateSharedPtr GetDefaultDepthStencilState() const noexcept;

        virtual void SetRasterizerState(const RasterizerStateSharedPtr& state) = 0;
        NODISCARD RasterizerStateSharedPtr GetRasterizerState() const noexcept;
        void SetDefaultRasterizerState();
        NODISCARD RasterizerStateSharedPtr GetDefaultRasterizerState() const noexcept;

        NODISCARD virtual bool Update(const BufferSharedPtr& buffer) = 0;
        NODISCARD virtual bool Update(const TextureSharedPtr& texture) = 0;

    protected:
        void CreateDefaultGlobalState();
        void SetActiveBlendState(const BlendStateSharedPtr& state) noexcept;
        void SetActiveDepthStencilState(const DepthStencilStateSharedPtr& state) noexcept;
        void SetActiveRasterizerState(const RasterizerStateSharedPtr& state) noexcept;

    private:
        RendererBasis rendererBasis;

        // 清除帧缓冲区。
        Colour clearColor;
        float clearDepth;
        int clearStencil;

        FontSharedPtr defaultFont;
        FontSharedPtr activeFont;

        BlendStateSharedPtr defaultBlendState;
        BlendStateSharedPtr activeBlendState;
        DepthStencilStateSharedPtr defaultDepthStencilState;
        DepthStencilStateSharedPtr activeDepthStencilState;
        RasterizerStateSharedPtr defaultRasterizerState;
        RasterizerStateSharedPtr activeRasterizerState;
    };
}

#endif  // RENDERING_BASE_RENDERER_H