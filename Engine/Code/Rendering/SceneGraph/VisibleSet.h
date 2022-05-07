///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/03 17:26)

#ifndef RENDERING_SCENE_GRAPH_VISIBLE_SET_H
#define RENDERING_SCENE_GRAPH_VISIBLE_SET_H

#include "Rendering/RenderingDll.h"

#include "Visual.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <vector>

RENDERING_NON_COPY_EXPORT_IMPL(VisibleSetImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE VisibleSet
    {
    public:
        NON_COPY_TYPE_DECLARE(VisibleSet);
        using VisualContainer = std::vector<VisualSharedPtr>;
        using VisualContainerIter = VisualContainer::iterator;

    public:
        NODISCARD static VisibleSet Create();

    private:
        explicit VisibleSet(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow);

    public:
        CLASS_INVARIANT_DECLARE;

        // 获得可见的元素集。
        NODISCARD int GetNumVisible() const;
        NODISCARD ConstVisualSharedPtr GetVisible(int index) const;

        // 插入一个可见的对象。
        void Insert(const VisualSharedPtr& visible);

        // 设置集合元素的个数为零。
        void Clear() noexcept;

        NODISCARD VisualContainerIter begin() noexcept;
        NODISCARD VisualContainerIter end() noexcept;

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_SCENE_GRAPH_VISIBLE_SET_H
