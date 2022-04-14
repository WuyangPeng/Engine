// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/29 10:18)

#include "Rendering/RenderingExport.h"

#include "PlatformVertexFormat.h"
#include "Renderer.h"
#include "Detail/PlatformVertexFormatImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

Rendering::PlatformVertexFormat::PlatformVertexFormat(Renderer* renderer, const VertexFormat* vertexFormat)
    : impl{ CoreTools::ImplCreateUseFactory::Default, renderer, vertexFormat }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::PlatformVertexFormat::~PlatformVertexFormat()
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, PlatformVertexFormat)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, PlatformVertexFormat, Enable, Renderer*, void)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, PlatformVertexFormat, Disable, Renderer*, void)