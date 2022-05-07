///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/08 15:26)

#include "Rendering/RenderingExport.h"

#include "ProjectorWorldPositionConstant.h"
#include "Detail/ProjectorConstantImpl.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

using std::make_shared;

CORE_TOOLS_RTTI_DEFINE(Rendering, ProjectorWorldPositionConstant);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, ProjectorWorldPositionConstant);
CORE_TOOLS_FACTORY_DEFINE(Rendering, ProjectorWorldPositionConstant);

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, ProjectorWorldPositionConstant)

Rendering::ProjectorWorldPositionConstant::ProjectorWorldPositionConstant(LoadConstructor loadConstructor)
    : ParentType{ loadConstructor }, impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CORE_TOOLS_WITH_IMPL_OBJECT_GET_STREAMING_SIZE_DEFINE(Rendering, ProjectorWorldPositionConstant)
CORE_TOOLS_DEFAULT_OBJECT_REGISTER_DEFINE(Rendering, ProjectorWorldPositionConstant)
CORE_TOOLS_WITH_IMPL_OBJECT_SAVE_DEFINE(Rendering, ProjectorWorldPositionConstant)
CORE_TOOLS_DEFAULT_OBJECT_LINK_DEFINE(Rendering, ProjectorWorldPositionConstant)
CORE_TOOLS_DEFAULT_OBJECT_POST_LINK_DEFINE(Rendering, ProjectorWorldPositionConstant)
CORE_TOOLS_WITH_IMPL_OBJECT_LOAD_DEFINE(Rendering, ProjectorWorldPositionConstant)
CORE_TOOLS_DEFAULT_NAMES_USE_IMPL_DEFINE(Rendering, ProjectorWorldPositionConstant);

Rendering::ProjectorWorldPositionConstant::ProjectorWorldPositionConstant(const ProjectorSharedPtr& projector)
    : ParentType{ numRegisters }, impl{ projector }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, ProjectorWorldPositionConstant)

void Rendering::ProjectorWorldPositionConstant::SetNumRegisters(int aNumRegisters)
{
    RENDERING_CLASS_IS_VALID_1;
    RENDERING_ASSERTION_2(aNumRegisters == numRegisters, "ProjectorWorldPositionConstant寄存器的数量必须为1");

    ParentType::SetNumRegisters(aNumRegisters);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, ProjectorWorldPositionConstant, GetProjector, Rendering::ConstProjectorSharedPtr)

void Rendering::ProjectorWorldPositionConstant::Update(MAYBE_UNUSED const Visual* visual, MAYBE_UNUSED const Camera* camera)
{
    RENDERING_CLASS_IS_VALID_1;

    const auto& worldPosition = GetProjector()->GetPosition();

    SetRegister(0, worldPosition);
}

Rendering::ShaderFloatSharedPtr Rendering::ProjectorWorldPositionConstant::Clone() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}
