///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
///	ÁªÏµ×÷Õß£º94458936@qq.com
///
///	±ê×¼£ºstd:c++20
///	ÒýÇæ°æ±¾£º0.9.0.12 (2023/06/12 14:05)

#include "Rendering/RenderingExport.h"

#include "ParticleControllerImpl.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"
#include "Mathematics/Algebra/AlgebraAggregate.h"
#include "Mathematics/Algebra/AlgebraStreamSize.h"
#include "Rendering/DataTypes/SpecializedIO.h"

Rendering::ParticleControllerImpl::ParticleControllerImpl(int numParticles)
    : systemLinearSpeed{ 0.0f },
      systemAngularSpeed{ 0.0f },
      systemLinearAxis{ Mathematics::AVectorF::GetUnitZ() },
      systemAngularAxis{ Mathematics::AVectorF::GetUnitZ() },
      systemSizeChange{ 0.0f },
      numParticles{ numParticles },
      particleLinearSpeeds(numParticles),
      particleLinearAxes(numParticles),
      particleSizeChanges(numParticles)
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::ParticleControllerImpl::ParticleControllerImpl() noexcept
    : systemLinearSpeed{ 0.0f },
      systemAngularSpeed{ 0.0f },
      systemLinearAxis{ Mathematics::AVectorF::GetUnitZ() },
      systemAngularAxis{ Mathematics::AVectorF::GetUnitZ() },
      systemSizeChange{ 0.0f },
      numParticles{ 0 },
      particleLinearSpeeds{},
      particleLinearAxes{},
      particleSizeChanges{}
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool Rendering::ParticleControllerImpl::IsValid() const noexcept
{
    if (0 <= numParticles)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

int Rendering::ParticleControllerImpl::GetNumParticles() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return numParticles;
}

float Rendering::ParticleControllerImpl::GetSystemLinearSpeed() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return systemLinearSpeed;
}

void Rendering::ParticleControllerImpl::SetSystemLinearSpeed(float aSystemLinearSpeed) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    systemLinearSpeed = aSystemLinearSpeed;
}

float Rendering::ParticleControllerImpl::GetSystemAngularSpeed() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return systemAngularSpeed;
}

void Rendering::ParticleControllerImpl::SetSystemAngularSpeed(float aSystemAngularSpeed) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    systemAngularSpeed = aSystemAngularSpeed;
}

Rendering::ParticleControllerImpl::AVector Rendering::ParticleControllerImpl::GetSystemLinearAxis() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return systemLinearAxis;
}

void Rendering::ParticleControllerImpl::SetSystemLinearAxis(const AVector& aSystemLinearAxis) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    systemLinearAxis = aSystemLinearAxis;
}

Rendering::ParticleControllerImpl::AVector Rendering::ParticleControllerImpl::GetSystemAngularAxis() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return systemAngularAxis;
}

void Rendering::ParticleControllerImpl::SetSystemAngularAxis(const AVector& aSystemAngularAxis) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    systemAngularAxis = aSystemAngularAxis;
}

float Rendering::ParticleControllerImpl::GetSystemSizeChange() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return systemSizeChange;
}

void Rendering::ParticleControllerImpl::SetSystemSizeChange(float aSystemSizeChange) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    systemSizeChange = aSystemSizeChange;
}

float Rendering::ParticleControllerImpl::GetParticleLinearSpeed(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    RENDERING_ASSERTION_0(0 <= index && index < numParticles, "Ë÷Òý´íÎó£¡");

    return particleLinearSpeeds.at(index);
}

Rendering::ParticleControllerImpl::AVector Rendering::ParticleControllerImpl::GetParticleLinearAxis(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    RENDERING_ASSERTION_0(0 <= index && index < numParticles, "Ë÷Òý´íÎó£¡");

    return particleLinearAxes.at(index);
}

float Rendering::ParticleControllerImpl::GetParticleSizeChange(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    RENDERING_ASSERTION_0(0 <= index && index < numParticles, "Ë÷Òý´íÎó£¡");

    return particleSizeChanges.at(index);
}

void Rendering::ParticleControllerImpl::SetParticleLinearSpeed(int index, float particleLinearSpeed)
{
    RENDERING_CLASS_IS_VALID_1;
    RENDERING_ASSERTION_0(0 <= index && index < numParticles, "Ë÷Òý´íÎó£¡");

    particleLinearSpeeds.at(index) = particleLinearSpeed;
}

void Rendering::ParticleControllerImpl::SetParticleLinearAxis(int index, const AVector& particleLinearAxis)
{
    RENDERING_CLASS_IS_VALID_1;
    RENDERING_ASSERTION_0(0 <= index && index < numParticles, "Ë÷Òý´íÎó£¡");

    particleLinearAxes.at(index) = particleLinearAxis;
}

void Rendering::ParticleControllerImpl::SetParticleSizeChange(int index, float particleSizeChange)
{
    RENDERING_CLASS_IS_VALID_1;
    RENDERING_ASSERTION_0(0 <= index && index < numParticles, "Ë÷Òý´íÎó£¡");

    particleSizeChanges.at(index) = particleSizeChange;
}

int Rendering::ParticleControllerImpl::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto size = CoreTools::GetStreamSize(systemLinearSpeed);

    size += CoreTools::GetStreamSize(systemAngularSpeed);
    size += Mathematics::GetStreamSize(systemLinearAxis);
    size += Mathematics::GetStreamSize(systemAngularAxis);
    size += CoreTools::GetStreamSize(systemSizeChange);
    size += CoreTools::GetStreamSize(numParticles);
    size += numParticles * CoreTools::GetStreamSize(particleLinearSpeeds.at(0));
    size += numParticles * Mathematics::GetStreamSize(particleLinearAxes.at(0));
    size += numParticles * CoreTools::GetStreamSize(particleSizeChanges.at(0));

    return size;
}

void Rendering::ParticleControllerImpl::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    target.Write(systemLinearSpeed);
    target.Write(systemAngularSpeed);
    target.WriteAggregate(systemLinearAxis);
    target.WriteAggregate(systemAngularAxis);
    target.Write(systemSizeChange);
    target.Write(numParticles);
    target.WriteContainerWithoutNumber(particleLinearSpeeds);
    target.WriteAggregateContainerWithoutNumber(particleLinearAxes);
    target.WriteContainerWithoutNumber(particleSizeChanges);
}

void Rendering::ParticleControllerImpl::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_1;

    source.Read(systemLinearSpeed);
    source.Read(systemAngularSpeed);
    source.ReadAggregate(systemLinearAxis);
    source.ReadAggregate(systemAngularAxis);
    source.Read(systemSizeChange);
    source.Read(numParticles);

    particleLinearSpeeds.resize(numParticles);
    particleLinearAxes.resize(numParticles);
    particleSizeChanges.resize(numParticles);

    source.ReadContainer(particleLinearSpeeds);
    source.ReadAggregateContainer(numParticles, particleLinearAxes);
    source.ReadContainer(particleSizeChanges);
}
