///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/05/06 11:29)

#include "Framework/FrameworkExport.h"

#include "PerformanceMeasurements.h"
#include "Detail/PerformanceMeasurementsImpl.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::string;

COPY_UNSHARED_CLONE_SELF_DEFINE(Framework, PerformanceMeasurements)

Framework::PerformanceMeasurements::PerformanceMeasurements(int maxTimer)
    : impl{ maxTimer }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, PerformanceMeasurements)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, PerformanceMeasurements, GetFrameRate, double);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, PerformanceMeasurements, ResetTime, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, PerformanceMeasurements, MeasureTime, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, PerformanceMeasurements, UpdateFrameCount, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, PerformanceMeasurements, GetFrameRateMessage, string)