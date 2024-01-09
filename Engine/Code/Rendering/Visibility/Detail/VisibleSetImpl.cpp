///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 11:15)

#include "Rendering/RenderingExport.h"

#include "VisibleSetImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::VisibleSetImpl::VisibleSetImpl() noexcept
    : visible{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::VisibleSetImpl::VisibleSetImpl(const VisibleSetImpl& rhs)
    : visible{}
{
    for (const auto& element : rhs.visible)
    {
        visible.emplace_back(boost::polymorphic_pointer_cast<Visual>(element->Clone()));
    }

    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::VisibleSetImpl& Rendering::VisibleSetImpl::operator=(const VisibleSetImpl& rhs)
{
    RENDERING_CLASS_IS_VALID_9;

    if (this == &rhs)
    {
        return *this;
    }

    visible.clear();
    for (const auto& element : rhs.visible)
    {
        visible.emplace_back(boost::polymorphic_pointer_cast<Visual>(element->Clone()));
    }
    visible.shrink_to_fit();

    return *this;
}

Rendering::VisibleSetImpl::VisibleSetImpl(VisibleSetImpl&& rhs) noexcept
    : visible{ std::move(rhs.visible) }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::VisibleSetImpl& Rendering::VisibleSetImpl::operator=(VisibleSetImpl&& rhs) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    visible = std::move(rhs.visible);

    return *this;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, VisibleSetImpl)

int Rendering::VisibleSetImpl::GetNumVisible() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(visible.size());
}

void Rendering::VisibleSetImpl::Insert(const VisualSharedPtr& aVisible)
{
    RENDERING_CLASS_IS_VALID_9;

    visible.emplace_back(aVisible);
}

Rendering::ConstVisualSharedPtr Rendering::VisibleSetImpl::GetVisible(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return visible.at(index);
}

void Rendering::VisibleSetImpl::Clear() noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    visible.clear();
}

Rendering::VisibleSetImpl::VisualContainerIter Rendering::VisibleSetImpl::begin() noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    return visible.begin();
}

Rendering::VisibleSetImpl::VisualContainerIter Rendering::VisibleSetImpl::end() noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    return visible.end();
}
