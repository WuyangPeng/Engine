// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/26 14:32)

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


// ��Ⱦ������һ����ÿ��ƽ̨ʵ�֣�Direct3D��OpenGL�������Ƕ��ʽ�豸�ȣ��ĳ���ӿڡ�
// ��������ֽ�������֡���һ�����г�����ƽ̨�޹صĺ��������ݣ���Щ�ڻ���ʵ�֡�
// �ڶ������г���ƽ̨��صĽӿڣ���Щ������ʵ�֡�

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

        // ƽ̨�޹صĽӿڲ��֡�
        
        // ���ʹ��캯�������롣
        int GetWidth () const;
        int GetHeight () const;
        TextureFormat GetColorFormat () const;
        TextureFormat GetDepthStencilFormat () const;
        int GetNumMultisamples () const;
        
        // ��Դ��������Դ������Ϊ�����ʽ�����㻺����������������������1D��2D��3D�������壩��
        // ��ȾĿ�꣬������ɫ����������ɫ��������ִ�����²�����
        
        // Bind:  ������Ӧ������������Դ����Ⱦ������������Դ֮���ӳ�䡣
        //        �ڴ��������£���Ƶ�洢����������Ӧ��ϵͳ�ڴ��н��з���Ϳ�����
        //        ���Enable��Lock��Bind֮ǰ���ã���Ⱦ��ĬĬ�ش�����һ����Դ�������ǵ����쳣��
        
        // Unbind:  ���ٶ�Ӧ������������Դ����Ⱦ����ӳ����ɾ��������Դ��
        //          ���󱣳���ϵͳ�洢���Ŀ��������ԣ����������ǿ��Ա��ٴΰ󶨡�
        
        // Enable:  ����Դ���ڵ�ǰ��ͼ�е��ô��ڻ״̬���������ڵ���DrawPrimitive֮ǰ��
        
        // Disable: ����Դ���ڵ�ǰ��ͼ�е��ô��ڷǻ״̬���������ڵ���DrawPrimitive֮��
      
        // Lock: �õ�һ��ָ����Դ����Ƶ�洢����ָ��
        //      ����Ȼ�洢��Ҳ��������AGP�ڴ��������ȡ����ͼ��API����Դʹ�õ�ϵͳ�ڴ棩��
        //       ʹ�ô˺����������Դ档�����������Ҫ֪����
        //       û�и��¶������Ӧϵͳ�洢װ���е������ڴ濽����ͬ����
        //       ��Ҳ����ֻ��Ϊ�˶�������������������£��Դ�����ݱ�������������Դ�����������ٵ�ʱ�䡣
       
        // Unlock:  �ͷ�ָ����Դ����Ƶ�洢����ָ�롣
        
        // Update:  ������Դ����Ƶ�洢��������ϵͳ�洢�������ݵ�����Ȼ�������Ƶ�ڴ档
        //          �����Ƽ�������Դ�ķ�ʽ������ϵͳ�ڴ棬Ȼ�����Update����������Ϊ��Ⱦ���ú�����
     
        // ReadColor:  �˺��������ڵ�RenderTargetʵ�֡�������ReadColorʱ��ȾĿ����뱻��ֹ��
        // �ú���������ȾĿ���ɫ��Ƶ�ڴ�ĸ�����Ϊһ��Texture2D����
        
        // �����ʽ���������ʽ����������Ѿ����䣬
        // �������ԺͿ����Ӧ�ó������������á�
		void Bind (VertexFormatConstPtr vertexFormat);
		void Unbind (VertexFormatConstPtr vertexFormat);
		void Enable (VertexFormatConstPtr vertexFormat);
		void Disable (VertexFormatConstPtr vertexFormat);
       
        // ���㻺�����������㻺��������������Ѿ���Ӧ�ó��������䡣
        void Bind (VertexBufferConstPtr vertexBuffer);
        void Unbind (VertexBufferConstPtr vertexBuffer);
        void Enable (VertexBufferConstPtr vertexBuffer,unsigned int streamIndex = 0, unsigned int offset = 0);
        void Disable (VertexBufferConstPtr vertexBuffer,unsigned int streamIndex = 0);
        void* Lock (VertexBufferConstPtr vertexBuffer, BufferLocking mode);
        void Unlock (VertexBufferConstPtr vertexBuffer);
        void Update (VertexBufferConstPtr vertexBuffer);
        
        // ����������������������������������Ѿ���Ӧ�ó��������䡣
        void Bind (IndexBufferConstPtr indexbuffer);
        void Unbind (IndexBufferConstPtr indexbuffer);
        void Enable (IndexBufferConstPtr indexbuffer);
        void Disable (IndexBufferConstPtr indexbuffer);
        void* Lock (IndexBufferConstPtr indexbuffer, BufferLocking mode);
        void Unlock (IndexBufferConstPtr indexbuffer);
        void Update (IndexBufferConstPtr indexbuffer);
        
        // 1D�����������������������Ѿ���Ӧ�ó��������䡣
        void Bind (Texture1DConstPtr texture);
        void Unbind (Texture1DConstPtr texture);
        void Enable (Texture1DConstPtr texture, int textureUnit);
        void Disable (Texture1DConstPtr texture, int textureUnit);
        void* Lock (Texture1DConstPtr texture, int level,BufferLocking mode);
        void Unlock (Texture1DConstPtr texture, int level);
        void Update (Texture1DConstPtr texture, int level);
        
        // 2D�����������������������Ѿ���Ӧ�ó��������䡣
        void Bind (Texture2DConstPtr texture);
        void Unbind (Texture2DConstPtr texture);
        void Enable (Texture2DConstPtr texture, int textureUnit);
        void Disable (Texture2DConstPtr texture, int textureUnit);
        void* Lock (Texture2DConstPtr, int level,BufferLocking mode);
        void Unlock (Texture2DConstPtr, int level);
        void Update (Texture2DConstPtr, int level);
        
        // 3D�����������������������Ѿ���Ӧ�ó��������䡣
        void Bind (Texture3DConstPtr texture);
        void Unbind (Texture3DConstPtr texture);
        void Enable (Texture3DConstPtr texture, int textureUnit);
        void Disable (Texture3DConstPtr texture, int textureUnit);
		void* Lock(Texture3DConstPtr texture, int level,BufferLocking mode);
		void Unlock(Texture3DConstPtr texture, int level);
        void Update (Texture3DConstPtr texture, int level);
        
        // Cube�����������������������Ѿ���Ӧ�ó��������䡣
        void Bind (TextureCubeConstPtr texture);
        void Unbind (TextureCubeConstPtr texture);
        void Enable (TextureCubeConstPtr texture, int textureUnit);
        void Disable (TextureCubeConstPtr texture, int textureUnit);
        void* Lock (TextureCubeConstPtr texture, int face, int level,BufferLocking mode);
        void Unlock (TextureCubeConstPtr texture, int face, int level);
        void Update (TextureCubeConstPtr texture, int face, int level);  
		
        // ��ȾĿ�������ȾĿ�����������Ѿ���Ӧ�ó��������䡣
        // ��ReadColor������index���ڶ����ȾĿ������Ŀ�������� 
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
