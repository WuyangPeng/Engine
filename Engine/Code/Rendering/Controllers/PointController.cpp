///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/24 16:26)

#include "Rendering/RenderingExport.h"

#include "PointController.h"
#include "Detail/PointControllerImpl.h"
#include "System/Helper/PragmaWarning.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Mathematics/Algebra/MatrixDetail.h"
#include "Rendering/Resources/Buffers/Buffer.h"
#include "Rendering/SceneGraph/Polypoint.h"
#include "Rendering/SceneGraph/Visual.h"

CORE_TOOLS_RTTI_DEFINE(Rendering, PointController);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, PointController);
CORE_TOOLS_ABSTRACT_FACTORY_DEFINE(Rendering, PointController);

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, PointController)

Rendering::PointController::PointController(const BaseRendererSharedPtr& baseRenderer)
    : ParentType{ CoreTools::DisableNotThrow::Disable }, impl{ baseRenderer }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, PointController)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, PointController, GetNumPoints, int)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, PointController, GetPointLinearSpeed, int, float)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, PointController, GetPointAngularSpeed, int, float)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, PointController, GetPointLinearAxis, int, Rendering::PointController::AVector)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, PointController, GetPointAngularAxis, int, Rendering::PointController::AVector)

void Rendering::PointController::SetPointLinearSpeed(int index, float pointLinearSpeed)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetPointLinearSpeed(index, pointLinearSpeed);
}

void Rendering::PointController::SetPointAngularSpeed(int index, float pointAngularSpeed)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetPointAngularSpeed(index, pointAngularSpeed);
}

void Rendering::PointController::SetPointLinearAxis(int index, const AVector& pointLinearAxis)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetPointLinearAxis(index, pointLinearAxis);
}

void Rendering::PointController::SetPointAngularAxis(int index, const AVector& pointAngularAxis)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetPointAngularAxis(index, pointAngularAxis);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, PointController, GetSystemLinearSpeed, float)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Rendering, PointController, SetSystemLinearSpeed, float, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, PointController, GetSystemAngularSpeed, float)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Rendering, PointController, SetSystemAngularSpeed, float, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, PointController, GetSystemLinearAxis, Rendering::PointController::AVector)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR_NOEXCEPT(Rendering, PointController, SetSystemLinearAxis, AVector, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, PointController, GetSystemAngularAxis, Rendering::PointController::AVector)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR_NOEXCEPT(Rendering, PointController, SetSystemAngularAxis, AVector, void)

void Rendering::PointController::SetControllerObject(const ControllerInterfaceSharedPtr& object)
{
    RENDERING_CLASS_IS_VALID_1;
    RENDERING_ASSERTION_0(object == nullptr || object->IsDerived(Visual::GetCurrentRttiType()), "无效类\n");

    const auto visual = boost::polymorphic_pointer_cast<Visual>(object);

    impl->SetControllerObject(*visual);

    ParentType::SetControllerObject(object);
}

void Rendering::PointController::UpdateSystemMotion(float ctrlTime)
{
    const auto visual = boost::polymorphic_pointer_cast<Visual>(GetControllerObject());

    impl->UpdateSystemMotion(*visual, ctrlTime);
}

void Rendering::PointController::UpdatePointMotion(float ctrlTime)
{
    const auto visual = boost::polymorphic_pointer_cast<Visual>(GetControllerObject());

    impl->UpdatePointMotion(*visual, ctrlTime);
}

bool Rendering::PointController::Update(double applicationTime)
{
    RENDERING_CLASS_IS_VALID_1;

    if (Controller::Update(applicationTime))
    {
        const auto ctrlTime = boost::numeric_cast<float>(GetControlTime(applicationTime));

        UpdateSystemMotion(ctrlTime);
        UpdatePointMotion(ctrlTime);

        return true;
    }

    return false;
}

Rendering::PointController::PointController(LoadConstructor loadConstructor)
    : ParentType{ loadConstructor }, impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

int Rendering::PointController::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto size = ParentType::GetStreamingSize();

    size += impl->GetStreamingSize();

    return size;
}

int64_t Rendering::PointController::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return ParentType::Register(target);
}

void Rendering::PointController::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    ParentType::Save(target);

    impl->Save(target);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::PointController::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::Link(source);
}

void Rendering::PointController::PostLink()
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::PostLink();
}

void Rendering::PointController::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);

    impl->Load(source);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}
