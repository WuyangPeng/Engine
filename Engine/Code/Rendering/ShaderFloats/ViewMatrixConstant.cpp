///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/08 15:33)

#include "Rendering/RenderingExport.h"

#include "ViewMatrixConstant.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Algebra/MatrixDetail.h"
#include "Rendering/SceneGraph/Camera.h"
#include "Rendering/SceneGraph/Visual.h"

CORE_TOOLS_RTTI_DEFINE(Rendering, ViewMatrixConstant);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, ViewMatrixConstant);
CORE_TOOLS_FACTORY_DEFINE(Rendering, ViewMatrixConstant);
CORE_TOOLS_DEFAULT_OBJECT_LOAD_CONSTRUCTOR_DEFINE(Rendering, ViewMatrixConstant);

Rendering::ViewMatrixConstant::ViewMatrixConstant(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow)
    : ParentType{ numRegisters }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, ViewMatrixConstant)

void Rendering::ViewMatrixConstant::Update(MAYBE_UNUSED const Visual* visual, const Camera* camera)
{
    RENDERING_CLASS_IS_VALID_1;

    if (camera != nullptr)
    {
        const auto viewMatrix = camera->GetViewMatrix();

        SetRegisters(viewMatrix);
    }
}

void Rendering::ViewMatrixConstant::SetNumRegisters(int aNumRegisters)
{
    RENDERING_CLASS_IS_VALID_1;
    RENDERING_ASSERTION_2(aNumRegisters == numRegisters, "ViewMatrixConstant寄存器的数量必须为4");

    ParentType::SetNumRegisters(aNumRegisters);
}

Rendering::ShaderFloatSharedPtr Rendering::ViewMatrixConstant::Clone() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}
