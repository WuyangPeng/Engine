///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/24 19:02)

#include "Rendering/RenderingExport.h"

#include "ParticleController.h"
#include "Detail/ParticleControllerImpl.h"
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
#include "Rendering/SceneGraph/Particles.h"
#include "Rendering/SceneGraph/Visual.h"

CORE_TOOLS_RTTI_DEFINE(Rendering, ParticleController);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, ParticleController);
CORE_TOOLS_ABSTRACT_FACTORY_DEFINE(Rendering, ParticleController);

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, ParticleController)

Rendering::ParticleController::ParticleController(const BaseRendererSharedPtr& baseRenderer)
    : ParentType{ "ParticleController" }, impl{ baseRenderer }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, ParticleController)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, ParticleController, GetNumParticles, int)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, ParticleController, GetSystemLinearSpeed, float)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Rendering, ParticleController, SetSystemLinearSpeed, float, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, ParticleController, GetSystemAngularSpeed, float)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Rendering, ParticleController, SetSystemAngularSpeed, float, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, ParticleController, GetSystemLinearAxis, Rendering::ParticleController::AVector)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR_NOEXCEPT(Rendering, ParticleController, SetSystemLinearAxis, AVector, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, ParticleController, GetSystemAngularAxis, Rendering::ParticleController::AVector)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR_NOEXCEPT(Rendering, ParticleController, SetSystemAngularAxis, AVector, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, ParticleController, GetSystemSizeChange, float)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Rendering, ParticleController, SetSystemSizeChange, float, void)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, ParticleController, GetParticleLinearSpeed, int, float)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, ParticleController, GetParticleLinearAxis, int, Rendering::ParticleController::AVector)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, ParticleController, GetParticleSizeChange, int, float)

void Rendering::ParticleController::SetParticleLinearSpeed(int index, float particleLinearSpeed)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetParticleLinearSpeed(index, particleLinearSpeed);
}

void Rendering::ParticleController::SetParticleLinearAxis(int index, const AVector& particleLinearAxis)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetParticleLinearAxis(index, particleLinearAxis);
}

void Rendering::ParticleController::SetParticleSizeChange(int index, float particleSizeChange)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetParticleSizeChange(index, particleSizeChange);
}

bool Rendering::ParticleController::Update(double applicationTime)
{
    RENDERING_CLASS_IS_VALID_1;

    if (ParentType::Update(applicationTime))
    {
        const auto ctrlTime = boost::numeric_cast<float>(GetControlTime(applicationTime));

        UpdateSystemMotion(ctrlTime);
        UpdatePointMotion(ctrlTime);

        return true;
    }

    return false;
}

void Rendering::ParticleController::SetCamera(const std::shared_ptr<Camera>& aCamera) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetCamera(aCamera);
}

std::shared_ptr<Rendering::Camera> Rendering::ParticleController::GetCamera() noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetCamera();
}

void Rendering::ParticleController::SetController(const ControllerSharedPtr& object)
{
    RENDERING_CLASS_IS_VALID_1;

    RENDERING_ASSERTION_0(object == nullptr || object->IsDerived(Particles::GetCurrentRttiType()), "无效类\n");

    const auto visual = boost::polymorphic_pointer_cast<Visual>(object);

    impl->SetControllerObject(*visual);

    ParentType::SetController(object);
}

void Rendering::ParticleController::UpdateSystemMotion(float ctrlTime)
{
    RENDERING_CLASS_IS_VALID_1;

    const auto visual = boost::polymorphic_pointer_cast<Particles>(GetController());

    impl->UpdateSystemMotion(*visual, ctrlTime);
}

void Rendering::ParticleController::UpdatePointMotion(float ctrlTime)
{
    RENDERING_CLASS_IS_VALID_1;

    const auto visual = boost::polymorphic_pointer_cast<Particles>(GetController());

    impl->UpdatePointMotion(*visual, ctrlTime);
}

Rendering::ParticleController::ParticleController(LoadConstructor value)
    : ParentType{ value }, impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

int Rendering::ParticleController::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto size = ParentType::GetStreamingSize();

    size += impl->GetStreamingSize();

    return size;
}

int64_t Rendering::ParticleController::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return ParentType::Register(target);
}

void Rendering::ParticleController::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    ParentType::Save(target);

    impl->Save(target);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::ParticleController::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::Link(source);
}

void Rendering::ParticleController::PostLink()
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::PostLink();
}

void Rendering::ParticleController::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);

    impl->Load(source);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}
