///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 11:07)

#ifndef RENDERING_SCENE_GRAPH_PICK_RECORD_CONTAINER_IMPL_H
#define RENDERING_SCENE_GRAPH_PICK_RECORD_CONTAINER_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Rendering/SceneGraph/PickRecord.h"

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

    private:
        std::vector<PickRecord> pickRecord;
    };
}

#endif  // RENDERING_SCENE_GRAPH_PICK_RECORD_CONTAINER_IMPL_H
