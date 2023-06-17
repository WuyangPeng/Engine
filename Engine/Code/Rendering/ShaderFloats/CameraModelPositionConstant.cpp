///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 11:04)

#include "Rendering/RenderingExport.h"

#include "CameraModelPositionConstant.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/MatrixDetail.h"
#include "Rendering/SceneGraph/Camera.h"
#include "Rendering/SceneGraph/Visual.h"

CORE_TOOLS_RTTI_DEFINE(Rendering, CameraModelPositionConstant);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, CameraModelPositionConstant);
CORE_TOOLS_FACTORY_DEFINE(Rendering, CameraModelPositionConstant);
CORE_TOOLS_DEFAULT_OBJECT_LOAD_CONSTRUCTOR_DEFINE(Rendering, CameraModelPositionConstant);

Rendering::CameraModelPositionConstant::CameraModelPositionConstant(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow)
    : ParentType{ numRegisters }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, CameraModelPositionConstant)

void Rendering::CameraModelPositionConstant::Update(const Visual* visual, const Camera* camera)
{
    RENDERING_CLASS_IS_VALID_1;

    if (visual != nullptr && camera != nullptr)
    {
        const auto worldPosition = camera->GetPosition();
        const auto worldInverseMatrix = visual->GetWorldTransform().GetInverseMatrix();
        const auto modelPosition = worldInverseMatrix * worldPosition;

        SetRegister(0, modelPosition);
    }
}

void Rendering::CameraModelPositionConstant::SetNumRegisters(int aNumRegisters)
{
    RENDERING_CLASS_IS_VALID_1;
    RENDERING_ASSERTION_2(aNumRegisters == numRegisters, "CameraModelPositionConstant寄存器的数量必须为1");

    ParentType::SetNumRegisters(aNumRegisters);
}

Rendering::ShaderFloatSharedPtr Rendering::CameraModelPositionConstant::Clone() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}
