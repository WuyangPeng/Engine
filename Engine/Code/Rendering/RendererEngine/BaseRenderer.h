/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2024/01/02 15:13)

#ifndef RENDERING_RENDERER_ENGINE_RENDERER_H
#define RENDERING_RENDERER_ENGINE_RENDERER_H

#include "Rendering/RenderingDll.h"

#include "DepthRange.h"
#include "PickRay.h"
#include "RendererEngineInternalFwd.h"
#include "Viewport.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Rendering/DataTypes/Colour.h"
#include "Rendering/Resources/Buffers/IndexBuffer.h"
#include "Rendering/Resources/Buffers/VertexBuffer.h"
#include "Rendering/Resources/Buffers/VertexFormat.h"
#include "Rendering/Resources/ResourcesFwd.h"
#include "Rendering/Resources/Textures/DrawTarget.h"
#include "Rendering/Resources/Textures/Texture1D.h"
#include "Rendering/Resources/Textures/TextureCube.h"
#include "Rendering/SceneGraph/Camera.h"
#include "Rendering/SceneGraph/Visual.h"
#include "Rendering/Shaders/ShadersFwd.h"
#include "Rendering/State/StateFwd.h"

#include <string>

RENDERING_NON_COPY_EXPORT_IMPL(BaseRendererImpl);
template class RENDERING_DEFAULT_DECLARE std::weak_ptr<Rendering::BaseRenderer>;
template class RENDERING_DEFAULT_DECLARE std::enable_shared_from_this<Rendering::BaseRenderer>;

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE BaseRenderer : public std::enable_shared_from_this<BaseRenderer>
    {
    public:
        NON_COPY_TYPE_DECLARE(BaseRenderer);

        using BaseRendererSharedPtr = std::shared_ptr<BaseRenderer>;

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
        BaseRenderer(const EnvironmentParameter& environmentParameter, const std::string& fileName);
        BaseRenderer(const EnvironmentParameter& environmentParameter, const RendererParameter& rendererParameter);

        CLASS_INVARIANT_DECLARE;

    public:
        NODISCARD static BaseRendererSharedPtr Create(const std::string& fileName, const EnvironmentParameter& environmentParameter);

    public:
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

        /// 当深度范围为[0, 1]（DirectX）时，该函数返回“true”，
        /// 当深度范围是[-1, 1]（OpenGL）时，函数返回“false”。
        NODISCARD bool HasDepthRange01() const;

        // 将着色器文件的扩展名附加到“name”（.hlsl表示DirectX，.glsl表示OpenGL）。
        NODISCARD std::string GetShaderName(const std::string& name) const;

        // 窗口大小变化
        NODISCARD void Resize(int width, int height);

        // 访问颜色，深度和模板缓冲区的当前清除参数。 颜色缓冲区是后缓冲区。
        void SetClearColor(const Colour& clearColor) noexcept;
        NODISCARD Colour GetClearColor() const noexcept;
        void SetClearDepth(float clearDepth) noexcept;
        NODISCARD float GetClearDepth() const noexcept;
        void SetClearStencil(int clearStencil) noexcept;
        NODISCARD int GetClearStencil() const noexcept;

        void DisplayColorBuffer(int syncInterval);

        // 支持文本渲染中使用的位图字体。默认字体为Arial（高度18，无斜体，无粗体）。
        void SetFont(const FontSharedPtr& font);
        NODISCARD FontSharedPtr GetFont() const noexcept;
        void SetDefaultFont();
        NODISCARD FontSharedPtr GetDefaultFont() const noexcept;

        // 全局绘图状态。
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

        // 支持清除颜色、深度和模板后缓冲区。
        void ClearColorBuffer();
        void ClearDepthBuffer();
        void ClearStencilBuffer();
        void ClearBuffers();

        /// 支持绘图。如果启用了遮挡查询，则返回值是通过深度和模板测试的样本数，实际上绘制的像素数。
        /// 如果遮挡查询被禁用，函数将返回0。

        // 绘制几何图元。
        NODISCARD int64_t Draw(Visual& visual);
        NODISCARD int64_t Draw(const VisualContainer& visuals);

        // 绘制二维文本。
        NODISCARD int64_t Draw(int x, int y, const Colour& color, const std::string& message);

        // 绘制二维矩形覆盖。这对于将按钮、控件、缩略图和其他GUI对象添加到应用程序窗口非常有用。
        NODISCARD int64_t Draw(const OverlayEffectSharedPtr& overlay);

        // 支持遮挡查询。启用时，Draw函数返回通过深度和模板测试的样本数，实际上是绘制的像素数。默认值为“false”。
        void SetAllowOcclusionQuery(bool allow) noexcept;

        // 支持绘图到屏幕外存储器（即不到后台缓冲区）。DrawTarget对象封装渲染目标（颜色信息）和深度模板目标。
        void Enable(const DrawTargetSharedPtr& target);
        void Disable(const DrawTargetSharedPtr& target);

        // 图形对象管理。Bind函数创建与输入Engine对象相对应的图形API特定对象。
        // GraphicsEngine在内部管理此桥接映射。取消绑定功能会破坏图形API特定对象。
        // 这些可以被明确地调用，但引擎被设计为按需创建和按设备销毁。
        RendererObjectSharedPtr Bind(const GraphicsObjectSharedPtr& graphicsObject);
        NODISCARD RendererDrawTargetSharedPtr Bind(const DrawTargetSharedPtr& target);
        NODISCARD RendererObjectSharedPtr Get(const GraphicsObjectSharedPtr& graphicsObject);
        NODISCARD RendererDrawTargetSharedPtr Get(const DrawTargetSharedPtr& target);

        void Unbind(const GraphicsObjectSharedPtr& object);
        void Unbind(const DrawTargetSharedPtr& object);

        NODISCARD TotalAllocation GetTotalAllocation() const;

        // 支持通过映射内存从CPU复制到GPU。
        NODISCARD bool Update(const BufferSharedPtr& buffer);
        NODISCARD bool Update(const TextureSingleSharedPtr& texture);
        NODISCARD bool Update(const TextureSingleSharedPtr& texture, int level);
        NODISCARD bool Update(const TextureArraySharedPtr& textureArray);
        NODISCARD bool Update(const TextureArraySharedPtr& textureArray, int item, int level);

        // 支持通过暂存内存从CPU复制到GPU。
        NODISCARD bool CopyCpuToGpu(const BufferSharedPtr& buffer);
        NODISCARD bool CopyCpuToGpu(const TextureSingleSharedPtr& texture);
        NODISCARD bool CopyCpuToGpu(const TextureSingleSharedPtr& texture, int level);
        NODISCARD bool CopyCpuToGpu(const TextureArraySharedPtr& textureArray);
        NODISCARD bool CopyCpuToGpu(const TextureArraySharedPtr& textureArray, int item, int level);

        // 支持通过暂存内存从GPU复制到CPU。
        NODISCARD bool CopyGpuToCpu(const BufferSharedPtr& buffer);
        NODISCARD bool CopyGpuToCpu(const TextureSingleSharedPtr& texture);
        NODISCARD bool CopyGpuToCpu(const TextureSingleSharedPtr& texture, int level);
        NODISCARD bool CopyGpuToCpu(const TextureArraySharedPtr& textureArray);
        NODISCARD bool CopyGpuToCpu(const TextureArraySharedPtr& textureArray, int item, int level);

        // 计数缓冲区管理。GetNumActiveElements将结果存储在“buffer”中。
        NODISCARD bool GetNumActiveElements(const StructuredBufferSharedPtr& buffer);

        // 执行计算程序。如果您希望CPU暂停等待结果，请在Execute(...)后立即调用WaitForFinish()。
        // 但是，您可以在稍后的某个时间通过调用WaitForFinish()。
        void Execute(ComputeProgram& program, int numXGroups, int numYGroups, int numZGroups);

        // 让CPU等待，直到GPU完成其当前命令缓冲区。
        void WaitForFinish();

        // 刷新命令缓冲区。
        void Flush();

    private:
        PackageType impl;
    };

    CORE_TOOLS_SHARED_PTR_DECLARE(BaseRenderer);
}

#endif  // RENDERING_RENDERER_ENGINE_RENDERER_H
