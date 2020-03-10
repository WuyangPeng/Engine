// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/22 18:40)

#include "Rendering/RenderingExport.h"

#include "VisibleSet.h"
#include "Detail/VisibleSetImpl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

using std::vector;
using std::make_shared;

Rendering::VisibleSet
    ::VisibleSet ()
    : m_Impl{ make_shared<ImplType>() }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Rendering,VisibleSet)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,VisibleSet,GetNumVisible,int)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering,VisibleSet,Insert,ConstSpatialSmartPointer,void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering,VisibleSet,GetVisible,int, const Rendering::ConstSpatialSmartPointer&)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,VisibleSet,Clear,void)


