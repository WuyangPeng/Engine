///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/07 15:56)

#include "Rendering/RenderingExport.h"

#include "IKJoint.h"
#include "Detail/IKJointImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Rendering/SceneGraph/Spatial.h"

using std::make_shared;
using std::string;
using std::vector;

CORE_TOOLS_RTTI_DEFINE(Rendering, IKJoint);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, IKJoint);
CORE_TOOLS_FACTORY_DEFINE(Rendering, IKJoint);
CORE_TOOLS_DEFAULT_NAMES_USE_IMPL_DEFINE(Rendering, IKJoint);

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, IKJoint)

Rendering::IKJoint::IKJoint(const SpatialSharedPtr& object, const IKGoalSharedPtrVector& goals)
    : ParentType{ "IKJoint" }, impl{ object, goals }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, IKJoint)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, IKJoint, GetAxis, MatrixRotationAxis, Rendering::IKJoint::AVector)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, IKJoint, GetObjectSharedPtr, Rendering::ConstSpatialSharedPtr)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, IKJoint, GetGoalsNum, int)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, IKJoint, GetGoalsSharedPtr, int, Rendering::ConstIKGoalSharedPtr)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, IKJoint, UpdateWorldTransform, void)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, IKJoint, UpdateLocalTranslate, MatrixRotationAxis, bool)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, IKJoint, UpdateLocalRotate, MatrixRotationAxis, bool)

Rendering::IKJoint::IKJoint(LoadConstructor value)
    : ParentType{ value }, impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

int Rendering::IKJoint::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto size = ParentType::GetStreamingSize();

    size += impl->GetStreamingSize();

    return size;
}

int64_t Rendering::IKJoint::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    const auto registerID = ParentType::Register(target);
    if (registerID != 0)
    {
        impl->Register(target);
    }

    return registerID;
}

void Rendering::IKJoint::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    ParentType::Save(target);

    impl->Save(target);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::IKJoint::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::Link(source);

    impl->Link(source);
}

void Rendering::IKJoint::PostLink()
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::PostLink();
}

void Rendering::IKJoint::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);

    impl->Load(source);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

void Rendering::IKJoint::SetAllowTranslation(MatrixRotationAxis axisIndex, bool allowTranslation)
{
    RENDERING_CLASS_IS_VALID_1;

    impl->SetAllowTranslation(axisIndex, allowTranslation);
}

void Rendering::IKJoint::SetAllowRotation(MatrixRotationAxis axisIndex, bool allowRotation)
{
    RENDERING_CLASS_IS_VALID_1;

    impl->SetAllowRotation(axisIndex, allowRotation);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, IKJoint, IsAllowTranslation, MatrixRotationAxis, bool)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, IKJoint, IsAllowRotation, MatrixRotationAxis, bool)

void Rendering::IKJoint::UpdateWorldRotateAndTranslate() noexcept(gAssert < 2 || gRenderingAssert < 2)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->UpdateWorldRotateAndTranslate();
}

CoreTools::ObjectInterfaceSharedPtr Rendering::IKJoint::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}
