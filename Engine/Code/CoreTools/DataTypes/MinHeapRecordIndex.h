///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.4 (2023/03/23 11:10)

#ifndef CORE_TOOLS_DATA_TYPE_MIN_HEAP_RECORD_INDEX_H
#define CORE_TOOLS_DATA_TYPE_MIN_HEAP_RECORD_INDEX_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"
#include "CoreTools/Helper/ExportMacro.h"

CORE_TOOLS_DELAY_COPY_UNSHARED_EXPORT_IMPL(MinHeapRecordIndex, MinHeapRecordIndexImpl);

namespace CoreTools
{
    // ��Ψһ��ʶ����UniqueIndex��ȡ��λ������HeapIndex
    class CORE_TOOLS_DEFAULT_DECLARE MinHeapRecordIndex final
    {
    public:
        DELAY_COPY_UNSHARED_TYPE_DECLARE(MinHeapRecordIndex);

    public:
        explicit MinHeapRecordIndex(int maxElements);
        MinHeapRecordIndex(int newMaxElements, const MinHeapRecordIndex& oldIndex);

#ifdef OPEN_CLASS_INVARIANT

        CLASS_INVARIANT_DECLARE;
        void PrintIndexInLog() const noexcept;

#endif  // OPEN_CLASS_INVARIANT

        NODISCARD int GetMaxElements() const;
        NODISCARD int GetHeapIndex(int uniqueIndex) const;

        // ����Ψһ��ʶ������Ӧ�Ķ�λ������
        void ChangeIndex(int lhsIndex, int rhsIndex);

        void GrowBy(int newMaxElements);

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_DATA_TYPE_MIN_HEAP_RECORD_INDEX_H
