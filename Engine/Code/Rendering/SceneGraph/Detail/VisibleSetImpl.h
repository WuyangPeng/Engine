// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ����汾��0.0.0.3 (2019/07/22 11:00)

#ifndef RENDERING_SCENE_GRAPH_VISIBLE_SET_IMPL_H
#define RENDERING_SCENE_GRAPH_VISIBLE_SET_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Rendering/SceneGraph/Visual.h"

#include <boost/noncopyable.hpp>
#include <vector>

namespace Rendering
{
    class Spatial;

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
        const ConstVisualSharedPtr GetVisible(int index) const;

        // ����һ���ɼ��Ķ���
        void Insert(const VisualSharedPtr& visible);

        // ���ü���Ԫ�صĸ���Ϊ�㡣
        void Clear() noexcept;

        VisualContainerIter begin() noexcept;
        VisualContainerIter end() noexcept;

    private:
        std::vector<VisualSharedPtr> m_Visible;
    };
}

#endif  // RENDERING_SCENE_GRAPH_VISIBLE_SET_IMPL_H
