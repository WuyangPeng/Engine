///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/10 15:58)

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
        NODISCARD bool IndexIsValid() const noexcept;
#endif  // OPEN_CLASS_INVARIANT

        NODISCARD int GetMaxElements() const;

        // ��HeapIndexֱ�ӻ�ȡֵ
        NODISCARD Scalar GetValue(int heapIndex) const;
        NODISCARD Generator GetGenerator(int heapIndex) const;
        NODISCARD int GetUniqueIndex(int heapIndex) const;

        void SetValue(int heapIndex, Scalar value);
        void SetGenerator(int heapIndex, Generator generator);
        void ChangeValue(int lhsIndex, int rhsIndex);

        void GrowBy(int newMaxElements);

    private:
        using RecordContainer = std::vector<RecordType>;

    private:
        // ʵ�ʵļ�¼�洢��������һ�����ģ��
        Scalar initialValue;  // ��ʼֵ
        RecordContainer records;
    };
}

#endif  // CORE_TOOLS_DATA_TYPE_MIN_HEAP_RECORD_STORED_H
