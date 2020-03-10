// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/22 11:00)

#ifndef RENDERING_SCENE_GRAPH_VISIBLE_SET_IMPL_H
#define RENDERING_SCENE_GRAPH_VISIBLE_SET_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Rendering/SceneGraph/Spatial.h"

#include <boost/noncopyable.hpp>
#include <vector>

namespace Rendering
{
    class Spatial;

    class RENDERING_HIDDEN_DECLARE VisibleSetImpl : private boost::noncopyable
    {
    public:
        using ClassType = VisibleSetImpl;
        
    public:
        VisibleSetImpl ();
        ~VisibleSetImpl ();
        
		CLASS_INVARIANT_DECLARE;

        // 获得可见的元素集。
        int GetNumVisible () const;
		const ConstSpatialSmartPointer& GetVisible(int index) const;

        // 插入一个可见的对象。
		void Insert(const ConstSpatialSmartPointer& visible);

        // 设置集合元素的个数为零。
        void Clear ();

    private:
        int m_NumVisible;
		std::vector<ConstSpatialSmartPointer> m_Visible;
    };
}

#endif // RENDERING_SCENE_GRAPH_VISIBLE_SET_IMPL_H
