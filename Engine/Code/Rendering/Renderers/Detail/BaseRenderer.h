///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 11:33)

#ifndef RENDERING_BASE_RENDERER_H
#define RENDERING_BASE_RENDERER_H

#include "Rendering/RenderingDll.h"

#include "Rendering/DataTypes/Colour.h"
#include "Rendering/Renderers/DepthRange.h"
#include "Rendering/Renderers/RendererBasis.h"
#include "Rendering/Renderers/RenderersFwd.h"
#include "Rendering/Renderers/RenderingEnvironment.h"
#include "Rendering/Renderers/Viewport.h"
#include "Rendering/Resources/ResourcesFwd.h"
#include "Rendering/State/GlobalState.h"

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
        using RendererObjectBridgeSharedPtr = std::shared_ptr<RendererObjectBridge>;

    public:
        BaseRenderer(RendererTypes rendererTypes, const RenderingEnvironment& renderingEnvironment, const RendererBasis& basis);
        virtual ~BaseRenderer() noexcept = default;
        BaseRenderer(const BaseRenderer& rhs) = delete;
        BaseRenderer& operator=(const BaseRenderer& rhs) = delete;
        BaseRenderer(BaseRenderer&& rhs) noexcept = delete;
        BaseRenderer& operator=(BaseRenderer&& rhs) noexcept = delete;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        // ���ʹ��캯�������롣
        NODISCARD int GetWidth() const noexcept;
        NODISCARD int GetHeight() const noexcept;
        NODISCARD DataFormatType GetColorFormat() const noexcept;
        NODISCARD DataFormatType GetDepthStencilFormat() const noexcept;
        NODISCARD int GetNumMultisamples() const noexcept;

        // �ӿڹ��� �ӿ���������Ļ����ָ���� ԭ������Ļ�����½ǣ�y��ָ���Ϸ���x��ָ���Ҳࡣ
        virtual void SetViewport(const Viewport& viewport) = 0;
        NODISCARD virtual Viewport GetViewport() const = 0;
        virtual void SetDepthRange(const DepthRange& depthRange) = 0;
        NODISCARD virtual DepthRange GetDepthRange() const = 0;

        NODISCARD virtual bool HasDepthRange01() const = 0;

        NODISCARD virtual std::string GetShaderName(const std::string& name) const = 0;

        NODISCARD virtual void Resize(int width, int height) = 0;

        // ������ɫ����Ⱥ�ģ�建�����ĵ�ǰ��������� ��ɫ�������Ǻ󻺳�����
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
        NODISCARD BlendStateSharedPtr GetBlendState() noexcept;
        NODISCARD BlendStateSharedPtr GetDefaultBlendState() noexcept;

        virtual void SetDepthStencilState(const DepthStencilStateSharedPtr& state) = 0;
        NODISCARD DepthStencilStateSharedPtr GetDepthStencilState() noexcept;
        NODISCARD DepthStencilStateSharedPtr GetDefaultDepthStencilState() noexcept;

        virtual void SetRasterizerState(const RasterizerStateSharedPtr& state) = 0;
        NODISCARD RasterizerStateSharedPtr GetRasterizerState() noexcept;
        NODISCARD RasterizerStateSharedPtr GetDefaultRasterizerState() noexcept;

        NODISCARD virtual bool Update(const BufferSharedPtr& buffer) = 0;
        NODISCARD virtual bool Update(const TextureSharedPtr& texture) = 0;

        void Release();

        void SwapBuffers();
        void ResetSize();
        void InitDevice();

    protected:
        void SetActiveBlendState(const BlendStateSharedPtr& state);
        void SetActiveDepthStencilState(const DepthStencilStateSharedPtr& state);
        void SetActiveRasterizerState(const RasterizerStateSharedPtr& state);

    private:
        RenderingEnvironment renderingEnvironment;
        RenderingDevice renderingDevice;

        RendererBasis rendererBasis;
        RendererObjectBridgeSharedPtr rendererObjectBridge;

        // ���֡��������
        Colour clearColor;
        float clearDepth;
        int clearStencil;

        FontSharedPtr defaultFont;
        FontSharedPtr activeFont;

        GlobalState globalState;
    };
}

#endif  // RENDERING_BASE_RENDERER_H