///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 11:05)

#include "Rendering/RenderingExport.h"

#include "ProjectorMatrixConstant.h"
#include "Detail/ProjectorMatrixConstantImpl.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Rendering/SceneGraph/Visual.h"

CORE_TOOLS_RTTI_DEFINE(Rendering, ProjectorMatrixConstant);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, ProjectorMatrixConstant);
CORE_TOOLS_FACTORY_DEFINE(Rendering, ProjectorMatrixConstant);

Rendering::ProjectorMatrixConstant::ProjectorMatrixConstant(LoadConstructor loadConstructor)
    : ParentType{ loadConstructor }, impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, ProjectorMatrixConstant)

CORE_TOOLS_WITH_IMPL_OBJECT_GET_STREAMING_SIZE_DEFINE(Rendering, ProjectorMatrixConstant)
CORE_TOOLS_DEFAULT_OBJECT_REGISTER_DEFINE(Rendering, ProjectorMatrixConstant)
CORE_TOOLS_WITH_IMPL_OBJECT_SAVE_DEFINE(Rendering, ProjectorMatrixConstant)
CORE_TOOLS_DEFAULT_OBJECT_LINK_DEFINE(Rendering, ProjectorMatrixConstant)
CORE_TOOLS_DEFAULT_OBJECT_POST_LINK_DEFINE(Rendering, ProjectorMatrixConstant)
CORE_TOOLS_WITH_IMPL_OBJECT_LOAD_DEFINE(Rendering, ProjectorMatrixConstant)
CORE_TOOLS_DEFAULT_NAMES_USE_IMPL_DEFINE(Rendering, ProjectorMatrixConstant);

Rendering::ProjectorMatrixConstant::ProjectorMatrixConstant(const ProjectorSharedPtr& projector, bool biased, int biasScaleMatrixIndex)
    : ParentType(numRegisters), impl{ projector, biased, biasScaleMatrixIndex }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, ProjectorMatrixConstant)

void Rendering::ProjectorMatrixConstant::SetNumRegisters(int aNumRegisters)
{
    RENDERING_CLASS_IS_VALID_1;
    RENDERING_ASSERTION_2(aNumRegisters == numRegisters, "ProjectorMatrixConstant寄存器的数量必须为4");

    ParentType::SetNumRegisters(aNumRegisters);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, ProjectorMatrixConstant, GetProjector, Rendering::ConstProjectorSharedPtr)

void Rendering::ProjectorMatrixConstant::Update(const Visual* visual, MAYBE_UNUSED const Camera* camera)
{
    RENDERING_CLASS_IS_VALID_1;

    if (visual != nullptr)
    {
        const auto projectionViewMatrix = GetProjector()->GetProjectionViewMatrix();
        const auto worldMatrix = visual->GetWorldTransform().GetMatrix();
        auto projectionViewWorldMatrix = projectionViewMatrix * worldMatrix;
        projectionViewWorldMatrix = impl->GetProjectionViewWorldMatrix(projectionViewWorldMatrix);

        SetRegisters(projectionViewWorldMatrix);
    }
}

Rendering::ShaderFloatSharedPtr Rendering::ProjectorMatrixConstant::Clone() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}
