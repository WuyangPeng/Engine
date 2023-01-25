///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/07 15:46)

#include "Rendering/RenderingExport.h"

#include "IKController.h"
#include "Detail/IKControllerImpl.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

using std::make_shared;
using std::string;
using std::vector;

CORE_TOOLS_RTTI_DEFINE(Rendering, IKController);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, IKController);
CORE_TOOLS_FACTORY_DEFINE(Rendering, IKController);
CORE_TOOLS_DEFAULT_NAMES_USE_IMPL_DEFINE(Rendering, IKController);

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, IKController)

Rendering::IKController::IKController(const IKJointSharedPtrVector& joints)
    : ParentType{ CoreTools::DisableNotThrow::Disable }, impl{ joints }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, IKController)

Rendering::ControllerInterfaceSharedPtr Rendering::IKController::Clone() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}

Rendering::IKController::IKController(LoadConstructor value)
    : ParentType{ value }, impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

int Rendering::IKController::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto size = ParentType::GetStreamingSize();

    size += impl->GetStreamingSize();

    return size;
}

int64_t Rendering::IKController::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    const auto registerID = ParentType::Register(target);
    if (registerID != 0)
    {
        impl->Register(target);
    }

    return registerID;
}

void Rendering::IKController::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    ParentType::Save(target);

    impl->Save(target);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::IKController::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::Link(source);

    impl->Link(source);
}

void Rendering::IKController::PostLink()
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::PostLink();
}

void Rendering::IKController::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);

    impl->Load(source);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, IKController, GetIterations, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, IKController, IsOrderEndToRoot, bool)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Rendering, IKController, SetIterations, int, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Rendering, IKController, SetOrderEndToRoot, bool, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, IKController, GetJointsSharedPtr, int, Rendering::IKJointSharedPtr)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, IKController, GetJointsNum, int)

bool Rendering::IKController::Update(double applicationTime)
{
    using namespace System;
    if (ParentType::Update(applicationTime))
    {
        // 确保效果都在当前世界空间。
        // 假设joints形成一个链，使joints I的世界变换是joint I + 1的父变换。

        const auto mNumJoints = impl->GetJointsNum();

        for (auto index = 0; index < mNumJoints; ++index)
        {
            auto pointer = impl->GetJointsSharedPtr(index);
            pointer->UpdateWorldTransform();
        }

        // 更新joints一次一个，以满足目标。
        // 由于每个关节被更新，即联合之后出现在链中的节点joint必须在世界空间。

        for (auto iter = 0; iter < impl->GetIterations(); ++iter)
        {
            for (auto index = 0; index < mNumJoints; ++index)
            {
                auto realIndex = index;
                if (impl->IsOrderEndToRoot())
                {
                    realIndex = mNumJoints - 1 - index;
                }

                auto joint = impl->GetJointsSharedPtr(realIndex);

                for (auto axis = Mathematics::MatrixRotationAxis::X; axis < Mathematics::MatrixRotationAxis::Count; ++axis)
                {
                    if (joint->IsAllowTranslation(axis))
                    {
                        if (joint->UpdateLocalTranslate(axis))
                        {
                            for (auto j = realIndex; j < mNumJoints; ++j)
                            {
                                auto joint2 = impl->GetJointsSharedPtr(j);
                                joint2->UpdateWorldRotateAndTranslate();
                            }
                        }
                    }
                }

                for (auto axis = Mathematics::MatrixRotationAxis::X; axis < Mathematics::MatrixRotationAxis::Count; ++axis)
                {
                    if (joint->IsAllowRotation(axis))
                    {
                        if (joint->UpdateLocalRotate(axis))
                        {
                            for (auto j = realIndex; j < mNumJoints; ++j)
                            {
                                auto joint2 = impl->GetJointsSharedPtr(j);

                                joint2->UpdateWorldRotateAndTranslate();
                            }
                        }
                    }
                }
            }
        }

        return true;
    }

    return false;
}

CoreTools::ObjectInterfaceSharedPtr Rendering::IKController::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return Clone();
}
