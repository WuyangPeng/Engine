/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2024/01/02 16:20)

#include "Rendering/RenderingExport.h"

#include "PickRay.h"
#include "Detail/PickRayImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

Rendering::PickRay::PickRay(bool result, const APoint& origin, const AVector& direction)
    : impl{ result, origin, direction }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::PickRay Rendering::PickRay::Create()
{
    return PickRay{ PickRayCreate::Init };
}

Rendering::PickRay::PickRay(PickRayCreate pickRayCreate)
    : impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    System::UnusedFunction(pickRayCreate);

    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, PickRay)

bool Rendering::PickRay::IsResult() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->IsResult();
}

Rendering::PickRay::APoint Rendering::PickRay::GetOrigin() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetOrigin();
}

Rendering::PickRay::AVector Rendering::PickRay::GetDirection() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetDirection();
}
