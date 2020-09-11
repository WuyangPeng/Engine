// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.3.0 (2020/03/27 11:09)

#ifndef RENDERING_RENDERERS_RENDERER_H
#define RENDERING_RENDERERS_RENDERER_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include "PickRay.h"
#include "Viewport.h"
#include "DepthRange.h"
#include "RenderersInternalFwd.h"

#include "Rendering/Shaders/ShadersFwd.h"
#include "Rendering/Shaders/WireState.h"
#include "Rendering/Shaders/CullState.h"
#include "Rendering/Shaders/AlphaState.h"
#include "Rendering/Shaders/DepthState.h"
#include "Rendering/Shaders/OffsetState.h"
#include "Rendering/Shaders/StencilState.h" 
#include "Rendering/Shaders/VisualEffectInstance.h"

#include "Rendering/Resources/ResourcesFwd.h"
#include "Rendering/Resources/Texture1D.h"
#include "Rendering/Resources/Texture2D.h"
#include "Rendering/Resources/Texture3D.h"
#include "Rendering/Resources/TextureCube.h"
#include "Rendering/Resources/VertexFormat.h"
#include "Rendering/Resources/VertexBuffer.h"
#include "Rendering/Resources/IndexBuffer.h"
#include "Rendering/Resources/RenderTarget.h"

#include "Rendering/SceneGraph/SceneGraphFwd.h"
#include "Rendering/SceneGraph/Camera.h"
#include "Rendering/SceneGraph/Visual.h"

#include "Rendering/GlobalEffects/GlobalEffectsFwd.h"
#include "Rendering/GlobalEffects/GlobalEffect.h"

#include "Rendering/DataTypes/DataTypesFwd.h"
#include "Rendering/DataTypes/Colour.h"

#include <boost/noncopyable.hpp>
#include <string>

EXPORT_NONCOPYABLE_CLASS(RENDERING);
RENDERING_EXPORT_SHARED_PTR(RendererImpl);
template class RENDERING_DEFAULT_DECLARE std::weak_ptr<Rendering::Renderer>;
template class RENDERING_DEFAULT_DECLARE std::enable_shared_from_this<Rendering::Renderer>;

namespace Rendering
{
	class RENDERING_DEFAULT_DECLARE Renderer : private boost::noncopyable, public std::enable_shared_from_this<Renderer>
	{
	public:
		NON_COPY_CLASSES_TYPE_DECLARE(Renderer);   
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
		// 初始化相关接口（必须手动调用）
		// 创建一个create函数，将构造函数设成私有
		void Init();

	public:
		// 平台无关的接口部分。

		// 访问构造函数的输入。
		int GetWidth() const;
		int GetHeight() const;
		TextureFormat GetColorFormat() const;
		TextureFormat GetDepthStencilFormat() const;
		int GetNumMultisamples() const;

		// 资源管理。该资源被定义为顶点格式，顶点缓冲区，索引缓冲区，纹理（1D，2D，3D，立方体），
		// 渲染目标，顶点着色器和像素着色器。函数执行以下操作。

		// Bind:  创建对应于输入对象的资源。渲染器保存对象和资源之间的映射。
		//        在大多数情况下，视频存储器从物体相应的系统内存中进行分配和拷贝。
		//        如果Enable或Lock在Bind之前调用，渲染器默默地创建了一个资源，而不是导致异常。

		// Unbind:  销毁对应于输入对象的资源。渲染器从映射中删除对象资源。
		//          对象保持其系统存储器的拷贝和属性，所以它总是可以被再次绑定。

		// Enable:  该资源在在当前绘图中调用处于活动状态，但必须在调用DrawPrimitive之前。

		// Disable: 该资源在在当前绘图中调用处于非活动状态，但必须在调用DrawPrimitive之后。

		// Lock: 得到一个指向资源的视频存储器的指针（虽然存储器也可能是在AGP内存或者甚至取决于图形API和资源使用的系统内存）。
		//       使用此函数来更新显存。如果这样做，要知道，没有更新对象的相应系统存储装置中的两个内存拷贝不同步。
		//       您也可以只是为了读而锁定，在这种情况下，显存的内容被保留。保持资源锁定尽可能少的时间。

		// Unlock:  释放指到资源的视频存储器的指针。

		// Update:  锁定资源的视频存储器，复制系统存储器的内容到它，然后解锁视频内存。
		//          这是推荐更新资源的方式（更新系统内存，然后调用Update）。更新是为渲染调用函数。

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
		void Bind(const ConstVertexShaderSmartPointer& vshader);
		void Unbind(const ConstVertexShaderSmartPointer& vshader);
		void Enable(const ConstVertexShaderSmartPointer& vshader, const ConstShaderParametersSmartPointer& parameters);
		void Disable(const ConstVertexShaderSmartPointer& vshader, const ConstShaderParametersSmartPointer& parameters);
 
		// 像素着色器管理。像素着色器对象必须已经由应用程序代码分配。
		void Bind(const ConstPixelShaderSmartPointer& pshader);
		void Unbind(const ConstPixelShaderSmartPointer& pshader);
		void Enable(const ConstPixelShaderSmartPointer& pshader, const ConstShaderParametersSmartPointer& parameters);
		void Disable(const ConstPixelShaderSmartPointer& pshader, const ConstShaderParametersSmartPointer& parameters);

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
		void Draw(VisibleSet& visibleSet, const GlobalEffectSmartPointer& globalEffect = GlobalEffectSmartPointer{});

		// 绘制单个对象的入口点。
		void Draw(const VisualSmartPointer& visual);
		void Draw(const VisualSmartPointer& visual, const VisualEffectInstanceSmartPointer& instance);

	public:
		// 接口的平台相关部分。

		// 视觉状态管理。
		void SetAlphaState(const ConstAlphaStateSmartPointer& alphaState);
		void SetCullState(const ConstCullStateSmartPointer& cullState);
		void SetDepthState(const ConstDepthStateSmartPointer& depthState);
		void SetOffsetState(const ConstOffsetStateSmartPointer& offsetState);
		void SetStencilState(const ConstStencilStateSmartPointer& stencilState);
		void SetWireState(const ConstWireStateSmartPointer& wireState);

		// 视口管理。 视口以右手屏幕坐标指定。 原点是屏幕的左下角，y轴指向上方，x轴指向右侧。
		void SetViewport(const Viewport& viewport);
		Viewport GetViewport() const;
		void SetDepthRange(const DepthRange& depthRange);
		DepthRange GetDepthRange() const;
		void Resize(int width, int height);

		// 支持清除颜色，深度和模板缓冲区。
		void ClearColorBuffer();
		void ClearDepthBuffer();
		void ClearStencilBuffer();
		void ClearBuffers();
		void ClearColorBuffer(int x, int y, int w, int h);
		void ClearDepthBuffer(int x, int y, int w, int h);
		void ClearStencilBuffer(int x, int y, int w, int h);
		void ClearBuffers(int x, int y, int w, int h);
		void DisplayColorBuffer(); 

		// 支持在绘制过程中掩藏颜色通道。
		void SetColorMask(bool allowRed, bool allowGreen, bool allowBlue, bool allowAlpha);

		// 支持PreDraw和PostDraw语义。 所有Renderer抽象接口函数和绘图函数必须出现在以PreDraw()和PostDraw()为边界的代码块中。
		// 通用格式为
		// if (renderer->PreDraw())
		// {
		//		<抽象界面渲染器调用和绘制调用>;
		//		renderer->PostDraw();
		//	}
		bool PreDraw();
		void PostDraw();

		// 绘制2D缓冲区的入口点（用于2D应用程序） 
		void Draw(const uint8_t* screenBuffer, bool reflectY = false);
		void Draw(const std::vector<ColourUByte>& screenBuffer, bool reflectY = false);
 
		// 绘制2D文本的入口点。
		void Draw(int x, int y, const Colour& color, const std::string& message);

		bool InTexture2DMap(const ConstTexture2DSmartPointer& texture);
		void InsertInTexture2DMap(const ConstTexture2DSmartPointer& texture,const PlatformTexture2DSharedPtr& platformTexture);

		RendererTypes GetRendererType() const;	 

	private:
		IMPL_TYPE_DECLARE(Renderer); 
		int64_t m_RendererID;
	};

	CORE_TOOLS_SHARED_PTR_DECLARE(Renderer);
}

#endif // RENDERING_RENDERERS_RENDERER_H
