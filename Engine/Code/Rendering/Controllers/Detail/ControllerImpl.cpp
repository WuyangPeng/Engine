/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/20 16:42)

#include "Rendering/RenderingExport.h"

#include "ControllerImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Mathematics/Base/MathDetail.h"
#include "Rendering/Controllers/ControllerInterface.h"

Rendering::ControllerImpl::ControllerImpl() noexcept
    : repeat{ ControllerRepeatType::Clamp },
      minTime{ 0.0 },
      maxTime{ 0.0 },
      phase{ 0.0 },
      frequency{ 1.0 },
      active{ true },
      applicationTime{ -Mathematics::MathD::maxReal },
      controller{}
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool Rendering::ControllerImpl::IsValid() const noexcept
{
    if (minTime <= maxTime)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

void Rendering::ControllerImpl::SetApplicationTime(double aApplicationTime) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    applicationTime = aApplicationTime;
}

double Rendering::ControllerImpl::GetApplicationTime() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return applicationTime;
}

bool Rendering::ControllerImpl::Update(double aApplicationTime) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    if (active)
    {
        applicationTime = aApplicationTime;

        return true;
    }

    return false;
}

double Rendering::ControllerImpl::GetControlTime(double aApplicationTime) const
{
    RENDERING_CLASS_IS_VALID_1;

    const auto controlTime = frequency * aApplicationTime + phase;

    if (repeat == ControllerRepeatType::Clamp)
    {
        // 截断时间在间隔[min,max]
        if (controlTime < minTime)
        {
            return minTime;
        }
        if (maxTime < controlTime)
        {
            return maxTime;
        }

        return controlTime;
    }

    if (const auto timeRange = maxTime - minTime;
        0.0 < timeRange)
    {
        const auto multiples = (controlTime - minTime) / timeRange;
        const auto integerTime = MathType::Floor(multiples);
        const auto fractionTime = multiples - integerTime;
        if (repeat == ControllerRepeatType::Wrap)
        {
            return minTime + fractionTime * timeRange;
        }

        // repeat == ControllerRepeatType::ClampCycle
        if ((boost::numeric_cast<int>(integerTime) & 1) != 0)
        {
            // 时间向后走。
            return maxTime - fractionTime * timeRange;
        }
        else
        {
            // 时间向前走。
            return minTime + fractionTime * timeRange;
        }
    }

    // 最小值和最大值是相等的，所以返回最小值。
    return minTime;
}

Rendering::ControllerRepeatType Rendering::ControllerImpl::GetRepeat() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return repeat;
}

double Rendering::ControllerImpl::GetMinTime() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return minTime;
}

double Rendering::ControllerImpl::GetMaxTime() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return maxTime;
}

double Rendering::ControllerImpl::GetPhase() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return phase;
}

double Rendering::ControllerImpl::GetFrequency() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return frequency;
}

bool Rendering::ControllerImpl::IsActive() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return active;
}

void Rendering::ControllerImpl::SetRepeat(ControllerRepeatType aRepeat) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    repeat = aRepeat;
}

void Rendering::ControllerImpl::SetTime(double aMinTime, double aMaxTime)
{
    RENDERING_CLASS_IS_VALID_1;

    if (minTime > maxTime)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("设置最小时间大于最大时间。"))
    }

    minTime = aMinTime;
    maxTime = aMaxTime;
}

void Rendering::ControllerImpl::SetPhase(double aPhase) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    phase = aPhase;
}

void Rendering::ControllerImpl::SetFrequency(double aFrequency) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    frequency = aFrequency;
}

void Rendering::ControllerImpl::SetActive(bool aActive) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    active = aActive;
}

void Rendering::ControllerImpl::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_1;

    source.ReadEnum(repeat);
    source.Read(minTime);
    source.Read(maxTime);
    source.Read(phase);
    source.Read(frequency);
    active = source.ReadBool();

    applicationTime = -Mathematics::MathD::maxReal;
}

void Rendering::ControllerImpl::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    target.WriteEnum(repeat);
    target.Write(minTime);
    target.Write(maxTime);
    target.Write(phase);
    target.Write(frequency);
    target.Write(active);
}

int Rendering::ControllerImpl::GetStreamingSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto size = CoreTools::GetStreamSize(repeat);
    size += CoreTools::GetStreamSize(minTime);
    size += CoreTools::GetStreamSize(maxTime);
    size += CoreTools::GetStreamSize(phase);
    size += CoreTools::GetStreamSize(frequency);
    size += CoreTools::GetStreamSize(active);

    return size;
}

void Rendering::ControllerImpl::SetController(const ControllerSharedPtr& aController) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    controller = aController;
}

Rendering::ControllerImpl::ConstControllerSharedPtr Rendering::ControllerImpl::GetControllerObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto result = controller.lock();

    if (!result)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("ControllerObject 已释放"))
    }

    return result;
}

Rendering::ControllerImpl::ControllerSharedPtr Rendering::ControllerImpl::GetControllerObject()
{
    RENDERING_CLASS_IS_VALID_1;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26473)

    return std::const_pointer_cast<ControllerInterface>(static_cast<const ClassType*>(this)->GetControllerObject());

#include SYSTEM_WARNING_POP
}
