// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ°æ±¾£º0.0.0.3 (2019/07/29 11:25)

#include "Rendering/RenderingExport.h"

#include "OpenGLRenderTargetData.h"
#include "OpenGLRenderTargetDataImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::make_shared;

Rendering::OpenGLRenderTargetData
    ::OpenGLRenderTargetData (Renderer* renderer,const RenderTarget* renderTarget)
	:m_Impl{ make_shared<ImplType>(renderer,renderTarget) }
{    
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Rendering,OpenGLRenderTargetData)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering,OpenGLRenderTargetData,Enable,Renderer*,void)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, OpenGLRenderTargetData,Disable,Renderer*,void)

Rendering::ConstTexture2DSmartPointer Rendering::OpenGLRenderTargetData
	::ReadColor( int index,Renderer* renderer )
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->ReadColor(index,renderer);
}