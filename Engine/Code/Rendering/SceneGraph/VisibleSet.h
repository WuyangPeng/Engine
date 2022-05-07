///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.6 (2022/04/03 17:26)

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

        // ��ÿɼ���Ԫ�ؼ���
        NODISCARD int GetNumVisible() const;
        NODISCARD ConstVisualSharedPtr GetVisible(int index) const;

        // ����һ���ɼ��Ķ���
        void Insert(const VisualSharedPtr& visible);

        // ���ü���Ԫ�صĸ���Ϊ�㡣
        void Clear() noexcept;

        NODISCARD VisualContainerIter begin() noexcept;
        NODISCARD VisualContainerIter end() noexcept;

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_SCENE_GRAPH_VISIBLE_SET_H
