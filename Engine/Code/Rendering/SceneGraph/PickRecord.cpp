///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/04/02 16:20)

#include "Rendering/RenderingExport.h"

#include "PickRecord.h"
#include "Detail/PickRecordContainerImpl.h"
#include "Detail/PickRecordImpl.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

Rendering::PickRecord Rendering::PickRecord::Create()
{
    return PickRecord{ CoreTools::DisableNotThrow::Disable };
}

Rendering::PickRecord::PickRecord(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow)
    : impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, PickRecord)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, PickRecord, GetIntersected, Rendering::ConstSpatialSharedPtr)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, PickRecord, GetParameter, float)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, PickRecord, GetTriangle, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, PickRecord, GetBary, int, float)
COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, PickRecord)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, PickRecord, SetIntersected, ConstSpatialSharedPtr, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, PickRecord, SetParameter, float, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, PickRecord, SetTriangle, int, void)

void Rendering::PickRecord::SetBary(float firstBary, float secondBary)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetBary(firstBary, secondBary);
}

bool Rendering::PickRecord::operator==(const PickRecord& rhs) const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return *impl == *rhs.impl;
}

bool Rendering::PickRecord::operator<(const PickRecord& rhs) const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return *impl < *rhs.impl;
}
