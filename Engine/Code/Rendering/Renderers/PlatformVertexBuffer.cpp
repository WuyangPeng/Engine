///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 12:49)

#include "Rendering/RenderingExport.h"

#include "PlatformVertexBuffer.h"
#include "Renderer.h"
#include "Detail/PlatformVertexBufferImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

Rendering::PlatformVertexBuffer::PlatformVertexBuffer(Renderer* renderer, const VertexBuffer* vertexBuffer)
    : impl{ CoreTools::ImplCreateUseFactory::Default, renderer, vertexBuffer }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, PlatformVertexBuffer)

void Rendering::PlatformVertexBuffer::Enable(Renderer* renderer, unsigned int vertexSize, unsigned int streamIndex, unsigned int offset)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->Enable(renderer, vertexSize, streamIndex, offset);
}

void Rendering::PlatformVertexBuffer::Disable(Renderer* renderer, unsigned int streamIndex)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->Disable(renderer, streamIndex);
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, PlatformVertexBuffer, Lock, BufferLocking, void*)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, PlatformVertexBuffer, Unlock, void)