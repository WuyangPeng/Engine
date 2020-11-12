// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/23 14:08)

#include "Rendering/RenderingExport.h" 

#include "PointControllerImpl.h"
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
using std::vector;

Rendering::PointControllerImpl
	::PointControllerImpl(int numPoints)
    : m_SystemLinearSpeed{ 0.0f }, m_SystemAngularSpeed{ 0.0f }, m_SystemLinearAxis{ Mathematics::FloatAVector::GetUnitZ() }, m_SystemAngularAxis{ Mathematics::FloatAVector::GetUnitZ() }, m_NumPoints{ numPoints },
	 m_PointLinearSpeed(numPoints), m_PointAngularSpeed(numPoints), m_PointLinearAxis(numPoints), m_PointAngularAxis(numPoints)
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::PointControllerImpl ::PointControllerImpl() noexcept
    : m_SystemLinearSpeed{ 0.0f }, m_SystemAngularSpeed{ 0.0f }, m_SystemLinearAxis{ Mathematics::FloatAVector::GetUnitZ() }, m_SystemAngularAxis{ Mathematics::FloatAVector::GetUnitZ() }, m_NumPoints{ 0 },
	 m_PointLinearSpeed{},m_PointAngularSpeed{},m_PointLinearAxis{},m_PointAngularAxis{}
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool Rendering::PointControllerImpl
	::IsValid() const noexcept
{
	if (0 <= m_NumPoints)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT	
 
int Rendering::PointControllerImpl ::GetNumPoints() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_NumPoints;
}

float Rendering::PointControllerImpl
	::GetPointLinearSpeed(int index) const 
{
	RENDERING_CLASS_IS_VALID_CONST_1;
	RENDERING_ASSERTION_0(0 <= index && index < m_NumPoints, "À˜“˝¥ÌŒÛ£°");

	return m_PointLinearSpeed[index];
}

float Rendering::PointControllerImpl
	::GetPointAngularSpeed(int index) const 
{
	RENDERING_CLASS_IS_VALID_CONST_1;
	RENDERING_ASSERTION_0(0 <= index && index < m_NumPoints, "À˜“˝¥ÌŒÛ£°");

	return m_PointAngularSpeed[index];
}

const Rendering::PointControllerImpl::AVector Rendering::PointControllerImpl
	::GetPointLinearAxis(int index) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
	RENDERING_ASSERTION_0(0 <= index && index < m_NumPoints, "À˜“˝¥ÌŒÛ£°");

	return m_PointLinearAxis[index];
}

const Rendering::PointControllerImpl::AVector Rendering::PointControllerImpl
	::GetPointAngularAxis(int index) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
	RENDERING_ASSERTION_0(0 <= index && index < m_NumPoints, "À˜“˝¥ÌŒÛ£°");

	return m_PointAngularAxis[index];
}

void Rendering::PointControllerImpl
	::SetPointLinearSpeed(int index, float pointLinearSpeed)
{
	RENDERING_CLASS_IS_VALID_1;
	RENDERING_ASSERTION_0(0 <= index && index < m_NumPoints, "À˜“˝¥ÌŒÛ£°");

	m_PointLinearSpeed[index] = pointLinearSpeed;
}

void Rendering::PointControllerImpl
	::SetPointAngularSpeed(int index, float pointAngularSpeed)
{
	RENDERING_CLASS_IS_VALID_1;
	RENDERING_ASSERTION_0(0 <= index && index < m_NumPoints, "À˜“˝¥ÌŒÛ£°");

	m_PointAngularSpeed[index] = pointAngularSpeed;
}

void Rendering::PointControllerImpl
	::SetPointLinearAxis(int index, const AVector& pointLinearAxis)
{
	RENDERING_CLASS_IS_VALID_1;
	RENDERING_ASSERTION_0(0 <= index && index < m_NumPoints, "À˜“˝¥ÌŒÛ£°");

	m_PointLinearAxis[index] = pointLinearAxis;
}

void Rendering::PointControllerImpl
	::SetPointAngularAxis(int index, const AVector& pointAngularAxis) 
{
	RENDERING_CLASS_IS_VALID_1;
	RENDERING_ASSERTION_0(0 <= index && index < m_NumPoints, "À˜“˝¥ÌŒÛ£°");

	m_PointAngularAxis[index] = pointAngularAxis;
}

float Rendering::PointControllerImpl ::GetSystemLinearSpeed() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_SystemLinearSpeed;
}

void Rendering::PointControllerImpl ::SetSystemLinearSpeed(float systemLinearSpeed) noexcept
{
	RENDERING_CLASS_IS_VALID_1;

	m_SystemLinearSpeed = systemLinearSpeed;
}

float Rendering::PointControllerImpl ::GetSystemAngularSpeed() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_SystemAngularSpeed;
}

void Rendering::PointControllerImpl ::SetSystemAngularSpeed(float systemAngularSpeed) noexcept
{
	RENDERING_CLASS_IS_VALID_1;

	m_SystemAngularSpeed = systemAngularSpeed;
}

const Rendering::PointControllerImpl::AVector Rendering::PointControllerImpl ::GetSystemLinearAxis() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_SystemLinearAxis;
}

void Rendering::PointControllerImpl ::SetSystemLinearAxis(const AVector& systemLinearAxis) noexcept
{
	RENDERING_CLASS_IS_VALID_1;

	m_SystemLinearAxis = systemLinearAxis;
}

const Rendering::PointControllerImpl::AVector Rendering::PointControllerImpl ::GetSystemAngularAxis() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_SystemAngularAxis;
}

void Rendering::PointControllerImpl ::SetSystemAngularAxis(const AVector& systemAngularAxis) noexcept
{
	RENDERING_CLASS_IS_VALID_1;

	m_SystemAngularAxis = systemAngularAxis;
}
 
void Rendering::PointControllerImpl
	::Load(const CoreTools::BufferSourceSharedPtr& source) 
{
	RENDERING_CLASS_IS_VALID_1;

	source->Read(m_SystemLinearSpeed);
        source->Read(m_SystemAngularSpeed);
        source->ReadAggregate(m_SystemLinearAxis);
        source->ReadAggregate(m_SystemAngularAxis);
        source->Read(m_NumPoints);

	m_PointLinearSpeed.resize(m_NumPoints);
	m_PointAngularSpeed.resize(m_NumPoints);
	m_PointLinearAxis.resize(m_NumPoints);
	m_PointAngularAxis.resize(m_NumPoints);

	//source->Read(m_NumPoints, &m_PointLinearSpeed[0]);
 //       source->Read(m_NumPoints, &m_PointAngularSpeed[0]);
        source->ReadAggregateContainer(m_NumPoints, m_PointLinearAxis);
        source->ReadAggregateContainer(m_NumPoints, m_PointAngularAxis);
} 

void Rendering::PointControllerImpl
	::Save(const CoreTools::BufferTargetSharedPtr& target) const 
{
	RENDERING_CLASS_IS_VALID_CONST_1;

    target->Write(m_SystemLinearSpeed);
	target->Write(m_SystemAngularSpeed);
    target->WriteAggregate(m_SystemLinearAxis);
        target->WriteAggregate(m_SystemAngularAxis);
	target->Write(m_NumPoints);
	//target.WriteWithoutNumber(m_NumPoints, &m_PointLinearSpeed[0]);
	//target.WriteWithoutNumber(m_NumPoints, &m_PointAngularSpeed[0]);
	//target.WriteAggregateWithoutNumber(m_NumPoints, &m_PointLinearAxis[0]);
	//target.WriteAggregateWithoutNumber(m_NumPoints, &m_PointAngularAxis[0]);
}

int Rendering::PointControllerImpl ::GetStreamingSize() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	auto size = CORE_TOOLS_STREAM_SIZE(m_SystemLinearSpeed);

	size += CORE_TOOLS_STREAM_SIZE(m_SystemAngularSpeed);
	size += MATHEMATICS_STREAM_SIZE(m_SystemLinearAxis);
	size += MATHEMATICS_STREAM_SIZE(m_SystemAngularAxis);
	size += CORE_TOOLS_STREAM_SIZE(m_NumPoints);
	size += m_NumPoints * CORE_TOOLS_STREAM_SIZE(m_PointLinearSpeed[0]);
	size += m_NumPoints * CORE_TOOLS_STREAM_SIZE(m_PointAngularSpeed[0]);
	size += m_NumPoints * MATHEMATICS_STREAM_SIZE(m_PointLinearAxis[0]);
	size += m_NumPoints * MATHEMATICS_STREAM_SIZE(m_PointAngularAxis[0]);

    return size;
}


#include STSTEM_WARNING_POP
