// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/22 18:40)

#include "Rendering/RenderingExport.h"

#include "VisibleSet.h"
#include "Detail/VisibleSetImpl.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::make_shared;
using std::vector;
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26455)
Rendering::VisibleSet ::VisibleSet()
    : impl{0}
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, VisibleSet)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, VisibleSet, GetNumVisible, int)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, VisibleSet, Insert, VisualSharedPtr, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VisibleSet, GetVisible, int, const Rendering::ConstVisualSharedPtr)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, VisibleSet, Clear, void)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, VisibleSet, begin, Rendering::VisibleSet::VisualContainerIter)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, VisibleSet, end, Rendering::VisibleSet::VisualContainerIter)

#include STSTEM_WARNING_POP