// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.0.3 (2019/07/29 11:42)

#include "Rendering/RenderingExport.h"

#include "Dx9Texture1D.h" 
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

#include "CoreTools/Contract/Noexcept.h"

Rendering::Dx9Texture1D ::Dx9Texture1D([[maybe_unused]] Renderer* renderer, [[maybe_unused]] const Texture1D* texture)

{	
	CoreTools::DisableNoexcept();
 

	/*
	IDirect3DDevice9* device = renderer->mData->mDevice;

	int numLevels = texture->GetNumLevels();
	HRESULT hr = device->CreateTexture((UINT)texture->GetLength(), 1u,
	(UINT)numLevels, gDX9BufferUsage[texture->GetUsage()],
	gDX9TextureFormat[texture->GetFormat()], D3DPOOL_MANAGED,
	&mTexture, 0);
	WM5_UNUSED(hr);
	RENDERING_ASSERTION_0(hr == D3D_OK, "Failed to create 1D texture: %s\n",
	DXGetErrorString(hr));

	for (int level = 0; level < numLevels; ++level)
	{
	void* data = Lock(level, Buffer::BL_WRITE_ONLY);
	memcpy(data, texture->GetData(level),
	texture->GetNumLevelBytes(level));
	Unlock(level);
	}*/

	RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::Dx9Texture1D
	::~Dx9Texture1D()
{
	//  mTexture->Release();
	RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, Dx9Texture1D)

void Rendering::Dx9Texture1D ::Enable([[maybe_unused]] Renderer* renderer, [[maybe_unused]] int textureUnit)
{
	RENDERING_CLASS_IS_VALID_9;

 
        CoreTools::DisableNoexcept();

	/*
	IDirect3DDevice9* device = renderer->mData->mDevice;

	HRESULT hr = device->SetTexture(textureUnit, mTexture);
	WM5_UNUSED(hr);
	RENDERING_ASSERTION_0(hr == D3D_OK, "Failed to enable 1D texture, unit %d: %s\n",
		textureUnit, DXGetErrorString(hr));*/
}

void Rendering::Dx9Texture1D ::Disable([[maybe_unused]] Renderer* renderer, [[maybe_unused]] int textureUnit)
{
	RENDERING_CLASS_IS_VALID_9;

 
        CoreTools::DisableNoexcept();
	/*
	IDirect3DDevice9* device = renderer->mData->mDevice;
	HRESULT hr;
	WM5_UNUSED(hr);

	#ifdef WM5_PDR_DEBUG
	// Verify that the active texture is the one making the disable request.
	IDirect3DBaseTexture9 *activeTexture = 0;
	hr = device->GetTexture(textureUnit, &activeTexture);
	RENDERING_ASSERTION_0(hr == D3D_OK, "Failed to get 1D texture, unit %d: %s\n",
	textureUnit, DXGetErrorString(hr));
	RENDERING_ASSERTION_0(activeTexture == mTexture, "Mismatched textures\n");
	activeTexture->Release();
	#endif

	// Disable the texture by clearing the state.
	hr = device->SetTexture(textureUnit, 0);
	RENDERING_ASSERTION_0(hr == D3D_OK, "Failed to disable 1D texture, unit %d: %s\n",
	textureUnit, DXGetErrorString(hr));*/
}

void* Rendering::Dx9Texture1D ::Lock([[maybe_unused]] int level, [[maybe_unused]] BufferLocking mode)
{
	RENDERING_CLASS_IS_VALID_9;

 
        CoreTools::DisableNoexcept();
	/*
	 D3DLOCKED_RECT rect;
	 HRESULT hr = mTexture->LockRect((UINT)level, &rect, 0,
	 gDX9BufferLocking[mode]);
	 WM5_UNUSED(hr);
	 RENDERING_ASSERTION_0(hr == D3D_OK, "Failed to lock level %u of 1D texture: %s\n",
	 level, DXGetErrorString(hr));
	 return rect.pBits;*/

	return nullptr;
}

void Rendering::Dx9Texture1D ::Unlock([[maybe_unused]] int level)
{
	RENDERING_CLASS_IS_VALID_9;

	/*
	HRESULT hr = mTexture->UnlockRect((UINT)level);
	WM5_UNUSED(hr);
	RENDERING_ASSERTION_0(hr == D3D_OK, "Failed to unlock level %u of 1D texture: %s\n",
	level, DXGetErrorString(hr));*/
        CoreTools::DisableNoexcept();
 
}

