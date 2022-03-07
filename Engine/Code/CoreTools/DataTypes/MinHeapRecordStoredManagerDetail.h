///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/10 16:36)

#ifndef CORE_TOOLS_DATA_TYPE_MIN_HEAP_RECORD_STORED_MANAGER_DETAIL_H
#define CORE_TOOLS_DATA_TYPE_MIN_HEAP_RECORD_STORED_MANAGER_DETAIL_H

#include "MinHeapRecordStoredDetail.h"
#include "MinHeapRecordStoredManager.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename Generator, typename Scalar>
CoreTools::MinHeapRecordStoredManager<Generator, Scalar>::MinHeapRecordStoredManager(int maxElements, Scalar initialValue)
    : recordStoreds{ maxElements, initialValue }, recordIndexes{ maxElements }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_8;
}

template <typename Generator, typename Scalar>
CoreTools::MinHeapRecordStoredManager<Generator, Scalar>::MinHeapRecordStoredManager(int newMaxElements, const MinHeapRecordStoredManager& oldRecordStoredManage)
    : recordStoreds{ newMaxElements, oldRecordStoredManage.recordStoreds }, recordIndexes{ newMaxElements, oldRecordStoredManage.recordIndexes }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_8;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Generator, typename Scalar>
bool CoreTools::MinHeapRecordStoredManager<Generator, Scalar>::IsValid() const noexcept
{
    try
    {
        if (recordStoreds.GetMaxElements() == recordIndexes.GetMaxElements() && IndexIsValid())
        {
            return true;
        }
        else
        {
            PrintIndexInLog();

            return false;
        }
    }
    catch (...)
    {
        return false;
    }
}

template <typename Generator, typename Scalar>
bool CoreTools::MinHeapRecordStoredManager<Generator, Scalar>::IndexIsValid() const
{
    const auto maxElements = recordStoreds.GetMaxElements();

    for (auto index = 0; index < maxElements; ++index)
    {
        if (recordStoreds.GetUniqueIndex(recordIndexes.GetHeapIndex(index)) != index)
        {
            return false;
        }
    }

    return true;
}

template <typename Generator, typename Scalar>
void CoreTools::MinHeapRecordStoredManager<Generator, Scalar>::PrintIndexInLog() const noexcept
{
    recordIndexes.PrintIndexInLog();
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Generator, typename Scalar>
int CoreTools::MinHeapRecordStoredManager<Generator, Scalar>::GetMaxElements() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_8;

    return recordStoreds.GetMaxElements();
}

template <typename Generator, typename Scalar>
Scalar CoreTools::MinHeapRecordStoredManager<Generator, Scalar>::GetValueByUniqueIndex(int uniqueIndex) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_8;

    return recordStoreds.GetValue(recordIndexes.GetHeapIndex(uniqueIndex));
}

template <typename Generator, typename Scalar>
Generator CoreTools::MinHeapRecordStoredManager<Generator, Scalar>::GetGeneratorByUniqueIndex(int uniqueIndex) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_8;

    return recordStoreds.GetGenerator(recordIndexes.GetHeapIndex(uniqueIndex));
}

template <typename Generator, typename Scalar>
int CoreTools::MinHeapRecordStoredManager<Generator, Scalar>::GetHeapIndex(int uniqueIndex) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_8;

    return recordIndexes.GetHeapIndex(uniqueIndex);
}

template <typename Generator, typename Scalar>
int CoreTools::MinHeapRecordStoredManager<Generator, Scalar>::GetUniqueIndex(int heapIndex) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_8;

    return recordStoreds.GetUniqueIndex(heapIndex);
}

template <typename Generator, typename Scalar>
Scalar CoreTools::MinHeapRecordStoredManager<Generator, Scalar>::GetValueByHeapIndex(int heapIndex) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_8;

    return recordStoreds.GetValue(heapIndex);
}

template <typename Generator, typename Scalar>
Generator CoreTools::MinHeapRecordStoredManager<Generator, Scalar>::GetGeneratorByHeapIndex(int heapIndex) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_8;

    return recordStoreds.GetGenerator(heapIndex);
}

template <typename Generator, typename Scalar>
void CoreTools::MinHeapRecordStoredManager<Generator, Scalar>::SetValueByUniqueIndex(int uniqueIndex, Scalar value)
{
    CORE_TOOLS_CLASS_IS_VALID_8;

    recordStoreds.SetValue(recordIndexes.GetHeapIndex(uniqueIndex), value);
}

template <typename Generator, typename Scalar>
void CoreTools::MinHeapRecordStoredManager<Generator, Scalar>::SetGeneratorByUniqueIndex(int uniqueIndex, Generator generator)
{
    CORE_TOOLS_CLASS_IS_VALID_8;

    recordStoreds.SetGenerator(recordIndexes.GetHeapIndex(uniqueIndex), generator);
}

template <typename Generator, typename Scalar>
void CoreTools::MinHeapRecordStoredManager<Generator, Scalar>::SetValueByHeapIndex(int heapIndex, Scalar value)
{
    CORE_TOOLS_CLASS_IS_VALID_8;

    recordStoreds.SetValue(heapIndex, value);
}

template <typename Generator, typename Scalar>
void CoreTools::MinHeapRecordStoredManager<Generator, Scalar>::SetGeneratorByHeapIndex(int heapIndex, Generator generator)
{
    CORE_TOOLS_CLASS_IS_VALID_8;

    recordStoreds.SetGenerator(heapIndex, generator);
}

template <typename Generator, typename Scalar>
void CoreTools::MinHeapRecordStoredManager<Generator, Scalar>::ChangeValue(int lhsHeapIndex, int rhsHeapIndex)
{
    CORE_TOOLS_CLASS_IS_VALID_8;

    const auto lhsUniqueIndex = recordStoreds.GetUniqueIndex(lhsHeapIndex);
    const auto rhsUniqueIndex = recordStoreds.GetUniqueIndex(rhsHeapIndex);

    recordStoreds.ChangeValue(lhsHeapIndex, rhsHeapIndex);
    recordIndexes.ChangeIndex(lhsUniqueIndex, rhsUniqueIndex);
}

template <typename Generator, typename Scalar>
void CoreTools::MinHeapRecordStoredManager<Generator, Scalar>::GrowBy(int newMaxElements)
{
    CORE_TOOLS_CLASS_IS_VALID_8;

    recordStoreds.GrowBy(newMaxElements);
    recordIndexes.GrowBy(newMaxElements);
}

#endif  // CORE_TOOLS_DATA_TYPE_MIN_HEAP_RECORD_STORED_MANAGER_DETAIL_H
