///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 11:08)

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

        // ��ÿɼ���Ԫ�ؼ���
        int GetNumVisible() const;
        NODISCARD ConstVisualSharedPtr GetVisible(int index) const;

        // ����һ���ɼ��Ķ���
        void Insert(const VisualSharedPtr& aVisible);

        // ���ü���Ԫ�صĸ���Ϊ�㡣
        void Clear() noexcept;

        NODISCARD VisualContainerIter begin() noexcept;
        NODISCARD VisualContainerIter end() noexcept;

    private:
        std::vector<VisualSharedPtr> visible;
    };
}

#endif  // RENDERING_SCENE_GRAPH_VISIBLE_SET_IMPL_H
