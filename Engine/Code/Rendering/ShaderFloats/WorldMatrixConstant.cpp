///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.6 (2022/04/08 16:31)

#include "Rendering/RenderingExport.h"

#include "WorldMatrixConstant.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Algebra/MatrixDetail.h"
#include "Rendering/SceneGraph/Camera.h"
#include "Rendering/SceneGraph/Visual.h"

CORE_TOOLS_RTTI_DEFINE(Rendering, WorldMatrixConstant);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, WorldMatrixConstant);
CORE_TOOLS_FACTORY_DEFINE(Rendering, WorldMatrixConstant);
CORE_TOOLS_DEFAULT_OBJECT_LOAD_CONSTRUCTOR_DEFINE(Rendering, WorldMatrixConstant);

Rendering::WorldMatrixConstant::WorldMatrixConstant(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow)
    : ParentType{ numRegisters }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, WorldMatrixConstant)

void Rendering::WorldMatrixConstant::Update(const Visual* visual, MAYBE_UNUSED const Camera* camera)
{
    RENDERING_CLASS_IS_VALID_1;

    if (visual != nullptr)
    {
        const auto worldMatrix = visual->GetWorldTransform().GetMatrix();

        SetRegisters(worldMatrix);
    }
}

void Rendering::WorldMatrixConstant::SetNumRegisters(int aNumRegisters)
{
    RENDERING_CLASS_IS_VALID_1;
    RENDERING_ASSERTION_2(aNumRegisters == numRegisters, "WorldMatrixConstant�Ĵ�������������Ϊ4");

    ParentType::SetNumRegisters(aNumRegisters);
}

Rendering::ShaderFloatSharedPtr Rendering::WorldMatrixConstant::Clone() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}
