///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/08 14:35)

#include "Rendering/RenderingExport.h"

#include "LightModelPositionConstant.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Rendering/SceneGraph/Camera.h"
#include "Rendering/SceneGraph/Visual.h"

CORE_TOOLS_RTTI_DEFINE(Rendering, LightModelPositionConstant);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, LightModelPositionConstant);
CORE_TOOLS_FACTORY_DEFINE(Rendering, LightModelPositionConstant);
CORE_TOOLS_DEFAULT_OBJECT_LOAD_CONSTRUCTOR_DEFINE(Rendering, LightModelPositionConstant);

Rendering::LightModelPositionConstant::LightModelPositionConstant(const LightSharedPtr& light)
    : ParentType{ light }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, LightModelPositionConstant)

void Rendering::LightModelPositionConstant::Update(const Visual* visual, MAYBE_UNUSED const Camera* camera)
{
    RENDERING_CLASS_IS_VALID_1;

    if (visual != nullptr)
    {
        const auto worldPosition = GetLight()->GetPosition();
        const auto worldInverseMatrix = visual->GetWorldTransform().GetInverseMatrix();
        const auto modelPosition = worldInverseMatrix * worldPosition;

        SetRegister(0, modelPosition);
    }
}

Rendering::ShaderFloatSharedPtr Rendering::LightModelPositionConstant::Clone() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}
