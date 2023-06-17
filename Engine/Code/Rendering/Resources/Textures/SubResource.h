///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 11:24)

#ifndef RENDERING_RESOURCES_SUB_RESOURCE_H
#define RENDERING_RESOURCES_SUB_RESOURCE_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Base/SpanIterator.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "Rendering/Resources/ResourcesFwd.h"

#include <vector>

RENDERING_COPY_UNSHARED_EXPORT_IMPL(SubResource, SubResourceImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE SubResource
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(SubResource);
        using StorageType = std::vector<char>;
        using SpanIterator = CoreTools::SpanIterator<StorageType::iterator>;

    public:
        SubResource(int item, int level, const SpanIterator& data, int rowPitch, int slicePitch);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetItem() const noexcept;
        NODISCARD int GetLevel() const noexcept;
        NODISCARD SpanIterator GetData() noexcept;
        NODISCARD int GetRowPitch() const noexcept;
        NODISCARD int GetSlicePitch() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_RESOURCES_SUB_RESOURCE_H
