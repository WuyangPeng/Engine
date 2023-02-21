///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/06 11:21)

#include "Rendering/RenderingExport.h"

#include "ControllerImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Mathematics/Base/MathDetail.h"
#include "Rendering/Controllers/ControllerInterface.h"

Rendering::ControllerImpl::ControllerImpl() noexcept
    : controllerRepeat{ ControllerRepeatType::Clamp }, controllerMinTime{ 0.0 }, controllerMaxTime{ 0.0 }, controllerPhase{ 0.0 }, controllerFrequency{ 1.0 }, controllerActive{ true }, controllerApplicationTime{ -Mathematics::MathD::maxReal }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool Rendering::ControllerImpl::IsValid() const noexcept
{
    if (controllerMinTime <= controllerMaxTime)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

void Rendering::ControllerImpl::SetApplicationTime(double applicationTime) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    controllerApplicationTime = applicationTime;
}

double Rendering::ControllerImpl::GetApplicationTime() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return controllerApplicationTime;
}

bool Rendering::ControllerImpl::Update(double applicationTime) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    if (controllerActive)
    {
        controllerApplicationTime = applicationTime;

        return true;
    }

    return false;
}

double Rendering::ControllerImpl::GetControlTime(double applicationTime)
{
    RENDERING_CLASS_IS_VALID_1;

    const auto controlTime = controllerFrequency * applicationTime + controllerPhase;

    if (controllerRepeat == ControllerRepeatType::Clamp)
    {
        // 截断时间在间隔[min,max]
        if (controlTime < controllerMinTime)
        {
            return controllerMinTime;
        }
        if (controllerMaxTime < controlTime)
        {
            return controllerMaxTime;
        }

        return controlTime;
    }

    const auto timeRange = controllerMaxTime - controllerMinTime;
    if (0.0 < timeRange)
    {
        const auto multiples = (controlTime - controllerMinTime) / timeRange;
        auto integerTime = Math::Floor(multiples);
        const auto fractionTime = multiples - integerTime;
        if (controllerRepeat == ControllerRepeatType::Wrap)
        {
            return controllerMinTime + fractionTime * timeRange;
        }

        // controllerRepeat == ControllerRepeatType::ClampCycle
        if (boost::numeric_cast<int>(integerTime) & 1)
        {
            // 时间向后走。
            return controllerMaxTime - fractionTime * timeRange;
        }
        else
        {
            // 时间向前走。
            return controllerMinTime + fractionTime * timeRange;
        }
    }

    // 最小值和最大值是相等的，所以返回最小值。
    return controllerMinTime;
}

Rendering::ControllerRepeatType Rendering::ControllerImpl::GetRepeat() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return controllerRepeat;
}

double Rendering::ControllerImpl::GetMinTime() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return controllerMinTime;
}

double Rendering::ControllerImpl::GetMaxTime() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return controllerMaxTime;
}

double Rendering::ControllerImpl::GetPhase() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return controllerPhase;
}

double Rendering::ControllerImpl::GetFrequency() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return controllerFrequency;
}

bool Rendering::ControllerImpl::IsActive() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return controllerActive;
}

void Rendering::ControllerImpl::SetRepeat(ControllerRepeatType repeat) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    controllerRepeat = repeat;
}

void Rendering::ControllerImpl::SetTime(double minTime, double maxTime) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    controllerMinTime = minTime;
    controllerMaxTime = maxTime;
}

void Rendering::ControllerImpl::SetPhase(double phase) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    controllerPhase = phase;
}

void Rendering::ControllerImpl::SetFrequency(double frequency) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    controllerFrequency = frequency;
}

void Rendering::ControllerImpl::SetActive(bool active) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    controllerActive = active;
}

void Rendering::ControllerImpl::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_1;

    source.ReadEnum(controllerRepeat);
    source.Read(controllerMinTime);
    source.Read(controllerMaxTime);
    source.Read(controllerPhase);
    source.Read(controllerFrequency);
    controllerActive = source.ReadBool();

    controllerApplicationTime = -Mathematics::MathD::maxReal;
}

void Rendering::ControllerImpl::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    target.WriteEnum(controllerRepeat);
    target.Write(controllerMinTime);
    target.Write(controllerMaxTime);
    target.Write(controllerPhase);
    target.Write(controllerFrequency);
    target.Write(controllerActive);
}

int Rendering::ControllerImpl::GetStreamingSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto size = CoreTools::GetStreamSize(controllerRepeat);
    size += CoreTools::GetStreamSize(controllerMinTime);
    size += CoreTools::GetStreamSize(controllerMaxTime);
    size += CoreTools::GetStreamSize(controllerPhase);
    size += CoreTools::GetStreamSize(controllerFrequency);
    size += CoreTools::GetStreamSize(controllerActive);

    return size;
}
