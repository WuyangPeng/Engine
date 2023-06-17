///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 11:03)

#include "Rendering/RenderingExport.h"

#include "CameraModelDirectionVectorConstant.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Algebra/MatrixDetail.h"
#include "Rendering/SceneGraph/Camera.h"
#include "Rendering/SceneGraph/Visual.h"

CORE_TOOLS_RTTI_DEFINE(Rendering, CameraModelDirectionVectorConstant);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, CameraModelDirectionVectorConstant);
CORE_TOOLS_FACTORY_DEFINE(Rendering, CameraModelDirectionVectorConstant);
CORE_TOOLS_DEFAULT_OBJECT_LOAD_CONSTRUCTOR_DEFINE(Rendering, CameraModelDirectionVectorConstant);

Rendering::CameraModelDirectionVectorConstant::CameraModelDirectionVectorConstant(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow)
    : ParentType{ numRegisters }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, CameraModelDirectionVectorConstant)

void Rendering::CameraModelDirectionVectorConstant::Update(const Visual* visual, const Camera* camera)
{
    RENDERING_CLASS_IS_VALID_1;

    if (visual != nullptr && camera != nullptr)
    {
        const auto worldDirectionVector = camera->GetDirectionVector();
        const auto worldInverseMatrix = visual->GetWorldTransform().GetInverseMatrix();
        const auto modelDirectionVector = worldInverseMatrix * worldDirectionVector;

        SetRegister(0, modelDirectionVector);
    }
}

void Rendering::CameraModelDirectionVectorConstant::SetNumRegisters(int aNumRegisters)
{
    RENDERING_CLASS_IS_VALID_1;
    RENDERING_ASSERTION_2(numRegisters == aNumRegisters, "CameraModelDirectionVectorConstant寄存器的数量必须为1");

    ParentType::SetNumRegisters(aNumRegisters);
}

Rendering::ShaderFloatSharedPtr Rendering::CameraModelDirectionVectorConstant::Clone() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}
