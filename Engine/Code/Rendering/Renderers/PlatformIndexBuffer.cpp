// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/29 10:13)

#include "Rendering/RenderingExport.h"

#include "../Resources/IndexBuffer.h"
#include "PlatformIndexBuffer.h"
#include "Renderer.h"
#include "Detail/PlatformIndexBufferImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"

Rendering::PlatformIndexBuffer::PlatformIndexBuffer(Renderer* renderer, const IndexBuffer* indexBuffer)
    : impl{ CoreTools::ImplCreateUseFactory::Default, renderer, indexBuffer }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::PlatformIndexBuffer::~PlatformIndexBuffer()
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, PlatformIndexBuffer)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, PlatformIndexBuffer, Enable, Renderer*, void)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, PlatformIndexBuffer, Disable, Renderer*, void)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, PlatformIndexBuffer, Lock, BufferLocking, void*)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, PlatformIndexBuffer, Unlock, void)
