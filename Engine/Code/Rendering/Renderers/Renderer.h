// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/26 15:33)

#ifndef RENDERING_RENDERERS_RENDERER_H
#define RENDERING_RENDERERS_RENDERER_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include "Flags/RendererTypes.h"
#include "Rendering/DataTypes/Flags/TextureFormat.h"
#include "Rendering/Resources/Flags/BufferFlags.h"
#include "Rendering/Resources/Texture2D.h"
#include "Rendering/DataTypes/Colour.h"
#include "Rendering/SceneGraph/Camera.h"
#include "Rendering/Shaders/AlphaState.h"
#include "Rendering/Shaders/CullState.h"
#include "Rendering/Shaders/DepthState.h"
#include "Rendering/Shaders/OffsetState.h"
#include "Rendering/Shaders/StencilState.h"
#include "Rendering/Shaders/WireState.h"

#include <boost/noncopyable.hpp>
#include <string>
 
RENDERING_EXPORT_SHARED_PTR(RendererImpl);
RENDERING_EXPORT_SHARED_PTR(RendererInputImpl);
EXPORT_NONCOPYABLE_CLASS(RENDERING);

namespace Rendering
{
	class RendererBasis;
	class VertexFormat;
	class VertexBuffer;
	class IndexBuffer;
	class Texture1D;
	class Texture2D;
	class Texture3D;
	class TextureCube;
	class RenderTarget;
	class VertexShader;
	class PixelShader;

	class PlatformTexture2D;

	class VisibleSet;
	class GlobalEffect;
	class Visual;
	class VisualEffectInstance;

    class RENDERING_DEFAULT_DECLARE Renderer : private boost::noncopyable
    {
    public:
		NON_COPY_CLASSES_TYPE_DECLARE(Renderer);
		using VertexFormatConstPtr = const VertexFormat*;
		using VertexBufferConstPtr = const VertexBuffer*;
		using IndexBufferConstPtr = const IndexBuffer*;
		using Texture1DConstPtr = const Texture1D*;
		using Texture2DConstPtr = const Texture2D*;
		using Texture3DConstPtr = const Texture3D*;
		using TextureCubeConstPtr = const TextureCube*;
		using RenderTargetConstPtr = const RenderTarget*;
		using VertexShaderConstPtr = const VertexShader*;
		using PixelShaderConstPtr = const PixelShader*;
		using Texture2DSmartPointer = CoreTools::FourthSubclassSmartPointer<Texture2D>;
		using ConstTexture2DSmartPointer = CoreTools::ConstFourthSubclassSmartPointer<Texture2D>;
		using Colour = Colour<float>;
		using PlatformTexture2DSharedPtr = std::shared_ptr<PlatformTexture2D>;
        
    public: 
		explicit Renderer(const std::string& fileName);
        Renderer(RendererTypes type,const RendererBasis& basis);
		~Renderer();
        
        CLASS_INVARIANT_DECLARE;

		// 访问构造函数的输入。
		int GetWidth () const;
		int GetHeight () const;
		TextureFormat GetColorFormat () const;
		TextureFormat GetDepthStencilFormat () const;
		int GetNumMultisamples () const;

		// 顶点格式管理。顶点格式对象必须是已经分配，
		// 它的属性和跨距由应用程序代码进行设置。
		void Bind (VertexFormatConstPtr vertexFormat);
		void Unbind (VertexFormatConstPtr vertexFormat);
		void Enable (VertexFormatConstPtr vertexFormat);
		void Disable (VertexFormatConstPtr vertexFormat);

		// 顶点缓冲区管理。顶点缓冲区对象必须是已经由应用程序代码分配。
        void Bind (VertexBufferConstPtr vertexBuffer);
        void Unbind (VertexBufferConstPtr vertexBuffer);
        void Enable (VertexBufferConstPtr vertexBuffer,unsigned int streamIndex = 0, unsigned int offset = 0);
        void Disable (VertexBufferConstPtr vertexBuffer,unsigned int streamIndex = 0);
        void* Lock (VertexBufferConstPtr vertexBuffer, BufferLocking mode);
        void Unlock (VertexBufferConstPtr vertexBuffer);
        void Update (VertexBufferConstPtr vertexBuffer);
        
        // 索引缓冲区管理。索引缓冲区对象必须是已经由应用程序代码分配。
        void Bind (IndexBufferConstPtr indexbuffer);
        void Unbind (IndexBufferConstPtr indexbuffer);
        void Enable (IndexBufferConstPtr indexbuffer);
        void Disable (IndexBufferConstPtr indexbuffer);
        void* Lock (IndexBufferConstPtr indexbuffer, BufferLocking mode);
        void Unlock (IndexBufferConstPtr indexbuffer);
        void Update (IndexBufferConstPtr indexbuffer);

        // 1D纹理对象管理。纹理对象必须是已经由应用程序代码分配。
        void Bind (Texture1DConstPtr texture);
        void Unbind (Texture1DConstPtr texture);
        void Enable (Texture1DConstPtr texture, int textureUnit);
        void Disable (Texture1DConstPtr texture, int textureUnit);
        void* Lock (Texture1DConstPtr texture, int level,BufferLocking mode);
        void Unlock (Texture1DConstPtr texture, int level);
        void Update (Texture1DConstPtr texture, int level);
        
        // 2D纹理对象管理。纹理对象必须是已经由应用程序代码分配。
        void Bind (Texture2DConstPtr texture);
        void Unbind (Texture2DConstPtr texture);
        void Enable (Texture2DConstPtr texture, int textureUnit);
        void Disable (Texture2DConstPtr texture, int textureUnit);
        void* Lock (Texture2DConstPtr, int level,BufferLocking mode);
        void Unlock (Texture2DConstPtr, int level);
        void Update (Texture2DConstPtr, int level);
        
        // 3D纹理对象管理。纹理对象必须是已经由应用程序代码分配。
        void Bind (Texture3DConstPtr texture);
        void Unbind (Texture3DConstPtr texture);
        void Enable (Texture3DConstPtr texture, int textureUnit);
        void Disable (Texture3DConstPtr texture, int textureUnit);
        void* Lock (Texture3DConstPtr texture, int level,BufferLocking mode);
        void Unlock (Texture3DConstPtr texture, int level);
        void Update (Texture3DConstPtr texture, int level);
        
        // Cube纹理对象管理。纹理对象必须是已经由应用程序代码分配。
        void Bind (TextureCubeConstPtr texture);
        void Unbind (TextureCubeConstPtr texture);
        void Enable (TextureCubeConstPtr texture, int textureUnit);
        void Disable (TextureCubeConstPtr texture, int textureUnit);
        void* Lock (TextureCubeConstPtr texture, int face, int level,BufferLocking mode);
        void Unlock (TextureCubeConstPtr texture, int face, int level);
        void Update (TextureCubeConstPtr texture, int face, int level);

		// 渲染目标管理。渲染目标对象必须是已经由应用程序代码分配。
		// 在ReadColor的索引index是在多个渲染目标对象的目标索引。 
		void Bind (RenderTargetConstPtr renderTarget);
		void Unbind (RenderTargetConstPtr renderTarget);
		void Enable (RenderTargetConstPtr renderTarget);
		void Disable (RenderTargetConstPtr renderTarget);
		ConstTexture2DSmartPointer ReadColor(int index,RenderTargetConstPtr renderTarget); 

		// The entry point for drawing 2D buffers (for 2D applications).
		void Draw(const unsigned char* screenBuffer, bool reflectY = false);

		void ClearColorBuffer ();
		void ClearBuffers ();
		void Resize (int width, int height);
		 // The entry point for drawing 2D text.
		void DrawMessage (int x, int y, const Colour& color,const std::string& message);
		const Colour GetClearColor () const;

		RendererTypes GetRendererType() const;

		bool PreDraw ();
		void PostDraw ();
		void DisplayColorBuffer ();

		void SetCamera (const ConstCameraSmartPointer& camera);
		const ConstCameraSmartPointer GetCamera () const;

		bool InTexture2DMap (Texture2DConstPtr texture);
		void InsertInTexture2DMap (Texture2DConstPtr texture,PlatformTexture2DSharedPtr platformTexture);

		// Access to current global state.
		const ConstAlphaStateSmartPointer GetAlphaState() const;
		const ConstCullStateSmartPointer GetCullState() const;
		const ConstDepthStateSmartPointer GetDepthState() const;
		const ConstOffsetStateSmartPointer GetOffsetState() const;
		const ConstStencilStateSmartPointer GetStencilState() const;
		const ConstWireStateSmartPointer GetWireState() const;

		void SetOverrideAlphaState(const ConstAlphaStateSmartPointer& alphaState);
		void SetOverrideCullState(const ConstCullStateSmartPointer&  cullState);
		void SetOverrideDepthState(const ConstDepthStateSmartPointer&  depthState);
		void SetOverrideOffsetState(const ConstOffsetStateSmartPointer&  offsetState);
		void SetOverrideStencilState(const ConstStencilStateSmartPointer&  stencilState);
		void SetOverrideWireState(const ConstWireStateSmartPointer&  wireState);
		const ConstAlphaStateSmartPointer GetOverrideAlphaState() const;
		const ConstCullStateSmartPointer GetOverrideCullState() const;
		const ConstDepthStateSmartPointer GetOverrideDepthState() const;
		const ConstOffsetStateSmartPointer GetOverrideOffsetState() const;
		const ConstStencilStateSmartPointer GetOverrideStencilState() const;
		const ConstWireStateSmartPointer GetOverrideWireState() const;
		void SetReverseCullOrder(bool reverseCullOrder);
		bool GetReverseCullOrder() const;

		void SetAlphaState(const ConstAlphaStateSmartPointer& alphaState);
		void SetCullState(const ConstCullStateSmartPointer& cullState);
		void SetDepthState(const ConstDepthStateSmartPointer& depthState);
		void SetOffsetState(const ConstOffsetStateSmartPointer& offsetState);
		void SetStencilState(const ConstStencilStateSmartPointer& stencilState);
		void SetWireState(const ConstWireStateSmartPointer& wireState);

		void SetDepthRange(float zMin, float zMax);
		void GetDepthRange(float& zMin, float& zMax) const;

		// Support for masking color channels during drawing.
		void SetColorMask(bool allowRed, bool allowGreen,bool allowBlue, bool allowAlpha);

		// The entry point to drawing the visible set of a scene graph.
		void Draw(const VisibleSet& visibleSet, GlobalEffect* globalEffect = 0);

		// The entry points for drawing a single object.
		void Draw(const Visual* visual);
		void Draw(const Visual* visual, const VisualEffectInstance* instance);
		 
		// The entry point for drawing 2D text.
		virtual void Draw(int x, int y, const Colour& color,const std::string& message);

	private:	
		using RendererInputPtr = std::shared_ptr<RendererInputImpl>;
		
    private:
		IMPL_TYPE_DECLARE(Renderer);
		RendererInputPtr m_InputImpl;
    };

	CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(First, Renderer);
}

#endif // RENDERING_RENDERERS_RENDERER_H
