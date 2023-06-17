///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/12 15:59)

#include "TestSurfacePatch.h"
#include "System/Helper/Helper.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "Mathematics/Algebra/Matrix2Detail.h"

CORE_TOOLS_RTTI_DEFINE(Rendering, TestSurfacePatch);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, TestSurfacePatch);
CORE_TOOLS_FACTORY_DEFINE(Rendering, TestSurfacePatch);
CORE_TOOLS_DEFAULT_OBJECT_LOAD_CONSTRUCTOR_DEFINE(Rendering, TestSurfacePatch);

Rendering::TestSurfacePatch::TestSurfacePatch(float uMin, float uMax, float vMin, float vMax, bool rectangular)
    : ParentType{ uMin, uMax, vMin, vMax, rectangular }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, TestSurfacePatch)

Rendering::TestSurfacePatch::APoint Rendering::TestSurfacePatch::GetPosition(float u, float v) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    RENDERING_ASSERTION_0(IsParameterValid(u, v), "��������Ч\n");

    return APoint(u, v, 0.0f);
}

Rendering::TestSurfacePatch::AVector Rendering::TestSurfacePatch::GetDerivativesU(float u, MAYBE_UNUSED float v) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    RENDERING_ASSERTION_2(IsParameterValid(u, v), "��������Ч\n");

    return AVector::GetUnitX() * u;
}

Rendering::TestSurfacePatch::AVector Rendering::TestSurfacePatch::GetDerivativesV(MAYBE_UNUSED float u, float v) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    RENDERING_ASSERTION_2(IsParameterValid(u, v), "��������Ч\n");

    return AVector::GetUnitY() * v;
}

Rendering::TestSurfacePatch::AVector Rendering::TestSurfacePatch::GetDerivativesUU(float u, MAYBE_UNUSED float v) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    RENDERING_ASSERTION_2(IsParameterValid(u, v), "��������Ч\n");

    return AVector::GetUnitX() * u + AVector::GetUnitY() * u;
}

Rendering::TestSurfacePatch::AVector Rendering::TestSurfacePatch::GetDerivativesUV(float u, float v) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    RENDERING_ASSERTION_2(IsParameterValid(u, v), "��������Ч\n");

    return AVector::GetUnitX() * u + AVector::GetUnitY() * v;
}

Rendering::TestSurfacePatch::AVector Rendering::TestSurfacePatch::GetDerivativesVV(MAYBE_UNUSED float u, float v) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    RENDERING_ASSERTION_2(IsParameterValid(u, v), "��������Ч\n");

    return AVector::GetUnitX() * v + AVector::GetUnitY() * v;
}

CoreTools::ObjectInterface::ObjectInterfaceSharedPtr Rendering::TestSurfacePatch::CloneObject() const
{
    return std::make_shared<ClassType>(*this);
}
