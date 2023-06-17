///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 11:07)

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
