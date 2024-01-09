///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 11:17)

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

Rendering::Picker::Picker(int numThread)
    : impl{ numThread }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, Picker)

void Rendering::Picker::SetMaxDistance(float maxDistance)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetMaxDistance(maxDistance);
}

float Rendering::Picker::GetMaxDistance() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetMaxDistance();
}

void Rendering::Picker::operator()(Spatial& scene, const APoint& origin, const AVector& direction, float tMin, float tMax)
{
    RENDERING_CLASS_IS_VALID_9;

    return (*impl)(scene, origin, direction, tMin, tMax);
}

bool Rendering::Picker::IsRecordsExist() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->IsRecordsExist();
}

Rendering::PickRecord Rendering::Picker::GetClosestToZero() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetClosestToZero();
}

Rendering::PickRecord Rendering::Picker::GetClosestNonnegative() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetClosestNonnegative();
}

Rendering::PickRecord Rendering::Picker::GetClosestNonpositive() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetClosestNonpositive();
}
