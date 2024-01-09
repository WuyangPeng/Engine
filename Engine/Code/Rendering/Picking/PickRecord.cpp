/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2024/01/04 10:21)

#include "Rendering/RenderingExport.h"

#include "PickRecord.h"
#include "Detail/PickRecordContainerImpl.h"
#include "Detail/PickRecordImpl.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, PickRecord)

Rendering::PickRecord Rendering::PickRecord::Create()
{
    return PickRecord{ CoreTools::DisableNotThrow::Disable };
}

Rendering::PickRecord::PickRecord(const VisualSharedPtr& visual, IndexFormatType primitiveType, int primitiveIndex, const VertexIndexType& vertexIndex, float t, const APoint& linePoint, const BarycentricType& barycentric, const APoint& primitivePoint, float distanceToLinePoint, float distanceToPrimitivePoint, float distanceBetweenLinePrimitive)
    : impl{ visual, primitiveType, primitiveIndex, vertexIndex, t, linePoint, barycentric, primitivePoint, distanceToLinePoint, distanceToPrimitivePoint, distanceBetweenLinePrimitive }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::PickRecord::PickRecord(CoreTools::DisableNotThrow disableNotThrow)
    : impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    System::UnusedFunction(disableNotThrow);

    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, PickRecord)

float Rendering::PickRecord::GetDistanceToLinePoint() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetDistanceToLinePoint();
}

float Rendering::PickRecord::GetT() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetT();
}
