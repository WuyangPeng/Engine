/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2024/01/04 10:23)

#ifndef RENDERING_PICKING_PICK_RECORD_CONTAINER_H
#define RENDERING_PICKING_PICK_RECORD_CONTAINER_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Rendering/Picking/PickingFwd.h"

RENDERING_DELAY_COPY_UNSHARED_EXPORT_IMPL(PickRecordContainer, PickRecordContainerImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE PickRecordContainer
    {
    public:
        DELAY_COPY_UNSHARED_TYPE_DECLARE(PickRecordContainer);

    public:
        NODISCARD static PickRecordContainer Create();

        CLASS_INVARIANT_DECLARE;

        void InsertPickRecord(const PickRecord& pickRecord);
        void InsertPickRecord(const PickRecordContainer& pickRecordContainerImpl);

        NODISCARD int GetSize() const;
        NODISCARD PickRecord GetPickRecord(int index) const;
        NODISCARD bool IsEmpty() const noexcept;

        void Clear();

    private:
        explicit PickRecordContainer(CoreTools::DisableNotThrow disableNotThrow);

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_PICKING_PICK_RECORD_CONTAINER_H
