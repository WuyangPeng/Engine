///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/21 18:54)

#include "Rendering/RenderingExport.h"

#include "PlatformIndexBuffer.h"
#include "Renderer.h"
#include "Detail/PlatformIndexBufferImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Rendering/Resources/Buffers/IndexBuffer.h"

Rendering::PlatformIndexBuffer::PlatformIndexBuffer(Renderer* renderer, const IndexBuffer* indexBuffer)
    : impl{ CoreTools::ImplCreateUseFactory::Default, renderer, indexBuffer }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, PlatformIndexBuffer)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, PlatformIndexBuffer, Enable, Renderer*, void)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, PlatformIndexBuffer, Disable, Renderer*, void)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, PlatformIndexBuffer, Lock, BufferLocking, void*)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, PlatformIndexBuffer, Unlock, void)
