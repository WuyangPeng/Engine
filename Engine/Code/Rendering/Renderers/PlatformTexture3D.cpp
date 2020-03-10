// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.0.3 (2019/07/29 10:24)

#include "Rendering/RenderingExport.h" 

#include "PlatformTexture3D.h"
#include "Renderer.h"
#include "Detail/PlatformTexture3DImpl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::PlatformTexture3D
	::PlatformTexture3D(Renderer* renderer,  const Texture3D* texture3D)	
	:m_Impl{ ImplType::Create(renderer, texture3D) }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::PlatformTexture3D
	::~PlatformTexture3D()
{
	RENDERING_SELF_CLASS_IS_VALID_1;	
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Rendering, PlatformTexture3D)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, PlatformTexture3D,Unlock,int,void)
										  
void Rendering::PlatformTexture3D
	::Enable(Renderer* renderer, int textureUnit)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Enable(renderer, textureUnit);
}

void Rendering::PlatformTexture3D
	::Disable(Renderer* renderer, int textureUnit)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Disable(renderer, textureUnit);
}

void* Rendering::PlatformTexture3D
	::Lock(int level, BufferLocking mode)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Lock(level, mode);
}

