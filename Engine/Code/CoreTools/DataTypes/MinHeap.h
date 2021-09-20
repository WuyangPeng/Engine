//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.2 (2020/10/19 9:53)

#ifndef CORE_TOOLS_DATA_TYPE_MIN_HEAP_H
#define CORE_TOOLS_DATA_TYPE_MIN_HEAP_H

#include "CoreTools/CoreToolsDll.h"

#include "DataTypesFwd.h"
#include "MinHeapRecordStoredManager.h"

#include <type_traits>

namespace CoreTools
{
    // �Ѵ���������������λ������HeapIndex��Ψһ��ʶ����UniqueIndex���������ǰ��ѵ�λ�ý���������������ʱ�ɱ䡣
    // Ψһ��ʶ�����ڼ�¼����ʱ�Զ����ɣ�������ʱ���ֲ��䡣Update����ʹ��Ψһ��ʶ�������и��¡�
    template <typename Generator, typename Scalar>
    class MinHeap final
    {
    public:
        static_assert(std::is_scalar_v<Scalar>, "Scalar must be scalar");

        using ClassType = MinHeap<Generator, Scalar>;
        using RecordType = MinHeapRecord<Generator, Scalar>;
        using RecordStoredManagerType = MinHeapRecordStoredManager<Generator, Scalar>;

    public:
        MinHeap(int maxElements, int growBy, Scalar initialValue = Scalar{});

#ifdef OPEN_CLASS_INVARIANT
        // ǰ������������¼����ȷʵ�γ�һ���ѡ����һ��������ӡ�ѵ�һ����־�С�
        CLASS_INVARIANT_DECLARE;
        bool IsValid(int startIndex, int finalIndex) const;
        void PrintMinHeapInLog() const;
#endif  // OPEN_CLASS_INVARIANT

        int GetMaxElements() const;
        int GetGrowBy() const noexcept;
        int GetElementsNumber() const noexcept;
        const RecordType GetMinimum() const;
        const RecordType GetRecordByHeapIndex(int heapIndex) const;
        const RecordType GetRecordByUniqueIndex(int uniqueIndex) const;

        // �������ֵ��value����Ӧ��ʶ��ġ�generator������ ����ֵ��һ��ָ��Ѽ�¼�洢��Ϣ��Ψһ����UniqueIndex��
        int Insert(Generator generator, Scalar value);

        // ȡ���ѵĸ��� ��Ŀ¼�������еĶ�Ԫ�ص���Сֵ�����ظ���Ϣ��
        const RecordType Remove();

        // �Ѽ�¼��ֵ����ͨ������������������޸ġ��������ǣ��ѱ�����Ӧ�ظ�������Ӧ�µ�ֵ��������������λ��HeapIndex��
        int Update(int uniqueIndex, Scalar value);

        bool IsUniqueIndexValid(int uniqueIndex) const;

    private:
        bool IsStoredValueLess(int lhsHeapIndex, int rhsHeapIndex) const;
        bool IsStoredValueLessEqual(int lhsHeapIndex, int rhsHeapIndex) const;

        void GrowRecords();
        void StoreInputInformation(Generator generator, Scalar value);
        int RestoringValidHeapInInsert(Scalar value);
        void RestoringValidHeapInRemove();
        int RestoringValidHeapInUpdateLargerValue(int heapIndex, Scalar value);
        int RestoringValidHeapInUpdateSmallerValue(int heapIndex, Scalar value);

    private:
        int m_ElementsNumber;  // Ԫ����Ŀ
        int m_GrowBy;  // ���ӷ���
        RecordStoredManagerType m_RecordStoredManager;
    };
}

#endif  // CORE_TOOLS_DATA_TYPE_MIN_HEAP_H
