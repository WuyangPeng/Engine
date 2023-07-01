///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 14:06)

#include "Rendering/RenderingExport.h"

#include "ParticleController.h"
#include "Detail/ParticleControllerImpl.h"
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

Rendering::ParticleController::ParticleController(CoreTools::DisableNotThrow disableNotThrow)
    : ParentType{ disableNotThrow }, impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }, particles{ nullptr }
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
        auto ctrlTime = boost::numeric_cast<float>(GetControlTime(applicationTime));

        UpdateSystemMotion(ctrlTime);
        UpdatePointMotion(ctrlTime);

        return true;
    }

    return false;
}

void Rendering::ParticleController::SetObject(ControllerInterface* object)
{
    RENDERING_CLASS_IS_VALID_1;

    RENDERING_ASSERTION_0(object == nullptr || object->IsDerived(Particles::GetCurrentRttiType()), "无效类\n");

    ParentType::SetObject(object);

    if (object != nullptr)
    {
        particles = dynamic_cast<Particles*>(object);
        Reallocate(particles->GetNumParticles());
    }
    else
    {
        particles = nullptr;
        Reallocate(0);
    }
}

void Rendering::ParticleController::SetObjectInCopy(ControllerInterface* object)
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::SetObject(object);
}

void Rendering::ParticleController::Reallocate(int numParticles)
{
    RENDERING_CLASS_IS_VALID_1;

    if (0 < numParticles)
        impl = PackageType{ numParticles };
    else
        impl = PackageType{ CoreTools::ImplCreateUseDefaultConstruction::Default };
}

void Rendering::ParticleController::UpdateSystemMotion(float ctrlTime)
{
    RENDERING_CLASS_IS_VALID_1;

    if (particles != nullptr)
    {
        const auto dSize = ctrlTime * GetSystemSizeChange();
        particles->SetSizeAdjust(particles->GetSizeAdjust() + dSize);
        if (particles->GetSizeAdjust() < 0.0f)
        {
            particles->SetSizeAdjust(0.0f);
        }

        const auto distance = ctrlTime * GetSystemLinearSpeed();
        auto deltaTrn = distance * GetSystemLinearAxis();
        auto localTransform = particles->GetLocalTransform();
        const auto translate = localTransform.GetTranslate() + deltaTrn;
        localTransform.SetTranslate(translate);

        const auto angle = ctrlTime * GetSystemAngularSpeed();
        const Mathematics::MatrixF deltaRot{ GetSystemAngularAxis(), angle };
        const auto rotate = deltaRot * localTransform.GetRotate();
        localTransform.SetRotate(rotate);

        particles->SetLocalTransform(localTransform);
    }
}

void Rendering::ParticleController::UpdatePointMotion(float ctrlTime)
{
    RENDERING_CLASS_IS_VALID_1;

    if (particles != nullptr)
    {
        const auto numActive = particles->GetNumActive();
        for (auto i = 0; i < numActive; ++i)
        {
            auto position = particles->GetParticlesPosition(i);
            auto size = particles->GetSize(i);

            const auto dSize = ctrlTime * GetParticleSizeChange(i);
            size += dSize;
            const auto distance = ctrlTime * GetParticleLinearSpeed(i);
            auto deltaTrn = distance * GetParticleLinearAxis(i);
            position += deltaTrn;

            particles->SetPosition(i, position);
            particles->SetSize(i, size);
        }
    }
}

Rendering::ParticleController::ParticleController(LoadConstructor value)
    : ParentType{ value }, impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }, particles{ nullptr }
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

    auto object = GetControllerObject();

    RENDERING_ASSERTION_0(object == nullptr || object->IsDerived(Particles::GetCurrentRttiType()), "无效类\n");

    particles = dynamic_cast<Particles*>(object);
}

void Rendering::ParticleController::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);

    impl->Load(source);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}
