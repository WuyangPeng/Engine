///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/09 15:11)

#include "Framework/FrameworkExport.h"

#include "PerformanceMeasurements.h"
#include "Detail/PerformanceMeasurementsImpl.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Framework, PerformanceMeasurements)

Framework::PerformanceMeasurements::PerformanceMeasurements(int maxTimer)
    : impl{ maxTimer }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, PerformanceMeasurements)

double Framework::PerformanceMeasurements::GetFrameRate() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetFrameRate();
}

std::string Framework::PerformanceMeasurements::GetFrameRateMessage() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetFrameRateMessage();
}

void Framework::PerformanceMeasurements::ResetTime()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return impl->ResetTime();
}

void Framework::PerformanceMeasurements::MeasureTime()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return impl->MeasureTime();
}

void Framework::PerformanceMeasurements::UpdateFrameCount()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return impl->UpdateFrameCount();
}
