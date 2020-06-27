// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/29 10:36)

#include "Rendering/RenderingExport.h"

#include "VertexFormatManagement.h"
#include "PlatformVertexFormat.h"
#include "Detail/VertexFormatManagementImpl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/MemoryTools/SubclassSmartPointerDetail.h"

using std::make_shared;

Rendering::VertexFormatManagement
	::VertexFormatManagement(RendererPtr ptr)
	: m_Impl{ make_shared<ImplType>(ptr) }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Rendering,VertexFormatManagement)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VertexFormatManagement,Bind, ConstVertexFormatSmartPointer,void)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VertexFormatManagement,Unbind, ConstVertexFormatSmartPointer,void)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VertexFormatManagement,Enable, ConstVertexFormatSmartPointer,void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VertexFormatManagement,Disable, ConstVertexFormatSmartPointer,void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VertexFormatManagement,GetResource, ConstVertexFormatSmartPointer,Rendering::VertexFormatManagement::PlatformVertexFormatPtr)
 