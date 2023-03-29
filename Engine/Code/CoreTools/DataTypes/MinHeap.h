///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.4 (2023/03/23 11:17)

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
        NODISCARD bool IsValid(int startIndex, int finalIndex) const;
        void PrintMinHeapInLog() const;

#endif  // OPEN_CLASS_INVARIANT

        NODISCARD int GetMaxElements() const;
        NODISCARD int GetGrowBy() const noexcept;
        NODISCARD int GetElementsNumber() const noexcept;
        NODISCARD RecordType GetMinimum() const;
        NODISCARD RecordType GetRecordByHeapIndex(int heapIndex) const;
        NODISCARD RecordType GetRecordByUniqueIndex(int uniqueIndex) const;

        // �������ֵ��value����Ӧ��ʶ��ġ�generator������ ����ֵ��һ��ָ��Ѽ�¼�洢��Ϣ��Ψһ����UniqueIndex��
        int Insert(Generator generator, Scalar value);

        // ȡ���ѵĸ��� ��Ŀ¼�������еĶ�Ԫ�ص���Сֵ�����ظ���Ϣ��
        RecordType Remove();

        // �Ѽ�¼��ֵ����ͨ������������������޸ġ��������ǣ��ѱ�����Ӧ�ظ�������Ӧ�µ�ֵ��������������λ��HeapIndex��
        int Update(int uniqueIndex, Scalar value);

        NODISCARD bool IsUniqueIndexValid(int uniqueIndex) const;

    private:
        NODISCARD bool IsStoredValueLess(int lhsHeapIndex, int rhsHeapIndex) const;
        NODISCARD bool IsStoredValueLessEqual(int lhsHeapIndex, int rhsHeapIndex) const;

        void GrowRecords();
        void StoreInputInformation(Generator generator, Scalar value);
        int RestoringValidHeapInInsert(Scalar value);
        void RestoringValidHeapInRemove();
        int RestoringValidHeapInUpdateLargerValue(int heapIndex, Scalar value);
        int RestoringValidHeapInUpdateSmallerValue(int heapIndex, Scalar value);

    private:
        int elementsNumber;  // Ԫ����Ŀ
        int growBy;  // ���ӷ���
        RecordStoredManagerType recordStoredManager;
    };
}

#endif  // CORE_TOOLS_DATA_TYPE_MIN_HEAP_H
