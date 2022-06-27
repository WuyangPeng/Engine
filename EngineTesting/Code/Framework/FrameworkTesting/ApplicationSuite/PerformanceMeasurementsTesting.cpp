///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/27 11:10)

#include "PerformanceMeasurementsTesting.h"
#include "System/Helper/PragmaWarning/Format.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Threading/SyncTools.h"
#include "System/Time/Using/DeltaTimeUsing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Time/CustomTime.h"
#include "Mathematics/Base/MathDetail.h"
#include "Framework/Application/PerformanceMeasurements.h"

namespace Framework
{
    using TestingType = PerformanceMeasurements;
}

Framework::PerformanceMeasurementsTesting::PerformanceMeasurementsTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, PerformanceMeasurementsTesting)

void Framework::PerformanceMeasurementsTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::PerformanceMeasurementsTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(PerformanceMeasurementsTest);
}

void Framework::PerformanceMeasurementsTesting::PerformanceMeasurementsTest()
{
    constexpr auto maxTimer = 30;

    TestingType performanceMeasurements{ maxTimer };

    constexpr auto frame = System::g_Millisecond / maxTimer;
    const auto testLoopCount = maxTimer * GetTestLoopCount();

    CoreTools::CustomTime customTime{};
    auto delta = 0;
    auto frameSum = 0;
    for (auto i = 0; i < testLoopCount; ++i)
    {
        performanceMeasurements.UpdateFrameCount();

        delta += boost::numeric_cast<int>(customTime.GetThisElapsedMillisecondTime());
        frameSum += frame;

        if (delta < frameSum)
        {
            System::SystemSleep(frameSum - delta);
        }

        performanceMeasurements.MeasureTime();
    }

    const auto rate = performanceMeasurements.GetFrameRate();

    constexpr auto epsilon = 0.5;

    ASSERT_RANGE(rate, maxTimer - epsilon, maxTimer + epsilon);

    boost::format message{ "fps: %.2lf" };
    message % performanceMeasurements.GetFrameRate();

    ASSERT_EQUAL(performanceMeasurements.GetFrameRateMessage(), message.str());

    performanceMeasurements.ResetTime();

    const auto zero = performanceMeasurements.GetFrameRate();

    ASSERT_APPROXIMATE(0.0, zero, Mathematics::MathD::epsilon);
}
