///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/10 14:59)

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
        RecordIndex recordIndexs;
    };
}

#endif  // CORE_TOOLS_DATA_TYPE_MIN_HEAP_RECORD_INDEX_IMPL_H
