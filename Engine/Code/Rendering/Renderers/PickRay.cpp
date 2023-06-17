///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 12:49)

#include "Rendering/RenderingExport.h"

#include "PickRay.h"
#include "Detail/PickRayImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

Rendering::PickRay::PickRay(bool result, const Mathematics::APointF& origin, const Mathematics::AVectorF& direction)
    : impl{ result, origin, direction }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::PickRay::PickRay(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow)
    : impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, PickRay)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, PickRay, IsResult, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, PickRay, GetOrigin, Mathematics::APointF)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, PickRay, GetDirection, Mathematics::AVectorF)
