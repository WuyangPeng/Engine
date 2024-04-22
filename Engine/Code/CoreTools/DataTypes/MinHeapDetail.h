/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/11 14:50)

#ifndef CORE_TOOLS_DATA_TYPE_MIN_HEAP_DETAIL_H
#define CORE_TOOLS_DATA_TYPE_MIN_HEAP_DETAIL_H

#include "MinHeap.h"
#include "MinHeapRecordDetail.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

#include <numeric>

template <typename KeyType, typename ValueType>
CoreTools::MinHeap<KeyType, ValueType>::MinHeap(int maxElements)
    : numElements{ 0 },
      records{},
      pointers{}
{
    Reset(maxElements);

    CORE_TOOLS_SELF_CLASS_IS_VALID_3;
}

template <typename KeyType, typename ValueType>
bool CoreTools::MinHeap<KeyType, ValueType>::IsValid() const noexcept
{
    try
    {
        for (auto childIndex = 1; childIndex < numElements; ++childIndex)
        {
            if (!IsValid(childIndex))
            {
                return false;
            }
        }

        return true;
    }
    catch (...)
    {
        return false;
    }
}

template <typename KeyType, typename ValueType>
bool CoreTools::MinHeap<KeyType, ValueType>::IsValid(int childIndex) const
{
    const auto parentIndex = (childIndex - 1) / 2;

    const auto& child = records.at(GetRecordKey(childIndex));
    const auto& parent = records.at(GetRecordKey(parentIndex));

    if (child.GetWeight() < parent.GetWeight())
    {
        return false;
    }

    if (parent.GetIndex() != parentIndex)
    {
        return false;
    }

    return true;
}

template <typename KeyType, typename ValueType>
void CoreTools::MinHeap<KeyType, ValueType>::Reset(int maxElements)
{
    CORE_TOOLS_CLASS_IS_VALID_3;

    numElements = 0;
    if (0 < maxElements)
    {
        pointers.resize(maxElements);
        records.resize(maxElements);
        std::iota(pointers.begin(), pointers.end(), 0);
    }
    else
    {
        pointers.clear();
        records.clear();
    }
}

template <typename KeyType, typename ValueType>
int CoreTools::MinHeap<KeyType, ValueType>::GetMaxElements() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_3;

    return boost::numeric_cast<int>(records.size());
}

template <typename KeyType, typename ValueType>
int CoreTools::MinHeap<KeyType, ValueType>::GetNumElements() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_3;

    return numElements;
}

template <typename KeyType, typename ValueType>
CoreTools::MinHeapRecord<KeyType, ValueType> CoreTools::MinHeap<KeyType, ValueType>::GetMinimum() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_3;

    if (0 < numElements)
    {
        /// 从最小堆的根中获取最小值。
        return records.at(GetRecordKey(0));
    }
    else
    {
        /// 如果故意取消分配权重，则无效。
        THROW_EXCEPTION(SYSTEM_TEXT("最小堆为空。"))
    }
}

template <typename KeyType, typename ValueType>
int CoreTools::MinHeap<KeyType, ValueType>::Insert(const KeyType& handle, const ValueType& weight)
{
    CORE_TOOLS_CLASS_IS_VALID_3;

    if (GetMaxElements() <= numElements)
    {
        /// 堆满后立即返回。
        THROW_EXCEPTION(SYSTEM_TEXT("最小堆已满。"))
    }

    /// 将输入信息(handle, weight)存储在最后一个堆记录中，该记录是树中的最后一个叶节点。
    auto childIndex = numElements++;

    auto& record = records.at(GetRecordKey(childIndex));
    record.SetRecord(childIndex, handle, weight);

    /// 向树的根传播信息，直到它到达正确的位置，从而将树恢复为最小堆。
    while (0 < childIndex)
    {
        const auto parentIndex = (childIndex - 1) / 2;

        if (records.at(GetRecordKey(parentIndex)).GetWeight() <= weight)
        {
            /// 父对象的权重小于或等于子对象的值。我们现在有一个最小堆。
            break;
        }

        /// 父对象的值大于子对象的值。交换父对象和子对象。

        /// 将父对象移动到子对象的槽中。
        pointers.at(childIndex) = GetRecordKey(parentIndex);
        SetIndex(childIndex);

        /// 将子对象移动到父对象的槽中。
        pointers.at(parentIndex) = record.GetIndex();
        SetIndex(parentIndex);

        /// 向上传播。
        childIndex = parentIndex;
    }

    return GetRecordKey(childIndex);
}

template <typename KeyType, typename ValueType>
CoreTools::MinHeapRecord<KeyType, ValueType> CoreTools::MinHeap<KeyType, ValueType>::Remove()
{
    CORE_TOOLS_CLASS_IS_VALID_3;

    if (numElements == 0)
    {
        /// 如果故意取消分配权重，则无效。
        THROW_EXCEPTION(SYSTEM_TEXT("最小堆为空。"))
    }

    /// 从最小堆的根中获取最小值。
    const auto root = records.at(GetRecordKey(0));
    const auto rootIndex = GetRecordKey(0);

    /// 将树恢复为堆。抽象地说，记录是堆的新根。
    /// 它通过父子交换沿着树向下移动，直到它位于将树恢复为堆的位置。
    const auto lastIndex = --numElements;

    const auto& record = records.at(GetRecordKey(lastIndex));

    auto parentIndex = 0;
    auto childIndex = 1;
    while (childIndex <= lastIndex)
    {
        if (childIndex < lastIndex)
        {
            /// 如有必要，选择具有最小值的子对象作为与父对象交换的对象。
            if (const auto nextChildIndex = childIndex + 1;
                records.at(GetRecordKey(nextChildIndex)).GetWeight() < records.at(GetRecordKey(childIndex)).GetWeight())
            {
                childIndex = nextChildIndex;
            }
        }

        if (record.GetWeight() <= records.at(GetRecordKey(childIndex)).GetWeight())
        {
            /// 树现在成了最小堆。
            break;
        }

        /// 将子对象移动到父对象的槽中。
        pointers.at(parentIndex) = GetRecordKey(childIndex);
        SetIndex(parentIndex);

        /// 向下传播。
        parentIndex = childIndex;
        childIndex = 2 * childIndex + 1;
    }

    /// 上一个“最后”记录被移到根上，并沿着树传播到它的最终位置，将树恢复为堆。
    /// 插槽pointers.at(parentIndex) 就是最终位置.
    pointers.at(parentIndex) = GetRecordKey(record.GetIndex());
    SetIndex(parentIndex);

    /// 旧的根记录不能丢失。将其连接到包含旧的最后一条记录的插槽中。
    pointers.at(lastIndex) = rootIndex;
    SetIndex(lastIndex);

    return root;
}

template <typename KeyType, typename ValueType>
void CoreTools::MinHeap<KeyType, ValueType>::Update(int index, const ValueType& weight)
{
    CORE_TOOLS_CLASS_IS_VALID_3;

    const auto oldWeight = records.at(index).GetWeight();
    if (oldWeight < weight)
    {
        UpdateGreater(index, weight);
    }
    else if (weight < oldWeight)
    {
        UpdateLess(index, weight);
    }
}

template <typename KeyType, typename ValueType>
void CoreTools::MinHeap<KeyType, ValueType>::UpdateGreater(int index, const ValueType& weight)
{
    records.at(index).SetWeight(weight);

    /// 新值大于旧值。把它传播到节点上。
    auto parentIndex = records.at(index).GetIndex();
    auto childIndex = 2 * parentIndex + 1;
    while (childIndex < numElements)
    {
        /// 至少存在一个子项。找到最大值之一。
        const auto maxChildIndex = GetMaxChildIndex(childIndex);

        if (weight <= records.at(GetRecordKey(maxChildIndex)).GetWeight())
        {
            /// 新值位于将树恢复为最小堆的正确位置。
            break;
        }

        /// 子项的值大于父项的值。交换父对象和子对象：

        /// 将子对象移动到父对象的槽中。
        pointers.at(parentIndex) = GetRecordKey(maxChildIndex);
        SetIndex(parentIndex);

        /// 将父对象移动到子对象的槽中。
        pointers.at(maxChildIndex) = index;
        SetIndex(maxChildIndex);

        /// 向下传播。
        parentIndex = maxChildIndex;
        childIndex = 2 * parentIndex + 1;
    }
}

template <typename KeyType, typename ValueType>
int CoreTools::MinHeap<KeyType, ValueType>::GetMaxChildIndex(int childIndex)
{
    if (const auto nextChildIndex = childIndex + 1;
        nextChildIndex < numElements)
    {
        /// 有两个子节点。
        if (records.at(GetRecordKey(childIndex)).GetWeight() <= records.at(GetRecordKey(nextChildIndex)).GetWeight())
        {
            return childIndex;
        }
        else
        {
            return nextChildIndex;
        }
    }
    else
    {
        return childIndex;
    }
}

template <typename KeyType, typename ValueType>
void CoreTools::MinHeap<KeyType, ValueType>::UpdateLess(int index, const ValueType& weight)
{
    records.at(index).SetWeight(weight);

    /// 新值小于旧值。将其向根部传播。
    auto childIndex = records.at(index).GetIndex();
    while (childIndex > 0)
    {
        const auto parentIndex = (childIndex - 1) / 2;

        if (records.at(GetRecordKey(parentIndex)).GetWeight() <= weight)
        {
            /// 新值位于将树恢复为最小堆堆的正确位置。
            break;
        }

        /// 父对象的值小于子对象的值。交换子对象和父对象。

        /// 将子对象移动到父对象的槽中。
        pointers.at(childIndex) = GetRecordKey(parentIndex);
        records.at(GetRecordKey(childIndex)).SetIndex(childIndex);

        /// 将父对象移动到子对象的槽中。
        pointers.at(parentIndex) = index;
        records.at(GetRecordKey(parentIndex)).SetIndex(parentIndex);

        /// 向下传播。
        childIndex = parentIndex;
    }
}

template <typename KeyType, typename ValueType>
CoreTools::MinHeapRecord<KeyType, ValueType> CoreTools::MinHeap<KeyType, ValueType>::GetRecord(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_3;

    return records.at(index);
}

template <typename KeyType, typename ValueType>
KeyType CoreTools::MinHeap<KeyType, ValueType>::GetHandle(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_3;

    return records.at(index).GetHandle();
}

template <typename KeyType, typename ValueType>
ValueType CoreTools::MinHeap<KeyType, ValueType>::GetWeight(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_3;

    return records.at(index).GetWeight();
}

template <typename KeyType, typename ValueType>
int CoreTools::MinHeap<KeyType, ValueType>::GetRecordKey(int index) const
{
    return pointers.at(index);
}

template <typename KeyType, typename ValueType>
void CoreTools::MinHeap<KeyType, ValueType>::SetIndex(int index)
{
    records.at(GetRecordKey(index)).SetIndex(index);
}

#endif  // CORE_TOOLS_DATA_TYPE_MIN_HEAP_DETAIL_H
