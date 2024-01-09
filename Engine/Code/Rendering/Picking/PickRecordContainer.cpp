/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2024/01/04 10:23)

#include "Rendering/RenderingExport.h"

#include "PickRecordContainer.h"
#include "Detail/PickRecordContainerImpl.h"
#include "Detail/PickRecordImpl.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, PickRecordContainer)

Rendering::PickRecordContainer Rendering::PickRecordContainer::Create()
{
    return PickRecordContainer{ CoreTools::DisableNotThrow::Disable };
}

Rendering::PickRecordContainer::PickRecordContainer(CoreTools::DisableNotThrow disableNotThrow)
    : impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    System::UnusedFunction(disableNotThrow);

    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, PickRecordContainer)

void Rendering::PickRecordContainer::InsertPickRecord(const PickRecord& pickRecord)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->InsertPickRecord(pickRecord);
}

int Rendering::PickRecordContainer::GetSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetSize();
}

Rendering::PickRecord Rendering::PickRecordContainer::GetPickRecord(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetPickRecord(index);
}

bool Rendering::PickRecordContainer::IsEmpty() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->IsEmpty();
}

void Rendering::PickRecordContainer::Clear()
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->Clear();
}

void Rendering::PickRecordContainer::InsertPickRecord(const PickRecordContainer& pickRecordContainerImpl)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->InsertPickRecord(*pickRecordContainerImpl.impl);
}
