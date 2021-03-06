//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.2 (2020/10/16 11:40)

#ifndef CORE_TOOLS_DATA_TYPE_MIN_HEAP_RECORD_INDEX_H
#define CORE_TOOLS_DATA_TYPE_MIN_HEAP_RECORD_INDEX_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/ExportMacro.h"

CORE_TOOLS_EXPORT_SHARED_PTR(MinHeapRecordIndexImpl);

namespace CoreTools
{
    // 由唯一标识索引UniqueIndex获取堆位置索引HeapIndex
    class CORE_TOOLS_DEFAULT_DECLARE MinHeapRecordIndex final
    {
    public:
        DELAY_COPY_UNSHARE_CLASSES_TYPE_DECLARE(MinHeapRecordIndex);

    public:
        explicit MinHeapRecordIndex(int maxElements);
        MinHeapRecordIndex(int newMaxElements, const MinHeapRecordIndex& oldIndex);

#ifdef OPEN_CLASS_INVARIANT
        CLASS_INVARIANT_DECLARE;
        void PrintIndexInLog() const noexcept;
#endif  // OPEN_CLASS_INVARIANT

        [[nodiscard]] int GetMaxElements() const;
        [[nodiscard]] int GetHeapIndex(int uniqueIndex) const;

        // 交换唯一标识索引对应的堆位置索引
        void ChangeIndex(int lhsIndex, int rhsIndex);

        void GrowBy(int newMaxElements);

    private:
        IMPL_TYPE_DECLARE(MinHeapRecordIndex);
    };
}

#endif  // CORE_TOOLS_DATA_TYPE_MIN_HEAP_RECORD_INDEX_H
