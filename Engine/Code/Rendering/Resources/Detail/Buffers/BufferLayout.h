///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.0 (2022/08/09 14:05)

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