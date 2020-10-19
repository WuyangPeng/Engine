//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.2 (2020/10/19 9:56)

#ifndef CORE_TOOLS_DATA_TYPE_MIN_HEAP_RECORD_STORED_H
#define CORE_TOOLS_DATA_TYPE_MIN_HEAP_RECORD_STORED_H

#include "CoreTools/CoreToolsDll.h"

#include "DataTypesFwd.h"

#include <type_traits>
#include <vector>

namespace CoreTools
{
    // ʹ�ö�����HeapIndex��������
    template <typename Generator, typename Scalar>
    class MinHeapRecordStored final
    {
    public:
        static_assert(std::is_scalar_v<Scalar>, "Scalar must be scalar");

        using ClassType = MinHeapRecordStored<Generator, Scalar>;
        using RecordType = MinHeapRecord<Generator, Scalar>;

    public:
        explicit MinHeapRecordStored(int maxElements, Scalar initialValue);
        MinHeapRecordStored(int newMaxElements, const MinHeapRecordStored& oldRecordStored);

#ifdef OPEN_CLASS_INVARIANT
        CLASS_INVARIANT_DECLARE;
        bool IndexIsValid() const noexcept;
#endif  // OPEN_CLASS_INVARIANT

        int GetMaxElements() const;

        // ��HeapIndexֱ�ӻ�ȡֵ
        Scalar GetValue(int heapIndex) const;
        Generator GetGenerator(int heapIndex) const;
        int GetUniqueIndex(int heapIndex) const;

        void SetValue(int heapIndex, Scalar value);
        void SetGenerator(int heapIndex, Generator generator);
        void ChangeValue(int lhsIndex, int rhsIndex);

        void GrowBy(int newMaxElements);

    private:
        using RecordContainer = std::vector<RecordType>;

    private:
        // ʵ�ʵļ�¼�洢��������һ�����ģ��
        Scalar m_InitialValue;  // ��ʼֵ
        RecordContainer m_Records;
    };
}

#endif  // CORE_TOOLS_DATA_TYPE_MIN_HEAP_RECORD_STORED_H
