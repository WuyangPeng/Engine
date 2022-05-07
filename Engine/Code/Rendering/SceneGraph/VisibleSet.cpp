///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/03 17:27)

#include "Rendering/RenderingExport.h"

#include "VisibleSet.h"
#include "Detail/VisibleSetImpl.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::make_shared;
using std::vector;

Rendering::VisibleSet Rendering::VisibleSet::Create()
{
    return VisibleSet{ CoreTools::DisableNotThrow::Disable };
}

Rendering::VisibleSet::VisibleSet(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow)
    : impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, VisibleSet)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, VisibleSet, GetNumVisible, int)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, VisibleSet, Insert, VisualSharedPtr, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VisibleSet, GetVisible, int, Rendering::ConstVisualSharedPtr)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, VisibleSet, Clear, void)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, VisibleSet, begin, Rendering::VisibleSet::VisualContainerIter)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, VisibleSet, end, Rendering::VisibleSet::VisualContainerIter)
