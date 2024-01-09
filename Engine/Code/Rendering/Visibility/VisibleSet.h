/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2023/12/28 15:31)

#ifndef RENDERING_VISIBILITY_VISIBLE_SET_H
#define RENDERING_VISIBILITY_VISIBLE_SET_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Rendering/SceneGraph/Visual.h"

#include <vector>

RENDERING_DELAY_COPY_UNSHARED_EXPORT_IMPL(VisibleSet, VisibleSetImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE VisibleSet
    {
    public:
        DELAY_COPY_UNSHARED_TYPE_DECLARE(VisibleSet);

        using VisualContainer = std::vector<VisualSharedPtr>;
        using VisualContainerIter = VisualContainer::iterator;

    public:
        NODISCARD static VisibleSet Create();

    private:
        explicit VisibleSet(CoreTools::DisableNotThrow disableNotThrow);

    public:
        CLASS_INVARIANT_DECLARE;

        // ��ÿɼ���Ԫ�ؼ���
        NODISCARD int GetNumVisible() const;
        NODISCARD ConstVisualSharedPtr GetVisible(int index) const;

        // ����һ���ɼ��Ķ���
        void Insert(const VisualSharedPtr& visible);

        // ���ü���Ԫ�صĸ���Ϊ�㡣
        void Clear();

        NODISCARD VisualContainerIter begin();
        NODISCARD VisualContainerIter end();

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_VISIBILITY_VISIBLE_SET_H
