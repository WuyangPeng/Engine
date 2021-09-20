// Copyright (c) 2010-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ����汾��0.0.3.0 (2020/03/27 11:09)

#ifndef RENDERING_RENDERERS_RENDERER_H
#define RENDERING_RENDERERS_RENDERER_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include "DepthRange.h"
#include "PickRay.h"
#include "RenderersInternalFwd.h"
#include "Viewport.h"

#include "Rendering/Shaders/AlphaState.h"
#include "Rendering/Shaders/CullState.h"
#include "Rendering/Shaders/DepthState.h"
#include "Rendering/Shaders/OffsetState.h"
#include "Rendering/Shaders/ShadersFwd.h"
#include "Rendering/Shaders/StencilState.h"
#include "Rendering/Shaders/VisualEffectInstance.h"
#include "Rendering/Shaders/WireState.h"

#include "Rendering/Resources/IndexBuffer.h"
#include "Rendering/Resources/RenderTarget.h"
#include "Rendering/Resources/ResourcesFwd.h"
#include "Rendering/Resources/Texture1D.h"
#include "Rendering/Resources/Texture2D.h"
#include "Rendering/Resources/Texture3D.h"
#include "Rendering/Resources/TextureCube.h"
#include "Rendering/Resources/VertexBuffer.h"
#include "Rendering/Resources/VertexFormat.h"

#include "Rendering/SceneGraph/Camera.h"
#include "Rendering/SceneGraph/SceneGraphFwd.h"
#include "Rendering/SceneGraph/Visual.h"

#include "Rendering/GlobalEffects/GlobalEffect.h"
#include "Rendering/GlobalEffects/GlobalEffectsFwd.h"

#include "Rendering/DataTypes/Colour.h"
#include "Rendering/DataTypes/DataTypesFwd.h"

#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include <boost/noncopyable.hpp>
#include <string>

RENDERING_NON_COPY_EXPORT_IMPL(RendererImpl);
template class RENDERING_DEFAULT_DECLARE std::weak_ptr<Rendering::Renderer>;
template class RENDERING_DEFAULT_DECLARE std::enable_shared_from_this<Rendering::Renderer>;

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE Renderer : public std::enable_shared_from_this<Renderer>
    {
    public:
        NON_COPY_TYPE_DECLARE(Renderer);
        using ColourUByte = Colour<uint8_t>;
        using Colour = Colour<float>;
        using Matrix = Mathematics::FloatMatrix;

    public:
        explicit Renderer(const std::string& fileName);
        Renderer(RendererTypes type, const RendererBasis& basis);
        ~Renderer();

        Renderer(Renderer&& rhs) noexcept;
        Renderer& operator=(Renderer&& rhs) noexcept;
        Renderer(const Renderer& rhs) noexcept = delete;
        Renderer& operator=(const Renderer& rhs) noexcept = delete;
        Renderer() = delete;

        CLASS_INVARIANT_DECLARE;

    public:
        // ��ʼ����ؽӿڣ������ֶ����ã�
        // ����һ��create�����������캯�����˽��
        void Init();

    public:
        // ƽ̨�޹صĽӿڲ��֡�

        // ���ʹ��캯�������롣
        int GetWidth() const;
        int GetHeight() const;
        TextureFormat GetColorFormat() const;
        TextureFormat GetDepthStencilFormat() const;
        int GetNumMultisamples() const;

        // ��Դ��������Դ������Ϊ�����ʽ�����㻺����������������������1D��2D��3D�������壩��
        // ��ȾĿ�꣬������ɫ����������ɫ��������ִ�����²�����

        // Bind:  ������Ӧ������������Դ����Ⱦ������������Դ֮���ӳ�䡣
        //        �ڴ��������£���Ƶ�洢����������Ӧ��ϵͳ�ڴ��н��з���Ϳ�����
        //        ���Enable��Lock��Bind֮ǰ���ã���Ⱦ��ĬĬ�ش�����һ����Դ�������ǵ����쳣��

        // Unbind:  ���ٶ�Ӧ������������Դ����Ⱦ����ӳ����ɾ��������Դ��
        //          ���󱣳���ϵͳ�洢���Ŀ��������ԣ����������ǿ��Ա��ٴΰ󶨡�

        // Enable:  ����Դ���ڵ�ǰ��ͼ�е��ô��ڻ״̬���������ڵ���DrawPrimitive֮ǰ��

        // Disable: ����Դ���ڵ�ǰ��ͼ�е��ô��ڷǻ״̬���������ڵ���DrawPrimitive֮��

        // Lock: �õ�һ��ָ����Դ����Ƶ�洢����ָ�루��Ȼ�洢��Ҳ��������AGP�ڴ��������ȡ����ͼ��API����Դʹ�õ�ϵͳ�ڴ棩��
        //       ʹ�ô˺����������Դ档�����������Ҫ֪����û�и��¶������Ӧϵͳ�洢װ���е������ڴ濽����ͬ����
        //       ��Ҳ����ֻ��Ϊ�˶�������������������£��Դ�����ݱ�������������Դ�����������ٵ�ʱ�䡣

        // Unlock:  �ͷ�ָ����Դ����Ƶ�洢����ָ�롣

        // Update:  ������Դ����Ƶ�洢��������ϵͳ�洢�������ݵ�����Ȼ�������Ƶ�ڴ档
        //          �����Ƽ�������Դ�ķ�ʽ������ϵͳ�ڴ棬Ȼ�����Update����������Ϊ��Ⱦ���ú�����

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
        void Bind(const ConstRenderTargetSharedPtr& renderTarget);
        void Unbind(const ConstRenderTargetSharedPtr& renderTarget);
        void Enable(const ConstRenderTargetSharedPtr& renderTarget);
        void Disable(const ConstRenderTargetSharedPtr& renderTarget);
        ConstTexture2DSharedPtr ReadColor(int index, const ConstRenderTargetSharedPtr& renderTarget);

        // ������ɫ������������ɫ����������Ѿ���Ӧ�ó��������䡣
        void Bind(const ConstVertexShaderSharedPtr& vshader);
        void Unbind(const ConstVertexShaderSharedPtr& vshader);
        void Enable(const ConstVertexShaderSharedPtr& vshader, const ConstShaderParametersSharedPtr& parameters);
        void Disable(const ConstVertexShaderSharedPtr& vshader, const ConstShaderParametersSharedPtr& parameters);

        // ������ɫ������������ɫ����������Ѿ���Ӧ�ó��������䡣
        void Bind(const ConstPixelShaderSharedPtr& pshader);
        void Unbind(const ConstPixelShaderSharedPtr& pshader);
        void Enable(const ConstPixelShaderSharedPtr& pshader, const ConstShaderParametersSharedPtr& parameters);
        void Disable(const ConstPixelShaderSharedPtr& pshader, const ConstShaderParametersSharedPtr& parameters);

        // ���ʵ�ǰ��ȫ��״̬��
        const ConstAlphaStateSharedPtr GetAlphaState() const;
        const ConstCullStateSharedPtr GetCullState() const;
        const ConstDepthStateSharedPtr GetDepthState() const;
        const ConstOffsetStateSharedPtr GetOffsetState() const;
        const ConstStencilStateSharedPtr GetStencilState() const;
        const ConstWireStateSharedPtr GetWireState() const;

        // ����ȫ��״̬�� ��������ǣ�����ͼ�ε����ڼ�ʹ�ô�״̬����VisualPass״̬�� Ҫ�������ǣ��봫�ݿ�ָ�롣
        const ConstAlphaStateSharedPtr GetOverrideAlphaState() const;
        const ConstCullStateSharedPtr GetOverrideCullState() const;
        const ConstDepthStateSharedPtr GetOverrideDepthState() const;
        const ConstOffsetStateSharedPtr GetOverrideOffsetState() const;
        const ConstStencilStateSharedPtr GetOverrideStencilState() const;
        const ConstWireStateSharedPtr GetOverrideWireState() const;
        void SetOverrideAlphaState(const ConstAlphaStateSharedPtr& alphaState);
        void SetOverrideCullState(const ConstCullStateSharedPtr& cullState);
        void SetOverrideDepthState(const ConstDepthStateSharedPtr& depthState);
        void SetOverrideOffsetState(const ConstOffsetStateSharedPtr& offsetState);
        void SetOverrideStencilState(const ConstStencilStateSharedPtr& stencilState);
        void SetOverrideWireState(const ConstWireStateSharedPtr& wireState);
        void SetReverseCullOrder(bool reverseCullOrder);
        bool GetReverseCullOrder() const;

        // ���ʵ�ǰ���״̬��
        void SetCamera(const CameraSharedPtr& camera);
        const ConstCameraSharedPtr GetCamera() const;
        const CameraSharedPtr GetCamera();
        const Matrix GetViewMatrix() const;
        const Matrix GetProjectionMatrix() const;
        const Matrix GetPostProjectionMatrix() const;

        // ����ָ����������Ļ���꣨x��y����ʹ�õ�ǰ�����������ߡ�
        // ����ġ�ԭ�㡱�����λ�ã����������ǵ�λ����ʸ����
        // ���߶������������С� �����x��y���ڵ�ǰ�ӿ��е��򷵻�ֵΪ'true'��
        PickRay GetPickRay(int x, int y) const;

        // ������ɫ����Ⱥ�ģ�建�����ĵ�ǰ��������� ��ɫ�������Ǻ󻺳�����
        void SetClearColor(const Colour& clearColor);
        const Colour GetClearColor() const;
        void SetClearDepth(float clearDepth);
        float GetClearDepth() const;
        void SetClearStencil(int clearStencil);
        int GetClearStencil() const;

        // ���ʵ�ǰ����ɫͨ���ɰ�
        bool GetAllowRed() const;
        bool GetAllowGreen() const;
        bool GetAllowBlue() const;
        bool GetAllowAlpha() const;
        void SetAllowRed(bool allowRed);
        void SetAllowGreen(bool allowGreen);
        void SetAllowBlue(bool allowBlue);
        void SetAllowAlpha(bool allowAlpha);

        // ���Ƴ���ͼ�Ŀɼ����ϵ���ڵ㡣
        void Draw(VisibleSet& visibleSet, const GlobalEffectSharedPtr& globalEffect = GlobalEffectSharedPtr{});

        // ���Ƶ����������ڵ㡣
        void Draw(const VisualSharedPtr& visual);
        void Draw(const VisualSharedPtr& visual, const VisualEffectInstanceSharedPtr& instance);

    public:
        // �ӿڵ�ƽ̨��ز��֡�

        // �Ӿ�״̬����
        void SetAlphaState(const ConstAlphaStateSharedPtr& alphaState);
        void SetCullState(const ConstCullStateSharedPtr& cullState);
        void SetDepthState(const ConstDepthStateSharedPtr& depthState);
        void SetOffsetState(const ConstOffsetStateSharedPtr& offsetState);
        void SetStencilState(const ConstStencilStateSharedPtr& stencilState);
        void SetWireState(const ConstWireStateSharedPtr& wireState);

        // �ӿڹ��� �ӿ���������Ļ����ָ���� ԭ������Ļ�����½ǣ�y��ָ���Ϸ���x��ָ���Ҳࡣ
        void SetViewport(const Viewport& viewport);
        Viewport GetViewport() const;
        void SetDepthRange(const DepthRange& depthRange);
        DepthRange GetDepthRange() const;
        void Resize(int width, int height);

        // ֧�������ɫ����Ⱥ�ģ�建������
        void ClearColorBuffer();
        void ClearDepthBuffer();
        void ClearStencilBuffer();
        void ClearBuffers();
        void ClearColorBuffer(int x, int y, int w, int h);
        void ClearDepthBuffer(int x, int y, int w, int h);
        void ClearStencilBuffer(int x, int y, int w, int h);
        void ClearBuffers(int x, int y, int w, int h);
        void DisplayColorBuffer();

        // ֧���ڻ��ƹ������ڲ���ɫͨ����
        void SetColorMask(bool allowRed, bool allowGreen, bool allowBlue, bool allowAlpha);

        // ֧��PreDraw��PostDraw���塣 ����Renderer����ӿں����ͻ�ͼ���������������PreDraw()��PostDraw()Ϊ�߽�Ĵ�����С�
        // ͨ�ø�ʽΪ
        // if (renderer->PreDraw())
        // {
        //		<���������Ⱦ�����úͻ��Ƶ���>;
        //		renderer->PostDraw();
        //	}
        bool PreDraw();
        void PostDraw();

        // ����2D����������ڵ㣨����2DӦ�ó���
        void Draw(const uint8_t* screenBuffer, bool reflectY = false);
        void Draw(const std::vector<ColourUByte>& screenBuffer, bool reflectY = false);

        // ����2D�ı�����ڵ㡣
        void Draw(int x, int y, const Colour& color, const std::string& message);

        bool InTexture2DMap(const ConstTexture2DSharedPtr& texture);
        void InsertInTexture2DMap(const ConstTexture2DSharedPtr& texture, const PlatformTexture2DSharedPtr& platformTexture);

        RendererTypes GetRendererType() const;

    private:
        PackageType impl;
        int64_t m_RendererID;
    };

    CORE_TOOLS_SHARED_PTR_DECLARE(Renderer);
}

#endif  // RENDERING_RENDERERS_RENDERER_H
