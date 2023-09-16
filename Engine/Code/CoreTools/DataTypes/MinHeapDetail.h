///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/13 14:26)

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
        // ����С�ѵĸ��л�ȡ��Сֵ��
        const auto key = keys.at(0);
        const auto& node = nodes.at(key);

        return MinHeapRecord{ key, node };
    }
    else
    {
        // �������ȡ������Ȩ�أ�����Ч��
        return MinHeapRecord{ invalid, invalid, 0 };
    }
}

template <typename T>
int CoreTools::MinHeap<T>::Insert(int handle, const T& weight)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    if (numElements < GetMaxElements())
    {
        /// ��(handle, weight)�洢�ڶ����������һ��Ҷ�ڵ��С�
        const auto insertIndex = numElements++;
        const auto insertKey = keys.at(insertIndex);
        indices.at(insertKey) = insertIndex;
        auto& node = nodes.at(insertKey);
        node.SetHandle(handle);
        node.SetWeight(weight);

        /// �����ĸ�������Ϣ��ֱ����������ȷ��λ�ã��Ӷ������ָ�Ϊ��С�ѡ�
        auto childIndex = insertIndex;
        while (0 < childIndex)
        {
            const auto parentIndex = (childIndex - 1) / 2;
            const auto parentKey = keys.at(parentIndex);
            if (!(weight < nodes.at(parentKey).GetWeight()))
            {
                // �������Ȩ��С�ڻ�����Ӷ����ֵ������������һ����С�ѡ�
                break;
            }

            // �������ֵ�����Ӷ����ֵ��������������Ӷ���
            keys.at(parentIndex) = insertKey;
            keys.at(childIndex) = parentKey;
            indices.at(parentKey) = childIndex;
            indices.at(insertKey) = parentIndex;

            // ���ϴ�����
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
        // ����С�ѵĸ��л�ȡ��Сֵ��
        const auto removeKey = keys.at(0);
        const auto& node = nodes.at(removeKey);
        const auto handle = node.GetHandle();
        const auto weight = node.GetWeight();

        // ��ȡ��С�ѵ����һ����ռ�õ�Ҷ�ڵ��������
        auto lastIndex = --numElements;
        if (lastIndex == 0)
        {
            /// ��С��ֻ��һ���ڵ㡣ɾ��������Ҫ����Ĺ�������С�������ǿյġ�
            /// �������Ӧ����ͬ�Ĳ��롢ɾ���͸������У��򽫼��������ָ�ΪĬ��ֵ����ȷ���������ȷ���ԡ�
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

        /// �����ָ�Ϊ��С�ѡ����һ����ռ�õ�Ҷ�ڵ㱻�ƶ������ĸ����Ա���δ��ռ�õ�Ҷ�ӽڵ�������Ҷ�������ĩβ��һ���䡣
        /// �ƶ�֮����Ҫ�����ָ�Ϊ��С�ѡ�
        /// ���ڵ�ֵ���滻Ϊ�ӽڵ����СȨ�ء�ʹ����СȨ�ص��ӽڵ��ظ��ù��̣���Ȩ�ر����ӽڵ����Сֵ�����档
        /// ����һֱ���������������ָ�����С��Ϊֹ��
        auto lastKey = keys.at(lastIndex);
        const auto& lastWeight = nodes.at(lastKey).GetWeight();

        /// �������ڵ�����һ��Ҷ�ڵ㡣lastIndex��ݼ�����˾ɵĸ�ֵ����λ�������ĵ�һ��δռ�õ�Ҷ�ڵ��С�
        keys.at(0) = lastKey;
        keys.at(lastIndex) = removeKey;
        indices.at(removeKey) = lastIndex;
        indices.at(lastKey) = 0;
        --lastIndex;

        // ���´����µĸ�ֵ��ֱ�����ָ�Ϊ��С�ѡ�
        auto parentIndex = 0;
        auto childIndex = 1;
        while (childIndex <= lastIndex)
        {
            auto childKey = keys.at(childIndex);
            if (childIndex < lastIndex)
            {
                // ѡ��ֵ��С�����
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
                // �����ڳ�����С�ѡ�
                break;
            }

            // ���Ӷ����ƶ���������Ĳ��С�
            keys.at(parentIndex) = childKey;
            keys.at(childIndex) = lastKey;
            indices.at(lastKey) = childIndex;
            indices.at(childKey) = parentIndex;

            // ���´�����
            parentIndex = childIndex;
            childIndex = 2 * childIndex + 1;
        }

        /// ��Сֵ���ڴ洢�ھ��������һ����ռ�õ�Ҷ�ڵ��У������ڴ洢�������ĵ�һ��δ��ռ�õ�Ҷ�ڵ��С�
        return MinHeapRecord{ removeKey, handle, weight };
    }
    else
    {
        // �������ȡ������Ȩ�أ�����Ч��
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

            // ��ֵ���ھ�ֵ������������Ҷ���ϡ�
            auto parentIndex = indices.at(updateKey);
            auto childIndex = 2 * parentIndex + 1;
            while (childIndex < numElements)
            {
                // ѡ��ֵ��С�����
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
                    // ��ֵλ�ڽ����ָ�Ϊ��С�ѵ���ȷλ�á�
                    break;
                }

                // �����ֵ���ڸ����ֵ��������������Ӷ���
                keys.at(parentIndex) = childKey;
                keys.at(childIndex) = updateKey;
                indices.at(updateKey) = childIndex;
                indices.at(childKey) = parentIndex;

                // ���´�����
                parentIndex = childIndex;
                childIndex = 2 * childIndex + 1;
            }
        }
        else if (updateWeight < oldWeight)
        {
            nodes.at(updateKey).SetWeight(updateWeight);

            // ��ֵС�ھ�ֵ�����������������
            auto childIndex = updateIndex;
            while (childIndex > 0)
            {
                const auto parentIndex = (childIndex - 1) / 2;
                auto parentKey = keys.at(parentIndex);
                if (!(updateWeight < nodes.at(parentKey).GetWeight()))
                {
                    // ��ֵλ�ڽ����ָ�Ϊ��С�Ѷѵ���ȷλ�á�
                    break;
                }

                // �������ֵС���Ӷ����ֵ�������Ӷ���͸�����
                keys.at(parentIndex) = updateKey;
                keys.at(childIndex) = parentKey;
                indices.at(parentKey) = childIndex;
                indices.at(updateKey) = parentIndex;

                // ���´�����
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