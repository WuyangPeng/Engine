//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.2 (2020/10/16 11:40)

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
        [[nodiscard]] bool IndexIsValid() const noexcept;
        void PrintIndexInLog() const noexcept;
#endif  // OPEN_CLASS_INVARIANT

        [[nodiscard]] int GetMaxElements() const;
        [[nodiscard]] int GetHeapIndex(int uniqueIndex) const;

        void ChangeIndex(int lhsIndex, int rhsIndex);

        void GrowBy(int newMaxElements);

    private:
        std::vector<int> m_RecordIndexs;
    };
}

#endif  // CORE_TOOLS_DATA_TYPE_MIN_HEAP_RECORD_INDEX_IMPL_H
