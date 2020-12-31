// Copyright (c) 2010-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.3.0 (2020/03/27 14:04)

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


// 渲染器类是一个在每个平台实现（Direct3D，OpenGL，软件，嵌入式设备等）的抽象接口。
// 类的描述分解成两部分。第一部分列出了与平台无关的函数和数据，这些在基类实现。
// 第二部分列出了平台相关的接口，这些在子类实现。

namespace Rendering
{
	class RENDERING_HIDDEN_DECLARE RendererImpl : private boost::noncopyable
	{
	public:
		using ClassType = RendererImpl;

		using Colour = Colour<float>;
		using Matrix = Mathematics::FloatMatrix;
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
		// 平台无关的接口部分。

		// 访问构造函数的输入。
		int GetWidth() const;
		int GetHeight() const;
		TextureFormat GetColorFormat() const;
		TextureFormat GetDepthStencilFormat() const;
		int GetNumMultisamples() const;		 

		// 顶点格式管理。顶点格式对象必须是已经分配，它的属性和跨距由应用程序代码进行设置。
		void Bind(const ConstVertexFormatSharedPtr& vertexFormat);
		void Unbind(const ConstVertexFormatSharedPtr& vertexFormat);
		void Enable(const ConstVertexFormatSharedPtr& vertexFormat);
		void Disable(const ConstVertexFormatSharedPtr& vertexFormat);

		// 顶点缓冲区管理。顶点缓冲区对象必须是已经由应用程序代码分配。
		void Bind(const ConstVertexBufferSharedPtr& vertexBuffer);
		void Unbind(const ConstVertexBufferSharedPtr& vertexBuffer);
		void Enable(const ConstVertexBufferSharedPtr& vertexBuffer, int streamIndex = 0, int offset = 0);
		void Disable(const ConstVertexBufferSharedPtr& vertexBuffer, int streamIndex = 0);
		void* Lock(const ConstVertexBufferSharedPtr& vertexBuffer, BufferLocking mode);
		void Unlock(const ConstVertexBufferSharedPtr& vertexBuffer);
		void Update(const ConstVertexBufferSharedPtr& vertexBuffer);

		// 索引缓冲区管理。索引缓冲区对象必须是已经由应用程序代码分配。
		void Bind(const ConstIndexBufferSharedPtr& indexbuffer);
		void Unbind(const ConstIndexBufferSharedPtr& indexbuffer);
		void Enable(const ConstIndexBufferSharedPtr& indexbuffer);
		void Disable(const ConstIndexBufferSharedPtr& indexbuffer);
		void* Lock(const ConstIndexBufferSharedPtr& indexbuffer, BufferLocking mode);
		void Unlock(const ConstIndexBufferSharedPtr& indexbuffer);
		void Update(const ConstIndexBufferSharedPtr& indexbuffer);

		// 1D纹理对象管理。纹理对象必须是已经由应用程序代码分配。
		void Bind(const ConstTexture1DSharedPtr& texture);
		void Unbind(const ConstTexture1DSharedPtr& texture);
		void Enable(const ConstTexture1DSharedPtr& texture, int textureUnit);
		void Disable(const ConstTexture1DSharedPtr& texture, int textureUnit);
		void* Lock(const ConstTexture1DSharedPtr& texture, int level, BufferLocking mode);
		void Unlock(const ConstTexture1DSharedPtr& texture, int level);
		void Update(const ConstTexture1DSharedPtr& texture, int level);

		// 2D纹理对象管理。纹理对象必须是已经由应用程序代码分配。
		void Bind(const ConstTexture2DSharedPtr& texture);
		void Unbind(const ConstTexture2DSharedPtr& texture);
		void Enable(const ConstTexture2DSharedPtr& texture, int textureUnit);
		void Disable(const ConstTexture2DSharedPtr& texture, int textureUnit);
		void* Lock(const ConstTexture2DSharedPtr& texture, int level, BufferLocking mode);
		void Unlock(const ConstTexture2DSharedPtr& texture, int level);
		void Update(const ConstTexture2DSharedPtr& texture, int level);

		// 3D纹理对象管理。纹理对象必须是已经由应用程序代码分配。
		void Bind(const ConstTexture3DSharedPtr& texture);
		void Unbind(const ConstTexture3DSharedPtr& texture);
		void Enable(const ConstTexture3DSharedPtr& texture, int textureUnit);
		void Disable(const ConstTexture3DSharedPtr& texture, int textureUnit);
		void* Lock(const ConstTexture3DSharedPtr& texture, int level, BufferLocking mode);
		void Unlock(const ConstTexture3DSharedPtr& texture, int level);
		void Update(const ConstTexture3DSharedPtr& texture, int level);

		// Cube纹理对象管理。纹理对象必须是已经由应用程序代码分配。
		void Bind(const ConstTextureCubeSharedPtr& texture);
		void Unbind(const ConstTextureCubeSharedPtr& texture);
		void Enable(const ConstTextureCubeSharedPtr& texture, int textureUnit);
		void Disable(const ConstTextureCubeSharedPtr& texture, int textureUnit);
		void* Lock(const ConstTextureCubeSharedPtr& texture, int face, int level, BufferLocking mode);
		void Unlock(const ConstTextureCubeSharedPtr& texture, int face, int level);
		void Update(const ConstTextureCubeSharedPtr& texture, int face, int level);

		// 渲染目标管理。渲染目标对象必须是已经由应用程序代码分配。
		// 在ReadColor的索引index是在多个渲染目标对象的目标索引。 
		void Bind(const ConstRenderTargetSharedPtr& renderTarget);
		void Unbind(const ConstRenderTargetSharedPtr& renderTarget);
		void Enable(const ConstRenderTargetSharedPtr& renderTarget);
		void Disable(const ConstRenderTargetSharedPtr& renderTarget);
		ConstTexture2DSharedPtr ReadColor(int index, const ConstRenderTargetSharedPtr& renderTarget);

		// 顶点着色器管理。顶点着色器对象必须已经由应用程序代码分配。
		void Bind(const ConstVertexShaderSharedPtr& vertexShader);
		void Unbind(const ConstVertexShaderSharedPtr& vertexShader);
		void Enable(const ConstVertexShaderSharedPtr& vertexShader, const ConstShaderParametersSharedPtr& parameters);
		void Disable(const ConstVertexShaderSharedPtr& vertexShader, const ConstShaderParametersSharedPtr& parameters);

		// 像素着色器管理。像素着色器对象必须已经由应用程序代码分配。
		void Bind(const ConstPixelShaderSharedPtr& pixelShader);
		void Unbind(const ConstPixelShaderSharedPtr& pixelShader);
		void Enable(const ConstPixelShaderSharedPtr& pixelShader, const ConstShaderParametersSharedPtr& parameters);
		void Disable(const ConstPixelShaderSharedPtr& pixelShader, const ConstShaderParametersSharedPtr& parameters);

		// TODO. ShaderParameters应该是另一个资源，映射到“常量缓冲区”。 将它们添加到渲染器。 
		// 准备好后，移除ShaderParameters输入以启用/禁用着色器，并设置一个Bind/Unbind/Enable/Disable函数块。

		// 结束资源管理。

		// 访问当前的全局状态。
		const ConstAlphaStateSharedPtr GetAlphaState() const;
		const ConstCullStateSharedPtr GetCullState() const;
		const ConstDepthStateSharedPtr GetDepthState() const;
		const ConstOffsetStateSharedPtr GetOffsetState() const;
		const ConstStencilStateSharedPtr GetStencilState() const;
		const ConstWireStateSharedPtr GetWireState() const;

		// 覆盖全局状态。 如果被覆盖，则在图形调用期间使用此状态代替VisualPass状态。 要撤消覆盖，请传递空指针。
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

		// 访问当前相机状态。
		void SetCamera(const CameraSharedPtr& camera);
		const ConstCameraSharedPtr GetCamera() const;
		const CameraSharedPtr GetCamera();
		const Matrix GetViewMatrix() const;
		const Matrix GetProjectionMatrix() const;
		const Matrix GetPostProjectionMatrix() const;

		// 根据指定的左手屏幕坐标（x，y）并使用当前相机来计算光线。 
		// 输出的“原点”是相机位置，而“方向”是单位长度矢量。 
		// 两者都在世界坐标中。 如果（x，y）在当前视口中的则返回值为'true'。
		PickRay GetPickRay(int x, int y) const;

		// 访问颜色，深度和模板缓冲区的当前清除参数。 颜色缓冲区是后缓冲区。
		void SetClearColor(const Colour& clearColor);
		const Colour GetClearColor() const;
		void SetClearDepth(float clearDepth);
		float GetClearDepth() const;
		void SetClearStencil(int clearStencil);
		int GetClearStencil() const;

		// 访问当前的颜色通道蒙版
		bool GetAllowRed() const;
		bool GetAllowGreen() const;
		bool GetAllowBlue() const;
		bool GetAllowAlpha() const;
		void SetAllowRed(bool allowRed);
		void SetAllowGreen(bool allowGreen);
		void SetAllowBlue(bool allowBlue);
		void SetAllowAlpha(bool allowAlpha);

		// 绘制场景图的可见集合的入口点。
		void Draw(VisibleSet& visibleSet, GlobalEffectSharedPtr globalEffect);

		// 绘制单个对象的入口点。
		void Draw(VisualSharedPtr visual);
		void Draw(const VisualSharedPtr& visual, VisualEffectInstanceSharedPtr instance);

		PlatformVertexFormatSharedPtr GetResource(const ConstVertexFormatSharedPtr& vertexFormat);
		PlatformVertexBufferSharedPtr GetResource(const ConstVertexBufferSharedPtr& vertexBuffer);
		PlatformIndexBufferSharedPtr GetResource(const ConstIndexBufferSharedPtr& indexBuffer);
		PlatformTexture1DSharedPtr GetResource(const ConstTexture1DSharedPtr& texture1D);
		PlatformTexture2DSharedPtr GetResource(const ConstTexture2DSharedPtr& texture2D);
		PlatformTexture3DSharedPtr GetResource(const ConstTexture3DSharedPtr& texture3D);
		PlatformTextureCubeSharedPtr GetResource(const ConstTextureCubeSharedPtr& textureCube);
		PlatformRenderTargetSharedPtr GetResource(const ConstRenderTargetSharedPtr& renderTarget);
		PlatformVertexShaderSharedPtr GetResource(const ConstVertexShaderSharedPtr& vertexShader);
		PlatformPixelShaderSharedPtr GetResource(const ConstPixelShaderSharedPtr& pixelShader);

		virtual bool InTexture2DMap(const ConstTexture2DSharedPtr& texture);
		virtual void InsertInTexture2DMap(const ConstTexture2DSharedPtr& texture, const PlatformTexture2DSharedPtr& platformTexture);

	public:
		// 接口的平台相关部分。

		// 视觉状态管理。
		virtual void SetAlphaState(const ConstAlphaStateSharedPtr& alphaState) = 0;
		virtual void SetCullState(const ConstCullStateSharedPtr& cullState) = 0;
		virtual void SetDepthState(const ConstDepthStateSharedPtr& depthState) = 0;
		virtual void SetOffsetState(const ConstOffsetStateSharedPtr& offsetState) = 0;
		virtual void SetStencilState(const ConstStencilStateSharedPtr& stencilState) = 0;
		virtual void SetWireState(const ConstWireStateSharedPtr& wireState) = 0;

		// 视口管理。 视口以右手屏幕坐标指定。 原点是屏幕的左下角，y轴指向上方，x轴指向右侧。
		virtual void SetViewport(const Viewport& viewport) = 0;
		virtual Viewport GetViewport() const = 0;
		virtual void SetDepthRange(const DepthRange& depthRange) = 0;
		virtual DepthRange GetDepthRange() const = 0;
		virtual void Resize(int width, int height) = 0;

		// 支持清除颜色，深度和模板缓冲区。
		virtual void ClearColorBuffer() = 0;
		virtual void ClearDepthBuffer() = 0;
		virtual void ClearStencilBuffer() = 0;
		virtual void ClearBuffers() = 0;
		virtual void ClearColorBuffer(int x, int y, int w, int h) = 0;
		virtual void ClearDepthBuffer(int x, int y, int w, int h) = 0;
		virtual void ClearStencilBuffer(int x, int y, int w, int h) = 0;
		virtual void ClearBuffers(int x, int y, int w, int h) = 0;
		virtual void DisplayColorBuffer() = 0;

		// 支持在绘制过程中掩藏颜色通道。
		virtual void SetColorMask(bool allowRed, bool allowGreen, bool allowBlue, bool allowAlpha) = 0;

		// 支持PreDraw和PostDraw语义。 所有Renderer抽象接口函数和绘图函数必须出现在以PreDraw()和PostDraw()为边界的代码块中。
		// 通用格式为
		// if (renderer->PreDraw())
		// {
		//		<抽象界面渲染器调用和绘制调用>;
		//		renderer->PostDraw();
		//	}
		virtual bool PreDraw() = 0;
		virtual void PostDraw() = 0;

		// 绘制2D缓冲区的入口点（用于2D应用程序） 
		virtual void Draw(const uint8_t* screenBuffer, bool reflectY) = 0;

		// 绘制2D文本的入口点。
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
		// 绘制3D对象的入口点，由单对象Draw函数调用。
		virtual void DrawPrimitive(const ConstVisualSharedPtr& visual) = 0;

	private:
		RendererBasis m_RendererBasis;

		// 全局状态
		AlphaStateSharedPtr m_DefaultAlphaState;
		CullStateSharedPtr m_DefaultCullState;
		DepthStateSharedPtr m_DefaultDepthState;
		OffsetStateSharedPtr m_DefaultOffsetState;
		StencilStateSharedPtr m_DefaultStencilState;
		WireStateSharedPtr m_DefaultWireState;
		ConstAlphaStateSharedPtr m_AlphaState;
		ConstCullStateSharedPtr m_CullState;
		ConstDepthStateSharedPtr m_DepthState;
		ConstOffsetStateSharedPtr m_OffsetState;
		ConstStencilStateSharedPtr m_StencilState;
		ConstWireStateSharedPtr m_WireState;
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
 
		// 特定于平台的数据。
		RendererData m_Data; 

		// 覆盖全局状态。
		ConstAlphaStateSharedPtr m_OverrideAlphaState;
		ConstCullStateSharedPtr m_OverrideCullState;
		ConstDepthStateSharedPtr m_OverrideDepthState;
		ConstOffsetStateSharedPtr m_OverrideOffsetState;
		ConstStencilStateSharedPtr m_OverrideStencilState;
		ConstWireStateSharedPtr m_OverrideWireState;
	 
		// 几何变换管道。相机存储视图，投影和投影后矩阵。
		CameraSharedPtr m_Camera;

		// 清除帧缓冲区。
		Colour m_ClearColor;
		float m_ClearDepth;
		int m_ClearStencil;

		// 后台缓冲区的通道屏蔽。
		bool m_AllowRed;
		bool m_AllowGreen;
		bool m_AllowBlue;
		bool m_AllowAlpha;

		std::weak_ptr<Renderer> m_RealRenderer;
	};
}

#endif // RENDERING_RENDERERS_RENDERER_IMPL_H
