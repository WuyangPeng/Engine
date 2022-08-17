///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.0 (2022/08/09 14:07)

#include "Rendering/RenderingExport.h"

#include "MemberLayout.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Rendering/Resources/Detail/Buffers/MemberLayoutImpl.h"

Rendering::MemberLayout::MemberLayout(const std::string& name, int offset, int numElements)
    : impl{ name, offset, numElements }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, MemberLayout)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, MemberLayout, GetName, std::string)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, MemberLayout, GetOffset, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, MemberLayout, GetNumElements, int)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, MemberLayout, GetStreamingSize, int)