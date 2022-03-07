// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/23 14:06)

#include "Rendering/RenderingExport.h" 

#include "ParticleControllerImpl.h"
#include "Rendering/DataTypes/SpecializedIO.h"
#include "Mathematics/Algebra/AlgebraAggregate.h"
#include "Mathematics/Algebra/AlgebraStreamSize.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"

#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26415)
#include SYSTEM_WARNING_DISABLE(26418)
Rendering::ParticleControllerImpl
	::ParticleControllerImpl(int numParticles)
    : m_SystemLinearSpeed{ 0.0f }, m_SystemAngularSpeed{ 0.0f }, m_SystemLinearAxis{ Mathematics::AVectorF::GetUnitZ() }, m_SystemAngularAxis{ Mathematics::AVectorF::GetUnitZ() }, m_SystemSizeChange{ 0.0f },
	 m_NumParticles{ numParticles }, m_ParticleLinearSpeed(numParticles), m_ParticleLinearAxis(numParticles), m_ParticleSizeChange(numParticles)
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::ParticleControllerImpl
	::ParticleControllerImpl() noexcept
    : m_SystemLinearSpeed{ 0.0f }, m_SystemAngularSpeed{ 0.0f }, m_SystemLinearAxis{ Mathematics::AVectorF::GetUnitZ() }, m_SystemAngularAxis{ Mathematics::AVectorF::GetUnitZ() }, m_SystemSizeChange{ 0.0f },
	 m_NumParticles{ 0 },m_ParticleLinearSpeed{},m_ParticleLinearAxis{},m_ParticleSizeChange{}
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool Rendering::ParticleControllerImpl
	::IsValid() const noexcept
{
	if (0 <= m_NumParticles)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT	


int Rendering::ParticleControllerImpl ::GetNumParticles() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_NumParticles;
}

float Rendering::ParticleControllerImpl ::GetSystemLinearSpeed() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_SystemLinearSpeed;
}

void Rendering::ParticleControllerImpl ::SetSystemLinearSpeed(float systemLinearSpeed) noexcept
{
	RENDERING_CLASS_IS_VALID_1;

	m_SystemLinearSpeed = systemLinearSpeed;
}

float Rendering::ParticleControllerImpl ::GetSystemAngularSpeed() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_SystemAngularSpeed;
}

void Rendering::ParticleControllerImpl ::SetSystemAngularSpeed(float systemAngularSpeed) noexcept
{
	RENDERING_CLASS_IS_VALID_1;

	m_SystemAngularSpeed = systemAngularSpeed;
}

const Rendering::ParticleControllerImpl::AVector Rendering::ParticleControllerImpl ::GetSystemLinearAxis() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_SystemLinearAxis;
}

void Rendering::ParticleControllerImpl ::SetSystemLinearAxis(const AVector& systemLinearAxis) noexcept
{
	RENDERING_CLASS_IS_VALID_1;

	m_SystemLinearAxis = systemLinearAxis;
}

const Rendering::ParticleControllerImpl::AVector Rendering::ParticleControllerImpl ::GetSystemAngularAxis() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_SystemAngularAxis;
}

void Rendering::ParticleControllerImpl ::SetSystemAngularAxis(const AVector& systemAngularAxis) noexcept
{
	RENDERING_CLASS_IS_VALID_1;

	m_SystemAngularAxis = systemAngularAxis;
}

float Rendering::ParticleControllerImpl ::GetSystemSizeChange() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_SystemSizeChange;
}

void Rendering::ParticleControllerImpl ::SetSystemSizeChange(float systemSizeChange) noexcept
{
	RENDERING_CLASS_IS_VALID_1;

	m_SystemSizeChange = systemSizeChange;
}

float Rendering::ParticleControllerImpl
	::GetParticleLinearSpeed(int index) const 
{
	RENDERING_CLASS_IS_VALID_CONST_1;
	RENDERING_ASSERTION_0(0 <= index && index < m_NumParticles, "À˜“˝¥ÌŒÛ£°");

	return m_ParticleLinearSpeed[index];
}

const Rendering::ParticleControllerImpl::AVector Rendering::ParticleControllerImpl
	::GetParticleLinearAxis(int index) const 
{
	RENDERING_CLASS_IS_VALID_CONST_1;
	RENDERING_ASSERTION_0(0 <= index && index < m_NumParticles, "À˜“˝¥ÌŒÛ£°");

	return m_ParticleLinearAxis[index];
}

float Rendering::ParticleControllerImpl
	::GetParticleSizeChange(int index) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
	RENDERING_ASSERTION_0(0 <= index && index < m_NumParticles, "À˜“˝¥ÌŒÛ£°");

	return m_ParticleSizeChange[index];
}

void Rendering::ParticleControllerImpl
	::SetParticleLinearSpeed(int index, float particleLinearSpeed) 
{
	RENDERING_CLASS_IS_VALID_1;
	RENDERING_ASSERTION_0(0 <= index && index < m_NumParticles, "À˜“˝¥ÌŒÛ£°");

	m_ParticleLinearSpeed[index] = particleLinearSpeed;
}

void Rendering::ParticleControllerImpl
	::SetParticleLinearAxis(int index, const AVector& particleLinearAxis)
{
	RENDERING_CLASS_IS_VALID_1;
	RENDERING_ASSERTION_0(0 <= index && index < m_NumParticles, "À˜“˝¥ÌŒÛ£°");

	m_ParticleLinearAxis[index] = particleLinearAxis;
}

void Rendering::ParticleControllerImpl
	::SetParticleSizeChange(int index, float particleSizeChange) 
{
	RENDERING_CLASS_IS_VALID_1;
	RENDERING_ASSERTION_0(0 <= index && index < m_NumParticles, "À˜“˝¥ÌŒÛ£°");

	m_ParticleSizeChange[index] = particleSizeChange;
}

int Rendering::ParticleControllerImpl
	::GetStreamingSize() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	auto size = CORE_TOOLS_STREAM_SIZE(m_SystemLinearSpeed);

	size += CORE_TOOLS_STREAM_SIZE(m_SystemAngularSpeed);
	size += MATHEMATICS_STREAM_SIZE(m_SystemLinearAxis);
	size += MATHEMATICS_STREAM_SIZE(m_SystemAngularAxis);
	size += CORE_TOOLS_STREAM_SIZE(m_SystemSizeChange);
	size += CORE_TOOLS_STREAM_SIZE(m_NumParticles);
	size += m_NumParticles * CORE_TOOLS_STREAM_SIZE(m_ParticleLinearSpeed[0]);
	size += m_NumParticles * MATHEMATICS_STREAM_SIZE(m_ParticleLinearAxis[0]);
	size += m_NumParticles * CORE_TOOLS_STREAM_SIZE(m_ParticleSizeChange[0]);
 
    return size;
}

void Rendering::ParticleControllerImpl
	::Save(CoreTools::BufferTarget& target) const 
{
	RENDERING_CLASS_IS_VALID_CONST_1;

    target.Write(m_SystemLinearSpeed);
	target.Write(m_SystemAngularSpeed);
    target.WriteAggregate(m_SystemLinearAxis);
        target.WriteAggregate(m_SystemAngularAxis);
	target.Write(m_SystemSizeChange);
	target.Write(m_NumParticles);
        target.WriteContainerWithoutNumber(m_ParticleLinearSpeed); 
	//target.WriteAggregateWithoutNumber(m_NumParticles, &m_ParticleLinearAxis[0]);
//	target.WriteWithoutNumber(m_NumParticles, &m_ParticleSizeChange[0]);
}

void Rendering::ParticleControllerImpl
	::Load(CoreTools::BufferSource& source)
{
	RENDERING_CLASS_IS_VALID_1;
	
	source.Read(m_SystemLinearSpeed);
        source.Read(m_SystemAngularSpeed);
        source.ReadAggregate(m_SystemLinearAxis);
        source.ReadAggregate(m_SystemAngularAxis);
        source.Read(m_SystemSizeChange);
        source.Read(m_NumParticles);

	m_ParticleLinearSpeed.resize(m_NumParticles);
	m_ParticleLinearAxis.resize(m_NumParticles);
	m_ParticleSizeChange.resize(m_NumParticles); 

//	source.Read(m_NumParticles, &m_ParticleLinearSpeed[0]);
        source.ReadAggregateContainer(m_NumParticles, m_ParticleLinearAxis);
   //     source.Read(m_NumParticles, &m_ParticleSizeChange[0]);
}





#include STSTEM_WARNING_POP