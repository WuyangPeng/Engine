///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.0 (2022/08/09 14:05)

#ifndef RENDERING_RESOURCES_BUFFER_LAYOUT_H
#define RENDERING_RESOURCES_BUFFER_LAYOUT_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Rendering/Resources/Buffers/MemberLayout.h"

#include <vector>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE BufferLayout
    {
    public:
        using ClassType = BufferLayout;
        using MemberLayoutContainer = std::vector<MemberLayout>;

    public:
        BufferLayout() noexcept;
        explicit BufferLayout(const MemberLayoutContainer& memberLayoutContainer);

        CLASS_INVARIANT_DECLARE;

        void SetLayout(const MemberLayoutContainer& memberLayoutContainer);
        NODISCARD MemberLayoutContainer GetLayout() const;

        NODISCARD bool HasMember(const std::string& name) const;

        NODISCARD MemberLayout GetMember(const std::string& name) const;

        void Load(CoreTools::BufferSource& source);
        void Save(CoreTools::BufferTarget& target) const;
        NODISCARD int GetStreamingSize() const;

    private:
        MemberLayoutContainer layout;
    };
}

#endif  // RENDERING_RESOURCES_BUFFER_LAYOUT_H