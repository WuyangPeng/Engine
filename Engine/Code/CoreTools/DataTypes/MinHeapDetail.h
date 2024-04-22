/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/11 14:50)

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
        /// ����С�ѵĸ��л�ȡ��Сֵ��
        return records.at(GetRecordKey(0));
    }
    else
    {
        /// �������ȡ������Ȩ�أ�����Ч��
        THROW_EXCEPTION(SYSTEM_TEXT("��С��Ϊ�ա�"))
    }
}

template <typename KeyType, typename ValueType>
int CoreTools::MinHeap<KeyType, ValueType>::Insert(const KeyType& handle, const ValueType& weight)
{
    CORE_TOOLS_CLASS_IS_VALID_3;

    if (GetMaxElements() <= numElements)
    {
        /// �������������ء�
        THROW_EXCEPTION(SYSTEM_TEXT("��С��������"))
    }

    /// ��������Ϣ(handle, weight)�洢�����һ���Ѽ�¼�У��ü�¼�����е����һ��Ҷ�ڵ㡣
    auto childIndex = numElements++;

    auto& record = records.at(GetRecordKey(childIndex));
    record.SetRecord(childIndex, handle, weight);

    /// �����ĸ�������Ϣ��ֱ����������ȷ��λ�ã��Ӷ������ָ�Ϊ��С�ѡ�
    while (0 < childIndex)
    {
        const auto parentIndex = (childIndex - 1) / 2;

        if (records.at(GetRecordKey(parentIndex)).GetWeight() <= weight)
        {
            /// �������Ȩ��С�ڻ�����Ӷ����ֵ������������һ����С�ѡ�
            break;
        }

        /// �������ֵ�����Ӷ����ֵ��������������Ӷ���

        /// ���������ƶ����Ӷ���Ĳ��С�
        pointers.at(childIndex) = GetRecordKey(parentIndex);
        SetIndex(childIndex);

        /// ���Ӷ����ƶ���������Ĳ��С�
        pointers.at(parentIndex) = record.GetIndex();
        SetIndex(parentIndex);

        /// ���ϴ�����
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
        /// �������ȡ������Ȩ�أ�����Ч��
        THROW_EXCEPTION(SYSTEM_TEXT("��С��Ϊ�ա�"))
    }

    /// ����С�ѵĸ��л�ȡ��Сֵ��
    const auto root = records.at(GetRecordKey(0));
    const auto rootIndex = GetRecordKey(0);

    /// �����ָ�Ϊ�ѡ������˵����¼�Ƕѵ��¸���
    /// ��ͨ�����ӽ��������������ƶ���ֱ����λ�ڽ����ָ�Ϊ�ѵ�λ�á�
    const auto lastIndex = --numElements;

    const auto& record = records.at(GetRecordKey(lastIndex));

    auto parentIndex = 0;
    auto childIndex = 1;
    while (childIndex <= lastIndex)
    {
        if (childIndex < lastIndex)
        {
            /// ���б�Ҫ��ѡ�������Сֵ���Ӷ�����Ϊ�븸���󽻻��Ķ���
            if (const auto nextChildIndex = childIndex + 1;
                records.at(GetRecordKey(nextChildIndex)).GetWeight() < records.at(GetRecordKey(childIndex)).GetWeight())
            {
                childIndex = nextChildIndex;
            }
        }

        if (record.GetWeight() <= records.at(GetRecordKey(childIndex)).GetWeight())
        {
            /// �����ڳ�����С�ѡ�
            break;
        }

        /// ���Ӷ����ƶ���������Ĳ��С�
        pointers.at(parentIndex) = GetRecordKey(childIndex);
        SetIndex(parentIndex);

        /// ���´�����
        parentIndex = childIndex;
        childIndex = 2 * childIndex + 1;
    }

    /// ��һ������󡱼�¼���Ƶ����ϣ�����������������������λ�ã������ָ�Ϊ�ѡ�
    /// ���pointers.at(parentIndex) ��������λ��.
    pointers.at(parentIndex) = GetRecordKey(record.GetIndex());
    SetIndex(parentIndex);

    /// �ɵĸ���¼���ܶ�ʧ���������ӵ������ɵ����һ����¼�Ĳ���С�
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

    /// ��ֵ���ھ�ֵ�������������ڵ��ϡ�
    auto parentIndex = records.at(index).GetIndex();
    auto childIndex = 2 * parentIndex + 1;
    while (childIndex < numElements)
    {
        /// ���ٴ���һ������ҵ����ֵ֮һ��
        const auto maxChildIndex = GetMaxChildIndex(childIndex);

        if (weight <= records.at(GetRecordKey(maxChildIndex)).GetWeight())
        {
            /// ��ֵλ�ڽ����ָ�Ϊ��С�ѵ���ȷλ�á�
            break;
        }

        /// �����ֵ���ڸ����ֵ��������������Ӷ���

        /// ���Ӷ����ƶ���������Ĳ��С�
        pointers.at(parentIndex) = GetRecordKey(maxChildIndex);
        SetIndex(parentIndex);

        /// ���������ƶ����Ӷ���Ĳ��С�
        pointers.at(maxChildIndex) = index;
        SetIndex(maxChildIndex);

        /// ���´�����
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
        /// �������ӽڵ㡣
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

    /// ��ֵС�ھ�ֵ�����������������
    auto childIndex = records.at(index).GetIndex();
    while (childIndex > 0)
    {
        const auto parentIndex = (childIndex - 1) / 2;

        if (records.at(GetRecordKey(parentIndex)).GetWeight() <= weight)
        {
            /// ��ֵλ�ڽ����ָ�Ϊ��С�Ѷѵ���ȷλ�á�
            break;
        }

        /// �������ֵС���Ӷ����ֵ�������Ӷ���͸�����

        /// ���Ӷ����ƶ���������Ĳ��С�
        pointers.at(childIndex) = GetRecordKey(parentIndex);
        records.at(GetRecordKey(childIndex)).SetIndex(childIndex);

        /// ���������ƶ����Ӷ���Ĳ��С�
        pointers.at(parentIndex) = index;
        records.at(GetRecordKey(parentIndex)).SetIndex(parentIndex);

        /// ���´�����
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
