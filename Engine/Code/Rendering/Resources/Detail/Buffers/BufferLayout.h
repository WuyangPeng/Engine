/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/29 13:50)

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
        using BufferTarget = CoreTools::BufferTarget;
        using BufferSource = CoreTools::BufferSource;

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

        void Load(BufferSource& source);
        void Save(BufferTarget& target) const;
        NODISCARD int GetStreamingSize() const;

        void SortLayouts();

    private:
        MemberLayoutContainer layout;
    };
}

#endif  // RENDERING_RESOURCES_BUFFER_LAYOUT_H