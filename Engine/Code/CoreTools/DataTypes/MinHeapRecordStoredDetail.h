///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/10 16:01)

#ifndef CORE_TOOLS_DATA_TYPE_MIN_HEAP_RECORD_STORED_DETAIL_H
#define CORE_TOOLS_DATA_TYPE_MIN_HEAP_RECORD_STORED_DETAIL_H

#include "MinHeapRecordDetail.h"
#include "MinHeapRecordStored.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename Generator, typename Scalar>
CoreTools::MinHeapRecordStored<Generator, Scalar>::MinHeapRecordStored(int maxElements, Scalar initialValue)
    : initialValue{ initialValue }, records{}
{
    for (auto i = 0; i < maxElements; ++i)
    {
        records.emplace_back(i, initialValue);
    }

    CORE_TOOLS_SELF_CLASS_IS_VALID_8;
}

template <typename Generator, typename Scalar>
CoreTools::MinHeapRecordStored<Generator, Scalar>::MinHeapRecordStored(int newMaxElements, const MinHeapRecordStored& oldRecordStored)
    : initialValue{ oldRecordStored.initialValue }, records{ oldRecordStored.records }
{
    GrowBy(newMaxElements);

    CORE_TOOLS_SELF_CLASS_IS_VALID_8;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Generator, typename Scalar>
bool CoreTools::MinHeapRecordStored<Generator, Scalar>::IsValid() const noexcept
{
    return !records.empty() && IndexIsValid();
}

template <typename Generator, typename Scalar>
bool CoreTools::MinHeapRecordStored<Generator, Scalar>::IndexIsValid() const noexcept
{
    try
    {
        std::vector<int> indexVector(records.size(), -1);

        auto index = 0;
        for (const auto& value : records)
        {
            const int uniqueIndex = value.GetUniqueIndex();

            auto& record = indexVector.at(uniqueIndex);
            if (record != -1)
                return false;

            record = index;
            ++index;
        }

        return true;
    }
    catch (...)
    {
        return false;
    }
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Generator, typename Scalar>
int CoreTools::MinHeapRecordStored<Generator, Scalar>::GetMaxElements() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_8;

    return boost::numeric_cast<int>(records.size());
}

template <typename Generator, typename Scalar>
Scalar CoreTools::MinHeapRecordStored<Generator, Scalar>::GetValue(int heapIndex) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_8;

    return records.at(heapIndex).GetValue();
}

template <typename Generator, typename Scalar>
Generator CoreTools::MinHeapRecordStored<Generator, Scalar>::GetGenerator(int heapIndex) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_8;

    return records.at(heapIndex).GetGenerator();
}

template <typename Generator, typename Scalar>
int CoreTools::MinHeapRecordStored<Generator, Scalar>::GetUniqueIndex(int heapIndex) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_8;

    return records.at(heapIndex).GetUniqueIndex();
}

template <typename Generator, typename Scalar>
void CoreTools::MinHeapRecordStored<Generator, Scalar>::SetValue(int heapIndex, Scalar value)
{
    CORE_TOOLS_CLASS_IS_VALID_8;

    records.at(heapIndex).SetValue(value);
}

template <typename Generator, typename Scalar>
void CoreTools::MinHeapRecordStored<Generator, Scalar>::SetGenerator(int heapIndex, Generator generator)
{
    CORE_TOOLS_CLASS_IS_VALID_8;

    records.at(heapIndex).SetGenerator(generator);
}

template <typename Generator, typename Scalar>
void CoreTools::MinHeapRecordStored<Generator, Scalar>::ChangeValue(int lhsIndex, int rhsIndex)
{
    CORE_TOOLS_CLASS_IS_VALID_8;

    std::swap(records.at(lhsIndex), records.at(rhsIndex));
}

template <typename Generator, typename Scalar>
void CoreTools::MinHeapRecordStored<Generator, Scalar>::GrowBy(int newMaxElements)
{
    CORE_TOOLS_CLASS_IS_VALID_8;

    const auto oldMaxElements = boost::numeric_cast<int>(records.size());

    // 初始化新的存储位置的剩余信息。
    for (auto i = oldMaxElements; i < newMaxElements; ++i)
    {
        records.emplace_back(i, initialValue);
    }
}

#endif  // CORE_TOOLS_DATA_TYPE_MIN_HEAP_RECORD_STORED_DETAIL_H