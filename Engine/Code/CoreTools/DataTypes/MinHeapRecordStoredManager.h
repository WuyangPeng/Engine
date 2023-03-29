///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/23 11:16)

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

        // 使用UniqueIndex进行搜索
        NODISCARD Scalar GetValueByUniqueIndex(int uniqueIndex) const;
        NODISCARD Generator GetGeneratorByUniqueIndex(int uniqueIndex) const;
        NODISCARD int GetHeapIndex(int uniqueIndex) const;

        // 使用HeapIndex进行搜索
        NODISCARD int GetUniqueIndex(int heapIndex) const;
        NODISCARD Scalar GetValueByHeapIndex(int heapIndex) const;
        NODISCARD Generator GetGeneratorByHeapIndex(int heapIndex) const;

        // 使用UniqueIndex进行修改
        void SetValueByUniqueIndex(int uniqueIndex, Scalar value);
        void SetGeneratorByUniqueIndex(int uniqueIndex, Generator generator);

        // 使用HeapIndex进行修改
        void SetValueByHeapIndex(int uniqueIndex, Scalar value);
        void SetGeneratorByHeapIndex(int uniqueIndex, Generator generator);
        void ChangeValue(int lhsHeapIndex, int rhsHeapIndex);

        void GrowBy(int newMaxElements);

    private:
        // 这个两级的系统避免了大量的分配和释放的发生，如果Records的每个元素都被单独的分配/释放。
        RecordStoredType recordStored;
        RecordIndexType recordIndexes;
    };
}

#endif  // CORE_TOOLS_DATA_TYPE_MIN_HEAP_RECORD_STORED_MANAGER_H
