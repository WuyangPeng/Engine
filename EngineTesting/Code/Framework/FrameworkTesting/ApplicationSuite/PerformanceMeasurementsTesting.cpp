///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/11 20:44)

#include "PerformanceMeasurementsTesting.h"
#include "System/Helper/PragmaWarning/Format.h"
#include "System/Threading/SyncTools.h"
#include "System/Time/Using/DeltaTimeUsing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Time/CustomTime.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Base/MathDetail.h"
#include "Framework/Application/PerformanceMeasurements.h"

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

    PerformanceMeasurements performanceMeasurements{ maxTimer };

    constexpr auto frame = System::gMillisecond / maxTimer;
    const auto maxTimerTestLoopCount = maxTimer * GetTestLoopCount();

    CoreTools::CustomTime customTime{};
    auto delta = 0;
    auto frameSum = 0;
    for (auto i = 0; i < maxTimerTestLoopCount; ++i)
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
