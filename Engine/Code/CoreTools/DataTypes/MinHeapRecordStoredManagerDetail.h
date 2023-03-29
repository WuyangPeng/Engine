///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/23 11:16)

#ifndef CORE_TOOLS_DATA_TYPE_MIN_HEAP_RECORD_STORED_MANAGER_DETAIL_H
#define CORE_TOOLS_DATA_TYPE_MIN_HEAP_RECORD_STORED_MANAGER_DETAIL_H

#include "MinHeapRecordStoredDetail.h"
#include "MinHeapRecordStoredManager.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename Generator, typename Scalar>
CoreTools::MinHeapRecordStoredManager<Generator, Scalar>::MinHeapRecordStoredManager(int maxElements, Scalar initialValue)
    : recordStored{ maxElements, initialValue }, recordIndexes{ maxElements }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_8;
}

template <typename Generator, typename Scalar>
CoreTools::MinHeapRecordStoredManager<Generator, Scalar>::MinHeapRecordStoredManager(int newMaxElements, const MinHeapRecordStoredManager& oldRecordStoredManage)
    : recordStored{ newMaxElements, oldRecordStoredManage.recordStored }, recordIndexes{ newMaxElements, oldRecordStoredManage.recordIndexes }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_8;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Generator, typename Scalar>
bool CoreTools::MinHeapRecordStoredManager<Generator, Scalar>::IsValid() const noexcept
{
    try
    {
        if (recordStored.GetMaxElements() == recordIndexes.GetMaxElements() && IndexIsValid())
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
    const auto maxElements = recordStored.GetMaxElements();

    for (auto index = 0; index < maxElements; ++index)
    {
        if (recordStored.GetUniqueIndex(recordIndexes.GetHeapIndex(index)) != index)
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

    return recordStored.GetMaxElements();
}

template <typename Generator, typename Scalar>
Scalar CoreTools::MinHeapRecordStoredManager<Generator, Scalar>::GetValueByUniqueIndex(int uniqueIndex) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_8;

    return recordStored.GetValue(recordIndexes.GetHeapIndex(uniqueIndex));
}

template <typename Generator, typename Scalar>
Generator CoreTools::MinHeapRecordStoredManager<Generator, Scalar>::GetGeneratorByUniqueIndex(int uniqueIndex) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_8;

    return recordStored.GetGenerator(recordIndexes.GetHeapIndex(uniqueIndex));
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

    return recordStored.GetUniqueIndex(heapIndex);
}

template <typename Generator, typename Scalar>
Scalar CoreTools::MinHeapRecordStoredManager<Generator, Scalar>::GetValueByHeapIndex(int heapIndex) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_8;

    return recordStored.GetValue(heapIndex);
}

template <typename Generator, typename Scalar>
Generator CoreTools::MinHeapRecordStoredManager<Generator, Scalar>::GetGeneratorByHeapIndex(int heapIndex) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_8;

    return recordStored.GetGenerator(heapIndex);
}

template <typename Generator, typename Scalar>
void CoreTools::MinHeapRecordStoredManager<Generator, Scalar>::SetValueByUniqueIndex(int uniqueIndex, Scalar value)
{
    CORE_TOOLS_CLASS_IS_VALID_8;

    recordStored.SetValue(recordIndexes.GetHeapIndex(uniqueIndex), value);
}

template <typename Generator, typename Scalar>
void CoreTools::MinHeapRecordStoredManager<Generator, Scalar>::SetGeneratorByUniqueIndex(int uniqueIndex, Generator generator)
{
    CORE_TOOLS_CLASS_IS_VALID_8;

    recordStored.SetGenerator(recordIndexes.GetHeapIndex(uniqueIndex), generator);
}

template <typename Generator, typename Scalar>
void CoreTools::MinHeapRecordStoredManager<Generator, Scalar>::SetValueByHeapIndex(int heapIndex, Scalar value)
{
    CORE_TOOLS_CLASS_IS_VALID_8;

    recordStored.SetValue(heapIndex, value);
}

template <typename Generator, typename Scalar>
void CoreTools::MinHeapRecordStoredManager<Generator, Scalar>::SetGeneratorByHeapIndex(int heapIndex, Generator generator)
{
    CORE_TOOLS_CLASS_IS_VALID_8;

    recordStored.SetGenerator(heapIndex, generator);
}

template <typename Generator, typename Scalar>
void CoreTools::MinHeapRecordStoredManager<Generator, Scalar>::ChangeValue(int lhsHeapIndex, int rhsHeapIndex)
{
    CORE_TOOLS_CLASS_IS_VALID_8;

    const auto lhsUniqueIndex = recordStored.GetUniqueIndex(lhsHeapIndex);
    const auto rhsUniqueIndex = recordStored.GetUniqueIndex(rhsHeapIndex);

    recordStored.ChangeValue(lhsHeapIndex, rhsHeapIndex);
    recordIndexes.ChangeIndex(lhsUniqueIndex, rhsUniqueIndex);
}

template <typename Generator, typename Scalar>
void CoreTools::MinHeapRecordStoredManager<Generator, Scalar>::GrowBy(int newMaxElements)
{
    CORE_TOOLS_CLASS_IS_VALID_8;

    recordStored.GrowBy(newMaxElements);
    recordIndexes.GrowBy(newMaxElements);
}

#endif  // CORE_TOOLS_DATA_TYPE_MIN_HEAP_RECORD_STORED_MANAGER_DETAIL_H
