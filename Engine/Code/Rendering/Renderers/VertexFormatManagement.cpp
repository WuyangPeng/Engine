///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/22 14:52)

#include "Rendering/RenderingExport.h"

#include "PlatformVertexFormat.h"
#include "VertexFormatManagement.h"
#include "Detail/VertexFormatManagementImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::make_shared;

Rendering::VertexFormatManagement::VertexFormatManagement(const RendererSharedPtr& renderer)
    : impl{ renderer }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, VertexFormatManagement)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, VertexFormatManagement, Bind, ConstVertexFormatSharedPtr, void)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, VertexFormatManagement, Unbind, ConstVertexFormatSharedPtr, void)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, VertexFormatManagement, Enable, ConstVertexFormatSharedPtr, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, VertexFormatManagement, Disable, ConstVertexFormatSharedPtr, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, VertexFormatManagement, GetResource, ConstVertexFormatSharedPtr, Rendering::VertexFormatManagement::PlatformVertexFormatSharedPtr)
