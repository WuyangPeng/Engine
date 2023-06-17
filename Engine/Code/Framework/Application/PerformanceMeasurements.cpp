///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/13 14:50)

#include "Framework/FrameworkExport.h"

#include "PerformanceMeasurements.h"
#include "Detail/PerformanceMeasurementsImpl.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

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
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, PerformanceMeasurements, GetFrameRateMessage, std::string)
