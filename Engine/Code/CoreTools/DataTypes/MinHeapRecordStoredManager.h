///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.4 (2023/03/23 11:16)

#ifndef CORE_TOOLS_DATA_TYPE_MIN_HEAP_RECORD_STORED_MANAGER_H
#define CORE_TOOLS_DATA_TYPE_MIN_HEAP_RECORD_STORED_MANAGER_H

#include "MinHeapRecord.h"
#include "MinHeapRecordIndex.h"
#include "MinHeapRecordStored.h"

#include <type_traits>

namespace CoreTools
{
    template <typename Generator, typename Scalar>
    class MinHeapRecordStoredManager
    {
    public:
        static_assert(std::is_scalar_v<Scalar>, "Scalar must be scalar");

        using ClassType = MinHeapRecordStoredManager<Generator, Scalar>;
        using RecordIndexType = MinHeapRecordIndex;
        using RecordType = MinHeapRecord<Generator, Scalar>;
        using RecordStoredType = MinHeapRecordStored<Generator, Scalar>;

    public:
        explicit MinHeapRecordStoredManager(int maxElements, Scalar initialValue);
        MinHeapRecordStoredManager(int newMaxElements, const MinHeapRecordStoredManager& oldRecordStoredManage);

#ifdef OPEN_CLASS_INVARIANT

        CLASS_INVARIANT_DECLARE;
        NODISCARD bool IndexIsValid() const;
        void PrintIndexInLog() const noexcept;

#endif  // OPEN_CLASS_INVARIANT

        NODISCARD int GetMaxElements() const;

        // ʹ��UniqueIndex��������
        NODISCARD Scalar GetValueByUniqueIndex(int uniqueIndex) const;
        NODISCARD Generator GetGeneratorByUniqueIndex(int uniqueIndex) const;
        NODISCARD int GetHeapIndex(int uniqueIndex) const;

        // ʹ��HeapIndex��������
        NODISCARD int GetUniqueIndex(int heapIndex) const;
        NODISCARD Scalar GetValueByHeapIndex(int heapIndex) const;
        NODISCARD Generator GetGeneratorByHeapIndex(int heapIndex) const;

        // ʹ��UniqueIndex�����޸�
        void SetValueByUniqueIndex(int uniqueIndex, Scalar value);
        void SetGeneratorByUniqueIndex(int uniqueIndex, Generator generator);

        // ʹ��HeapIndex�����޸�
        void SetValueByHeapIndex(int uniqueIndex, Scalar value);
        void SetGeneratorByHeapIndex(int uniqueIndex, Generator generator);
        void ChangeValue(int lhsHeapIndex, int rhsHeapIndex);

        void GrowBy(int newMaxElements);

    private:
        // ���������ϵͳ�����˴����ķ�����ͷŵķ��������Records��ÿ��Ԫ�ض��������ķ���/�ͷš�
        RecordStoredType recordStored;
        RecordIndexType recordIndexes;
    };
}

#endif  // CORE_TOOLS_DATA_TYPE_MIN_HEAP_RECORD_STORED_MANAGER_H
