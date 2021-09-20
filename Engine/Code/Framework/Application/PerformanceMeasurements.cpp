// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 13:57)

#include "Framework/FrameworkExport.h"

#include "PerformanceMeasurements.h"
#include "Detail/PerformanceMeasurementsImpl.h"

#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::string;
COPY_UNSHARED_CLONE_SELF_DEFINE(Framework, PerformanceMeasurements)
Framework::PerformanceMeasurements ::PerformanceMeasurements(int maxTimer)
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