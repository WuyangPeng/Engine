///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/29 14:29)

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
        explicit BufferLayout(MemberLayoutContainer memberLayoutContainer) noexcept;

        CLASS_INVARIANT_DECLARE;

        void SetLayout(const MemberLayoutContainer& memberLayoutContainer);
        NODISCARD MemberLayoutContainer GetLayout() const;
        void AddLayout(const MemberLayout& memberLayout);

        NODISCARD bool HasMember(const std::string& name) const;

        NODISCARD MemberLayout GetMember(const std::string& name) const;

        NODISCARD int GetSize() const;

        void Load(CoreTools::BufferSource& source);
        void Save(CoreTools::BufferTarget& target) const;
        NODISCARD int GetStreamingSize() const;

        void SortLayouts();

    private:
        MemberLayoutContainer layout;
    };
}

#endif  // RENDERING_RESOURCES_BUFFER_LAYOUT_H