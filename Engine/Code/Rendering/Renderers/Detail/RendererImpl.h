// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.3.0 (2020/03/27 14:04)

#ifndef RENDERING_RENDERERS_RENDERER_IMPL_H
#define RENDERING_RENDERERS_RENDERER_IMPL_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include "Rendering/Renderers/RenderersFwd.h"
#include "Rendering/Renderers/PickRay.h"
#include "Rendering/Renderers/Viewport.h"
#include "Rendering/Renderers/DepthRange.h"
#include "Rendering/Renderers/GlobalState.h"
#include "Rendering/Renderers/CameraState.h"
#include "Rendering/Renderers/ClearParameter.h"
#include "Rendering/Renderers/DrawManagement.h"
#include "Rendering/Renderers/ShaderManagement.h"
#include "Rendering/Renderers/ViewportManagement.h"
#include "Rendering/Renderers/RendererBasis.h"

#include "Rendering/OpenGLRenderer/OpenGLRendererData.h"
#include "Rendering/OpenGLRenderer/OpenGLVertexShader.h"
#include "Rendering/OpenGLRenderer/OpenGLPixelShader.h"
#include "Rendering/OpenGLRenderer/OpenGLRendererInternalFwd.h" 

#include "Rendering/SceneGraph/Visual.h"
#include "Rendering/SceneGraph/Camera.h"

#include "Rendering/Shaders/WireState.h"
#include "Rendering/Shaders/CullState.h"
#include "Rendering/Shaders/DepthState.h"
#include "Rendering/Shaders/AlphaState.h"
#include "Rendering/Shaders/OffsetState.h"
#include "Rendering/Shaders/StencilState.h"

#include "Rendering/Resources/Texture1D.h"
#include "Rendering/Resources/Texture2D.h"
#include "Rendering/Resources/Texture3D.h"
#include "Rendering/Resources/TextureCube.h"
#include "Rendering/Resources/VertexFormat.h"
#include "Rendering/Resources/VertexBuffer.h"
#include "Rendering/Resources/IndexBuffer.h"
#include "Rendering/Resources/RenderTarget.h"

#include "Rendering/GlobalEffects/GlobalEffect.h"

#include <boost/noncopyable.hpp>  


// ��Ⱦ������һ����ÿ��ƽ̨ʵ�֣�Direct3D��OpenGL�������Ƕ��ʽ�豸�ȣ��ĳ���ӿڡ�
// ��������ֽ�������֡���һ�����г�����ƽ̨�޹صĺ��������ݣ���Щ�ڻ���ʵ�֡�
// �ڶ������г���ƽ̨��صĽӿڣ���Щ������ʵ�֡�

namespace Rendering
{
	class RENDERING_HIDDEN_DECLARE RendererImpl : private boost::noncopyable
	{
	public:
		using ClassType = RendererImpl;

		using Colour = Colour<float>;
		using Matrix = Mathematics::Matrixf;
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

	public:
		explicit RendererImpl(const RendererBasis& basis);
		virtual ~RendererImpl();
		RendererImpl(const RendererImpl&) =delete;
		RendererImpl& operator=(const RendererImpl&) =delete;
		RendererImpl(RendererImpl&&) =delete;
		RendererImpl& operator=(RendererImpl&&) =delete;

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		void SetRealRenderer(const RendererSharedPtr& renderer);

	public:
		// ƽ̨�޹صĽӿڲ��֡�

		// ���ʹ��캯�������롣
		int GetWidth() const;
		int GetHeight() const;
		TextureFormat GetColorFormat() const;
		TextureFormat GetDepthStencilFormat() const;
		int GetNumMultisamples() const;		 

		// �����ʽ���������ʽ����������Ѿ����䣬�������ԺͿ����Ӧ�ó������������á�
		void Bind(const ConstVertexFormatSmartPointer& vertexFormat);
		void Unbind(const ConstVertexFormatSmartPointer& vertexFormat);
		void Enable(const ConstVertexFormatSmartPointer& vertexFormat);
		void Disable(const ConstVertexFormatSmartPointer& vertexFormat);

		// ���㻺�����������㻺��������������Ѿ���Ӧ�ó��������䡣
		void Bind(const ConstVertexBufferSmartPointer& vertexBuffer);
		void Unbind(const ConstVertexBufferSmartPointer& vertexBuffer);
		void Enable(const ConstVertexBufferSmartPointer& vertexBuffer, int streamIndex = 0, int offset = 0);
		void Disable(const ConstVertexBufferSmartPointer& vertexBuffer, int streamIndex = 0);
		void* Lock(const ConstVertexBufferSmartPointer& vertexBuffer, BufferLocking mode);
		void Unlock(const ConstVertexBufferSmartPointer& vertexBuffer);
		void Update(const ConstVertexBufferSmartPointer& vertexBuffer);

		// ����������������������������������Ѿ���Ӧ�ó��������䡣
		void Bind(const ConstIndexBufferSmartPointer& indexbuffer);
		void Unbind(const ConstIndexBufferSmartPointer& indexbuffer);
		void Enable(const ConstIndexBufferSmartPointer& indexbuffer);
		void Disable(const ConstIndexBufferSmartPointer& indexbuffer);
		void* Lock(const ConstIndexBufferSmartPointer& indexbuffer, BufferLocking mode);
		void Unlock(const ConstIndexBufferSmartPointer& indexbuffer);
		void Update(const ConstIndexBufferSmartPointer& indexbuffer);

		// 1D�����������������������Ѿ���Ӧ�ó��������䡣
		void Bind(const ConstTexture1DSmartPointer& texture);
		void Unbind(const ConstTexture1DSmartPointer& texture);
		void Enable(const ConstTexture1DSmartPointer& texture, int textureUnit);
		void Disable(const ConstTexture1DSmartPointer& texture, int textureUnit);
		void* Lock(const ConstTexture1DSmartPointer& texture, int level, BufferLocking mode);
		void Unlock(const ConstTexture1DSmartPointer& texture, int level);
		void Update(const ConstTexture1DSmartPointer& texture, int level);

		// 2D�����������������������Ѿ���Ӧ�ó��������䡣
		void Bind(const ConstTexture2DSmartPointer& texture);
		void Unbind(const ConstTexture2DSmartPointer& texture);
		void Enable(const ConstTexture2DSmartPointer& texture, int textureUnit);
		void Disable(const ConstTexture2DSmartPointer& texture, int textureUnit);
		void* Lock(const ConstTexture2DSmartPointer& texture, int level, BufferLocking mode);
		void Unlock(const ConstTexture2DSmartPointer& texture, int level);
		void Update(const ConstTexture2DSmartPointer& texture, int level);

		// 3D�����������������������Ѿ���Ӧ�ó��������䡣
		void Bind(const ConstTexture3DSmartPointer& texture);
		void Unbind(const ConstTexture3DSmartPointer& texture);
		void Enable(const ConstTexture3DSmartPointer& texture, int textureUnit);
		void Disable(const ConstTexture3DSmartPointer& texture, int textureUnit);
		void* Lock(const ConstTexture3DSmartPointer& texture, int level, BufferLocking mode);
		void Unlock(const ConstTexture3DSmartPointer& texture, int level);
		void Update(const ConstTexture3DSmartPointer& texture, int level);

		// Cube�����������������������Ѿ���Ӧ�ó��������䡣
		void Bind(const ConstTextureCubeSmartPointer& texture);
		void Unbind(const ConstTextureCubeSmartPointer& texture);
		void Enable(const ConstTextureCubeSmartPointer& texture, int textureUnit);
		void Disable(const ConstTextureCubeSmartPointer& texture, int textureUnit);
		void* Lock(const ConstTextureCubeSmartPointer& texture, int face, int level, BufferLocking mode);
		void Unlock(const ConstTextureCubeSmartPointer& texture, int face, int level);
		void Update(const ConstTextureCubeSmartPointer& texture, int face, int level);

		// ��ȾĿ�������ȾĿ�����������Ѿ���Ӧ�ó��������䡣
		// ��ReadColor������index���ڶ����ȾĿ������Ŀ�������� 
		void Bind(const ConstRenderTargetSmartPointer& renderTarget);
		void Unbind(const ConstRenderTargetSmartPointer& renderTarget);
		void Enable(const ConstRenderTargetSmartPointer& renderTarget);
		void Disable(const ConstRenderTargetSmartPointer& renderTarget);
		ConstTexture2DSmartPointer ReadColor(int index, const ConstRenderTargetSmartPointer& renderTarget);

		// ������ɫ������������ɫ����������Ѿ���Ӧ�ó��������䡣
		void Bind(const ConstVertexShaderSmartPointer& vertexShader);
		void Unbind(const ConstVertexShaderSmartPointer& vertexShader);
		void Enable(const ConstVertexShaderSmartPointer& vertexShader, const ConstShaderParametersSmartPointer& parameters);
		void Disable(const ConstVertexShaderSmartPointer& vertexShader, const ConstShaderParametersSmartPointer& parameters);

		// ������ɫ������������ɫ����������Ѿ���Ӧ�ó��������䡣
		void Bind(const ConstPixelShaderSmartPointer& pixelShader);
		void Unbind(const ConstPixelShaderSmartPointer& pixelShader);
		void Enable(const ConstPixelShaderSmartPointer& pixelShader, const ConstShaderParametersSmartPointer& parameters);
		void Disable(const ConstPixelShaderSmartPointer& pixelShader, const ConstShaderParametersSmartPointer& parameters);

		// TODO. ShaderParametersӦ������һ����Դ��ӳ�䵽���������������� ��������ӵ���Ⱦ���� 
		// ׼���ú��Ƴ�ShaderParameters����������/������ɫ����������һ��Bind/Unbind/Enable/Disable�����顣

		// ������Դ����

		// ���ʵ�ǰ��ȫ��״̬��
		const ConstAlphaStateSmartPointer GetAlphaState() const;
		const ConstCullStateSmartPointer GetCullState() const;
		const ConstDepthStateSmartPointer GetDepthState() const;
		const ConstOffsetStateSmartPointer GetOffsetState() const;
		const ConstStencilStateSmartPointer GetStencilState() const;
		const ConstWireStateSmartPointer GetWireState() const;

		// ����ȫ��״̬�� ��������ǣ�����ͼ�ε����ڼ�ʹ�ô�״̬����VisualPass״̬�� Ҫ�������ǣ��봫�ݿ�ָ�롣
		const ConstAlphaStateSmartPointer GetOverrideAlphaState() const;
		const ConstCullStateSmartPointer GetOverrideCullState() const;
		const ConstDepthStateSmartPointer GetOverrideDepthState() const;
		const ConstOffsetStateSmartPointer GetOverrideOffsetState() const;
		const ConstStencilStateSmartPointer GetOverrideStencilState() const;
		const ConstWireStateSmartPointer GetOverrideWireState() const;
		void SetOverrideAlphaState(const ConstAlphaStateSmartPointer& alphaState);
		void SetOverrideCullState(const ConstCullStateSmartPointer& cullState);
		void SetOverrideDepthState(const ConstDepthStateSmartPointer& depthState);
		void SetOverrideOffsetState(const ConstOffsetStateSmartPointer& offsetState);
		void SetOverrideStencilState(const ConstStencilStateSmartPointer& stencilState);
		void SetOverrideWireState(const ConstWireStateSmartPointer& wireState);
		void SetReverseCullOrder(bool reverseCullOrder);
		bool GetReverseCullOrder() const;

		// ���ʵ�ǰ���״̬��
		void SetCamera(const CameraSmartPointer& camera);
		const ConstCameraSmartPointer GetCamera() const;
		const CameraSmartPointer GetCamera();
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
		void Draw(VisibleSet& visibleSet, GlobalEffectSmartPointer globalEffect);

		// ���Ƶ����������ڵ㡣
		void Draw(VisualSmartPointer visual);
		void Draw(const VisualSmartPointer& visual, VisualEffectInstanceSmartPointer instance);

		PlatformVertexFormatSharedPtr GetResource(const ConstVertexFormatSmartPointer& vertexFormat);
		PlatformVertexBufferSharedPtr GetResource(const ConstVertexBufferSmartPointer& vertexBuffer);
		PlatformIndexBufferSharedPtr GetResource(const ConstIndexBufferSmartPointer& indexBuffer);
		PlatformTexture1DSharedPtr GetResource(const ConstTexture1DSmartPointer& texture1D);
		PlatformTexture2DSharedPtr GetResource(const ConstTexture2DSmartPointer& texture2D);
		PlatformTexture3DSharedPtr GetResource(const ConstTexture3DSmartPointer& texture3D);
		PlatformTextureCubeSharedPtr GetResource(const ConstTextureCubeSmartPointer& textureCube);
		PlatformRenderTargetSharedPtr GetResource(const ConstRenderTargetSmartPointer& renderTarget);
		PlatformVertexShaderSharedPtr GetResource(const ConstVertexShaderSmartPointer& vertexShader);
		PlatformPixelShaderSharedPtr GetResource(const ConstPixelShaderSmartPointer& pixelShader);

		virtual bool InTexture2DMap(const ConstTexture2DSmartPointer& texture);
		virtual void InsertInTexture2DMap(const ConstTexture2DSmartPointer& texture, const PlatformTexture2DSharedPtr& platformTexture);

	public:
		// �ӿڵ�ƽ̨��ز��֡�

		// �Ӿ�״̬����
		virtual void SetAlphaState(const ConstAlphaStateSmartPointer& alphaState) = 0;
		virtual void SetCullState(const ConstCullStateSmartPointer& cullState) = 0;
		virtual void SetDepthState(const ConstDepthStateSmartPointer& depthState) = 0;
		virtual void SetOffsetState(const ConstOffsetStateSmartPointer& offsetState) = 0;
		virtual void SetStencilState(const ConstStencilStateSmartPointer& stencilState) = 0;
		virtual void SetWireState(const ConstWireStateSmartPointer& wireState) = 0;

		// �ӿڹ��� �ӿ���������Ļ����ָ���� ԭ������Ļ�����½ǣ�y��ָ���Ϸ���x��ָ���Ҳࡣ
		virtual void SetViewport(const Viewport& viewport) = 0;
		virtual Viewport GetViewport() const = 0;
		virtual void SetDepthRange(const DepthRange& depthRange) = 0;
		virtual DepthRange GetDepthRange() const = 0;
		virtual void Resize(int width, int height) = 0;

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
		virtual bool PreDraw() = 0;
		virtual void PostDraw() = 0;

		// ����2D����������ڵ㣨����2DӦ�ó��� 
		virtual void Draw(const uint8_t* screenBuffer, bool reflectY) = 0;

		// ����2D�ı�����ڵ㡣
		virtual void Draw(int x, int y, const Colour& color, const std::string& message) = 0;

		virtual RendererTypes GetRendererType() const = 0;		

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
		virtual void DrawPrimitive(const ConstVisualSmartPointer& visual) = 0;

	private:
		RendererBasis m_RendererBasis;

		// ȫ��״̬
		AlphaStateSmartPointer m_DefaultAlphaState;
		CullStateSmartPointer m_DefaultCullState;
		DepthStateSmartPointer m_DefaultDepthState;
		OffsetStateSmartPointer m_DefaultOffsetState;
		StencilStateSmartPointer m_DefaultStencilState;
		WireStateSmartPointer m_DefaultWireState;
		ConstAlphaStateSmartPointer m_AlphaState;
		ConstCullStateSmartPointer m_CullState;
		ConstDepthStateSmartPointer m_DepthState;
		ConstOffsetStateSmartPointer m_OffsetState;
		ConstStencilStateSmartPointer m_StencilState;
		ConstWireStateSmartPointer m_WireState;
		bool m_ReverseCullOrder;

		VertexFormatManagementPtr m_VertexFormatManagement;
		VertexBufferManagementPtr m_VertexBufferManagement;
		IndexBufferManagementPtr m_IndexBufferManagement;
		Texture1DManagementPtr m_Texture1DManagement;
		Texture2DManagementPtr m_Texture2DManagement;
		Texture3DManagementPtr m_Texture3DManagement;
		TextureCubeManagementPtr m_TextureCubeManagement;
		RenderTargetManagementPtr m_RenderTargetManagement;
		VertexShaderManagementPtr m_VertexShaderManagement;
		PixelShaderManagementPtr m_PixelShaderManagement;

		GlobalState m_GlobalState;
		CameraState m_CameraState;
		ClearParameter m_ClearParameter;
		ViewportManagement m_ViewportManagement;
		DrawManagement m_DrawManagement; 
 
		// �ض���ƽ̨�����ݡ�
		RendererData m_Data; 

		// ����ȫ��״̬��
		ConstAlphaStateSmartPointer m_OverrideAlphaState;
		ConstCullStateSmartPointer m_OverrideCullState;
		ConstDepthStateSmartPointer m_OverrideDepthState;
		ConstOffsetStateSmartPointer m_OverrideOffsetState;
		ConstStencilStateSmartPointer m_OverrideStencilState;
		ConstWireStateSmartPointer m_OverrideWireState;
	 
		// ���α任�ܵ�������洢��ͼ��ͶӰ��ͶӰ�����
		CameraSmartPointer m_Camera;

		// ���֡��������
		Colour m_ClearColor;
		float m_ClearDepth;
		int m_ClearStencil;

		// ��̨��������ͨ�����Ρ�
		bool m_AllowRed;
		bool m_AllowGreen;
		bool m_AllowBlue;
		bool m_AllowAlpha;

		std::weak_ptr<Renderer> m_RealRenderer;
	};
}

#endif // RENDERING_RENDERERS_RENDERER_IMPL_H
