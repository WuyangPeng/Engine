///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 11:10)

#ifndef RENDERING_SCENE_GRAPH_PICK_RECORD_CONTAINER_H
#define RENDERING_SCENE_GRAPH_PICK_RECORD_CONTAINER_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Rendering/SceneGraph/SceneGraphFwd.h"

#include <vector>

RENDERING_DELAY_COPY_UNSHARED_EXPORT_IMPL(PickRecordContainer, PickRecordContainerImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE PickRecordContainer
    {
    public:
        DELAY_COPY_UNSHARED_TYPE_DECLARE(PickRecordContainer);

    public:
        NODISCARD static PickRecordContainer Create();

        explicit PickRecordContainer(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow);

        CLASS_INVARIANT_DECLARE;

        void InsertPickRecord(const PickRecord& pickRecord);
        void InsertPickRecord(const PickRecordContainer& pickRecordContainerImpl);

        NODISCARD int GetSize() const;
        NODISCARD PickRecord GetPickRecord(int index) const;
        NODISCARD bool IsEmpty() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_SCENE_GRAPH_PICK_RECORD_CONTAINER_H
