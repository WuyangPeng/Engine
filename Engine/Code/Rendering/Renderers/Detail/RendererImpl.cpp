// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/29 09:35)

#include "Rendering/RenderingExport.h"

#include "RendererImpl.h"
#include "Rendering/SceneGraph/Visual.h"
#include "Rendering/SceneGraph/VisibleSet.h"
#include "Rendering/GlobalEffects/GlobalEffect.h"
#include "Rendering/Renderers/RendererBasis.h"
#include "Rendering/Renderers/VertexFormatManagement.h"
#include "Rendering/Renderers/BufferManagementDetail.h"
#include "Rendering/Renderers/TextureManagementDetail.h"
#include "Rendering/Renderers/RenderTargetManagement.h"
#include "CoreTools/MemoryTools/SubclassSmartPointerDetail.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

using std::make_shared;

Rendering::RendererImpl
    ::RendererImpl(const RendererBasis& basis)
	:m_RendererBasis{ make_shared<RendererBasis>(basis) }, m_VertexFormatManagement{}, m_VertexBufferManagement{}, m_IndexBufferManagement{},
	 m_Texture1DManagement{}, m_Texture2DManagement{}, m_Texture3DManagement{}, m_TextureCubeManagement{},
	 m_RenderTargetManagement{}, m_RealRenderer{ nullptr }, mDefaultAlphaState{ NEW0 AlphaState() }, mDefaultCullState{ NEW0 CullState() },
	 mDefaultDepthState{ NEW0 DepthState() }, mDefaultOffsetState{ NEW0 OffsetState() }, mDefaultStencilState{ NEW0 StencilState() },mDefaultWireState{ NEW0 WireState() },
	 mAlphaState{ mDefaultAlphaState }, mCullState{ mDefaultCullState }, mDepthState{ mDefaultDepthState }, mOffsetState{ mDefaultOffsetState },
	 mStencilState{ mDefaultStencilState }, mWireState{ mDefaultWireState }, mReverseCullOrder{ false }, mOverrideAlphaState{},
	mOverrideCullState{}, mOverrideDepthState{}, mOverrideOffsetState{}, mOverrideStencilState{}, mOverrideWireState{}
{	
	RENDERING_SELF_CLASS_IS_VALID_1;
}

void Rendering::RendererImpl
	::SetRealRenderer(Renderer* renderer) 
{
	RENDERING_CLASS_IS_VALID_1;

	m_RealRenderer = renderer;

	m_VertexFormatManagement = make_shared<VertexFormatManagement>(m_RealRenderer);
	m_VertexBufferManagement = make_shared<VertexBufferManagement>(m_RealRenderer);
	m_IndexBufferManagement = make_shared<IndexBufferManagement>(m_RealRenderer);
	m_Texture1DManagement = make_shared<Texture1DManagement>(m_RealRenderer);
	m_Texture2DManagement = make_shared<Texture2DManagement>(m_RealRenderer);
	m_Texture3DManagement = make_shared<Texture3DManagement>(m_RealRenderer);
	m_TextureCubeManagement = make_shared<TextureCubeManagement>(m_RealRenderer);
	m_RenderTargetManagement = make_shared<RenderTargetManagement>(m_RealRenderer);
}

Rendering::RendererImpl
    ::~RendererImpl()
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool Rendering::RendererImpl
    ::IsValid() const noexcept
{
	if(m_RendererBasis != nullptr && (m_RealRenderer == nullptr || 
		(m_VertexFormatManagement != nullptr &&	m_VertexBufferManagement != nullptr &&	m_IndexBufferManagement != nullptr &&
		m_Texture1DManagement != nullptr &&	m_Texture2DManagement != nullptr &&	m_Texture3DManagement != nullptr &&
		m_TextureCubeManagement != nullptr && m_RenderTargetManagement != nullptr)))
	{
		return true;
	}
	else
	{
		return false;
	}
}
#endif // OPEN_CLASS_INVARIANT

int Rendering::RendererImpl
    ::GetWidth () const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    
    return m_RendererBasis->GetWidth ();
}

int Rendering::RendererImpl
    ::GetHeight () const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    
    return m_RendererBasis->GetHeight ();
}

Rendering::TextureFormat Rendering::RendererImpl
    ::GetColorFormat () const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    
    return m_RendererBasis->GetColorFormat ();
}

Rendering::TextureFormat Rendering::RendererImpl
    ::GetDepthStencilFormat () const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    
    return m_RendererBasis->GetDepthStencilFormat ();
}

int Rendering::RendererImpl
    ::GetNumMultisamples () const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    
    return m_RendererBasis->GetNumMultisamples ();
}

void Rendering::RendererImpl
    ::Bind (VertexFormatConstPtr vertexFormat)
{
    RENDERING_CLASS_IS_VALID_1;
    
    return m_VertexFormatManagement->Bind (vertexFormat);
}

void Rendering::RendererImpl
    ::Unbind (VertexFormatConstPtr vertexFormat)
{
    RENDERING_CLASS_IS_VALID_1;
    
    return m_VertexFormatManagement->Unbind (vertexFormat);
}

void Rendering::RendererImpl
    ::Enable (VertexFormatConstPtr vertexFormat)
{
    RENDERING_CLASS_IS_VALID_1;
    
    return m_VertexFormatManagement->Enable (vertexFormat);
}

void Rendering::RendererImpl
    ::Disable (VertexFormatConstPtr vertexFormat)
{
    RENDERING_CLASS_IS_VALID_1;
    
    return m_VertexFormatManagement->Disable (vertexFormat);
}

Rendering::RendererImpl::PlatformVertexFormatSharedPtr Rendering::RendererImpl
	::GetResource( VertexFormatConstPtr vertexFormat )
{
	RENDERING_CLASS_IS_VALID_1;

	return m_VertexFormatManagement->GetResource (vertexFormat);
}

void Rendering::RendererImpl
	::Bind (VertexBufferConstPtr vertexBuffer)
{
	RENDERING_CLASS_IS_VALID_1;

    return m_VertexBufferManagement->Bind (vertexBuffer);
}

void Rendering::RendererImpl
	::Unbind (VertexBufferConstPtr vertexBuffer)
{
	RENDERING_CLASS_IS_VALID_1;

    return m_VertexBufferManagement->Unbind (vertexBuffer);
}

void Rendering::RendererImpl
	::Enable (VertexBufferConstPtr vertexBuffer,unsigned int streamIndex, unsigned int offset)
{
	RENDERING_CLASS_IS_VALID_1;

    return m_VertexBufferManagement->EnableVertexBuffer (vertexBuffer, streamIndex, offset);
}

void Rendering::RendererImpl
	::Disable (VertexBufferConstPtr vertexBuffer,unsigned int streamIndex)
{
	RENDERING_CLASS_IS_VALID_1;

    return m_VertexBufferManagement->DisableVertexBuffer (vertexBuffer, streamIndex);
}

void* Rendering::RendererImpl
	::Lock (VertexBufferConstPtr vertexBuffer,BufferLocking mode)
{
	RENDERING_CLASS_IS_VALID_1;

    return m_VertexBufferManagement->Lock (vertexBuffer, mode);
}

void Rendering::RendererImpl
	::Unlock (VertexBufferConstPtr vertexBuffer)
{
	RENDERING_CLASS_IS_VALID_1;

    return m_VertexBufferManagement->Unlock (vertexBuffer);
}

void Rendering::RendererImpl
	::Update (VertexBufferConstPtr vertexBuffer)
{
	RENDERING_CLASS_IS_VALID_1;

    return m_VertexBufferManagement->Update (vertexBuffer);
}
        
void Rendering::RendererImpl
	::Bind (IndexBufferConstPtr indexbuffer)
{
	RENDERING_CLASS_IS_VALID_1;

    return m_IndexBufferManagement->Bind (indexbuffer);
}

void Rendering::RendererImpl
	::Unbind (IndexBufferConstPtr indexbuffer)
{
	RENDERING_CLASS_IS_VALID_1;

    return m_IndexBufferManagement->Unbind (indexbuffer);
}

void Rendering::RendererImpl
	::Enable (IndexBufferConstPtr indexbuffer)
{
	RENDERING_CLASS_IS_VALID_1;

    return m_IndexBufferManagement->EnableIndexBuffer (indexbuffer);
}


void Rendering::RendererImpl
	::Disable (IndexBufferConstPtr indexbuffer)
{
	RENDERING_CLASS_IS_VALID_1;

    return m_IndexBufferManagement->DisableIndexBuffer (indexbuffer);
}

void* Rendering::RendererImpl
	::Lock (IndexBufferConstPtr indexbuffer, BufferLocking mode)
{
	RENDERING_CLASS_IS_VALID_1;

    return m_IndexBufferManagement->Lock (indexbuffer, mode);
}

void Rendering::RendererImpl
	::Unlock (IndexBufferConstPtr indexbuffer)
{
	RENDERING_CLASS_IS_VALID_1;

    return m_IndexBufferManagement->Unlock (indexbuffer);
}

void Rendering::RendererImpl
	::Update (IndexBufferConstPtr indexbuffer)
{
	RENDERING_CLASS_IS_VALID_1;

    return m_IndexBufferManagement->Update (indexbuffer);
}


Rendering::RendererImpl::PlatformVertexBufferSharedPtr Rendering::RendererImpl
	::GetResource (VertexBufferConstPtr vertexBuffer)
{
	RENDERING_CLASS_IS_VALID_1;

    return m_VertexBufferManagement->GetResource (vertexBuffer);
}

Rendering::RendererImpl::PlatformIndexBufferSharedPtr Rendering::RendererImpl
	::GetResource (IndexBufferConstPtr indexBuffer)
{
	RENDERING_CLASS_IS_VALID_1;

    return m_IndexBufferManagement->GetResource (indexBuffer);

}

void Rendering::RendererImpl
	::Bind (Texture1DConstPtr texture)
{
	RENDERING_CLASS_IS_VALID_1;

    return m_Texture1DManagement->Bind (texture);
}

void Rendering::RendererImpl
	::Unbind (Texture1DConstPtr texture)
{
	RENDERING_CLASS_IS_VALID_1;

    return m_Texture1DManagement->Unbind (texture);
}

void Rendering::RendererImpl
	::Enable (Texture1DConstPtr texture, int textureUnit)
{
	RENDERING_CLASS_IS_VALID_1;

    return m_Texture1DManagement->Enable (texture, textureUnit);
}


void Rendering::RendererImpl
	::Disable (Texture1DConstPtr texture, int textureUnit)
{
	RENDERING_CLASS_IS_VALID_1;

    return m_Texture1DManagement->Disable (texture, textureUnit);
}

void* Rendering::RendererImpl
	::Lock (Texture1DConstPtr texture, int level, BufferLocking mode)
{
	RENDERING_CLASS_IS_VALID_1;

    return m_Texture1DManagement->Lock (texture, level, mode);
}

void Rendering::RendererImpl
	::Unlock (Texture1DConstPtr texture, int level)
{
	RENDERING_CLASS_IS_VALID_1;

    return m_Texture1DManagement->Unlock (texture, level);
}

void Rendering::RendererImpl
	::Update (Texture1DConstPtr texture, int level)
{
	RENDERING_CLASS_IS_VALID_1;

    return m_Texture1DManagement->Update (texture, level);
}

Rendering::RendererImpl::PlatformTexture1DSharedPtr Rendering::RendererImpl
	::GetResource (Texture1DConstPtr texture1D)
{
	RENDERING_CLASS_IS_VALID_1;

    return m_Texture1DManagement->GetResource (texture1D);
}

void Rendering::RendererImpl
	::Bind (Texture2DConstPtr texture)
{
	RENDERING_CLASS_IS_VALID_1;

    return m_Texture2DManagement->Bind (texture);
}

void Rendering::RendererImpl
	::Unbind (Texture2DConstPtr texture)
{
	RENDERING_CLASS_IS_VALID_1;

    return m_Texture2DManagement->Unbind (texture);
}

void Rendering::RendererImpl
	::Enable (Texture2DConstPtr texture, int textureUnit)
{
	RENDERING_CLASS_IS_VALID_1;

    return m_Texture2DManagement->Enable (texture, textureUnit);
}

void Rendering::RendererImpl
	::Disable (Texture2DConstPtr texture, int textureUnit)
{
	RENDERING_CLASS_IS_VALID_1;

    return m_Texture2DManagement->Disable (texture, textureUnit);
}

void* Rendering::RendererImpl
	::Lock (Texture2DConstPtr texture, int level,BufferLocking mode)
{
	RENDERING_CLASS_IS_VALID_1;

    return m_Texture2DManagement->Lock (texture, level, mode);
}

void Rendering::RendererImpl
	::Unlock (Texture2DConstPtr texture, int level)
{
	RENDERING_CLASS_IS_VALID_1;

    return m_Texture2DManagement->Unlock (texture, level);
}

void Rendering::RendererImpl
	::Update (Texture2DConstPtr texture, int level)
{
	RENDERING_CLASS_IS_VALID_1;

    return m_Texture2DManagement->Update (texture, level);
}

Rendering::RendererImpl::PlatformTexture2DSharedPtr Rendering::RendererImpl
	::GetResource (Texture2DConstPtr texture2D)
{
	RENDERING_CLASS_IS_VALID_1;

    return m_Texture2DManagement->GetResource (texture2D);
}

void Rendering::RendererImpl
	::Bind (Texture3DConstPtr texture)
{
	RENDERING_CLASS_IS_VALID_1;

    return m_Texture3DManagement->Bind (texture);
}

void Rendering::RendererImpl
	::Unbind (Texture3DConstPtr texture)
{
	RENDERING_CLASS_IS_VALID_1;

    return m_Texture3DManagement->Unbind (texture);
}

void Rendering::RendererImpl
	::Enable (Texture3DConstPtr texture, int textureUnit)
{
	RENDERING_CLASS_IS_VALID_1;

    return m_Texture3DManagement->Enable (texture, textureUnit);
}

void Rendering::RendererImpl
	::Disable (Texture3DConstPtr texture, int textureUnit)
{
	RENDERING_CLASS_IS_VALID_1;

    return m_Texture3DManagement->Disable (texture, textureUnit);
}

void* Rendering::RendererImpl
	::Lock (Texture3DConstPtr texture, int level,BufferLocking mode)
{
	RENDERING_CLASS_IS_VALID_1;

    return m_Texture3DManagement->Lock (texture, level, mode);
}

void Rendering::RendererImpl
	::Unlock (Texture3DConstPtr texture, int level)
{
	RENDERING_CLASS_IS_VALID_1;

    return m_Texture3DManagement->Unlock (texture, level);
}

void Rendering::RendererImpl
	::Update (Texture3DConstPtr texture, int level)
{
	RENDERING_CLASS_IS_VALID_1;

    return m_Texture3DManagement->Update (texture, level);
}

Rendering::RendererImpl::PlatformTexture3DSharedPtr Rendering::RendererImpl
	::GetResource (Texture3DConstPtr texture3D)
{
	RENDERING_CLASS_IS_VALID_1;

    return m_Texture3DManagement->GetResource (texture3D);
}

void Rendering::RendererImpl
	::Bind (TextureCubeConstPtr texture)
{
	RENDERING_CLASS_IS_VALID_1;

    return m_TextureCubeManagement->Bind (texture);
}

void Rendering::RendererImpl
	::Unbind (TextureCubeConstPtr texture)
{
	RENDERING_CLASS_IS_VALID_1;

    return m_TextureCubeManagement->Unbind (texture);
}

void Rendering::RendererImpl
	::Enable (TextureCubeConstPtr texture, int textureUnit)
{
	RENDERING_CLASS_IS_VALID_1;

    return m_TextureCubeManagement->Enable (texture, textureUnit);
}

void Rendering::RendererImpl
	::Disable (TextureCubeConstPtr texture, int textureUnit)
{
	RENDERING_CLASS_IS_VALID_1;

    return m_TextureCubeManagement->Disable (texture, textureUnit);
}

void* Rendering::RendererImpl
	::Lock (TextureCubeConstPtr texture, int face,int level,BufferLocking mode)
{
	RENDERING_CLASS_IS_VALID_1;

    return m_TextureCubeManagement->LockCube (texture,face, level, mode);
}

void Rendering::RendererImpl
	::Unlock (TextureCubeConstPtr texture, int face,int level)
{
	RENDERING_CLASS_IS_VALID_1;

    return m_TextureCubeManagement->UnlockCube (texture,face, level);
}

void Rendering::RendererImpl
	::Update (TextureCubeConstPtr texture, int face,int level)
{
	RENDERING_CLASS_IS_VALID_1;

    return m_TextureCubeManagement->UpdateCube (texture,face, level);
}

Rendering::RendererImpl::PlatformTextureCubeSharedPtr Rendering::RendererImpl
	::GetResource (TextureCubeConstPtr textureCube)
{
	RENDERING_CLASS_IS_VALID_1;

    return m_TextureCubeManagement->GetResource (textureCube);
}

void Rendering::RendererImpl
	::Bind (RenderTargetConstPtr renderTarget)
{
	RENDERING_CLASS_IS_VALID_1;

    return m_RenderTargetManagement->Bind (renderTarget);
}

void Rendering::RendererImpl
	::Unbind (RenderTargetConstPtr renderTarget)
{
	RENDERING_CLASS_IS_VALID_1;

    return m_RenderTargetManagement->Unbind (renderTarget);
}

void Rendering::RendererImpl
	::Enable (RenderTargetConstPtr renderTarget)
{
	RENDERING_CLASS_IS_VALID_1;

    return m_RenderTargetManagement->Enable (renderTarget);
}

void Rendering::RendererImpl
	::Disable (RenderTargetConstPtr renderTarget)
{
	RENDERING_CLASS_IS_VALID_1;

    return m_RenderTargetManagement->Disable (renderTarget);
}

Rendering::RendererImpl::ConstTexture2DSmartPointer Rendering::RendererImpl
	::ReadColor(int index,RenderTargetConstPtr renderTarget)
{
	RENDERING_CLASS_IS_VALID_1;

    return m_RenderTargetManagement->ReadColor (index ,renderTarget);
}
 
Rendering::RendererImpl::PlatformRenderTargetSharedPtr Rendering::RendererImpl
	::GetResource (RenderTargetConstPtr renderTarget)
{
	RENDERING_CLASS_IS_VALID_1;

    return m_RenderTargetManagement->GetResource (renderTarget);
}

bool Rendering::RendererImpl
	::InTexture2DMap( Texture2DConstPtr texture )
{
	RENDERING_CLASS_IS_VALID_1;

	return m_Texture2DManagement->IsInTextureMap(texture);
}

void Rendering::RendererImpl
	::InsertInTexture2DMap( Texture2DConstPtr texture,PlatformTexture2DSharedPtr platformTexture )
{
	RENDERING_CLASS_IS_VALID_1;

	return m_Texture2DManagement->InsertTextureMap(texture,platformTexture);
}

void Rendering::RendererImpl
	::Draw(const unsigned char* screenBuffer, bool reflectY ) 
{
	RENDERING_CLASS_IS_VALID_1;

	screenBuffer;
	reflectY;
}

void Rendering::RendererImpl
	::Draw(const VisibleSet& visibleSet, GlobalEffect* globalEffect)
{
	if (!globalEffect)
	{
		const int numVisible = visibleSet.GetNumVisible();
		for (int i = 0; i < numVisible; ++i)
		{
			const Visual* visual = (const Visual*)visibleSet.GetVisible(i).GetData();
			const VisualEffectInstance* instance = visual->GetEffectInstance().GetData();
			Draw(visual, instance);
		}
	}
	else
	{
		globalEffect->Draw(m_RealRenderer, visibleSet);
	}
}

void Rendering::RendererImpl::Draw(const Visual* visual)
{
	const VisualEffectInstance* instance = visual->GetEffectInstance().GetData();
	Draw(visual, instance);
}

void Rendering::RendererImpl::Draw(const Visual* visual, const VisualEffectInstance* instance)
{
	if (!visual)
	{
		RENDERING_ASSERTION_0(false, "The visual object must exist.\n");
		return;
	}

	if (!instance)
	{
		RENDERING_ASSERTION_0(false, "The visual object must have an effect instance.\n");
		return;
	}

	const ConstVertexFormatSmartPointer vformat = visual->GetConstVertexFormat();
	const ConstVertexBufferSmartPointer vbuffer = visual->GetConstVertexBuffer();
	const ConstIndexBufferSmartPointer ibuffer = visual->GetConstIndexBuffer();

	// The OpenGL renderer requires the vertex buffer to be enabled before
	// the vertex format is enabled.  The order is irrelevant for the
	// DirectX9 renderer.
	Enable(vbuffer.GetData());
	Enable(vformat.GetData());
	if (ibuffer.IsValidPtr())
	{
		Enable(ibuffer.GetData());
	}

	const int numPasses = instance->GetNumPasses();
	for (int i = 0; i < numPasses; ++i)
	{
		// œ»Õ®π˝±‡“Î
	/*	const ConstVisualPassSmartPointer pass = instance->GetPass(i);
		ShaderParameters* vparams = instance->GetVertexParameters(i);
		ShaderParameters* pparams = instance->GetPixelParameters(i);
		VertexShader* vshader = pass->GetVertexShader();
		PixelShader* pshader = pass->GetPixelShader();

		// Update any shader constants that vary during runtime.
		vparams->UpdateConstants(visual, mCamera);
		pparams->UpdateConstants(visual, mCamera);

		// Set visual state.
		SetAlphaState(pass->GetAlphaState());
		SetCullState(pass->GetCullState());
		SetDepthState(pass->GetDepthState());
		SetOffsetState(pass->GetOffsetState());
		SetStencilState(pass->GetStencilState());
		SetWireState(pass->GetWireState());

		// Enable the shaders.
		Enable(vshader, vparams);
		Enable(pshader, pparams);

		// Draw the primitive.
		DrawPrimitive(visual);

		// Disable the shaders.
		Disable(vshader, vparams);
		Disable(pshader, pparams);*/

#ifdef RENDERING_RESET_STATE_AFTER_DRAW
		// Restore visual state.
		SetAlphaState(mDefaultAlphaState);
		SetCullState(mDefaultCullState);
		SetDepthState(mDefaultDepthState);
		SetOffsetState(mDefaultOffsetState);
		SetStencilState(mDefaultStencilState);
		SetWireState(mDefaultWireState);
#endif // RENDERING_RESET_STATE_AFTER_DRAW
	}

	if (ibuffer.IsValidPtr())
	{
		Disable(ibuffer.GetData());
	}

	Disable(vformat.GetData());
	Disable(vbuffer.GetData());
}

void Rendering::RendererImpl
	::Draw(int x, int y, const Colour& color, const std::string& message)
{
	RENDERING_CLASS_IS_VALID_1;

	x, y, color, message;
}

void Rendering::RendererImpl
	::DrawMessage( int x, int y, const Colour& color, const std::string& message )
{
	RENDERING_CLASS_IS_VALID_1;

	x;y;color;message;
}

void Rendering::RendererImpl
	::ClearColorBuffer()
{
	RENDERING_CLASS_IS_VALID_1;
}

void Rendering::RendererImpl
	::Resize( int width, int height )
{
	RENDERING_CLASS_IS_VALID_1;

	width;
	height;
}

const Rendering::RendererImpl::Colour Rendering::RendererImpl
	::GetClearColor() const
{
	RENDERING_CLASS_IS_VALID_1;

	return m_ClearColor;
}


bool Rendering::RendererImpl
	::PreDraw(  )
{
	RENDERING_CLASS_IS_VALID_1;
	
	return true;
}


void Rendering::RendererImpl
	::PostDraw(  )
{
	RENDERING_CLASS_IS_VALID_1;

	
}

void Rendering::RendererImpl
	::ClearBuffers(  )
{
	RENDERING_CLASS_IS_VALID_1;


}

void Rendering::RendererImpl
	::DisplayColorBuffer(  )
{
	RENDERING_CLASS_IS_VALID_1;


}

void Rendering::RendererImpl
	::SetCamera( const ConstCameraSmartPointer& camera )
{
	RENDERING_CLASS_IS_VALID_1;

	camera;
}

const Rendering::ConstCameraSmartPointer Rendering::RendererImpl
	::GetCamera() const
{
	RENDERING_CLASS_IS_VALID_1;

	return ConstCameraSmartPointer();
}

const Rendering::ConstAlphaStateSmartPointer Rendering::RendererImpl
	::GetAlphaState() const
{
	return mAlphaState;
}

const Rendering::ConstCullStateSmartPointer Rendering::RendererImpl
	::GetCullState() const
{
	return mCullState;
}

const Rendering::ConstDepthStateSmartPointer Rendering::RendererImpl
	::GetDepthState() const
{
	return mDepthState;
}

const Rendering::ConstOffsetStateSmartPointer Rendering::RendererImpl
	::GetOffsetState() const
{
	return mOffsetState;
}

const Rendering::ConstStencilStateSmartPointer Rendering::RendererImpl
	::GetStencilState() const
{
	return mStencilState;
}

const Rendering::ConstWireStateSmartPointer Rendering::RendererImpl
	::GetWireState() const
{
	return mWireState;
}

void Rendering::RendererImpl
	::SetOverrideAlphaState(const ConstAlphaStateSmartPointer& alphaState)
{
	mOverrideAlphaState = alphaState;
	if (alphaState.IsValidPtr())
	{
		SetAlphaState(alphaState);
	}
	else
	{
		SetAlphaState(mDefaultAlphaState);
	}
}

void Rendering::RendererImpl
	::SetOverrideCullState(const ConstCullStateSmartPointer& cullState)
{
	mOverrideCullState = cullState;
	if (cullState.IsValidPtr())
	{
		SetCullState(cullState);
	}
	else
	{
		SetCullState(mDefaultCullState);
	}
}

void Rendering::RendererImpl
	::SetOverrideDepthState(const ConstDepthStateSmartPointer& depthState)
{
	mOverrideDepthState = depthState;
	if (depthState.IsValidPtr())
	{
		SetDepthState(depthState);
	}
	else
	{
		SetDepthState(mDefaultDepthState);
	}
}

void Rendering::RendererImpl
	::SetOverrideOffsetState(const ConstOffsetStateSmartPointer& offsetState)
{
	mOverrideOffsetState = offsetState;
	if (offsetState.IsValidPtr())
	{
		SetOffsetState(offsetState);
	}
	else
	{
		SetOffsetState(mDefaultOffsetState);
	}
}

void Rendering::RendererImpl	
	::SetOverrideStencilState(const ConstStencilStateSmartPointer& stencilState)
{
	mOverrideStencilState = stencilState;
	if (stencilState.IsValidPtr())
	{
		SetStencilState(stencilState);
	}
	else
	{
		SetStencilState(mDefaultStencilState);
	}
}

void Rendering::RendererImpl
	::SetOverrideWireState(const ConstWireStateSmartPointer& wireState)
{
	mOverrideWireState = wireState;
	if (wireState.IsValidPtr())
	{
		SetWireState(wireState);
	}
	else
	{
		SetWireState(mDefaultWireState);
	}
}

const Rendering::ConstAlphaStateSmartPointer Rendering::RendererImpl
	::GetOverrideAlphaState() const
{
	return mOverrideAlphaState;
}

const Rendering::ConstCullStateSmartPointer Rendering::RendererImpl
	::GetOverrideCullState() const
{
	return mOverrideCullState;
}

const Rendering::ConstDepthStateSmartPointer Rendering::RendererImpl
	::GetOverrideDepthState() const
{
	return mOverrideDepthState;
}

const Rendering::ConstOffsetStateSmartPointer Rendering::RendererImpl
	::GetOverrideOffsetState() const
{
	return mOverrideOffsetState;
}

const Rendering::ConstStencilStateSmartPointer Rendering::RendererImpl
	::GetOverrideStencilState() const
{
	return mOverrideStencilState;
}

const Rendering::ConstWireStateSmartPointer Rendering::RendererImpl
	::GetOverrideWireState() const
{
	return mOverrideWireState;
}

void Rendering::RendererImpl
	::SetReverseCullOrder(bool reverseCullOrder)
{
	mReverseCullOrder = reverseCullOrder;
}

 bool Rendering::RendererImpl
	::GetReverseCullOrder() const
{
	return mReverseCullOrder;
}

 void Rendering::RendererImpl
	 ::SetAlphaState(const ConstAlphaStateSmartPointer& alphaState)
 {
	 alphaState;
 }

 void Rendering::RendererImpl
	 ::SetCullState(const ConstCullStateSmartPointer& cullState)
 {
	 cullState;
 }

 void Rendering::RendererImpl
	 ::SetDepthState(const ConstDepthStateSmartPointer& depthState)
 {
	 depthState;
 }

 void Rendering::RendererImpl
	 ::SetOffsetState(const ConstOffsetStateSmartPointer& offsetState)
 {
	 offsetState;
 }

 void Rendering::RendererImpl
	 ::SetStencilState(const ConstStencilStateSmartPointer& stencilState)
 {
	 stencilState;
 }

 void Rendering::RendererImpl
	 ::SetWireState(const ConstWireStateSmartPointer& wireState)
 {
	 wireState;
 }

 void Rendering::RendererImpl
	 ::SetDepthRange(float zMin, float zMax)
 {
	 zMin; zMax;
 }

 void Rendering::RendererImpl
	 ::GetDepthRange(float& zMin, float& zMax) const
 {
	 zMin = 0.0f; 
	 zMax = 0.0f;
 }

 void Rendering::RendererImpl
	 ::SetColorMask(bool allowRed, bool allowGreen, bool allowBlue, bool allowAlpha)
 {
	 allowRed; allowGreen; allowBlue; allowAlpha;
 }

 void Rendering::RendererImpl
	 ::SetClearColor(const Colour& clearColor)
 {
	 m_ClearColor = clearColor;
 }

