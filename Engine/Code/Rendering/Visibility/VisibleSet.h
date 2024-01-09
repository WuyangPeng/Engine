/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/28 15:31)

#ifndef RENDERING_VISIBILITY_VISIBLE_SET_H
#define RENDERING_VISIBILITY_VISIBLE_SET_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Rendering/SceneGraph/Visual.h"

#include <vector>

RENDERING_DELAY_COPY_UNSHARED_EXPORT_IMPL(VisibleSet, VisibleSetImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE VisibleSet
    {
    public:
        DELAY_COPY_UNSHARED_TYPE_DECLARE(VisibleSet);

        using VisualContainer = std::vector<VisualSharedPtr>;
        using VisualContainerIter = VisualContainer::iterator;

    public:
        NODISCARD static VisibleSet Create();

    private:
        explicit VisibleSet(CoreTools::DisableNotThrow disableNotThrow);

    public:
        CLASS_INVARIANT_DECLARE;

        // 获得可见的元素集。
        NODISCARD int GetNumVisible() const;
        NODISCARD ConstVisualSharedPtr GetVisible(int index) const;

        // 插入一个可见的对象。
        void Insert(const VisualSharedPtr& visible);

        // 设置集合元素的个数为零。
        void Clear();

        NODISCARD VisualContainerIter begin();
        NODISCARD VisualContainerIter end();

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_VISIBILITY_VISIBLE_SET_H
