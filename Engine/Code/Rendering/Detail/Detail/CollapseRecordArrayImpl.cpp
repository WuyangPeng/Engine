///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/09 19:25)

#include "Rendering/RenderingExport.h"

#include "CollapseRecordArrayImpl.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

#include <algorithm>

using std::for_each;

Rendering::CollapseRecordArrayImpl::CollapseRecordArrayImpl() noexcept
    : collapseRecord{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::CollapseRecordArrayImpl::CollapseRecordArrayImpl(const std::vector<CollapseRecord>& collapseRecord)
    : collapseRecord{ collapseRecord }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, CollapseRecordArrayImpl)

int Rendering::CollapseRecordArrayImpl::GetNumRecords() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(collapseRecord.size());
}

std::vector<Rendering::CollapseRecord> Rendering::CollapseRecordArrayImpl::GetRecords() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return collapseRecord;
}

Rendering::CollapseRecord Rendering::CollapseRecordArrayImpl::GetRecord(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_0(0 <= index && index < GetNumRecords(), "索引错误！");

    return collapseRecord.at(index);
}

void Rendering::CollapseRecordArrayImpl::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    int numRecords{ 0 };
    source.Read(numRecords);

    collapseRecord.resize(numRecords, CollapseRecord{ -1 });

    for_each(collapseRecord.begin(), collapseRecord.end(), std::bind(&CollapseRecord::Load, std::placeholders::_1, std::ref(source)));
}

void Rendering::CollapseRecordArrayImpl::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    target.Write(GetNumRecords());

    for_each(collapseRecord.begin(), collapseRecord.end(), std::bind(&CollapseRecord::Save, std::placeholders::_1, std::ref(target)));
}

int Rendering::CollapseRecordArrayImpl::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto numRecords = boost::numeric_cast<int>(collapseRecord.size());
    auto size = CORE_TOOLS_STREAM_SIZE(numRecords);

    for (const auto& record : collapseRecord)
    {
        size += record.GetStreamingSize();
    }

    return size;
}
