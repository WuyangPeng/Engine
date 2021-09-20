// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒýÇæ°æ±¾£º0.0.0.3 (2019/07/22 17:54)

#include "Rendering/RenderingExport.h"

#include "PickRecord.h"
#include "Detail/PickRecordImpl.h"
#include "Detail/PickRecordContainerImpl.h"

#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
using std::make_shared;
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26455)
#include SYSTEM_WARNING_DISABLE(26440)

Rendering::PickRecord ::PickRecord()
    : impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, PickRecord)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, PickRecord, GetIntersected, Rendering::ConstSpatialSharedPtr)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, PickRecord, GetParameter, float)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, PickRecord, GetTriangle, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, PickRecord, GetBary, int, float)
COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, PickRecord)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, PickRecord, SetIntersected, ConstSpatialSharedPtr, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, PickRecord, SetParameter, float, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, PickRecord, SetTriangle, int, void)

void Rendering::PickRecord ::SetBary(float firstBary, float secondBary)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetBary(firstBary, secondBary);
}

bool Rendering::PickRecord ::operator==(const PickRecord& rhs) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return *impl == *rhs.impl;
}

bool Rendering::PickRecord ::operator<(const PickRecord& rhs) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return *impl < *rhs.impl;
}

#include STSTEM_WARNING_POP