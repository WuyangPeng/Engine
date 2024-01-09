/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2023/12/29 13:51)

#ifndef RENDERING_RESOURCES_SUB_RESOURCE_IMPL_H
#define RENDERING_RESOURCES_SUB_RESOURCE_IMPL_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Base/SpanIterator.h"

#include <vector>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE SubResourceImpl
    {
    public:
        using ClassType = SubResourceImpl;

        using StorageType = std::vector<char>;
        using SpanIterator = CoreTools::SpanIterator<StorageType::iterator>;

    public:
        SubResourceImpl(int item, int level, const SpanIterator& data, int rowPitch, int slicePitch) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetItem() const noexcept;
        NODISCARD int GetLevel() const noexcept;
        NODISCARD SpanIterator GetData() noexcept;
        NODISCARD int GetRowPitch() const noexcept;
        NODISCARD int GetSlicePitch() const noexcept;

    private:
        int item;
        int level;
        SpanIterator data;
        int rowPitch;
        int slicePitch;
    };
}

#endif  // RENDERING_RESOURCES_SUB_RESOURCE_IMPL_H
