// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.0.3 (2019/07/29 11:43)

#include "Rendering/RenderingExport.h"

#include "Dx9TextureCube.h"
 
#include "System/Helper/UnusedMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::Dx9TextureCube
	::Dx9TextureCube( Renderer* renderer, const TextureCube* texture )
	 
{	
	SYSTEM_UNUSED_ARG(renderer);
	SYSTEM_UNUSED_ARG(texture);

	/*
	  IDirect3DDevice9* device = renderer->mData->mDevice;

	  int numLevels = texture->GetNumLevels();
	  HRESULT hr = device->CreateCubeTexture((UINT)texture->GetWidth(),
	  (UINT)numLevels, gDX9BufferUsage[texture->GetUsage()],
	  gDX9TextureFormat[texture->GetFormat()], D3DPOOL_MANAGED,
	  &mTexture, 0);
	  WM5_UNUSED(hr);
	  RENDERING_ASSERTION_0(hr == D3D_OK, "Failed to create cube texture: %s\n",
	  DXGetErrorString(hr));

	  for (int face = 0; face < 6; ++face)
	  {
	  for (int level = 0; level < numLevels; ++level)
	  {
	  void* data = Lock(face, level, Buffer::BL_WRITE_ONLY);
	  memcpy(data, texture->GetData(face, level),
	  texture->GetNumLevelBytes(level));
	  Unlock(face, level);
	  }
	  }*/

	RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::Dx9TextureCube
	::~Dx9TextureCube()
{
	//  mTexture->Release();
	RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, Dx9TextureCube)

void Rendering::Dx9TextureCube
	::Enable( Renderer* renderer, int textureUnit )
{
	RENDERING_CLASS_IS_VALID_9;

	/*
	IDirect3DDevice9* device = renderer->mData->mDevice;

	HRESULT hr = device->SetTexture(textureUnit, mTexture);
	WM5_UNUSED(hr);
	RENDERING_ASSERTION_0(hr == D3D_OK, "Failed to enable cube texture, unit %d: %s\n",
	textureUnit, DXGetErrorString(hr));*/
	SYSTEM_UNUSED_ARG(renderer);
	SYSTEM_UNUSED_ARG(textureUnit);
}

void Rendering::Dx9TextureCube
	::Disable( Renderer* renderer, int textureUnit )
{
	RENDERING_CLASS_IS_VALID_9;

	/*
	IDirect3DDevice9* device = renderer->mData->mDevice;
	HRESULT hr;
	WM5_UNUSED(hr);

	#ifdef WM5_PDR_DEBUG
	// Verify that the active texture is the one making the disable request.
	IDirect3DBaseTexture9 *activeTexture = 0;
	hr = device->GetTexture(textureUnit, &activeTexture);
	RENDERING_ASSERTION_0(hr == D3D_OK, "Failed to get cube texture, unit %d: %s\n",
	textureUnit, DXGetErrorString(hr));
	RENDERING_ASSERTION_0(activeTexture == mTexture, "Mismatched textures\n");
	activeTexture->Release();
	#endif

	// Disable the texture by clearing the state.
	hr = device->SetTexture(textureUnit, 0);
	RENDERING_ASSERTION_0(hr == D3D_OK, "Failed to disable cube texture, unit %d: %s\n",
	textureUnit, DXGetErrorString(hr));*/

	SYSTEM_UNUSED_ARG(renderer);
	SYSTEM_UNUSED_ARG(textureUnit);
}

void* Rendering::Dx9TextureCube
	::Lock( int face,int level, BufferLocking mode )
{
	RENDERING_CLASS_IS_VALID_9;

	/*
	D3DLOCKED_RECT rect;
	HRESULT hr = mTexture->LockRect((D3DCUBEMAP_FACES)face, (UINT)level,
	&rect, 0, gDX9BufferLocking[mode]);
	WM5_UNUSED(hr);
	RENDERING_ASSERTION_0(hr == D3D_OK,
	"Failed to lock face %u level %u of cube texture: %s\n",
	face, level, DXGetErrorString(hr));
	return rect.pBits;*/

	SYSTEM_UNUSED_ARG(face);
	SYSTEM_UNUSED_ARG(level);
	SYSTEM_UNUSED_ARG(mode);

	return nullptr;
}

void Rendering::Dx9TextureCube
	::Unlock( int face,int level )
{
	RENDERING_CLASS_IS_VALID_9;

	/*
	  HRESULT hr = mTexture->UnlockRect((D3DCUBEMAP_FACES)face, (UINT)level);
	  WM5_UNUSED(hr);
	  RENDERING_ASSERTION_0(hr == D3D_OK,
	  "Failed to unlock face %u level %u of cube texture: %s\n",
	  face, level, DXGetErrorString(hr));*/

	SYSTEM_UNUSED_ARG(face);
	SYSTEM_UNUSED_ARG(level);
}
 
 