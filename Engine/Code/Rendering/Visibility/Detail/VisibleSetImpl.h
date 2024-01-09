/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/28 15:23)

#ifndef RENDERING_VISIBILITY_VISIBLE_SET_IMPL_H
#define RENDERING_VISIBILITY_VISIBLE_SET_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Rendering/SceneGraph/Visual.h"

#include <boost/noncopyable.hpp>
#include <vector>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE VisibleSetImpl
    {
    public:
        using ClassType = VisibleSetImpl;

        using VisualContainer = std::vector<VisualSharedPtr>;
        using VisualContainerIter = VisualContainer::iterator;

    public:
        VisibleSetImpl() noexcept;
        ~VisibleSetImpl() noexcept = default;
        VisibleSetImpl(const VisibleSetImpl& rhs);
        VisibleSetImpl& operator=(const VisibleSetImpl& rhs);
        VisibleSetImpl(VisibleSetImpl&& rhs) noexcept;
        VisibleSetImpl& operator=(VisibleSetImpl&& rhs) noexcept;

        CLASS_INVARIANT_DECLARE;

        // 获得可见的元素集。
        NODISCARD int GetNumVisible() const;
        NODISCARD ConstVisualSharedPtr GetVisible(int index) const;

        // 插入一个可见的对象。
        void Insert(const VisualSharedPtr& aVisible);

        // 设置集合元素的个数为零。
        void Clear() noexcept;

        NODISCARD VisualContainerIter begin() noexcept;
        NODISCARD VisualContainerIter end() noexcept;

    private:
        VisualContainer visible;
    };
}

#endif  // RENDERING_VISIBILITY_VISIBLE_SET_IMPL_H
