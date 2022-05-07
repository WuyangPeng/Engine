///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/21 19:01)

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

CLASS_INVARIANT_STUB_DEFINE(Rendering, PlatformVertexFormat)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, PlatformVertexFormat, Enable, Renderer*, void)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, PlatformVertexFormat, Disable, Renderer*, void)