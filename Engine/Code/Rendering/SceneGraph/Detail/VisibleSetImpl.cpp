///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/04/01 19:04)

#include "Rendering/RenderingExport.h"

#include "VisibleSetImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

using std::vector;

Rendering::VisibleSetImpl::VisibleSetImpl() noexcept
    : visible{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

bool Rendering::VisibleSetImpl::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

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
    RENDERING_ASSERTION_0(0 <= index && index < GetNumVisible(), "索引无效在GetVisible\n");

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
