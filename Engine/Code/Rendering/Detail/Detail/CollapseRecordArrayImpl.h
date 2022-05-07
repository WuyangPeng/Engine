///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.6 (2022/04/09 19:22)

#ifndef RENDERING_DETAIL_COLLAPSE_RECORD_ARRAY_IMPL_H
#define RENDERING_DETAIL_COLLAPSE_RECORD_ARRAY_IMPL_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Rendering/Detail/CollapseRecord.h"

#include <vector>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE CollapseRecordArrayImpl
    {
    public:
        using ClassType = CollapseRecordArrayImpl;
        using BufferSource = CoreTools::BufferSource;
        using BufferTarget = CoreTools::BufferTarget;

    public:
        CollapseRecordArrayImpl() noexcept;
        explicit CollapseRecordArrayImpl(const std::vector<CollapseRecord>& collapseRecord);

        CLASS_INVARIANT_DECLARE;

        void Load(CoreTools::BufferSource& source);
        void Save(CoreTools::BufferTarget& target) const;
        NODISCARD int GetStreamingSize() const;

        NODISCARD int GetNumRecords() const;
        NODISCARD std::vector<CollapseRecord> GetRecords() const;
        NODISCARD CollapseRecord GetRecord(int index) const;

    private:
        std::vector<CollapseRecord> collapseRecord;
    };
}

#endif  // RENDERING_DETAIL_COLLAPSE_RECORD_ARRAY_IMPL_H
