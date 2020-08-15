// Copyright (c) 2011-2020
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
		// 平台无关的接口部分。

		// 访问构造函数的输入。
		int GetWidth() const;
		int GetHeight() const;
		TextureFormat GetColorFormat() const;
		TextureFormat GetDepthStencilFormat() const;
		int GetNumMultisamples() const;		 

		// 顶点格式管理。顶点格式对象必须是已经分配，它的属性和跨距由应用程序代码进行设置。
		void Bind(const ConstVertexFormatSmartPointer& vertexFormat);
		void Unbind(const ConstVertexFormatSmartPointer& vertexFormat);
		void Enable(const ConstVertexFormatSmartPointer& vertexFormat);
		void Disable(const ConstVertexFormatSmartPointer& vertexFormat);

		// 顶点缓冲区管理。顶点缓冲区对象必须是已经由应用程序代码分配。
		void Bind(const ConstVertexBufferSmartPointer& vertexBuffer);
		void Unbind(const ConstVertexBufferSmartPointer& vertexBuffer);
		void Enable(const ConstVertexBufferSmartPointer& vertexBuffer, int streamIndex = 0, int offset = 0);
		void Disable(const ConstVertexBufferSmartPointer& vertexBuffer, int streamIndex = 0);
		void* Lock(const ConstVertexBufferSmartPointer& vertexBuffer, BufferLocking mode);
		void Unlock(const ConstVertexBufferSmartPointer& vertexBuffer);
		void Update(const ConstVertexBufferSmartPointer& vertexBuffer);

		// 索引缓冲区管理。索引缓冲区对象必须是已经由应用程序代码分配。
		void Bind(const ConstIndexBufferSmartPointer& indexbuffer);
		void Unbind(const ConstIndexBufferSmartPointer& indexbuffer);
		void Enable(const ConstIndexBufferSmartPointer& indexbuffer);
		void Disable(const ConstIndexBufferSmartPointer& indexbuffer);
		void* Lock(const ConstIndexBufferSmartPointer& indexbuffer, BufferLocking mode);
		void Unlock(const ConstIndexBufferSmartPointer& indexbuffer);
		void Update(const ConstIndexBufferSmartPointer& indexbuffer);

		// 1D纹理对象管理。纹理对象必须是已经由应用程序代码分配。
		void Bind(const ConstTexture1DSmartPointer& texture);
		void Unbind(const ConstTexture1DSmartPointer& texture);
		void Enable(const ConstTexture1DSmartPointer& texture, int textureUnit);
		void Disable(const ConstTexture1DSmartPointer& texture, int textureUnit);
		void* Lock(const ConstTexture1DSmartPointer& texture, int level, BufferLocking mode);
		void Unlock(const ConstTexture1DSmartPointer& texture, int level);
		void Update(const ConstTexture1DSmartPointer& texture, int level);

		// 2D纹理对象管理。纹理对象必须是已经由应用程序代码分配。
		void Bind(const ConstTexture2DSmartPointer& texture);
		void Unbind(const ConstTexture2DSmartPointer& texture);
		void Enable(const ConstTexture2DSmartPointer& texture, int textureUnit);
		void Disable(const ConstTexture2DSmartPointer& texture, int textureUnit);
		void* Lock(const ConstTexture2DSmartPointer& texture, int level, BufferLocking mode);
		void Unlock(const ConstTexture2DSmartPointer& texture, int level);
		void Update(const ConstTexture2DSmartPointer& texture, int level);

		// 3D纹理对象管理。纹理对象必须是已经由应用程序代码分配。
		void Bind(const ConstTexture3DSmartPointer& texture);
		void Unbind(const ConstTexture3DSmartPointer& texture);
		void Enable(const ConstTexture3DSmartPointer& texture, int textureUnit);
		void Disable(const ConstTexture3DSmartPointer& texture, int textureUnit);
		void* Lock(const ConstTexture3DSmartPointer& texture, int level, BufferLocking mode);
		void Unlock(const ConstTexture3DSmartPointer& texture, int level);
		void Update(const ConstTexture3DSmartPointer& texture, int level);

		// Cube纹理对象管理。纹理对象必须是已经由应用程序代码分配。
		void Bind(const ConstTextureCubeSmartPointer& texture);
		void Unbind(const ConstTextureCubeSmartPointer& texture);
		void Enable(const ConstTextureCubeSmartPointer& texture, int textureUnit);
		void Disable(const ConstTextureCubeSmartPointer& texture, int textureUnit);
		void* Lock(const ConstTextureCubeSmartPointer& texture, int face, int level, BufferLocking mode);
		void Unlock(const ConstTextureCubeSmartPointer& texture, int face, int level);
		void Update(const ConstTextureCubeSmartPointer& texture, int face, int level);

		// 渲染目标管理。渲染目标对象必须是已经由应用程序代码分配。
		// 在ReadColor的索引index是在多个渲染目标对象的目标索引。 
		void Bind(const ConstRenderTargetSmartPointer& renderTarget);
		void Unbind(const ConstRenderTargetSmartPointer& renderTarget);
		void Enable(const ConstRenderTargetSmartPointer& renderTarget);
		void Disable(const ConstRenderTargetSmartPointer& renderTarget);
		ConstTexture2DSmartPointer ReadColor(int index, const ConstRenderTargetSmartPointer& renderTarget);

		// 顶点着色器管理。顶点着色器对象必须已经由应用程序代码分配。
		void Bind(const ConstVertexShaderSmartPointer& vertexShader);
		void Unbind(const ConstVertexShaderSmartPointer& vertexShader);
		void Enable(const ConstVertexShaderSmartPointer& vertexShader, const ConstShaderParametersSmartPointer& parameters);
		void Disable(const ConstVertexShaderSmartPointer& vertexShader, const ConstShaderParametersSmartPointer& parameters);

		// 像素着色器管理。像素着色器对象必须已经由应用程序代码分配。
		void Bind(const ConstPixelShaderSmartPointer& pixelShader);
		void Unbind(const ConstPixelShaderSmartPointer& pixelShader);
		void Enable(const ConstPixelShaderSmartPointer& pixelShader, const ConstShaderParametersSmartPointer& parameters);
		void Disable(const ConstPixelShaderSmartPointer& pixelShader, const ConstShaderParametersSmartPointer& parameters);

		// TODO. ShaderParameters应该是另一个资源，映射到“常量缓冲区”。 将它们添加到渲染器。 
		// 准备好后，移除ShaderParameters输入以启用/禁用着色器，并设置一个Bind/Unbind/Enable/Disable函数块。

		// 结束资源管理。

		// 访问当前的全局状态。
		const ConstAlphaStateSmartPointer GetAlphaState() const;
		const ConstCullStateSmartPointer GetCullState() const;
		const ConstDepthStateSmartPointer GetDepthState() const;
		const ConstOffsetStateSmartPointer GetOffsetState() const;
		const ConstStencilStateSmartPointer GetStencilState() const;
		const ConstWireStateSmartPointer GetWireState() const;

		// 覆盖全局状态。 如果被覆盖，则在图形调用期间使用此状态代替VisualPass状态。 要撤消覆盖，请传递空指针。
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

		// 访问当前相机状态。
		void SetCamera(const CameraSmartPointer& camera);
		const ConstCameraSmartPointer GetCamera() const;
		const CameraSmartPointer GetCamera();
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
		void Draw(VisibleSet& visibleSet, GlobalEffectSmartPointer globalEffect);

		// 绘制单个对象的入口点。
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
		// 接口的平台相关部分。

		// 视觉状态管理。
		virtual void SetAlphaState(const ConstAlphaStateSmartPointer& alphaState) = 0;
		virtual void SetCullState(const ConstCullStateSmartPointer& cullState) = 0;
		virtual void SetDepthState(const ConstDepthStateSmartPointer& depthState) = 0;
		virtual void SetOffsetState(const ConstOffsetStateSmartPointer& offsetState) = 0;
		virtual void SetStencilState(const ConstStencilStateSmartPointer& stencilState) = 0;
		virtual void SetWireState(const ConstWireStateSmartPointer& wireState) = 0;

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
		virtual void DrawPrimitive(const ConstVisualSmartPointer& visual) = 0;

	private:
		RendererBasis m_RendererBasis;

		// 全局状态
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
 
		// 特定于平台的数据。
		RendererData m_Data; 

		// 覆盖全局状态。
		ConstAlphaStateSmartPointer m_OverrideAlphaState;
		ConstCullStateSmartPointer m_OverrideCullState;
		ConstDepthStateSmartPointer m_OverrideDepthState;
		ConstOffsetStateSmartPointer m_OverrideOffsetState;
		ConstStencilStateSmartPointer m_OverrideStencilState;
		ConstWireStateSmartPointer m_OverrideWireState;
	 
		// 几何变换管道。相机存储视图，投影和投影后矩阵。
		CameraSmartPointer m_Camera;

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
