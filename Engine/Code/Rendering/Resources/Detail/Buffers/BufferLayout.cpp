///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/29 17:11)

#include "Rendering/RenderingExport.h"

#include "BufferLayout.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Rendering/DataTypes/SpecializedIO.h"

Rendering::BufferLayout::BufferLayout(MemberLayoutContainer memberLayoutContainer) noexcept
    : layout{ std::move(memberLayoutContainer) }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::BufferLayout::BufferLayout() noexcept
    : layout{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, BufferLayout)

void Rendering::BufferLayout::SetLayout(const MemberLayoutContainer& memberLayoutContainer)
{
    RENDERING_CLASS_IS_VALID_9;

    layout = memberLayoutContainer;
}

Rendering::BufferLayout::MemberLayoutContainer Rendering::BufferLayout::GetLayout() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return layout;
}

void Rendering::BufferLayout::AddLayout(const MemberLayout& memberLayout)
{
    RENDERING_CLASS_IS_VALID_9;

    layout.emplace_back(memberLayout);
}

bool Rendering::BufferLayout::HasMember(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    if (const auto iter = std::ranges::find_if(layout, [name](const auto& item) {
            return name == item.GetName();
        });
        iter != layout.end())
    {
        return true;
    }
    else
    {
        return false;
    }
}

Rendering::MemberLayout Rendering::BufferLayout::GetMember(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    if (const auto iter = std::ranges::find_if(layout, [name](const auto& item) {
            return name == item.GetName();
        });
        iter != layout.end())
    {
        return *iter;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("查找成员名字失败。"s))
    }
}

int Rendering::BufferLayout::GetSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return boost::numeric_cast<int>(layout.size());
}

void Rendering::BufferLayout::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_1;

    layout = source.ReadAggregateContainerNotUseNumber<MemberLayoutContainer>();
}

void Rendering::BufferLayout::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    target.WriteAggregateContainerWithNumber(layout);
}

int Rendering::BufferLayout::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return RENDERING_STREAM_SIZE(layout);
}

void Rendering::BufferLayout::SortLayouts()
{
    RENDERING_CLASS_IS_VALID_1;

    std::ranges::sort(layout,
                      [](const MemberLayout& lhs, const MemberLayout& rhs) noexcept {
                          return lhs.GetOffset() < rhs.GetOffset();
                      });
}
