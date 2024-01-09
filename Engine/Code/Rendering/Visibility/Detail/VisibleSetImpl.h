/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2023/12/28 15:23)

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

        // ��ÿɼ���Ԫ�ؼ���
        NODISCARD int GetNumVisible() const;
        NODISCARD ConstVisualSharedPtr GetVisible(int index) const;

        // ����һ���ɼ��Ķ���
        void Insert(const VisualSharedPtr& aVisible);

        // ���ü���Ԫ�صĸ���Ϊ�㡣
        void Clear() noexcept;

        NODISCARD VisualContainerIter begin() noexcept;
        NODISCARD VisualContainerIter end() noexcept;

    private:
        VisualContainer visible;
    };
}

#endif  // RENDERING_VISIBILITY_VISIBLE_SET_IMPL_H
