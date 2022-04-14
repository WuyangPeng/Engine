// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.0.3 (2019/07/29 10:35)

#include "Rendering/RenderingExport.h"

#include "RenderTargetManagement.h"
#include "PlatformRenderTarget.h"
#include "Detail/RenderTargetManagementImpl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

using std::make_shared;

Rendering::RenderTargetManagement
	::RenderTargetManagement(RendererPtr ptr)
    : impl{ ptr }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering,RenderTargetManagement)
	
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, RenderTargetManagement,Bind,RenderTargetConstPtr,void)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, RenderTargetManagement,Unbind,RenderTargetConstPtr,void)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, RenderTargetManagement,Enable,RenderTargetConstPtr,void) 
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, RenderTargetManagement,Disable,RenderTargetConstPtr,void) 
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, RenderTargetManagement,GetResource,RenderTargetConstPtr,
										  Rendering::RenderTargetManagement::PlatformRenderTargetSharedPtr)
 
Rendering::ConstTexture2DSharedPtr  Rendering::RenderTargetManagement
::ReadColor(int index,RenderTargetConstPtr renderTarget)
{
	;
    
    return impl->ReadColor(index,renderTarget);
}
 