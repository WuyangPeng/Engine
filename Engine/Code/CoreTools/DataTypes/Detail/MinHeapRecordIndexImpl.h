///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/23 11:11)

#ifndef CORE_TOOLS_DATA_TYPE_MIN_HEAP_RECORD_INDEX_IMPL_H
#define CORE_TOOLS_DATA_TYPE_MIN_HEAP_RECORD_INDEX_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include <vector>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE MinHeapRecordIndexImpl final
    {
    public:
        using ClassType = MinHeapRecordIndexImpl;

    public:
        explicit MinHeapRecordIndexImpl(int maxElements);
        MinHeapRecordIndexImpl(int newMaxElements, const MinHeapRecordIndexImpl& oldIndex);

#ifdef OPEN_CLASS_INVARIANT

        CLASS_INVARIANT_DECLARE;
        NODISCARD bool IndexIsValid() const noexcept;
        void PrintIndexInLog() const noexcept;
        void DoPrintIndexInLog() const;

#endif  // OPEN_CLASS_INVARIANT

        NODISCARD int GetMaxElements() const;
        NODISCARD int GetHeapIndex(int uniqueIndex) const;

        void ChangeIndex(int lhsIndex, int rhsIndex);

        void GrowBy(int newMaxElements);

    private:
        using RecordIndex = std::vector<int>;

    private:
        NODISCARD static RecordIndex CreateDefaultRecordIndex(int maxElements);

    private:
        RecordIndex recordIndex;
    };
}

#endif  // CORE_TOOLS_DATA_TYPE_MIN_HEAP_RECORD_INDEX_IMPL_H
