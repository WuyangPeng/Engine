///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 14:06)

#include "Rendering/RenderingExport.h"

#include "PointController.h"
#include "Detail/PointControllerImpl.h"
#include "System/Helper/PragmaWarning.h"
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

Rendering::PointController::PointController(CoreTools::DisableNotThrow disableNotThrow)
    : ParentType{ disableNotThrow }, impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }, points{ nullptr }
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

void Rendering::PointController::Reallocate(int numPoints)
{
    RENDERING_CLASS_IS_VALID_1;

    if (0 < numPoints)
        impl = PackageType{ numPoints };
    else
        impl = PackageType{ CoreTools::ImplCreateUseDefaultConstruction::Default };
}

void Rendering::PointController::SetObject(ControllerInterface* object)
{
    RENDERING_CLASS_IS_VALID_1;
    RENDERING_ASSERTION_0(object == nullptr || object->IsDerived(Visual::GetCurrentRttiType()), "无效类\n");

    ParentType::SetObject(object);

    if (object != nullptr)
    {
        points = dynamic_cast<Polypoint*>(object);
        Reallocate(points->GetVertexBuffer()->GetNumElements());
    }
    else
    {
        points = nullptr;
        Reallocate(0);
    }
}

void Rendering::PointController::SetObjectInCopy(ControllerInterface* object)
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::SetObject(object);
}

bool Rendering::PointController::Update(double applicationTime)
{
    RENDERING_CLASS_IS_VALID_1;

    if (Controller::Update(applicationTime))
    {
        auto ctrlTime = boost::numeric_cast<float>(GetControlTime(applicationTime));

        UpdateSystemMotion(ctrlTime);
        UpdatePointMotion(ctrlTime);

        return true;
    }

    return false;
}

void Rendering::PointController::UpdateSystemMotion(float ctrlTime)
{
    RENDERING_CLASS_IS_VALID_1;

    if (points != nullptr)
    {
        const auto distance = ctrlTime * GetSystemLinearSpeed();
        auto deltaTrn = distance * GetSystemLinearAxis();
        auto localTransform = points->GetLocalTransform();
        const auto translate = localTransform.GetTranslate() + deltaTrn;
        localTransform.SetTranslate(translate);

        const auto angle = ctrlTime * GetSystemAngularSpeed();
        const Mathematics::MatrixF deltaRot{ GetSystemAngularAxis(), angle };
        const auto rotate = deltaRot * localTransform.GetRotate();
        localTransform.SetRotate(rotate);

        points->SetLocalTransform(localTransform);
    }
}

void Rendering::PointController::UpdatePointMotion(float ctrlTime)
{
    RENDERING_CLASS_IS_VALID_1;

    if (points != nullptr)
    {
        VertexBuffer vba = *points->GetVertexBuffer();

        const auto numPoints = points->GetNumPoints();
        for (auto i = 0; i < numPoints; ++i)
        {
            const auto distance = ctrlTime * GetPointLinearSpeed(i);

            auto deltaTrn = distance * GetPointLinearAxis(i);
        }

        
    }
}

Rendering::PointController::PointController(LoadConstructor value)
    : ParentType{ value }, impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }, points{ nullptr }
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

    auto object = GetControllerObject();

    RENDERING_ASSERTION_0(object == nullptr || object->IsDerived(Visual::GetCurrentRttiType()), "无效类\n");

    points = dynamic_cast<Polypoint*>(object);
}

void Rendering::PointController::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);

    impl->Load(source);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}
