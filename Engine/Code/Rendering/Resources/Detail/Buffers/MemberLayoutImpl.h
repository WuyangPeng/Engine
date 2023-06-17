///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 11:23)

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