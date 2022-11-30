///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.0 (2022/08/05 10:13)

#ifndef RENDERING_RENDERERS_RENDERER_IMPL_H
#define RENDERING_RENDERERS_RENDERER_IMPL_H

#include "Rendering/RenderingDll.h"

#include "BaseRenderer.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Rendering/Base/GraphicsObject.h"
#include "Rendering/GlobalEffects/GlobalEffect.h"
#include "Rendering/OpenGLRenderer/OpenGLPixelShader.h"
#include "Rendering/OpenGLRenderer/OpenGLRendererData.h"
#include "Rendering/OpenGLRenderer/OpenGLRendererInternalFwd.h"
#include "Rendering/OpenGLRenderer/OpenGLVertexShader.h"
#include "Rendering/Renderers/CameraState.h"
#include "Rendering/Renderers/ClearParameter.h"
#include "Rendering/Renderers/DepthRange.h"
#include "Rendering/Renderers/DrawManagement.h"
#include "Rendering/Renderers/PickRay.h"
#include "Rendering/Renderers/RendererBasis.h"
#include "Rendering/Renderers/RenderersFwd.h"
#include "Rendering/Renderers/RenderersInternalFwd.h"
#include "Rendering/Renderers/ShaderManagement.h"
#include "Rendering/Renderers/Viewport.h"
#include "Rendering/Renderers/ViewportManagement.h"
#include "Rendering/Resources/Buffers/IndexBuffer.h"
#include "Rendering/Resources/Buffers/VertexBuffer.h"
#include "Rendering/Resources/Buffers/VertexFormat.h"
#include "Rendering/Resources/Textures/DrawTarget.h"
#include "Rendering/Resources/Textures/Texture1D.h"
#include "Rendering/Resources/Textures/Texture2D.h"
#include "Rendering/Resources/Textures/Texture3D.h"
#include "Rendering/Resources/Textures/TextureCube.h"
#include "Rendering/SceneGraph/Camera.h"
#include "Rendering/SceneGraph/Visual.h"
#include "Rendering/Shaders/AlphaState.h"
#include "Rendering/Shaders/CullState.h"
#include "Rendering/Shaders/DepthState.h"
#include "Rendering/Shaders/OffsetState.h"
#include "Rendering/Shaders/StencilState.h"
#include "Rendering/Shaders/WireState.h"

// ��Ⱦ������һ����ÿ��ƽ̨ʵ�֣�Direct3D��OpenGL�������Ƕ��ʽ�豸�ȣ��ĳ���ӿڡ�
// ��������ֽ�������֡���һ�����г�����ƽ̨�޹صĺ��������ݣ���Щ�ڻ���ʵ�֡�
// �ڶ������г���ƽ̨��صĽӿڣ���Щ������ʵ�֡�

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE RendererImpl : public BaseRenderer
    {
    public:
        using ClassType = RendererImpl;
        using ParentType = BaseRenderer;
        using Matrix = Mathematics::MatrixF;
        using RendererSharedPtr = std::shared_ptr<Renderer>;
        using PlatformVertexFormatSharedPtr = std::shared_ptr<PlatformVertexFormat>;
        using PlatformVertexBufferSharedPtr = std::shared_ptr<PlatformVertexBuffer>;
        using PlatformIndexBufferSharedPtr = std::shared_ptr<PlatformIndexBuffer>;
        using PlatformTexture1DSharedPtr = std::shared_ptr<PlatformTexture1D>;
        using PlatformTexture2DSharedPtr = std::shared_ptr<PlatformTexture2D>;
        using PlatformTexture3DSharedPtr = std::shared_ptr<PlatformTexture3D>;
        using PlatformTextureCubeSharedPtr = std::shared_ptr<PlatformTextureCube>;
        using PlatformRenderTargetSharedPtr = std::shared_ptr<PlatformRenderTarget>;
        using PlatformVertexShaderSharedPtr = std::shared_ptr<PdrVertexShader>;
        using PlatformPixelShaderSharedPtr = std::shared_ptr<PdrPixelShader>;
        using FactoryType = RendererFactory;

    public:
        RendererImpl(RendererTypes rendererTypes, const RenderingEnvironment& renderingEnvironment, const RendererBasis& basis);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void SetRealRenderer(const RendererSharedPtr& renderer);

    public:
        // ƽ̨�޹صĽӿڲ��֡�

        // �����ʽ���������ʽ����������Ѿ����䣬�������ԺͿ����Ӧ�ó������������á�
        void Bind(const ConstVertexFormatSharedPtr& vertexFormat);
        void Unbind(const ConstVertexFormatSharedPtr& vertexFormat);
        void Enable(const ConstVertexFormatSharedPtr& vertexFormat);
        void Disable(const ConstVertexFormatSharedPtr& vertexFormat);

        // ���㻺�����������㻺��������������Ѿ���Ӧ�ó��������䡣
        void Bind(const ConstVertexBufferSharedPtr& vertexBuffer);
        void Unbind(const ConstVertexBufferSharedPtr& vertexBuffer);
        void Enable(const ConstVertexBufferSharedPtr& vertexBuffer, int streamIndex = 0, int offset = 0);
        void Disable(const ConstVertexBufferSharedPtr& vertexBuffer, int streamIndex = 0);
        void* Lock(const ConstVertexBufferSharedPtr& vertexBuffer, BufferLocking mode);
        void Unlock(const ConstVertexBufferSharedPtr& vertexBuffer);
        void Update(const ConstVertexBufferSharedPtr& vertexBuffer);

        // ����������������������������������Ѿ���Ӧ�ó��������䡣
        void Bind(const ConstIndexBufferSharedPtr& indexbuffer);
        void Unbind(const ConstIndexBufferSharedPtr& indexbuffer);
        void Enable(const ConstIndexBufferSharedPtr& indexbuffer);
        void Disable(const ConstIndexBufferSharedPtr& indexbuffer);
        void* Lock(const ConstIndexBufferSharedPtr& indexbuffer, BufferLocking mode);
        void Unlock(const ConstIndexBufferSharedPtr& indexbuffer);
        void Update(const ConstIndexBufferSharedPtr& indexbuffer);

        // 1D�����������������������Ѿ���Ӧ�ó��������䡣
        void Bind(const ConstTexture1DSharedPtr& texture);
        void Unbind(const ConstTexture1DSharedPtr& texture);
        void Enable(const ConstTexture1DSharedPtr& texture, int textureUnit);
        void Disable(const ConstTexture1DSharedPtr& texture, int textureUnit);
        void* Lock(const ConstTexture1DSharedPtr& texture, int level, BufferLocking mode);
        void Unlock(const ConstTexture1DSharedPtr& texture, int level);
        void Update(const ConstTexture1DSharedPtr& texture, int level);

        // 2D�����������������������Ѿ���Ӧ�ó��������䡣
        void Bind(const ConstTexture2DSharedPtr& texture);
        void Unbind(const ConstTexture2DSharedPtr& texture);
        void Enable(const ConstTexture2DSharedPtr& texture, int textureUnit);
        void Disable(const ConstTexture2DSharedPtr& texture, int textureUnit);
        void* Lock(const ConstTexture2DSharedPtr& texture, int level, BufferLocking mode);
        void Unlock(const ConstTexture2DSharedPtr& texture, int level);
        void Update(const ConstTexture2DSharedPtr& texture, int level);

        // 3D�����������������������Ѿ���Ӧ�ó��������䡣
        void Bind(const ConstTexture3DSharedPtr& texture);
        void Unbind(const ConstTexture3DSharedPtr& texture);
        void Enable(const ConstTexture3DSharedPtr& texture, int textureUnit);
        void Disable(const ConstTexture3DSharedPtr& texture, int textureUnit);
        void* Lock(const ConstTexture3DSharedPtr& texture, int level, BufferLocking mode);
        void Unlock(const ConstTexture3DSharedPtr& texture, int level);
        void Update(const ConstTexture3DSharedPtr& texture, int level);

        // Cube�����������������������Ѿ���Ӧ�ó��������䡣
        void Bind(const ConstTextureCubeSharedPtr& texture);
        void Unbind(const ConstTextureCubeSharedPtr& texture);
        void Enable(const ConstTextureCubeSharedPtr& texture, int textureUnit);
        void Disable(const ConstTextureCubeSharedPtr& texture, int textureUnit);
        void* Lock(const ConstTextureCubeSharedPtr& texture, int face, int level, BufferLocking mode);
        void Unlock(const ConstTextureCubeSharedPtr& texture, int face, int level);
        void Update(const ConstTextureCubeSharedPtr& texture, int face, int level);

        // ��ȾĿ�������ȾĿ�����������Ѿ���Ӧ�ó��������䡣
        // ��ReadColor������index���ڶ����ȾĿ������Ŀ��������
        void Bind(const ConstDrawTargetSharedPtr& renderTarget);
        void Unbind(const ConstDrawTargetSharedPtr& renderTarget);
        void Enable(const ConstDrawTargetSharedPtr& renderTarget);
        void Disable(const ConstDrawTargetSharedPtr& renderTarget);
        ConstTexture2DSharedPtr ReadColor(int index, const ConstDrawTargetSharedPtr& renderTarget);

        // ������ɫ������������ɫ����������Ѿ���Ӧ�ó��������䡣
        void Bind(const ConstVertexShaderSharedPtr& vertexShader);
        void Unbind(const ConstVertexShaderSharedPtr& vertexShader);
        void Enable(const ConstVertexShaderSharedPtr& vertexShader, const ShaderParameters& parameters);
        void Disable(const ConstVertexShaderSharedPtr& vertexShader, const ShaderParameters& parameters);

        // ������ɫ������������ɫ����������Ѿ���Ӧ�ó��������䡣
        void Bind(const ConstPixelShaderSharedPtr& pixelShader);
        void Unbind(const ConstPixelShaderSharedPtr& pixelShader);
        void Enable(const ConstPixelShaderSharedPtr& pixelShader, const ShaderParameters& parameters);
        void Disable(const ConstPixelShaderSharedPtr& pixelShader, const ShaderParameters& parameters);

        void Bind(const std::shared_ptr<const Shader>& shader) noexcept;
        void Unbind(const std::shared_ptr<const Shader>& shader) noexcept;

        void Bind(const std::shared_ptr<const GraphicsObject>& object) noexcept;
        void Unbind(const std::shared_ptr<const GraphicsObject>& object) noexcept;

        // ShaderParametersӦ������һ����Դ��ӳ�䵽���������������� ��������ӵ���Ⱦ����
        // ׼���ú��Ƴ�ShaderParameters����������/������ɫ����������һ��Bind/Unbind/Enable/Disable�����顣

        // ������Դ����

        // ���ʵ�ǰ��ȫ��״̬��
        NODISCARD ConstAlphaStateSharedPtr GetAlphaState() const noexcept;
        NODISCARD ConstCullStateSharedPtr GetCullState() const noexcept;
        NODISCARD ConstDepthStateSharedPtr GetDepthState() const noexcept;
        NODISCARD ConstOffsetStateSharedPtr GetOffsetState() const noexcept;
        NODISCARD ConstStencilStateSharedPtr GetStencilState() const noexcept;
        NODISCARD ConstWireStateSharedPtr GetWireState() const noexcept;

        // ����ȫ��״̬�� ��������ǣ�����ͼ�ε����ڼ�ʹ�ô�״̬����VisualPass״̬�� Ҫ�������ǣ��봫�ݿ�ָ�롣
        NODISCARD ConstAlphaStateSharedPtr GetOverrideAlphaState() const noexcept;
        NODISCARD ConstCullStateSharedPtr GetOverrideCullState() const noexcept;
        NODISCARD ConstDepthStateSharedPtr GetOverrideDepthState() const noexcept;
        NODISCARD ConstOffsetStateSharedPtr GetOverrideOffsetState() const noexcept;
        NODISCARD ConstStencilStateSharedPtr GetOverrideStencilState() const noexcept;
        NODISCARD ConstWireStateSharedPtr GetOverrideWireState() const noexcept;
        void SetOverrideAlphaState(const ConstAlphaStateSharedPtr& alphaState);
        void SetOverrideCullState(const ConstCullStateSharedPtr& cullState);
        void SetOverrideDepthState(const ConstDepthStateSharedPtr& depthState);
        void SetOverrideOffsetState(const ConstOffsetStateSharedPtr& offsetState);
        void SetOverrideStencilState(const ConstStencilStateSharedPtr& stencilState);
        void SetOverrideWireState(const ConstWireStateSharedPtr& wireState);
        void SetReverseCullOrder(bool aReverseCullOrder) noexcept;
        NODISCARD bool GetReverseCullOrder() const noexcept;

        // ���ʵ�ǰ���״̬��
        void SetCamera(const CameraSharedPtr& aCamera) noexcept;
        NODISCARD ConstCameraSharedPtr GetCamera() const noexcept;
        NODISCARD CameraSharedPtr GetCamera() noexcept;
        NODISCARD Matrix GetViewMatrix() const;
        NODISCARD Matrix GetProjectionMatrix() const;
        NODISCARD Matrix GetPostProjectionMatrix() const;

        // ����ָ����������Ļ���꣨x��y����ʹ�õ�ǰ�����������ߡ�
        // ����ġ�ԭ�㡱�����λ�ã����������ǵ�λ����ʸ����
        // ���߶������������С� �����x��y���ڵ�ǰ�ӿ��е��򷵻�ֵΪ'true'��
        NODISCARD PickRay GetPickRay(int x, int y) const;

        // ���ʵ�ǰ����ɫͨ���ɰ�
        NODISCARD bool GetAllowRed() const noexcept;
        NODISCARD bool GetAllowGreen() const noexcept;
        NODISCARD bool GetAllowBlue() const noexcept;
        NODISCARD bool GetAllowAlpha() const noexcept;
        void SetAllowRed(bool allowRed) noexcept;
        void SetAllowGreen(bool allowGreen) noexcept;
        void SetAllowBlue(bool allowBlue) noexcept;
        void SetAllowAlpha(bool allowAlpha) noexcept;

        // ���Ƴ���ͼ�Ŀɼ����ϵ���ڵ㡣
        void Draw(VisibleSet& visibleSet, GlobalEffect* globalEffect);

        // ���Ƶ����������ڵ㡣
        void Draw(VisualSharedPtr visual);
        void Draw(const VisualSharedPtr& visual, VisualEffectInstanceSharedPtr instance);

        NODISCARD PlatformVertexFormatSharedPtr GetResource(const ConstVertexFormatSharedPtr& vertexFormat);
        NODISCARD PlatformVertexBufferSharedPtr GetResource(const ConstVertexBufferSharedPtr& vertexBuffer);
        NODISCARD PlatformIndexBufferSharedPtr GetResource(const ConstIndexBufferSharedPtr& indexBuffer);
        NODISCARD PlatformTexture1DSharedPtr GetResource(const ConstTexture1DSharedPtr& texture1D);
        NODISCARD PlatformTexture2DSharedPtr GetResource(const ConstTexture2DSharedPtr& texture2D);
        NODISCARD PlatformTexture3DSharedPtr GetResource(const ConstTexture3DSharedPtr& texture3D);
        NODISCARD PlatformTextureCubeSharedPtr GetResource(const ConstTextureCubeSharedPtr& textureCube);
        NODISCARD PlatformRenderTargetSharedPtr GetResource(const ConstDrawTargetSharedPtr& renderTarget);
        NODISCARD PlatformVertexShaderSharedPtr GetResource(const ConstVertexShaderSharedPtr& vertexShader);
        NODISCARD PlatformPixelShaderSharedPtr GetResource(const ConstPixelShaderSharedPtr& pixelShader);

        NODISCARD virtual bool InTexture2DMap(const ConstTexture2DSharedPtr& texture);
        virtual void InsertInTexture2DMap(const ConstTexture2DSharedPtr& texture, const PlatformTexture2DSharedPtr& platformTexture);

    public:
        // �ӿڵ�ƽ̨��ز��֡�

        // �Ӿ�״̬����
        virtual void SetAlphaState(const ConstAlphaStateSharedPtr& alphaState) = 0;
        virtual void SetCullState(const ConstCullStateSharedPtr& cullState) = 0;
        virtual void SetDepthState(const ConstDepthStateSharedPtr& depthState) = 0;
        virtual void SetOffsetState(const ConstOffsetStateSharedPtr& offsetState) = 0;
        virtual void SetStencilState(const ConstStencilStateSharedPtr& stencilState) = 0;
        virtual void SetWireState(const ConstWireStateSharedPtr& wireState) = 0;

        // ֧�������ɫ����Ⱥ�ģ�建������
        virtual void ClearColorBuffer() = 0;
        virtual void ClearDepthBuffer() = 0;
        virtual void ClearStencilBuffer() = 0;
        virtual void ClearBuffers() = 0;
        virtual void ClearColorBuffer(int x, int y, int w, int h) = 0;
        virtual void ClearDepthBuffer(int x, int y, int w, int h) = 0;
        virtual void ClearStencilBuffer(int x, int y, int w, int h) = 0;
        virtual void ClearBuffers(int x, int y, int w, int h) = 0;
        virtual void DisplayColorBuffer() = 0;

        // ֧���ڻ��ƹ������ڲ���ɫͨ����
        virtual void SetColorMask(bool allowRed, bool allowGreen, bool allowBlue, bool allowAlpha) = 0;

        // ֧��PreDraw��PostDraw���塣 ����Renderer����ӿں����ͻ�ͼ���������������PreDraw()��PostDraw()Ϊ�߽�Ĵ�����С�
        // ͨ�ø�ʽΪ
        // if (renderer->PreDraw())
        // {
        //		<���������Ⱦ�����úͻ��Ƶ���>;
        //		renderer->PostDraw();
        //	}
        NODISCARD virtual bool PreDraw() = 0;
        virtual void PostDraw() = 0;

        // ����2D����������ڵ㣨����2DӦ�ó���
        virtual void Draw(const uint8_t* screenBuffer, bool reflectY) = 0;

        // ����2D�ı�����ڵ㡣
        virtual void Draw(int x, int y, const Colour& color, const std::string& message) = 0;

        NODISCARD virtual RendererTypes GetRendererType() const = 0;

        void SetFont(const FontSharedPtr& font) override;

    private:
        using VertexFormatManagementPtr = std::shared_ptr<VertexFormatManagement>;
        using VertexBufferManagement = BufferManagement<PlatformVertexBuffer>;
        using IndexBufferManagement = BufferManagement<PlatformIndexBuffer>;
        using VertexBufferManagementPtr = std::shared_ptr<VertexBufferManagement>;
        using IndexBufferManagementPtr = std::shared_ptr<IndexBufferManagement>;
        using Texture1DManagement = TextureManagement<PlatformTexture1D>;
        using Texture2DManagement = TextureManagement<PlatformTexture2D>;
        using Texture3DManagement = TextureManagement<PlatformTexture3D>;
        using TextureCubeManagement = TextureManagement<PlatformTextureCube>;
        using Texture1DManagementPtr = std::shared_ptr<Texture1DManagement>;
        using Texture2DManagementPtr = std::shared_ptr<Texture2DManagement>;
        using Texture3DManagementPtr = std::shared_ptr<Texture3DManagement>;
        using TextureCubeManagementPtr = std::shared_ptr<TextureCubeManagement>;
        using RenderTargetManagementPtr = std::shared_ptr<RenderTargetManagement>;
        using VertexShaderManagement = ShaderManagement<VertexShader, PdrVertexShader>;
        using PixelShaderManagement = ShaderManagement<PixelShader, PdrPixelShader>;
        using VertexShaderManagementPtr = std::shared_ptr<VertexShaderManagement>;
        using PixelShaderManagementPtr = std::shared_ptr<PixelShaderManagement>;

    private:
        // ����3D�������ڵ㣬�ɵ�����Draw�������á�
        virtual void DrawPrimitive(const ConstVisualSharedPtr& visual) = 0;

    private:
        // ȫ��״̬
        AlphaStateSharedPtr defaultAlphaState;
        CullStateSharedPtr defaultCullState;
        DepthStateSharedPtr defaultDepthState;
        OffsetStateSharedPtr defaultOffsetState;
        StencilStateSharedPtr defaultStencilState;
        WireStateSharedPtr defaultWireState;
        ConstAlphaStateSharedPtr globalAlphaState;
        ConstCullStateSharedPtr globalCullState;
        ConstDepthStateSharedPtr globalDepthState;
        ConstOffsetStateSharedPtr globalOffsetState;
        ConstStencilStateSharedPtr globalStencilState;
        ConstWireStateSharedPtr globalWireState;
        bool reverseCullOrder;

        VertexFormatManagementPtr vertexFormatManagement;
        VertexBufferManagementPtr vertexBufferManagement;
        IndexBufferManagementPtr indexBufferManagement;
        Texture1DManagementPtr texture1DManagement;
        Texture2DManagementPtr texture2DManagement;
        Texture3DManagementPtr texture3DManagement;
        TextureCubeManagementPtr textureCubeManagement;
        RenderTargetManagementPtr renderTargetManagement;
        VertexShaderManagementPtr vertexShaderManagement;
        PixelShaderManagementPtr pixelShaderManagement;

        CameraState cameraState;
        ClearParameter clearParameter;
        ViewportManagement viewportManagement;
        DrawManagement drawManagement;

        // �ض���ƽ̨�����ݡ�
        RendererData rendererData;

        // ����ȫ��״̬��
        ConstAlphaStateSharedPtr overrideAlphaState;
        ConstCullStateSharedPtr overrideCullState;
        ConstDepthStateSharedPtr overrideDepthState;
        ConstOffsetStateSharedPtr overrideOffsetState;
        ConstStencilStateSharedPtr overrideStencilState;
        ConstWireStateSharedPtr overrideWireState;

        // ���α任�ܵ�������洢��ͼ��ͶӰ��ͶӰ�����
        CameraSharedPtr camera;

        // ��̨��������ͨ�����Ρ�
        bool bufferAllowRed;
        bool bufferAllowGreen;
        bool bufferAllowBlue;
        bool bufferAllowAlpha;

        std::weak_ptr<Renderer> realRenderer;
    };
}

#endif  // RENDERING_RENDERERS_RENDERER_IMPL_H
