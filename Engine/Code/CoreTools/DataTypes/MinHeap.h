///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/23 11:17)

#ifndef CORE_TOOLS_DATA_TYPE_MIN_HEAP_H
#define CORE_TOOLS_DATA_TYPE_MIN_HEAP_H

#include "CoreTools/CoreToolsDll.h"

#include "DataTypesFwd.h"
#include "MinHeapRecordStoredManager.h"

#include <type_traits>

namespace CoreTools
{
    // 堆存在两个索引：堆位置索引HeapIndex，唯一标识索引UniqueIndex，堆索引是按堆的位置进行索引，在排序时可变。
    // 唯一标识索引在记录产生时自动生成，在排序时保持不变。Update必须使用唯一标识索引进行更新。
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

        // 前两个函数检查记录数组确实形成一个堆。最后一个函数打印堆到一个日志中。
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

        // 插入堆数值“value”对应于识别的“generator”对象， 返回值是一个指向堆记录存储信息的唯一索引UniqueIndex。
        int Insert(Generator generator, Scalar value);

        // 取出堆的根。 根目录包含所有的堆元素的最小值。返回根信息。
        RecordType Remove();

        // 堆记录的值必须通过调用这个函数进行修改。副作用是，堆必须相应地更新以适应新的值。返回索引的新位置HeapIndex。
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
        int elementsNumber;  // 元素数目
        int growBy;  // 增加幅度
        RecordStoredManagerType recordStoredManager;
    };
}

#endif  // CORE_TOOLS_DATA_TYPE_MIN_HEAP_H
