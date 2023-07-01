///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.0 (2023/06/29 14:30)

#ifndef RENDERING_RESOURCES_MEMBER_LAYOUT_IMPL_H
#define RENDERING_RESOURCES_MEMBER_LAYOUT_IMPL_H

#include "Rendering/RenderingDll.h"

#include <string>
#include <vector>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE MemberLayoutImpl final
    {
    public:
        using ClassType = MemberLayoutImpl;

    public:
        MemberLayoutImpl(const std::string& name, int offset, int numElements);

        CLASS_INVARIANT_DECLARE;

        NODISCARD std::string GetName() const;
        NODISCARD int GetOffset() const noexcept;
        NODISCARD int GetNumElements() const noexcept;

        NODISCARD int GetStreamingSize() const;

    private:
        std::string name;
        int offset;
        int numElements;
    };
}

#endif  // RENDERING_RESOURCES_MEMBER_LAYOUT_IMPL_H