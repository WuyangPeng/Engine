///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 11:17)

#include "Rendering/RenderingExport.h"

#include "PickRecord.h"
#include "Picker.h"
#include "Detail/PickRecordContainerImpl.h"
#include "Detail/PickRecordImpl.h"
#include "Detail/PickerImpl.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, Picker)

Rendering::Picker::Picker(const Spatial& scene, const APoint& origin, const AVector& direction, float tMin, float tMax)
    : impl{ scene, origin, direction, tMin, tMax }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, Picker)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Picker, IsRecordsExist, bool)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Picker, GetClosestToZero, Rendering::PickRecord)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Picker, GetClosestNonnegative, Rendering::PickRecord)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Picker, GetClosestNonpositive, Rendering::PickRecord)
