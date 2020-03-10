// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/22 11:00)

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

        // ��ÿɼ���Ԫ�ؼ���
        int GetNumVisible () const;
		const ConstSpatialSmartPointer& GetVisible(int index) const;

        // ����һ���ɼ��Ķ���
		void Insert(const ConstSpatialSmartPointer& visible);

        // ���ü���Ԫ�صĸ���Ϊ�㡣
        void Clear ();

    private:
        int m_NumVisible;
		std::vector<ConstSpatialSmartPointer> m_Visible;
    };
}

#endif // RENDERING_SCENE_GRAPH_VISIBLE_SET_IMPL_H
