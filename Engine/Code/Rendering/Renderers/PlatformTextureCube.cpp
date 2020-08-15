// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.0.3 (2019/07/29 10:16)

#include "Rendering/RenderingExport.h" 

#include "Detail/PlatformTextureCubeImpl.h"
#include "Rendering/Renderers/Renderer.h"
#include "Rendering/Renderers/PlatformTextureCube.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::PlatformTextureCube
	::PlatformTextureCube(Renderer* renderer, const TextureCube* textureCube)	
	:m_Impl{ ImplType::Create(renderer,textureCube) }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::PlatformTextureCube
	::~PlatformTextureCube()
{
	RENDERING_SELF_CLASS_IS_VALID_1;	
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Rendering, PlatformTextureCube)
									  
void Rendering::PlatformTextureCube
	::Enable(Renderer* renderer, int textureUnit)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Enable(renderer, textureUnit);
}

void Rendering::PlatformTextureCube
	::Disable(Renderer* renderer, int textureUnit)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Disable(renderer, textureUnit);
}

void* Rendering::PlatformTextureCube
	::Lock(int face,int level, BufferLocking mode)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Lock(face,level, mode);
}

void Rendering::PlatformTextureCube
	::Unlock(int face, int level)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Unlock(face, level);
}

