///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/04/02 16:27)

#include "Rendering/RenderingExport.h"

#include "PickRecordContainer.h"
#include "Detail/PickRecordContainerImpl.h"
#include "Detail/PickRecordImpl.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

Rendering::PickRecordContainer Rendering::PickRecordContainer::Create()
{
    return PickRecordContainer{ CoreTools::DisableNotThrow::Disable };
}

Rendering::PickRecordContainer::PickRecordContainer(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow)
    : impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, PickRecordContainer)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, PickRecordContainer, InsertPickRecord, PickRecord, void)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, PickRecordContainer, GetSize, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, PickRecordContainer, IsEmpty, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, PickRecordContainer, GetPickRecord, int, Rendering::PickRecord)
COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, PickRecordContainer)

void Rendering::PickRecordContainer::InsertPickRecord(const PickRecordContainer& pickRecordContainerImpl)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->InsertPickRecord(*pickRecordContainerImpl.impl);
}
