// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/29 10:36)

#include "Rendering/RenderingExport.h"

#include "PlatformVertexFormat.h"
#include "VertexFormatManagement.h"
#include "Detail/VertexFormatManagementImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::make_shared;

Rendering::VertexFormatManagement::VertexFormatManagement(RendererPtr ptr)
    : impl{ ptr }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, VertexFormatManagement)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VertexFormatManagement, Bind, ConstVertexFormatSharedPtr, void)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VertexFormatManagement, Unbind, ConstVertexFormatSharedPtr, void)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VertexFormatManagement, Enable, ConstVertexFormatSharedPtr, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VertexFormatManagement, Disable, ConstVertexFormatSharedPtr, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VertexFormatManagement, GetResource, ConstVertexFormatSharedPtr, Rendering::VertexFormatManagement::PlatformVertexFormatPtr)
