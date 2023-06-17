///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 11:13)

#include "Rendering/RenderingExport.h"

#include "PickRecordContainerImpl.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "System/Helper/PragmaWarning/NumericCast.h"

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
    RENDERING_ASSERTION_0(0 <= index && index < GetSize(), "��������");

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
