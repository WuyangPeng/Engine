// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 13:57)

#include "Framework/FrameworkExport.h"

#include "PerformanceMeasurements.h"
#include "Detail/PerformanceMeasurementsImpl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

using std::string;
using std::make_shared;

Framework::PerformanceMeasurements
	::PerformanceMeasurements(int maxTimer)
	:m_Impl{ make_shared<ImplType>(maxTimer) }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

DELAY_COPY_CONSTRUCTION_DEFINE(Framework, PerformanceMeasurements)

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Framework, PerformanceMeasurements)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, PerformanceMeasurements, GetFrameRate, double);
IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_0(Framework, PerformanceMeasurements, ResetTime, void)
IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_0(Framework, PerformanceMeasurements, MeasureTime, void)
IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_0(Framework, PerformanceMeasurements, UpdateFrameCount, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, PerformanceMeasurements, GetFrameRateMessage, string)