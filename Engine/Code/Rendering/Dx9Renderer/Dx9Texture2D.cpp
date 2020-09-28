// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.0.3 (2019/07/29 11:43)

#include "Rendering/RenderingExport.h"

#include "Dx9Texture2D.h" 
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

#include "CoreTools/ClassInvariant/Noexcept.h"

Rendering::Dx9Texture2D ::Dx9Texture2D([[maybe_unused]] Renderer* renderer, [[maybe_unused]] const Texture2D* texture)
{
    CoreTools::DoNothing();
	 
	/*
	IDirect3DDevice9* device = renderer->mData->mDevice;

	int numLevels = texture->GetNumLevels();

	D3DPOOL pool;
	if (texture->GetUsage() == Buffer::BU_TEXTURE)
	{
	pool = D3DPOOL_MANAGED;
	}
	else
	{
	pool = D3DPOOL_DEFAULT;
	}

	HRESULT hr = device->CreateTexture((UINT)texture->GetWidth(),
	(UINT)texture->GetHeight(), (UINT)numLevels,
	gDX9BufferUsage[texture->GetUsage()],
	gDX9TextureFormat[texture->GetFormat()], pool, &mTexture, 0);
	WM5_UNUSED(hr);
	RENDERING_ASSERTION_0(hr == D3D_OK, "Failed to create 2D texture: %s\n",
	DXGetErrorString(hr));

	if (pool == D3DPOOL_MANAGED)
	{
	for (int level = 0; level < numLevels; ++level)
	{
	void* data = Lock(level, Buffer::BL_WRITE_ONLY);
	memcpy(data, texture->GetData(level),
	texture->GetNumLevelBytes(level));
	Unlock(level);
	}
	}*/

	RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::Dx9Texture2D
	::Dx9Texture2D(Renderer* renderer, bool isColortexture, const Texture2D* texture,bool autoGenMipMap)
{
    CoreTools::DoNothing();
	renderer; isColortexture; texture;
	autoGenMipMap;
	/*
	IDirect3DDevice9* device = renderer->mData->mDevice;
	HRESULT hr;
	WM5_UNUSED(hr);

	if (isColorTexture)
	{
	UINT levels = 1;
	DWORD usage = gDX9BufferUsage[texture->GetUsage()];
	if (autoGenMipMap)
	{
	levels = 0;
	usage |= D3DUSAGE_AUTOGENMIPMAP;
	}

	hr = device->CreateTexture((UINT)texture->GetWidth(),
	(UINT)texture->GetHeight(), levels, usage,
	gDX9TextureFormat[texture->GetFormat()], D3DPOOL_DEFAULT,
	&mTexture, 0);
	RENDERING_ASSERTION_0(hr == D3D_OK,
	"Failed to create render target color texture: %s\n",
	DXGetErrorString(hr));
	}
	else
	{
	hr = device->CreateTexture((UINT)texture->GetWidth(),
	(UINT)texture->GetHeight(), 1,
	gDX9BufferUsage[texture->GetUsage()],
	gDX9TextureFormat[texture->GetFormat()],
	D3DPOOL_DEFAULT, &mTexture, 0);
	RENDERING_ASSERTION_0(hr == D3D_OK,
	"Failed to create render target depthstencil texture: %s\n",
	DXGetErrorString(hr));
	}*/
}

Rendering::Dx9Texture2D
	::~Dx9Texture2D()
{
	//mTexture->Release();
	RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, Dx9Texture2D)

void Rendering::Dx9Texture2D ::Enable([[maybe_unused]] Renderer* renderer, [[maybe_unused]] int textureUnit)
{
	RENDERING_CLASS_IS_VALID_9;
    CoreTools::DoNothing();
	/*
	 IDirect3DDevice9* device = renderer->mData->mDevice;

	 HRESULT hr = device->SetTexture(textureUnit, mTexture);
	 WM5_UNUSED(hr);
	 RENDERING_ASSERTION_0(hr == D3D_OK, "Failed to enable 2D texture, unit %d: %s\n",
	 textureUnit, DXGetErrorString(hr));*/

 
}

void Rendering::Dx9Texture2D ::Disable([[maybe_unused]] Renderer* renderer, [[maybe_unused]] int textureUnit)
{
	RENDERING_CLASS_IS_VALID_9;
    CoreTools::DoNothing();
	/*
	IDirect3DDevice9* device = renderer->mData->mDevice;
	HRESULT hr;
	WM5_UNUSED(hr);

	#ifdef WM5_PDR_DEBUG
	// Verify that the active texture is the one making the disable request.
	IDirect3DBaseTexture9 *activeTexture = 0;
	hr = device->GetTexture(textureUnit, &activeTexture);
	RENDERING_ASSERTION_0(hr == D3D_OK, "Failed to get 2D texture, unit %d: %s\n",
	textureUnit, DXGetErrorString(hr));
	RENDERING_ASSERTION_0(activeTexture == mTexture, "Mismatched textures\n");
	activeTexture->Release();
	#endif

	// Disable the texture by clearing the state.
	hr = device->SetTexture(textureUnit, 0);
	RENDERING_ASSERTION_0(hr == D3D_OK, "Failed to disable 2D texture, unit %d: %s\n",
	textureUnit, DXGetErrorString(hr));*/

 
}

void* Rendering::Dx9Texture2D
	::Lock([[maybe_unused]] int level,[[maybe_unused]] BufferLocking mode )
{
	RENDERING_CLASS_IS_VALID_9;
    CoreTools::DoNothing();
	/*
	 D3DLOCKED_RECT rect;
	 HRESULT hr = mTexture->LockRect((UINT)level, &rect, 0,
	 gDX9BufferLocking[mode]);
	 WM5_UNUSED(hr);
	 RENDERING_ASSERTION_0(hr == D3D_OK, "Failed to lock level %u of 2D texture: %s\n",
	 level, DXGetErrorString(hr));
	 return rect.pBits;*/

 

	return nullptr;
}

void Rendering::Dx9Texture2D ::Unlock([[maybe_unused]] int level)
{
	RENDERING_CLASS_IS_VALID_9;
    CoreTools::DoNothing();
	/*
	 HRESULT hr = mTexture->UnlockRect((UINT)level);
	 WM5_UNUSED(hr);
	 RENDERING_ASSERTION_0(hr == D3D_OK, "Failed to unlock level %u of 2D texture: %s\n",
	 level, DXGetErrorString(hr));*/

	 
}

System::OpenGLUInt Rendering::Dx9Texture2D
	::GetTexture() const
{
    CoreTools::DoNothing();
	return 0;
}

