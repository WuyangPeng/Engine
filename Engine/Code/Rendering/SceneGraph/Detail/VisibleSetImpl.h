///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/04/01 19:04)

#ifndef RENDERING_SCENE_GRAPH_VISIBLE_SET_IMPL_H
#define RENDERING_SCENE_GRAPH_VISIBLE_SET_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Rendering/SceneGraph/SceneGraphFwd.h"
#include "Rendering/SceneGraph/Visual.h"

#include <boost/noncopyable.hpp>
#include <vector>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE VisibleSetImpl : private boost::noncopyable
    {
    public:
        using ClassType = VisibleSetImpl;
        using VisualContainer = std::vector<VisualSharedPtr>;
        using VisualContainerIter = VisualContainer::iterator;

    public:
        VisibleSetImpl() noexcept;

        CLASS_INVARIANT_DECLARE;

        // 获得可见的元素集。
        int GetNumVisible() const;
        NODISCARD ConstVisualSharedPtr GetVisible(int index) const;

        // 插入一个可见的对象。
        void Insert(const VisualSharedPtr& aVisible);

        // 设置集合元素的个数为零。
        void Clear() noexcept;

        NODISCARD VisualContainerIter begin() noexcept;
        NODISCARD VisualContainerIter end() noexcept;

    private:
        std::vector<VisualSharedPtr> visible;
    };
}

#endif  // RENDERING_SCENE_GRAPH_VISIBLE_SET_IMPL_H
