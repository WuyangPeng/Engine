// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/23 10:51)

#include "Rendering/RenderingExport.h"

#include "ControllerImpl.h"
#include "Mathematics/Base/MathDetail.h"
#include "Rendering/Controllers/ControllerInterface.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26418)
#include SYSTEM_WARNING_DISABLE(26415)
Rendering::ControllerImpl
    ::ControllerImpl () noexcept
	:m_Repeat{ ControllerRepeatType::Clamp }, m_MinTime{ 0.0 }, m_MaxTime{ 0.0 }, m_Phase{ 0.0 }, m_Frequency{ 1.0 }, m_Active{ true }, m_ApplicationTime{ -Mathematics::DoubleMath::sm_MaxReal }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

 

#ifdef OPEN_CLASS_INVARIANT
bool Rendering::ControllerImpl
    ::IsValid() const noexcept
{
    if(m_MinTime <= m_MaxTime)
        return true;
    else
        return false;
}
#endif // OPEN_CLASS_INVARIANT

void Rendering::ControllerImpl 
    ::SetApplicationTime(double applicationTime) noexcept
{
    RENDERING_CLASS_IS_VALID_1;
    
    m_ApplicationTime = applicationTime;
}

double Rendering::ControllerImpl ::GetApplicationTime() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    
    return m_ApplicationTime;
}

bool Rendering::ControllerImpl ::Update(double applicationTime) noexcept
{
    RENDERING_CLASS_IS_VALID_1;
    
    if (m_Active)
    {
        m_ApplicationTime = applicationTime;
        return true;
    }
    
    return false;
}

double Rendering::ControllerImpl
    ::GetControlTime (double applicationTime)
{
    RENDERING_CLASS_IS_VALID_1;
    
   const  auto controlTime = m_Frequency * applicationTime + m_Phase;

    if (m_Repeat == ControllerRepeatType::Clamp)
    {
        // 截断时间在间隔[min,max]
        if (controlTime < m_MinTime)
        {
            return m_MinTime;
        }
        if (m_MaxTime < controlTime)
        {
            return m_MaxTime;
        }
        return controlTime;
    }

	const auto timeRange = m_MaxTime - m_MinTime;
    if (0.0 < timeRange)
    {
        const auto multiples = (controlTime - m_MinTime) / timeRange;
		auto integerTime = Math::Floor(multiples);
        const auto fractionTime = multiples - integerTime;
        if (m_Repeat == ControllerRepeatType::Wrap)
        {
            return m_MinTime + fractionTime * timeRange;
        }
    
        // m_Repeat == ControllerRepeatType::ClampCycle
        if (boost::numeric_cast<int>(integerTime) & 1)
        {
            // 时间向后走。
            return m_MaxTime - fractionTime * timeRange;
        }
        else
        {
            // 时间向前走。
            return m_MinTime + fractionTime * timeRange;
        }
    }
    
    
    // 最小值和最大值是相等的，所以返回最小值。
    return m_MinTime;
}
            
Rendering::ControllerRepeatType  Rendering::ControllerImpl
      ::GetRepeat() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    
    return m_Repeat;
}

double Rendering::ControllerImpl ::GetMinTime() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    
    return m_MinTime;
}

double Rendering::ControllerImpl ::GetMaxTime() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    
    return m_MaxTime;
}

double Rendering::ControllerImpl ::GetPhase() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    
    return m_Phase;
}

double Rendering::ControllerImpl ::GetFrequency() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    
    return m_Frequency;
}

bool Rendering::ControllerImpl ::IsActive() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    
    return m_Active;
}
            
void Rendering::ControllerImpl ::SetRepeat(ControllerRepeatType repeat) noexcept
{
    RENDERING_CLASS_IS_VALID_1;
    
    m_Repeat = repeat;
}

void Rendering::ControllerImpl ::SetTime(double minTime, double maxTime) noexcept
{
    RENDERING_CLASS_IS_VALID_1;
    
    m_MinTime = minTime;
	m_MaxTime = maxTime;
}

void Rendering::ControllerImpl ::SetPhase(double phase) noexcept
{
    RENDERING_CLASS_IS_VALID_1;
    
    m_Phase = phase;
}

void Rendering::ControllerImpl ::SetFrequency(double frequency) noexcept
{
    RENDERING_CLASS_IS_VALID_1;
    
    m_Frequency = frequency;
}

void Rendering::ControllerImpl ::SetActive(bool active) noexcept
{
    RENDERING_CLASS_IS_VALID_1;
    
    m_Active = active;
}

void Rendering::ControllerImpl ::Load(const CoreTools::BufferSourceSharedPtr& source)
{
	RENDERING_CLASS_IS_VALID_1;
    
    source->ReadEnum(m_Repeat);
    source->Read(m_MinTime);
    source->Read(m_MaxTime);
    source->Read(m_Phase);
    source->Read(m_Frequency);
    m_Active = source->ReadBool();
    
    m_ApplicationTime = -Mathematics::DoubleMath::sm_MaxReal;
}

void Rendering::ControllerImpl
    ::Save( const CoreTools::BufferTargetSharedPtr& target ) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    
	target->WriteEnum(m_Repeat);
        target->Write(m_MinTime);
        target->Write(m_MaxTime);
        target->Write(m_Phase);
        target->Write(m_Frequency);
        target->Write(m_Active);
}

int Rendering::ControllerImpl ::GetStreamingSize() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    
	auto size = CORE_TOOLS_STREAM_SIZE(m_Repeat);
	size += CORE_TOOLS_STREAM_SIZE(m_MinTime);
	size += CORE_TOOLS_STREAM_SIZE(m_MaxTime);
	size += CORE_TOOLS_STREAM_SIZE(m_Phase);
    size += CORE_TOOLS_STREAM_SIZE(m_Frequency);
    size += CORE_TOOLS_STREAM_SIZE(m_Active);
    
	return size;
}


#include STSTEM_WARNING_POP