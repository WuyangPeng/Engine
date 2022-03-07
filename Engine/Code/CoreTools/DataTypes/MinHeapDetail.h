///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/10 16:38)

#ifndef CORE_TOOLS_DATA_TYPE_MIN_HEAP_DETAIL_H
#define CORE_TOOLS_DATA_TYPE_MIN_HEAP_DETAIL_H

#include "MinHeap.h"
#include "MinHeapRecordStoredManagerDetail.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/LogMacro.h"

#include <sstream>

template <typename Generator, typename Scalar>
CoreTools::MinHeap<Generator, Scalar>::MinHeap(int maxElements, int growBy, Scalar initialValue)
    : elementsNumber{ 0 }, growBy{ 0 < growBy ? growBy : 1 }, recordStoredManager{ maxElements, initialValue }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_3;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Generator, typename Scalar>
bool CoreTools::MinHeap<Generator, Scalar>::IsValid() const noexcept
{
    try
    {
        if (IsValid(0, elementsNumber - 1) && 0 <= elementsNumber && 0 < growBy && 0 < recordStoredManager.GetMaxElements())
            return true;
        else
            return false;
    }
    catch (...)
    {
        return false;
    }
}

template <typename Generator, typename Scalar>
bool CoreTools::MinHeap<Generator, Scalar>::IsValid(int startIndex, int finalIndex) const
{
    // 索引为HeapIndex
    for (auto child = startIndex; child <= finalIndex; ++child)
    {
        const auto parent = (child - 1) / 2;
        if (startIndex < parent)
        {
            if (IsStoredValueLess(child, parent))
            {
                PrintMinHeapInLog();

                return false;
            }
        }
    }

    return true;
}

template <typename Generator, typename Scalar>
void CoreTools::MinHeap<Generator, Scalar>::PrintMinHeapInLog() const
{
    System::OStringStream os{};

    os << SYSTEM_TEXT("最小堆信息\n");

    for (auto index = 0; index < elementsNumber; ++index)
    {
        os << index
           << SYSTEM_TEXT(": realIndex = ")
           << recordStoredManager.GetUniqueIndex(index)
           << SYSTEM_TEXT(", generator = ")
           << recordStoredManager.GetGeneratorByHeapIndex(index)
           << SYSTEM_TEXT(", value = ")
           << recordStoredManager.GetValueByHeapIndex(index)
           << SYSTEM_TEXT("\n");
    }

    LOG_SINGLETON_ENGINE_APPENDER(Info, CoreTools)
        << os.str();

    recordStoredManager.PrintIndexInLog();

    LOG_SINGLETON_ENGINE_APPENDER(Info, CoreTools)
        << LogAppenderIOManageSign::Refresh;
}
#endif  // OPEN_CLASS_INVARIANT

// private
template <typename Generator, typename Scalar>
bool CoreTools::MinHeap<Generator, Scalar>::IsStoredValueLess(int lhsHeapIndex, int rhsHeapIndex) const
{
    return recordStoredManager.GetValueByHeapIndex(lhsHeapIndex) < recordStoredManager.GetValueByHeapIndex(rhsHeapIndex);
}

template <typename Generator, typename Scalar>
bool CoreTools::MinHeap<Generator, Scalar>::IsStoredValueLessEqual(int lhsHeapIndex, int rhsHeapIndex) const
{
    return !IsStoredValueLess(rhsHeapIndex, lhsHeapIndex);
}

template <typename Generator, typename Scalar>
int CoreTools::MinHeap<Generator, Scalar>::GetMaxElements() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_3;

    return recordStoredManager.GetMaxElements();
}

template <typename Generator, typename Scalar>
int CoreTools::MinHeap<Generator, Scalar>::GetGrowBy() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_3;

    return growBy;
}

template <typename Generator, typename Scalar>
int CoreTools::MinHeap<Generator, Scalar>::GetElementsNumber() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_3;

    return elementsNumber;
}

template <typename Generator, typename Scalar>
CoreTools::MinHeapRecord<Generator, Scalar> CoreTools::MinHeap<Generator, Scalar>::GetMinimum() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_3;

    return GetRecordByHeapIndex(0);
}

template <typename Generator, typename Scalar>
CoreTools::MinHeapRecord<Generator, Scalar> CoreTools::MinHeap<Generator, Scalar>::GetRecordByUniqueIndex(int uniqueIndex) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_3;

    MAYBE_UNUSED const auto heapIndex = recordStoredManager.GetHeapIndex(uniqueIndex);

    CORE_TOOLS_ASSERTION_2(0 <= heapIndex && heapIndex < elementsNumber, "无效索引\n");

    return RecordType{ uniqueIndex, recordStoredManager.GetGeneratorByUniqueIndex(uniqueIndex), recordStoredManager.GetValueByUniqueIndex(uniqueIndex) };
}

template <typename Generator, typename Scalar>
CoreTools::MinHeapRecord<Generator, Scalar> CoreTools::MinHeap<Generator, Scalar>::GetRecordByHeapIndex(int heapIndex) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_3;
    CORE_TOOLS_ASSERTION_2(0 <= heapIndex && heapIndex < elementsNumber, "无效索引\n");

    return RecordType{ recordStoredManager.GetHeapIndex(heapIndex),
                       recordStoredManager.GetGeneratorByHeapIndex(heapIndex),
                       recordStoredManager.GetValueByHeapIndex(heapIndex) };
}

template <typename Generator, typename Scalar>
int CoreTools::MinHeap<Generator, Scalar>::Insert(Generator generator, Scalar value)
{
    CORE_TOOLS_CLASS_IS_VALID_3;

    // 如果有必要，增加记录堆数组。
    GrowRecords();

    // 存储输入信息在堆记录的最后，这是在树中的最后一个叶节点。
    StoreInputInformation(generator, value);

    // 传播信息朝向树的根，直到它到达正确的位置，从而恢复树为一个有效的堆。
    return RestoringValidHeapInInsert(value);
}

// private
template <typename Generator, typename Scalar>
void CoreTools::MinHeap<Generator, Scalar>::GrowRecords()
{
    const auto maxElements = recordStoredManager.GetMaxElements();
    if (elementsNumber == maxElements)
    {
        const auto newMaxElements = maxElements + growBy;

        recordStoredManager.GrowBy(newMaxElements);
    }
}

// private
template <typename Generator, typename Scalar>
void CoreTools::MinHeap<Generator, Scalar>::StoreInputInformation(Generator generator, Scalar value)
{
    const auto child = elementsNumber++;

    recordStoredManager.SetGeneratorByHeapIndex(child, generator);
    recordStoredManager.SetValueByHeapIndex(child, value);
}

// private
template <typename Generator, typename Scalar>
int CoreTools::MinHeap<Generator, Scalar>::RestoringValidHeapInInsert(Scalar value)
{
    auto child = elementsNumber - 1;

    while (0 < child)
    {
        const auto parent = (child - 1) / 2;
        if (recordStoredManager.GetValueByHeapIndex(parent) <= value)
        {
            // parent有一个值小于或等于child的值，所以我们现在有一个有效的堆。
            break;
        }

        // parent具有比child更大的值。交换parent和child：
        recordStoredManager.ChangeValue(child, parent);

        child = parent;
    }

    return recordStoredManager.GetUniqueIndex(child);
}

template <typename Generator, typename Scalar>
CoreTools::MinHeapRecord<Generator, Scalar> CoreTools::MinHeap<Generator, Scalar>::Remove()
{
    CORE_TOOLS_CLASS_IS_VALID_3;

    // 从堆的根中得到的信息。
    RecordType root{ recordStoredManager.GetHeapIndex(0), recordStoredManager.GetGeneratorByHeapIndex(0), recordStoredManager.GetValueByHeapIndex(0) };

    RestoringValidHeapInRemove();

    return root;
}

// private
template <typename Generator, typename Scalar>
void CoreTools::MinHeap<Generator, Scalar>::RestoringValidHeapInRemove()
{
    // 恢复堆中的树。交换第0位和last位的记录。
    // 然后通过parent-child互换向下移动第0位，直到它恢复在堆中树的位置。

    const auto last = --elementsNumber;
    auto parent = 0;
    auto child = 1;

    // 旧的记录不能丢失。它附加到插槽包含最后的旧记录。
    recordStoredManager.ChangeValue(parent, last);

    while (child < last)
    {
        if (child < last - 1)
        {
            // 如果有必要，选择最小值的child与parent交换。
            const auto childRight = child + 1;
            if (IsStoredValueLess(childRight, child))
            {
                child = childRight;
            }
        }

        if (IsStoredValueLessEqual(parent, child))
        {
            // 树现在是一个堆。
            break;
        }
        else
        {
            // 交换child和parent的插槽。
            recordStoredManager.ChangeValue(child, parent);

            parent = child;
            child = 2 * child + 1;
        }
    }
}

template <typename Generator, typename Scalar>
bool CoreTools::MinHeap<Generator, Scalar>::IsUniqueIndexValid(int uniqueIndex) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_3;

    const auto heapIndex = recordStoredManager.GetHeapIndex(uniqueIndex);

    if (0 <= heapIndex && heapIndex < elementsNumber)
        return true;
    else
        return false;
}

template <typename Generator, typename Scalar>
int CoreTools::MinHeap<Generator, Scalar>::Update(int uniqueIndex, Scalar value)
{
    CORE_TOOLS_CLASS_IS_VALID_3;

    // 只有MinHeap才可以更新记录。
    auto scalar = recordStoredManager.GetValueByUniqueIndex(uniqueIndex);
    const auto heapIndex = recordStoredManager.GetHeapIndex(uniqueIndex);

    CORE_TOOLS_ASSERTION_2(0 <= heapIndex && heapIndex < elementsNumber, "无效索引\n");

    if (scalar < value)
        return RestoringValidHeapInUpdateLargerValue(heapIndex, value);
    else if (value < scalar)
        return RestoringValidHeapInUpdateSmallerValue(heapIndex, value);
    else
        return heapIndex;
}

template <typename Generator, typename Scalar>
int CoreTools::MinHeap<Generator, Scalar>::RestoringValidHeapInUpdateLargerValue(int heapIndex, Scalar value)
{
    // 新值大于旧值。它向叶子传播。

    recordStoredManager.SetValueByHeapIndex(heapIndex, value);

    auto parent = heapIndex;
    auto child = 2 * parent + 1;
    auto maxChild = child;
    while (child < elementsNumber)
    {
        // 至少有一个child存在。找到最大值之一。

        if (child < elementsNumber - 1)
        {
            // 两个child的存在。
            const auto childRight = child + 1;
            if (IsStoredValueLessEqual(child, childRight))
                maxChild = child;
            else
                maxChild = childRight;
        }
        else
        {
            // 一个child的存在。
            maxChild = child;
        }

        if (value <= recordStoredManager.GetValueByHeapIndex(maxChild))
        {
            // 新的值是在正确的位置，已恢复树为一个堆。
            break;
        }
        else
        {
            // child比parent的值更大。
            // 交换maxChild和parent的插槽。
            recordStoredManager.ChangeValue(maxChild, parent);

            parent = maxChild;
            child = 2 * parent + 1;
        }
    }

    return parent;
}

template <typename Generator, typename Scalar>
int CoreTools::MinHeap<Generator, Scalar>::RestoringValidHeapInUpdateSmallerValue(int heapIndex, Scalar value)
{
    recordStoredManager.SetValueByHeapIndex(heapIndex, value);

    // 新值小于旧值。它向根传播。
    auto child = heapIndex;

    while (0 < child)
    {
        // 一个parent存在。
        const auto parent = (child - 1) / 2;

        if (recordStoredManager.GetValueByHeapIndex(parent) <= value)
        {
            // 新的值是在正确的位置，已恢复树为一个堆。
            break;
        }
        else
        {
            // child比parent的值更小。交换child和parent的插槽。
            recordStoredManager.ChangeValue(child, parent);

            child = parent;
        }
    }

    return child;
}

#endif  // CORE_TOOLS_DATA_TYPE_MIN_HEAP_DETAIL_H