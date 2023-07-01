///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/28 15:33)

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

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, PickRay, IsResult, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, PickRay, GetOrigin, Rendering::PickRay::APoint)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, PickRay, GetDirection, Rendering::PickRay::AVector)
