/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2024/01/04 10:22)

#ifndef RENDERING_PICKING_PICK_RECORD_CONTAINER_IMPL_H
#define RENDERING_PICKING_PICK_RECORD_CONTAINER_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Picking/PickRecord.h"

#include <vector>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE PickRecordContainerImpl
    {
    public:
        using ClassType = PickRecordContainerImpl;

    public:
        PickRecordContainerImpl() noexcept;

        CLASS_INVARIANT_DECLARE;

        void InsertPickRecord(const PickRecord& aPickRecord);
        void InsertPickRecord(const PickRecordContainerImpl& pickRecordContainerImpl);

        NODISCARD int GetSize() const;
        NODISCARD PickRecord GetPickRecord(int index) const;
        NODISCARD bool IsEmpty() const noexcept;
        void Clear() noexcept;

    private:
        using Container = std::vector<PickRecord>;

    private:
        Container pickRecord;
    };
}

#endif  // RENDERING_PICKING_PICK_RECORD_CONTAINER_IMPL_H
