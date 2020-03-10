// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/26 14:32)

#ifndef RENDERING_RENDERERS_RENDERER_IMPL_H
#define RENDERING_RENDERERS_RENDERER_IMPL_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/MemoryTools/ThirdSubclassSmartPointer.h"
#include "CoreTools/MemoryTools/ConstThirdSubclassSmartPointer.h"
#include "Mathematics/Base/Float4.h"
#include "Mathematics/Algebra/Matrix.h"
#include "Rendering/Resources/Texture2D.h"
#include "Rendering/Resources/Flags/BufferFlags.h"
#include "Rendering/Renderers/Flags/RendererTypes.h"
#include "Rendering/DataTypes/Flags/TextureFormat.h"
#include "Rendering/Shaders/WireState.h"
#include "Rendering/Shaders/CullState.h"
#include "Rendering/Shaders/DepthState.h"
#include "Rendering/Shaders/AlphaState.h"
#include "Rendering/Shaders/OffsetState.h"
#include "Rendering/Shaders/StencilState.h"
#include "Rendering/DataTypes/Colour.h"
#include "Rendering/SceneGraph/Camera.h"
#include "Rendering/Renderers/GlobalState.h"
#include "Rendering/Renderers/CameraState.h"
#include "Rendering/Renderers/ClearParameter.h"
#include "Rendering/Renderers/DrawManagement.h"
#include "Rendering/Renderers/ShaderManagement.h"
#include "Rendering/Renderers/ViewportManagement.h"

#include <boost/noncopyable.hpp>


// 渲染器类是一个在每个平台实现（Direct3D，OpenGL，软件，嵌入式设备等）的抽象接口。
// 类的描述分解成两部分。第一部分列出了与平台无关的函数和数据，这些在基类实现。
// 第二部分列出了平台相关的接口，这些在子类实现。

namespace Rendering
{
	class Renderer;

	class RendererBasis;
	class VertexFormatManagement;	

    template <typename PlatformBufferType>
	class BufferManagement;

	template <typename PlatformTextureType>
	class TextureManagement;

	class RenderTargetManagement;

    class VertexFormat;
	class PlatformVertexFormat;

    class VertexBuffer;
    class PlatformVertexBuffer;

    class IndexBuffer;
    class PlatformIndexBuffer;

	class Texture1D;
	class PlatformTexture1D;

	class Texture2D;
	class PlatformTexture2D;

	class Texture3D;
	class PlatformTexture3D;

	class TextureCube;
	class PlatformTextureCube;

	class RenderTarget;
	class PlatformRenderTarget;

	class VisibleSet;
	class GlobalEffect;
	class Visual;
	class VisualEffectInstance;

	class VertexShader;
	class ShaderParameters;
	class PixelShader;

	class PdrVertexShader;
	class PdrPixelShader;
	class RendererInput;
	class RendererData;
    
    class RENDERING_HIDDEN_DECLARE RendererImpl : private boost::noncopyable
    {
    public:
        using ClassType = RendererImpl;
		using VertexFormatConstPtr = const VertexFormat*;
		using VertexBufferConstPtr = const VertexBuffer*;
		using IndexBufferConstPtr = const IndexBuffer*;
		using Texture1DConstPtr = const Texture1D*;
		using Texture2DConstPtr = const Texture2D*;
		using Texture3DConstPtr = const Texture3D*;
		using TextureCubeConstPtr = const TextureCube*;
		using RenderTargetConstPtr = const RenderTarget*;
        using PlatformVertexFormatSharedPtr = std::shared_ptr<PlatformVertexFormat>;
        using PlatformVertexBufferSharedPtr = std::shared_ptr<PlatformVertexBuffer>;
        using PlatformIndexBufferSharedPtr = std::shared_ptr<PlatformIndexBuffer>;
        using PlatformTexture1DSharedPtr = std::shared_ptr<PlatformTexture1D>;
		using PlatformTexture2DSharedPtr = std::shared_ptr<PlatformTexture2D>;
		using PlatformTexture3DSharedPtr = std::shared_ptr<PlatformTexture3D>;
		using PlatformTextureCubeSharedPtr = std::shared_ptr<PlatformTextureCube>;
		using PlatformRenderTargetSharedPtr = std::shared_ptr<PlatformRenderTarget>;
		using Texture2DSmartPointer = CoreTools::FourthSubclassSmartPointer<Texture2D>;
		using ConstTexture2DSmartPointer = CoreTools::ConstFourthSubclassSmartPointer<Texture2D>;
		using Colour = Colour<float>;
	
	public:
        explicit RendererImpl(const RendererBasis& basis);
        virtual ~RendererImpl();
        
        CLASS_INVARIANT_VIRTUAL_DECLARE;

    public:
		void SetRealRenderer(Renderer* renderer);

        // 平台无关的接口部分。
        
        // 访问构造函数的输入。
        int GetWidth () const;
        int GetHeight () const;
        TextureFormat GetColorFormat () const;
        TextureFormat GetDepthStencilFormat () const;
        int GetNumMultisamples () const;
        
        // 资源管理。该资源被定义为顶点格式，顶点缓冲区，索引缓冲区，纹理（1D，2D，3D，立方体），
        // 渲染目标，顶点着色器和像素着色器。函数执行以下操作。
        
        // Bind:  创建对应于输入对象的资源。渲染器保存对象和资源之间的映射。
        //        在大多数情况下，视频存储器从物体相应的系统内存中进行分配和拷贝。
        //        如果Enable或Lock在Bind之前调用，渲染器默默地创建了一个资源，而不是导致异常。
        
        // Unbind:  销毁对应于输入对象的资源。渲染器从映射中删除对象资源。
        //          对象保持其系统存储器的拷贝和属性，所以它总是可以被再次绑定。
        
        // Enable:  该资源在在当前绘图中调用处于活动状态，但必须在调用DrawPrimitive之前。
        
        // Disable: 该资源在在当前绘图中调用处于非活动状态，但必须在调用DrawPrimitive之后。
      
        // Lock: 得到一个指向资源的视频存储器的指针
        //      （虽然存储器也可能是在AGP内存或者甚至取决于图形API和资源使用的系统内存）。
        //       使用此函数来更新显存。如果这样做，要知道，
        //       没有更新对象的相应系统存储装置中的两个内存拷贝不同步。
        //       您也可以只是为了读而锁定，在这种情况下，显存的内容被保留。保持资源锁定尽可能少的时间。
       
        // Unlock:  释放指到资源的视频存储器的指针。
        
        // Update:  锁定资源的视频存储器，复制系统存储器的内容到它，然后解锁视频内存。
        //          这是推荐更新资源的方式（更新系统内存，然后调用Update）。更新是为渲染调用函数。
     
        // ReadColor:  此函数仅用于的RenderTarget实现。当调用ReadColor时渲染目标必须被禁止。
        // 该函数返回渲染目标彩色视频内存的副本作为一个Texture2D对象。
        
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
		void* Lock(Texture3DConstPtr texture, int level,BufferLocking mode);
		void Unlock(Texture3DConstPtr texture, int level);
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
 
		
        // Vertex shader management.  The vertex shader object must have been
        // already allocated by the application code.
        void Bind (const VertexShader* vshader);
        void Unbind (const VertexShader* vshader);
        void Enable (const VertexShader* vshader,const ShaderParameters* parameters);
        void Disable (const VertexShader* vshader,const ShaderParameters* parameters);
        
        // Pixel shader management.  The pixel shader object must have been
        // already allocated by the application code.
        void Bind (const PixelShader* pshader);
        void Unbind (const PixelShader* pshader);
        void Enable (const PixelShader* pshader,const ShaderParameters* parameters);
        void Disable (const PixelShader* pshader, const ShaderParameters* parameters);
        
        // TODO.  ShaderParameters should be another resource, mapped to
        // "constant buffers".  Add these to the renderer.  When ready, remove the
        // ShaderParameters inputs to Enable/Disable of shaders and set up a block
        // of Bind/Unbind/Enable/Disable functions.
        
        // === End resource management.
		 

		 PlatformVertexFormatSharedPtr GetResource (VertexFormatConstPtr vertexFormat);		
		 PlatformVertexBufferSharedPtr GetResource (VertexBufferConstPtr vertexBuffer);
		 PlatformIndexBufferSharedPtr GetResource (IndexBufferConstPtr indexBuffer);
		 PlatformTexture1DSharedPtr GetResource (Texture1DConstPtr texture1D);
		 PlatformTexture2DSharedPtr GetResource (Texture2DConstPtr texture2D);
		 PlatformTexture3DSharedPtr GetResource (Texture3DConstPtr texture3D);
		 PlatformTextureCubeSharedPtr GetResource (TextureCubeConstPtr textureCube);	
		 PlatformRenderTargetSharedPtr GetResource (RenderTargetConstPtr renderTarget);
 
		 PdrVertexShader* GetResource (const VertexShader* vshader);
		 PdrPixelShader* GetResource (const PixelShader* pshader);
		
		 bool InTexture2DMap (Texture2DConstPtr texture);
		 void InsertInTexture2DMap (Texture2DConstPtr texture,PlatformTexture2DSharedPtr platformTexture);

        
        // Access to current global state.
        const ConstAlphaStateSmartPointer GetAlphaState () const;
		const ConstCullStateSmartPointer GetCullState() const;
		const ConstDepthStateSmartPointer GetDepthState() const;
		const ConstOffsetStateSmartPointer GetOffsetState() const;
		const ConstStencilStateSmartPointer GetStencilState() const;
		const ConstWireStateSmartPointer GetWireState() const;

		 
        // Access to the current camera state.
          void SetCamera (Camera* camera);
          const Mathematics::Matrixf& GetViewMatrix () const;
          const Mathematics::Matrixf& GetProjectionMatrix () const;
          const Mathematics::Matrixf& GetPostProjectionMatrix () const;
        
        // Compute a picking ray from the specified left-handed screen
        // coordinates (x,y) and using the current camera.  The output
        // 'origin' is the camera position and the 'direction' is a
        // unit-length vector.  Both are in world coordinates.  The return
        // value is 'true' iff (x,y) is in the current viewport.
        bool GetPickRay (int x, int y, Mathematics::APointf& origin, Mathematics::AVectorf& direction) const;
        
        // Access to the current clearing parameters for the color, depth, and
        // stencil buffers.  The color buffer is the back buffer.
        void SetClearColor (const Mathematics::Float4& clearColor);
   
        void SetClearDepth (float clearDepth);
        float GetClearDepth () const;
        void SetClearStencil (unsigned int clearStencil);
        unsigned int GetClearStencil () const;
        
        // Access to the current color channel masks.
        inline void GetColorMask (bool& allowRed, bool& allowGreen,bool& allowBlue, bool& allowAlpha) const;
     
        // Override the global state.  If overridden, this state is used instead
        // of the VisualPass state during a drawing call.  To undo the override,
        // pass a null pointer.
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
        void SetReverseCullOrder (bool reverseCullOrder);
        bool GetReverseCullOrder () const;
        
        // The entry point to drawing the visible set of a scene graph.
        void Draw (const VisibleSet& visibleSet, GlobalEffect* globalEffect = 0);
        
        // The entry points for drawing a single object.
        void Draw (const Visual* visual);
        void Draw (const Visual* visual, const VisualEffectInstance* instance);        
		 
        // Platform-dependent portion of the interface.	

    public:
         virtual RendererTypes GetRendererType() const = 0;

		 // The entry point for drawing 2D buffers (for 2D applications).
		 void Draw(const unsigned char* screenBuffer, bool reflectY = false);
		 
		 void ClearColorBuffer ();
		 void Resize (int width, int height);
		 void DrawMessage (int x, int y, const Colour& color,const std::string& message);
		 const Colour GetClearColor () const;

		 void SetClearColor(const Colour& clearColor);

		 virtual bool PreDraw ();
		 virtual void PostDraw ();

		 virtual void ClearBuffers ();

		 virtual void DisplayColorBuffer ();

		 void SetCamera (const ConstCameraSmartPointer& camera);
		 const ConstCameraSmartPointer GetCamera () const;

    public:
        // Construction and destruction.  Each platform passes opaquely through
        // 'input' whatever information is needed to create a renderer.
	    RendererImpl (RendererInput& input, int width, int height, TextureFormat colorFormat, TextureFormat depthStencilFormat, int numMultisamples);        

        // Visual state management.
		 virtual void SetAlphaState(const ConstAlphaStateSmartPointer& alphaState);
		 virtual void SetCullState(const ConstCullStateSmartPointer& cullState);
		 virtual void SetDepthState(const ConstDepthStateSmartPointer& depthState);
		 virtual void SetOffsetState(const ConstOffsetStateSmartPointer& offsetState);
		 virtual void SetStencilState(const ConstStencilStateSmartPointer& stencilState);
		 virtual void SetWireState(const ConstWireStateSmartPointer& wireState);

		 
        // Viewport management.  The viewport is specified in right-handed screen
        // coordinates.  The origin is the lower-left corner of the screen, the
        // y-axis points upward, and the x-axis points rightward.
       // virtual void SetViewport (int xPosition, int yPosition, int width,int height);
       // virtual void GetViewport (int& xPosition, int& yPosition, int& width,int& height) const;
								  
        virtual void SetDepthRange (float zMin, float zMax);
        virtual void GetDepthRange (float& zMin, float& zMax) const;
		 
        
        // Support for clearing the color, depth, and stencil buffers.
     
       // virtual void ClearDepthBuffer ();
       // virtual void ClearStencilBuffer ();

      //  virtual void ClearColorBuffer (int x, int y, int w, int h);
      //  virtual void ClearDepthBuffer (int x, int y, int w, int h);
       // virtual void ClearStencilBuffer (int x, int y, int w, int h);
      //  virtual void ClearBuffers (int x, int y, int w, int h);
   
        
        // Support for masking color channels during drawing.
        virtual void SetColorMask (bool allowRed, bool allowGreen,bool allowBlue, bool allowAlpha);
		 
        // Support for predraw and postdraw semantics.  All Renderer abstract
        // interface functions and drawing functions must occur within a block of
        // code bounded by PreDraw() and PostDraw().  The general format is
        //   if (renderer->PreDraw())
        //   {
        //       <abstract-interface renderer calls and draw calls>;
        //       renderer->PostDraw();
        //   }
          
       
   
        // The entry point for drawing 2D text.
		virtual void Draw(int x, int y, const Colour& color,const std::string& message);
		
    private:
        // The entry point for drawing 3D objects, called by the single-object
        // Draw function.
       // virtual void DrawPrimitive (const Visual* visual);
        
	private:
        // The platform-specific data.  It is in public scope to allow the
        // renderer resource classes to access it.
        RendererData* mData;            
        
        // For render target access to allow creation of color/depth textures.
       // virtual void InsertInTexture2DMap (const Texture2D* texture, PlatformTexture2D* platformTexture);
        
    private:
		using RendererBasisPtr = std::shared_ptr<RendererBasis>;
        using VertexFormatManagementPtr = std::shared_ptr<VertexFormatManagement>;
        using VertexBufferManagement = BufferManagement<PlatformVertexBuffer>;
        using IndexBufferManagement = BufferManagement<PlatformIndexBuffer>;
        using VertexBufferManagementPtr = std::shared_ptr<VertexBufferManagement>;
        using IndexBufferManagementPtr = std::shared_ptr<IndexBufferManagement>;
		using Texture1DManagement = TextureManagement<PlatformTexture1D>;
		using Texture1DManagementPtr = std::shared_ptr<Texture1DManagement>;
		using Texture2DManagement = TextureManagement<PlatformTexture2D>;
		using Texture2DManagementPtr = std::shared_ptr<Texture2DManagement>;
		using Texture3DManagement = TextureManagement<PlatformTexture3D>;
		using Texture3DManagementPtr = std::shared_ptr<Texture3DManagement>;
		using TextureCubeManagement = TextureManagement<PlatformTextureCube>;
		using TextureCubeManagementPtr = std::shared_ptr<TextureCubeManagement>;
		using RenderTargetManagementPtr = std::shared_ptr<RenderTargetManagement>;
        
    private:
        RendererBasisPtr m_RendererBasis;
		VertexFormatManagementPtr m_VertexFormatManagement;		
        VertexBufferManagementPtr m_VertexBufferManagement;
        IndexBufferManagementPtr m_IndexBufferManagement;
		Texture1DManagementPtr m_Texture1DManagement;
		Texture2DManagementPtr m_Texture2DManagement;
		Texture3DManagementPtr m_Texture3DManagement;
		TextureCubeManagementPtr m_TextureCubeManagement;
		RenderTargetManagementPtr m_RenderTargetManagement;		
		
		std::shared_ptr < ShaderManagement<VertexShader,PdrVertexShader>> m_VertexShaderManagement;
		std::shared_ptr < ShaderManagement<PixelShader,PdrPixelShader>> m_PixelShaderManagement;
        GlobalState m_GlobalState;
        CameraState m_CameraState;
        ClearParameter m_ClearParameter;
		ViewportManagement m_ViewportManagement;
        DrawManagement m_DrawManagement;  		
                
    private:
        
        // Construction parameters.
        int mWidth;
        int mHeight;
        TextureFormat mColorFormat;
        TextureFormat mDepthStencilFormat;
        int mNumMultisamples;
        
        // Global state.
		AlphaStateSmartPointer mDefaultAlphaState;
		CullStateSmartPointer mDefaultCullState;
		DepthStateSmartPointer mDefaultDepthState;
		OffsetStateSmartPointer mDefaultOffsetState;
		StencilStateSmartPointer mDefaultStencilState;
		WireStateSmartPointer mDefaultWireState;
		ConstAlphaStateSmartPointer mAlphaState;
		ConstCullStateSmartPointer mCullState;
		ConstDepthStateSmartPointer mDepthState;
		ConstOffsetStateSmartPointer mOffsetState;
		ConstStencilStateSmartPointer mStencilState;
		ConstWireStateSmartPointer mWireState;
		
        bool mReverseCullOrder;
        
        // Overrides of global state.
        ConstAlphaStateSmartPointer mOverrideAlphaState;
		ConstCullStateSmartPointer mOverrideCullState;
		ConstDepthStateSmartPointer mOverrideDepthState;
		ConstOffsetStateSmartPointer mOverrideOffsetState;
		ConstStencilStateSmartPointer mOverrideStencilState;
		ConstWireStateSmartPointer mOverrideWireState;

		Colour m_ClearColor;
		
        // Geometric transformation pipeline.  The camera stores the view,
        // projection, and postprojection matrices.
        Camera* mCamera;
        
        // Framebuffer clearing.
        Mathematics::Float4 mClearColor;
        float mClearDepth;
        unsigned int mClearStencil;
        
        // Channel masking for the back buffer.
        bool mAllowRed, mAllowGreen, mAllowBlue, mAllowAlpha;
        
        // Active resources.
        using VertexFormatMap = std::map<const VertexFormat*, PlatformVertexFormat*>;
		using VertexBufferMap = std::map<const VertexBuffer*, PlatformVertexBuffer*>;
        using IndexBufferMap = std::map<const IndexBuffer*, PlatformIndexBuffer*>;
        using Texture1DMap = std::map<const Texture1D*, PlatformTexture1D*>;
        using Texture2DMap = std::map<const Texture2D*, PlatformTexture2D*>;
        using Texture3DMap = std::map<const Texture3D*, PlatformTexture3D*>;
        using TextureCubeMap = std::map<const TextureCube*, PlatformTextureCube*>;
        using RenderTargetMap = std::map<const RenderTarget*, PlatformRenderTarget*>;
        using VertexShaderMap = std::map<const VertexShader*, PdrVertexShader*>;
        using PixelShaderMap = std::map<const PixelShader*, PdrPixelShader*>;
        VertexFormatMap mVertexFormats;
        VertexBufferMap mVertexBuffers;
        IndexBufferMap mIndexBuffers;
        Texture1DMap mTexture1Ds;
        Texture2DMap mTexture2Ds;
        Texture3DMap mTexture3Ds;
        TextureCubeMap mTextureCubes;
        RenderTargetMap mRenderTargets;
        VertexShaderMap mVertexShaders;
        PixelShaderMap mPixelShaders;        
         
		Renderer* m_RealRenderer;
    };
}

#endif // RENDERING_RENDERERS_RENDERER_IMPL_H
