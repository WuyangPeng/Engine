// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/29 10:36)

#include "Rendering/RenderingExport.h"

#include "VertexFormatManagement.h"
#include "PlatformVertexFormat.h"
#include "Detail/VertexFormatManagementImpl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"


using std::make_shared;

Rendering::VertexFormatManagement
	::VertexFormatManagement(RendererPtr ptr)
	: m_Impl{ make_shared<ImplType>(ptr) }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Rendering,VertexFormatManagement)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VertexFormatManagement,Bind, ConstVertexFormatSharedPtr,void)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VertexFormatManagement,Unbind, ConstVertexFormatSharedPtr,void)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VertexFormatManagement,Enable, ConstVertexFormatSharedPtr,void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VertexFormatManagement,Disable, ConstVertexFormatSharedPtr,void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VertexFormatManagement,GetResource, ConstVertexFormatSharedPtr,Rendering::VertexFormatManagement::PlatformVertexFormatPtr)
 