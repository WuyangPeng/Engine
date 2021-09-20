// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/22 15:07)

#ifndef RENDERING_SCENE_GRAPH_VISIBLE_SET_H
#define RENDERING_SCENE_GRAPH_VISIBLE_SET_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "Visual.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include <boost/noncopyable.hpp>

#include <vector>

RENDERING_NON_COPY_EXPORT_IMPL(VisibleSetImpl); 

namespace Rendering
{
    class Spatial;

    class RENDERING_DEFAULT_DECLARE VisibleSet 
    {
    public:
        NON_COPY_TYPE_DECLARE(VisibleSet);     
		using VisualContainer = std::vector<VisualSharedPtr>;
		using VisualContainerIter = VisualContainer::iterator;

    public:
        VisibleSet ();
        ~VisibleSet() noexcept = default;
        VisibleSet(const VisibleSet& rhs) noexcept = delete;
        VisibleSet& operator=(const VisibleSet& rhs) noexcept = delete;
        VisibleSet(VisibleSet&& rhs) noexcept = delete;
        VisibleSet& operator=(VisibleSet&& rhs) noexcept = delete;

		CLASS_INVARIANT_DECLARE;

        // 获得可见的元素集。
        int GetNumVisible () const;
		const ConstVisualSharedPtr GetVisible(int index) const;

        // 插入一个可见的对象。
		void Insert(const VisualSharedPtr& visible);

        // 设置集合元素的个数为零。
        void Clear () noexcept;

		VisualContainerIter begin() noexcept;
        VisualContainerIter end() noexcept;

    private:
        PackageType impl;
    };
}

#endif // RENDERING_SCENE_GRAPH_VISIBLE_SET_H
