///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/10 16:38)

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
    // ����ΪHeapIndex
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

    os << SYSTEM_TEXT("��С����Ϣ\n");

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

    CORE_TOOLS_ASSERTION_2(0 <= heapIndex && heapIndex < elementsNumber, "��Ч����\n");

    return RecordType{ uniqueIndex, recordStoredManager.GetGeneratorByUniqueIndex(uniqueIndex), recordStoredManager.GetValueByUniqueIndex(uniqueIndex) };
}

template <typename Generator, typename Scalar>
CoreTools::MinHeapRecord<Generator, Scalar> CoreTools::MinHeap<Generator, Scalar>::GetRecordByHeapIndex(int heapIndex) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_3;
    CORE_TOOLS_ASSERTION_2(0 <= heapIndex && heapIndex < elementsNumber, "��Ч����\n");

    return RecordType{ recordStoredManager.GetHeapIndex(heapIndex),
                       recordStoredManager.GetGeneratorByHeapIndex(heapIndex),
                       recordStoredManager.GetValueByHeapIndex(heapIndex) };
}

template <typename Generator, typename Scalar>
int CoreTools::MinHeap<Generator, Scalar>::Insert(Generator generator, Scalar value)
{
    CORE_TOOLS_CLASS_IS_VALID_3;

    // ����б�Ҫ�����Ӽ�¼�����顣
    GrowRecords();

    // �洢������Ϣ�ڶѼ�¼��������������е����һ��Ҷ�ڵ㡣
    StoreInputInformation(generator, value);

    // ������Ϣ�������ĸ���ֱ����������ȷ��λ�ã��Ӷ��ָ���Ϊһ����Ч�Ķѡ�
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
            // parent��һ��ֵС�ڻ����child��ֵ����������������һ����Ч�Ķѡ�
            break;
        }

        // parent���б�child�����ֵ������parent��child��
        recordStoredManager.ChangeValue(child, parent);

        child = parent;
    }

    return recordStoredManager.GetUniqueIndex(child);
}

template <typename Generator, typename Scalar>
CoreTools::MinHeapRecord<Generator, Scalar> CoreTools::MinHeap<Generator, Scalar>::Remove()
{
    CORE_TOOLS_CLASS_IS_VALID_3;

    // �Ӷѵĸ��еõ�����Ϣ��
    RecordType root{ recordStoredManager.GetHeapIndex(0), recordStoredManager.GetGeneratorByHeapIndex(0), recordStoredManager.GetValueByHeapIndex(0) };

    RestoringValidHeapInRemove();

    return root;
}

// private
template <typename Generator, typename Scalar>
void CoreTools::MinHeap<Generator, Scalar>::RestoringValidHeapInRemove()
{
    // �ָ����е�����������0λ��lastλ�ļ�¼��
    // Ȼ��ͨ��parent-child���������ƶ���0λ��ֱ�����ָ��ڶ�������λ�á�

    const auto last = --elementsNumber;
    auto parent = 0;
    auto child = 1;

    // �ɵļ�¼���ܶ�ʧ�������ӵ���۰������ľɼ�¼��
    recordStoredManager.ChangeValue(parent, last);

    while (child < last)
    {
        if (child < last - 1)
        {
            // ����б�Ҫ��ѡ����Сֵ��child��parent������
            const auto childRight = child + 1;
            if (IsStoredValueLess(childRight, child))
            {
                child = childRight;
            }
        }

        if (IsStoredValueLessEqual(parent, child))
        {
            // ��������һ���ѡ�
            break;
        }
        else
        {
            // ����child��parent�Ĳ�ۡ�
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

    // ֻ��MinHeap�ſ��Ը��¼�¼��
    auto scalar = recordStoredManager.GetValueByUniqueIndex(uniqueIndex);
    const auto heapIndex = recordStoredManager.GetHeapIndex(uniqueIndex);

    CORE_TOOLS_ASSERTION_2(0 <= heapIndex && heapIndex < elementsNumber, "��Ч����\n");

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
    // ��ֵ���ھ�ֵ������Ҷ�Ӵ�����

    recordStoredManager.SetValueByHeapIndex(heapIndex, value);

    auto parent = heapIndex;
    auto child = 2 * parent + 1;
    auto maxChild = child;
    while (child < elementsNumber)
    {
        // ������һ��child���ڡ��ҵ����ֵ֮һ��

        if (child < elementsNumber - 1)
        {
            // ����child�Ĵ��ڡ�
            const auto childRight = child + 1;
            if (IsStoredValueLessEqual(child, childRight))
                maxChild = child;
            else
                maxChild = childRight;
        }
        else
        {
            // һ��child�Ĵ��ڡ�
            maxChild = child;
        }

        if (value <= recordStoredManager.GetValueByHeapIndex(maxChild))
        {
            // �µ�ֵ������ȷ��λ�ã��ѻָ���Ϊһ���ѡ�
            break;
        }
        else
        {
            // child��parent��ֵ����
            // ����maxChild��parent�Ĳ�ۡ�
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

    // ��ֵС�ھ�ֵ�������������
    auto child = heapIndex;

    while (0 < child)
    {
        // һ��parent���ڡ�
        const auto parent = (child - 1) / 2;

        if (recordStoredManager.GetValueByHeapIndex(parent) <= value)
        {
            // �µ�ֵ������ȷ��λ�ã��ѻָ���Ϊһ���ѡ�
            break;
        }
        else
        {
            // child��parent��ֵ��С������child��parent�Ĳ�ۡ�
            recordStoredManager.ChangeValue(child, parent);

            child = parent;
        }
    }

    return child;
}

#endif  // CORE_TOOLS_DATA_TYPE_MIN_HEAP_DETAIL_H