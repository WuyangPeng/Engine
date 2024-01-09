/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2024/01/02 15:13)

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

        /// ����ȷ�ΧΪ[0, 1]��DirectX��ʱ���ú������ء�true����
        /// ����ȷ�Χ��[-1, 1]��OpenGL��ʱ���������ء�false����
        NODISCARD bool HasDepthRange01() const;

        // ����ɫ���ļ�����չ�����ӵ���name����.hlsl��ʾDirectX��.glsl��ʾOpenGL����
        NODISCARD std::string GetShaderName(const std::string& name) const;

        // ���ڴ�С�仯
        NODISCARD void Resize(int width, int height);

        // ������ɫ����Ⱥ�ģ�建�����ĵ�ǰ��������� ��ɫ�������Ǻ󻺳�����
        void SetClearColor(const Colour& clearColor) noexcept;
        NODISCARD Colour GetClearColor() const noexcept;
        void SetClearDepth(float clearDepth) noexcept;
        NODISCARD float GetClearDepth() const noexcept;
        void SetClearStencil(int clearStencil) noexcept;
        NODISCARD int GetClearStencil() const noexcept;

        void DisplayColorBuffer(int syncInterval);

        // ֧���ı���Ⱦ��ʹ�õ�λͼ���塣Ĭ������ΪArial���߶�18����б�壬�޴��壩��
        void SetFont(const FontSharedPtr& font);
        NODISCARD FontSharedPtr GetFont() const noexcept;
        void SetDefaultFont();
        NODISCARD FontSharedPtr GetDefaultFont() const noexcept;

        // ȫ�ֻ�ͼ״̬��
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

        // ֧�������ɫ����Ⱥ�ģ��󻺳�����
        void ClearColorBuffer();
        void ClearDepthBuffer();
        void ClearStencilBuffer();
        void ClearBuffers();

        /// ֧�ֻ�ͼ������������ڵ���ѯ���򷵻�ֵ��ͨ����Ⱥ�ģ����Ե���������ʵ���ϻ��Ƶ���������
        /// ����ڵ���ѯ�����ã�����������0��

        // ���Ƽ���ͼԪ��
        NODISCARD int64_t Draw(Visual& visual);
        NODISCARD int64_t Draw(const VisualContainer& visuals);

        // ���ƶ�ά�ı���
        NODISCARD int64_t Draw(int x, int y, const Colour& color, const std::string& message);

        // ���ƶ�ά���θ��ǡ�����ڽ���ť���ؼ�������ͼ������GUI������ӵ�Ӧ�ó��򴰿ڷǳ����á�
        NODISCARD int64_t Draw(const OverlayEffectSharedPtr& overlay);

        // ֧���ڵ���ѯ������ʱ��Draw��������ͨ����Ⱥ�ģ����Ե���������ʵ�����ǻ��Ƶ���������Ĭ��ֵΪ��false����
        void SetAllowOcclusionQuery(bool allow) noexcept;

        // ֧�ֻ�ͼ����Ļ��洢������������̨����������DrawTarget�����װ��ȾĿ�꣨��ɫ��Ϣ�������ģ��Ŀ�ꡣ
        void Enable(const DrawTargetSharedPtr& target);
        void Disable(const DrawTargetSharedPtr& target);

        // ͼ�ζ������Bind��������������Engine�������Ӧ��ͼ��API�ض�����
        // GraphicsEngine���ڲ�������Ž�ӳ�䡣ȡ���󶨹��ܻ��ƻ�ͼ��API�ض�����
        // ��Щ���Ա���ȷ�ص��ã������汻���Ϊ���贴���Ͱ��豸���١�
        RendererObjectSharedPtr Bind(const GraphicsObjectSharedPtr& graphicsObject);
        NODISCARD RendererDrawTargetSharedPtr Bind(const DrawTargetSharedPtr& target);
        NODISCARD RendererObjectSharedPtr Get(const GraphicsObjectSharedPtr& graphicsObject);
        NODISCARD RendererDrawTargetSharedPtr Get(const DrawTargetSharedPtr& target);

        void Unbind(const GraphicsObjectSharedPtr& object);
        void Unbind(const DrawTargetSharedPtr& object);

        NODISCARD TotalAllocation GetTotalAllocation() const;

        // ֧��ͨ��ӳ���ڴ��CPU���Ƶ�GPU��
        NODISCARD bool Update(const BufferSharedPtr& buffer);
        NODISCARD bool Update(const TextureSingleSharedPtr& texture);
        NODISCARD bool Update(const TextureSingleSharedPtr& texture, int level);
        NODISCARD bool Update(const TextureArraySharedPtr& textureArray);
        NODISCARD bool Update(const TextureArraySharedPtr& textureArray, int item, int level);

        // ֧��ͨ���ݴ��ڴ��CPU���Ƶ�GPU��
        NODISCARD bool CopyCpuToGpu(const BufferSharedPtr& buffer);
        NODISCARD bool CopyCpuToGpu(const TextureSingleSharedPtr& texture);
        NODISCARD bool CopyCpuToGpu(const TextureSingleSharedPtr& texture, int level);
        NODISCARD bool CopyCpuToGpu(const TextureArraySharedPtr& textureArray);
        NODISCARD bool CopyCpuToGpu(const TextureArraySharedPtr& textureArray, int item, int level);

        // ֧��ͨ���ݴ��ڴ��GPU���Ƶ�CPU��
        NODISCARD bool CopyGpuToCpu(const BufferSharedPtr& buffer);
        NODISCARD bool CopyGpuToCpu(const TextureSingleSharedPtr& texture);
        NODISCARD bool CopyGpuToCpu(const TextureSingleSharedPtr& texture, int level);
        NODISCARD bool CopyGpuToCpu(const TextureArraySharedPtr& textureArray);
        NODISCARD bool CopyGpuToCpu(const TextureArraySharedPtr& textureArray, int item, int level);

        // ��������������GetNumActiveElements������洢�ڡ�buffer���С�
        NODISCARD bool GetNumActiveElements(const StructuredBufferSharedPtr& buffer);

        // ִ�м�����������ϣ��CPU��ͣ�ȴ����������Execute(...)����������WaitForFinish()��
        // ���ǣ����������Ժ��ĳ��ʱ��ͨ������WaitForFinish()��
        void Execute(ComputeProgram& program, int numXGroups, int numYGroups, int numZGroups);

        // ��CPU�ȴ���ֱ��GPU����䵱ǰ���������
        void WaitForFinish();

        // ˢ�����������
        void Flush();

    private:
        PackageType impl;
    };

    CORE_TOOLS_SHARED_PTR_DECLARE(BaseRenderer);
}

#endif  // RENDERING_RENDERER_ENGINE_RENDERER_H
