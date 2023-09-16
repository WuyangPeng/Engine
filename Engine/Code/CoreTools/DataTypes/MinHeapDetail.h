///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/13 14:26)

#ifndef CORE_TOOLS_DATA_TYPE_MIN_HEAP_DETAIL_H
#define CORE_TOOLS_DATA_TYPE_MIN_HEAP_DETAIL_H

#include "MinHeap.h"
#include "MinHeapNodeDetail.h"
#include "MinHeapRecordDetail.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename T>
CoreTools::MinHeap<T>::MinHeap(int maxElements)
    : numElements{ 0 },
      keys{},
      indices{},
      nodes{}
{
    Reset(maxElements);

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <typename T>
bool CoreTools::MinHeap<T>::IsValid() const noexcept
{
    try
    {
        for (auto childIndex = 1; childIndex < numElements; ++childIndex)
        {
            const auto childKey = keys.at(childIndex);
            const auto parentIndex = (childIndex - 1) / 2;
            const auto parentKey = keys.at(parentIndex);
            if (nodes.at(childKey).GetWeight() < nodes.at(parentKey).GetWeight())
            {
                return false;
            }

            if (indices.at(parentKey) != parentIndex)
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

template <typename T>
void CoreTools::MinHeap<T>::Reset(int maxElements)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    numElements = 0;
    if (maxElements > 0)
    {
        keys.resize(maxElements);
        indices.resize(maxElements);
        nodes.resize(maxElements);
        for (auto i = 0; i < maxElements; ++i)
        {
            keys.at(i) = i;
            indices.at(i) = i;
            nodes.at(i).SetHandle(invalid);
        }
    }
    else
    {
        keys.clear();
        indices.clear();
        nodes.clear();
    }
}

template <typename T>
int CoreTools::MinHeap<T>::GetMaxElements() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(keys.size());
}

template <typename T>
int CoreTools::MinHeap<T>::GetNumElements() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return numElements;
}

template <typename T>
typename CoreTools::MinHeap<T>::MinHeapRecord CoreTools::MinHeap<T>::GetMinimum() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    if (0 < numElements)
    {
        // 从最小堆的根中获取最小值。
        const auto key = keys.at(0);
        const auto& node = nodes.at(key);

        return MinHeapRecord{ key, node };
    }
    else
    {
        // 如果故意取消分配权重，则无效。
        return MinHeapRecord{ invalid, invalid, 0 };
    }
}

template <typename T>
int CoreTools::MinHeap<T>::Insert(int handle, const T& weight)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    if (numElements < GetMaxElements())
    {
        /// 将(handle, weight)存储在二叉树的最后一个叶节点中。
        const auto insertIndex = numElements++;
        const auto insertKey = keys.at(insertIndex);
        indices.at(insertKey) = insertIndex;
        auto& node = nodes.at(insertKey);
        node.SetHandle(handle);
        node.SetWeight(weight);

        /// 向树的根传播信息，直到它到达正确的位置，从而将树恢复为最小堆。
        auto childIndex = insertIndex;
        while (0 < childIndex)
        {
            const auto parentIndex = (childIndex - 1) / 2;
            const auto parentKey = keys.at(parentIndex);
            if (!(weight < nodes.at(parentKey).GetWeight()))
            {
                // 父对象的权重小于或等于子对象的值。我们现在有一个最小堆。
                break;
            }

            // 父对象的值大于子对象的值。交换父对象和子对象。
            keys.at(parentIndex) = insertKey;
            keys.at(childIndex) = parentKey;
            indices.at(parentKey) = childIndex;
            indices.at(insertKey) = parentIndex;

            // 向上传播。
            childIndex = parentIndex;
        }

        return insertKey;
    }
    else
    {
        return invalid;
    }
}

template <typename T>
typename CoreTools::MinHeap<T>::MinHeapRecord CoreTools::MinHeap<T>::Remove()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    if (numElements > 0)
    {
        // 从最小堆的根中获取最小值。
        const auto removeKey = keys.at(0);
        const auto& node = nodes.at(removeKey);
        const auto handle = node.GetHandle();
        const auto weight = node.GetWeight();

        // 获取最小堆的最后一个被占用的叶节点的索引。
        auto lastIndex = --numElements;
        if (lastIndex == 0)
        {
            /// 最小堆只有一个节点。删除它不需要额外的工作。最小堆现在是空的。
            /// 如果两次应用相同的插入、删除和更新序列，则将键和索引恢复为默认值，以确保结果具有确定性。
            if (numElements == 0)
            {
                const auto maxElements = GetMaxElements();
                for (auto i = 0; i < maxElements; ++i)
                {
                    keys.at(i) = i;
                    indices.at(i) = i;
                    nodes.at(i).SetHandle(invalid);
                }
            }

            return MinHeapRecord{ removeKey, handle, weight };
        }

        /// 将树恢复为最小堆。最后一个被占用的叶节点被移动到树的根，以保持未被占用的叶子节点总是在叶子数组的末尾这一不变。
        /// 移动之后，需要将树恢复为最小堆。
        /// 根节点值将替换为子节点的最小权重。使用最小权重的子节点重复该过程；其权重被其子节点的最小值所代替。
        /// 遍历一直持续到二进制树恢复到最小堆为止。
        auto lastKey = keys.at(lastIndex);
        const auto& lastWeight = nodes.at(lastKey).GetWeight();

        /// 交换根节点和最后一个叶节点。lastIndex会递减，因此旧的根值现在位于新树的第一个未占用的叶节点中。
        keys.at(0) = lastKey;
        keys.at(lastIndex) = removeKey;
        indices.at(removeKey) = lastIndex;
        indices.at(lastKey) = 0;
        --lastIndex;

        // 向下传播新的根值，直到树恢复为最小堆。
        auto parentIndex = 0;
        auto childIndex = 1;
        while (childIndex <= lastIndex)
        {
            auto childKey = keys.at(childIndex);
            if (childIndex < lastIndex)
            {
                // 选择值最小的子项。
                const auto otherChildIndex = childIndex + 1;
                const auto otherChildKey = keys.at(otherChildIndex);
                if (nodes.at(otherChildIndex).GetWeight() < nodes.at(childKey).GetWeight())
                {
                    childIndex = otherChildIndex;
                    childKey = otherChildKey;
                }
            }

            if (!(nodes.at(childKey).GetWeight() < lastWeight))
            {
                // 树现在成了最小堆。
                break;
            }

            // 将子对象移动到父对象的槽中。
            keys.at(parentIndex) = childKey;
            keys.at(childIndex) = lastKey;
            indices.at(lastKey) = childIndex;
            indices.at(childKey) = parentIndex;

            // 向下传播。
            parentIndex = childIndex;
            childIndex = 2 * childIndex + 1;
        }

        /// 最小值现在存储在旧树的最后一个被占用的叶节点中，但现在存储在新树的第一个未被占用的叶节点中。
        return MinHeapRecord{ removeKey, handle, weight };
    }
    else
    {
        // 如果故意取消分配权重，则无效。
        return MinHeapRecord{ invalid, invalid, 0 };
    }
}

template <typename T>
bool CoreTools::MinHeap<T>::Update(int updateKey, const T& updateWeight)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    if (const auto updateIndex = indices.at(updateKey);
        updateKey < GetMaxElements() && updateIndex < GetNumElements())
    {
        const auto oldWeight = nodes.at(updateKey).GetWeight();
        if (oldWeight < updateWeight)
        {
            nodes.at(updateKey).SetWeight(updateWeight);

            // 新值大于旧值。把它传播到叶子上。
            auto parentIndex = indices.at(updateKey);
            auto childIndex = 2 * parentIndex + 1;
            while (childIndex < numElements)
            {
                // 选择值最小的子项。
                auto childKey = keys.at(childIndex);

                if (const auto otherChildIndex = childIndex + 1;
                    otherChildIndex < numElements)
                {
                    if (auto otherChildKey = keys.at(otherChildIndex);
                        nodes.at(otherChildKey).GetWeight() < nodes.at(childKey).GetWeight())
                    {
                        childIndex = otherChildIndex;
                        childKey = otherChildKey;
                    }
                }

                if (!(nodes.at(childKey).GetWeight() < updateWeight))
                {
                    // 新值位于将树恢复为最小堆的正确位置。
                    break;
                }

                // 子项的值大于父项的值。交换父对象和子对象：
                keys.at(parentIndex) = childKey;
                keys.at(childIndex) = updateKey;
                indices.at(updateKey) = childIndex;
                indices.at(childKey) = parentIndex;

                // 向下传播。
                parentIndex = childIndex;
                childIndex = 2 * childIndex + 1;
            }
        }
        else if (updateWeight < oldWeight)
        {
            nodes.at(updateKey).SetWeight(updateWeight);

            // 新值小于旧值。将其向根部传播。
            auto childIndex = updateIndex;
            while (childIndex > 0)
            {
                const auto parentIndex = (childIndex - 1) / 2;
                auto parentKey = keys.at(parentIndex);
                if (!(updateWeight < nodes.at(parentKey).GetWeight()))
                {
                    // 新值位于将树恢复为最小堆堆的正确位置。
                    break;
                }

                // 父对象的值小于子对象的值。交换子对象和父对象。
                keys.at(parentIndex) = updateKey;
                keys.at(childIndex) = parentKey;
                indices.at(parentKey) = childIndex;
                indices.at(updateKey) = parentIndex;

                // 向下传播。
                childIndex = parentIndex;
            }
        }

        return true;
    }
    else
    {
        return false;
    }
}

template <typename T>
typename CoreTools::MinHeap<T>::MinHeapNodeContainer CoreTools::MinHeap<T>::GetNodes() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return nodes;
}

template <typename T>
typename CoreTools::MinHeap<T>::MinHeapNode CoreTools::MinHeap<T>::GetNode(int key) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return nodes.at(key);
}

template <typename T>
int CoreTools::MinHeap<T>::GetHandle(int key) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return nodes.at(key).GetHandle();
}

template <typename T>
T CoreTools::MinHeap<T>::GetWeight(int key) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return nodes.at(key).GetWeight();
}

#endif  // CORE_TOOLS_DATA_TYPE_MIN_HEAP_DETAIL_H