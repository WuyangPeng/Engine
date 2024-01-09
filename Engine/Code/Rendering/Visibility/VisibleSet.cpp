/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/28 15:32)

#include "Rendering/RenderingExport.h"

#include "VisibleSet.h"
#include "Detail/VisibleSetImpl.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, VisibleSet)

Rendering::VisibleSet Rendering::VisibleSet::Create()
{
    return VisibleSet{ CoreTools::DisableNotThrow::Disable };
}

Rendering::VisibleSet::VisibleSet(CoreTools::DisableNotThrow disableNotThrow)
    : impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    System::UnusedFunction(disableNotThrow);

    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, VisibleSet)

int Rendering::VisibleSet::GetNumVisible() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetNumVisible();
}

Rendering::ConstVisualSharedPtr Rendering::VisibleSet::GetVisible(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetVisible(index);
}

void Rendering::VisibleSet::Insert(const VisualSharedPtr& visible)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->Insert(visible);
}

void Rendering::VisibleSet::Clear()
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->Clear();
}

Rendering::VisibleSet::VisualContainerIter Rendering::VisibleSet::begin()
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->begin();
}

Rendering::VisibleSet::VisualContainerIter Rendering::VisibleSet::end()
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->end();
}
