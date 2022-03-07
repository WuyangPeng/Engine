///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/10 15:58)

#ifndef CORE_TOOLS_DATA_TYPE_MIN_HEAP_RECORD_STORED_H
#define CORE_TOOLS_DATA_TYPE_MIN_HEAP_RECORD_STORED_H

#include "CoreTools/CoreToolsDll.h"

#include "DataTypesFwd.h"

#include <type_traits>
#include <vector>

namespace CoreTools
{
    // 使用堆索引HeapIndex进行排序
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

        // 由HeapIndex直接获取值
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
        // 实际的记录存储，分配在一个大的模块
        Scalar initialValue;  // 初始值
        RecordContainer records;
    };
}

#endif  // CORE_TOOLS_DATA_TYPE_MIN_HEAP_RECORD_STORED_H
