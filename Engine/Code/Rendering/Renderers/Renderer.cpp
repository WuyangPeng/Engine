// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.0.3 (2019/07/29 10:18)

#include "Rendering/RenderingExport.h"

#include "Renderer.h"
#include "RendererFactory.h"
#include "Detail/RendererImpl.h"
#include "Rendering/Renderers/RendererManager.h" 
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

using std::string;

Rendering::Renderer
	::Renderer(RendererTypes type,const RendererBasis& basis)
	:m_Impl{ RendererFactory::Create(type,basis) }, m_InputImpl{ RendererFactory::CreateInput(type) }
{
	RENDERER_MANAGE_SINGLETON.Insert(this); 
	m_Impl->SetRealRenderer(this);

	RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::Renderer
	::Renderer(const std::string& fileName)
	:m_Impl{ RendererFactory::Create(fileName) }
{
	RENDERER_MANAGE_SINGLETON.Insert(this); 
	m_Impl->SetRealRenderer(this);

	RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::Renderer
	::~Renderer()
{
	RENDERING_SELF_CLASS_IS_VALID_1;

	RENDERER_MANAGE_SINGLETON.Erase(this);
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Rendering,Renderer)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Renderer,GetWidth,int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Renderer,GetHeight,int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Renderer,GetColorFormat,Rendering::TextureFormat)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Renderer,GetDepthStencilFormat,Rendering::TextureFormat)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Renderer,GetNumMultisamples,int)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Renderer,Bind,VertexFormatConstPtr,void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Renderer,Unbind,VertexFormatConstPtr,void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Renderer,Enable,VertexFormatConstPtr,void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Renderer,Disable,VertexFormatConstPtr,void)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Renderer,Bind,VertexBufferConstPtr,void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Renderer,Unbind,VertexBufferConstPtr,void)

void Rendering::Renderer
   ::Enable (VertexBufferConstPtr vertexBuffer,
	         unsigned int streamIndex, unsigned int offset)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Enable(vertexBuffer,streamIndex,offset);
}

void Rendering::Renderer
	::Disable (VertexBufferConstPtr vertexBuffer,unsigned int streamIndex)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Disable(vertexBuffer,streamIndex);
}

void* Rendering::Renderer
	::Lock (VertexBufferConstPtr vertexBuffer,BufferLocking mode)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Lock(vertexBuffer,mode);
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Renderer,Unlock,VertexBufferConstPtr,void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Renderer,Update,VertexBufferConstPtr,void)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Renderer,Bind,IndexBufferConstPtr,void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Renderer,Unbind,IndexBufferConstPtr,void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Renderer,Enable,IndexBufferConstPtr,void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Renderer,Disable,IndexBufferConstPtr,void)

void* Rendering::Renderer
    ::Lock (IndexBufferConstPtr indexbuffer,BufferLocking mode)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Lock(indexbuffer,mode);
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Renderer,Unlock,IndexBufferConstPtr,void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Renderer,Update,IndexBufferConstPtr,void)


IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Renderer,Bind,Texture1DConstPtr,void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Renderer,Unbind,Texture1DConstPtr,void)

void Rendering::Renderer
    :: Enable (Texture1DConstPtr texture, int textureUnit)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Enable(texture, textureUnit);
}

void Rendering::Renderer
    :: Disable (Texture1DConstPtr texture, int textureUnit)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Disable(texture, textureUnit);
}

void* Rendering::Renderer
    ::Lock (Texture1DConstPtr texture, int level,BufferLocking mode)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Lock(texture, level ,mode);
}

void Rendering::Renderer
    :: Unlock (Texture1DConstPtr texture, int level)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Unlock(texture, level);
}

void Rendering::Renderer
    :: Update (Texture1DConstPtr texture, int level)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Update(texture, level);
} 

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Renderer,Bind,Texture2DConstPtr,void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Renderer,Unbind,Texture2DConstPtr,void)

void Rendering::Renderer
    :: Enable (Texture2DConstPtr texture, int textureUnit)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Enable(texture, textureUnit);
}

void Rendering::Renderer
    :: Disable (Texture2DConstPtr texture, int textureUnit)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Disable(texture, textureUnit);
}

void* Rendering::Renderer
    ::Lock (Texture2DConstPtr texture, int level,BufferLocking mode)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Lock(texture, level ,mode);
}

void Rendering::Renderer
    :: Unlock (Texture2DConstPtr texture, int level)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Unlock(texture, level);
}

void Rendering::Renderer
    :: Update (Texture2DConstPtr texture, int level)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Update(texture, level);
} 

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Renderer,Bind,Texture3DConstPtr,void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Renderer,Unbind,Texture3DConstPtr,void)

void Rendering::Renderer
    :: Enable (Texture3DConstPtr texture, int textureUnit)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Enable(texture, textureUnit);
}

void Rendering::Renderer
    :: Disable (Texture3DConstPtr texture, int textureUnit)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Disable(texture, textureUnit);
}

void* Rendering::Renderer
    ::Lock (Texture3DConstPtr texture, int level,BufferLocking mode)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Lock(texture, level ,mode);
}

void Rendering::Renderer
    :: Unlock (Texture3DConstPtr texture, int level)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Unlock(texture, level);
}

void Rendering::Renderer
    :: Update (Texture3DConstPtr texture, int level)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Update(texture, level);
} 

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Renderer,Bind,TextureCubeConstPtr,void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Renderer,Unbind,TextureCubeConstPtr,void)

void Rendering::Renderer
    :: Enable (TextureCubeConstPtr texture, int textureUnit)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Enable(texture, textureUnit);
}

void Rendering::Renderer
    :: Disable (TextureCubeConstPtr texture, int textureUnit)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Disable(texture, textureUnit);
}

void* Rendering::Renderer
    ::Lock (TextureCubeConstPtr texture, int face,int level,BufferLocking mode)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Lock(texture, face,level ,mode);
}

void Rendering::Renderer
    :: Unlock (TextureCubeConstPtr texture, int face,int level)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Unlock(texture,face, level);
}

void Rendering::Renderer
    :: Update (TextureCubeConstPtr texture, int face,int level)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Update(texture, face,level);
} 

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Renderer,Bind,RenderTargetConstPtr,void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Renderer,Unbind,RenderTargetConstPtr,void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Renderer,Enable,RenderTargetConstPtr,void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Renderer,Disable,RenderTargetConstPtr,void)

Rendering::Renderer::ConstTexture2DSmartPointer Rendering::Renderer
	::ReadColor( int index,RenderTargetConstPtr renderTarget )
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->ReadColor(index, renderTarget);
}

void Rendering::Renderer
	::Draw(const unsigned char* screenBuffer, bool reflectY ) 
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Draw(screenBuffer, reflectY);
}

void Rendering::Renderer
	::Draw(const VisibleSet& visibleSet, GlobalEffect* globalEffect /*= 0*/)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Draw(visibleSet, globalEffect);
}

void Rendering::Renderer
	::Draw(const Visual* visual)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Draw(visual);
}

void Rendering::Renderer
	::Draw(const Visual* visual, const VisualEffectInstance* instance)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Draw(visual, instance);
}

void Rendering::Renderer
	::Draw(int x, int y, const Colour& color, const std::string& message)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Draw(x,y,color,message);
}

void Rendering::Renderer
	::DrawMessage( int x, int y, const Colour& color, const std::string& message )
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->DrawMessage(x,y,color,message);
}

void Rendering::Renderer
	::Resize( int width, int height )
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Resize(width, height);
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Renderer,ClearColorBuffer,void)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Renderer,GetClearColor,const Rendering::Renderer::Colour)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Renderer,GetRendererType,Rendering::RendererTypes)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Renderer,PreDraw,bool)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Renderer,PostDraw,void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Renderer,ClearBuffers,void)		
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Renderer,DisplayColorBuffer,void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, Renderer,SetCamera,ConstCameraSmartPointer,void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Renderer,GetCamera,const Rendering::ConstCameraSmartPointer)										

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Renderer,InTexture2DMap,Texture2DConstPtr,bool)	


IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Renderer,GetAlphaState,const Rendering::ConstAlphaStateSmartPointer)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Renderer,GetCullState,const Rendering::ConstCullStateSmartPointer)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Renderer, GetDepthState,const Rendering::ConstDepthStateSmartPointer) 
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Renderer, GetOffsetState,const Rendering::ConstOffsetStateSmartPointer)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Renderer, GetStencilState,const Rendering::ConstStencilStateSmartPointer)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Renderer, GetWireState,const Rendering::ConstWireStateSmartPointer)


IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, Renderer,SetOverrideAlphaState,ConstAlphaStateSmartPointer, void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, Renderer, SetOverrideCullState, ConstCullStateSmartPointer, void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, Renderer, SetOverrideDepthState, ConstDepthStateSmartPointer, void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, Renderer, SetOverrideOffsetState, ConstOffsetStateSmartPointer, void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, Renderer, SetOverrideStencilState, ConstStencilStateSmartPointer, void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, Renderer, SetOverrideWireState, ConstWireStateSmartPointer, void);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Renderer, GetOverrideAlphaState, const Rendering::ConstAlphaStateSmartPointer);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Renderer, GetOverrideCullState, const Rendering::ConstCullStateSmartPointer);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Renderer, GetOverrideDepthState, const Rendering::ConstDepthStateSmartPointer);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Renderer, GetOverrideOffsetState, const Rendering::ConstOffsetStateSmartPointer);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Renderer, GetOverrideStencilState, const Rendering::ConstStencilStateSmartPointer);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Renderer, GetOverrideWireState, const Rendering::ConstWireStateSmartPointer);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Renderer, SetReverseCullOrder,bool ,void);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Renderer, GetReverseCullOrder, bool) 

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, Renderer, SetAlphaState, ConstAlphaStateSmartPointer, void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, Renderer, SetCullState, ConstCullStateSmartPointer, void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, Renderer, SetDepthState, ConstDepthStateSmartPointer, void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, Renderer, SetOffsetState, ConstOffsetStateSmartPointer, void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, Renderer, SetStencilState, ConstStencilStateSmartPointer, void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, Renderer, SetWireState, ConstWireStateSmartPointer, void);

									  
void Rendering::Renderer
	::InsertInTexture2DMap( Texture2DConstPtr texture,PlatformTexture2DSharedPtr platformTexture )
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->InsertInTexture2DMap(texture, platformTexture);
}

void Rendering::Renderer
	::SetDepthRange(float zMin, float zMax)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	m_Impl->SetDepthRange(zMin, zMax);
}

void Rendering::Renderer
	::GetDepthRange(float& zMin, float& zMax) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	m_Impl->GetDepthRange(zMin, zMax);
}

void Rendering::Renderer
	::SetColorMask(bool allowRed, bool allowGreen, bool allowBlue, bool allowAlpha)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	m_Impl->SetColorMask(allowRed, allowGreen, allowBlue, allowAlpha);
}

									