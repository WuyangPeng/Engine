// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/29 10:14)

#include "Rendering/RenderingExport.h" 

#include "PlatformTexture1D.h"
#include "Renderer.h"
#include "Detail/PlatformTexture1DImpl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"

Rendering::PlatformTexture1D
	::PlatformTexture1D(Renderer* renderer,  const Texture1D* texture1D)	
	: impl{ CoreTools::ImplCreateUseFactory::Default,  renderer, texture1D  }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, PlatformTexture1D)


IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, PlatformTexture1D, Unlock, int, void)
										  
void Rendering::PlatformTexture1D
	::Enable(Renderer* renderer, int textureUnit)
{
	;

	return impl->Enable(renderer, textureUnit);
}

void Rendering::PlatformTexture1D
	::Disable(Renderer* renderer, int textureUnit)
{
	;

	return impl->Disable(renderer, textureUnit);
}

void* Rendering::PlatformTexture1D
	::Lock(int level, BufferLocking mode)
{
	;

	return impl->Lock(level, mode);
}

