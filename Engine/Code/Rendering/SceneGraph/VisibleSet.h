// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/22 15:07)

#ifndef RENDERING_SCENE_GRAPH_VISIBLE_SET_H
#define RENDERING_SCENE_GRAPH_VISIBLE_SET_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "Visual.h"

#include <boost/noncopyable.hpp>

#include <vector>

RENDERING_EXPORT_SHARED_PTR(VisibleSetImpl);
EXPORT_NONCOPYABLE_CLASS(RENDERING);

namespace Rendering
{
    class Spatial;

    class RENDERING_DEFAULT_DECLARE VisibleSet: private boost::noncopyable
    {
    public:
        NON_COPY_CLASSES_TYPE_DECLARE(VisibleSet);     
		using VisualContainer = std::vector<VisualSharedPtr>;
		using VisualContainerIter = VisualContainer::iterator;

    public:
        VisibleSet ();
        
		CLASS_INVARIANT_DECLARE;

        // ��ÿɼ���Ԫ�ؼ���
        int GetNumVisible () const;
		const ConstVisualSharedPtr GetVisible(int index) const;

        // ����һ���ɼ��Ķ���
		void Insert(const VisualSharedPtr& visible);

        // ���ü���Ԫ�صĸ���Ϊ�㡣
        void Clear () noexcept;

		VisualContainerIter begin() noexcept;
        VisualContainerIter end() noexcept;

    private:
        IMPL_TYPE_DECLARE(VisibleSet);
    };
}

#endif // RENDERING_SCENE_GRAPH_VISIBLE_SET_H
