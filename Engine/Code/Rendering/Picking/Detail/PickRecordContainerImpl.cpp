/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2024/01/04 10:23)

#include "Rendering/RenderingExport.h"

#include "PickRecordContainerImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

Rendering::PickRecordContainerImpl::PickRecordContainerImpl() noexcept
    : pickRecord{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, PickRecordContainerImpl)

void Rendering::PickRecordContainerImpl::InsertPickRecord(const PickRecord& aPickRecord)
{
    RENDERING_CLASS_IS_VALID_9;

    pickRecord.emplace_back(aPickRecord);
}

int Rendering::PickRecordContainerImpl::GetSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(pickRecord.size());
}

Rendering::PickRecord Rendering::PickRecordContainerImpl::GetPickRecord(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return pickRecord.at(index);
}

void Rendering::PickRecordContainerImpl::InsertPickRecord(const PickRecordContainerImpl& pickRecordContainerImpl)
{
    RENDERING_CLASS_IS_VALID_9;

    pickRecord.insert(pickRecord.end(), pickRecordContainerImpl.pickRecord.begin(), pickRecordContainerImpl.pickRecord.end());
}

bool Rendering::PickRecordContainerImpl::IsEmpty() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return pickRecord.empty();
}

void Rendering::PickRecordContainerImpl::Clear() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return pickRecord.clear();
}
