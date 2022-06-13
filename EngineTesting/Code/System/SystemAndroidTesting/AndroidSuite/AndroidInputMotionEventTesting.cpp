///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/12 13:39)

#include "AndroidInputMotionEventTesting.h"
#include "System/Android/AndroidInputMotionEvent.h"
#include "System/Android/AndroidInputQueue.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Base/MathDetail.h"

System::AndroidInputMotionEventTesting::AndroidInputMotionEventTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }, androidInputEvent{}
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, AndroidInputMotionEventTesting)

void System::AndroidInputMotionEventTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::AndroidInputMotionEventTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(AndroidInputMotionEventTest);
}

void System::AndroidInputMotionEventTesting::AndroidInputMotionEventTest()
{
    ASSERT_ENUM_EQUAL(AndroidMotionEventGetAction(&androidInputEvent), AndroidMotionEventAction::Down);
    ASSERT_ENUM_EQUAL(AndroidMotionEventGetFlags(&androidInputEvent), AndroidMotionEvent::WindowIsObscured);
    ASSERT_ENUM_EQUAL(AndroidMotionEventGetMetaState(&androidInputEvent), AndroidMeta::None);
    ASSERT_ENUM_EQUAL(AndroidMotionEventGetButtonState(&androidInputEvent), AndroidMotionEventButton::Primary);
    ASSERT_ENUM_EQUAL(AndroidMotionEventGetEdgeFlags(&androidInputEvent), AndroidMotionEventEdge::None);
    ASSERT_EQUAL(AndroidMotionEventGetDownTime(&androidInputEvent), 0);
    ASSERT_EQUAL(AndroidMotionEventGetEventTime(&androidInputEvent), 0);
    ASSERT_APPROXIMATE(AndroidMotionEventGetXOffset(&androidInputEvent), 0.0f, Mathematics::MathF::GetZeroTolerance());
    ASSERT_APPROXIMATE(AndroidMotionEventGetYOffset(&androidInputEvent), 0.0f, Mathematics::MathF::GetZeroTolerance());
    ASSERT_APPROXIMATE(AndroidMotionEventGetXPrecision(&androidInputEvent), 0.0f, Mathematics::MathF::GetZeroTolerance());
    ASSERT_APPROXIMATE(AndroidMotionEventGetYPrecision(&androidInputEvent), 0.0, Mathematics::MathF::GetZeroTolerance());
    ASSERT_EQUAL(AndroidMotionEventGetPointerCount(&androidInputEvent), 1u);
    ASSERT_EQUAL(AndroidMotionEventGetPointerID(&androidInputEvent, 0), 0);
    ASSERT_ENUM_EQUAL(AndroidMotionEventGetToolType(&androidInputEvent, 0), AndroidMotionEventTool::Unknown);
    ASSERT_APPROXIMATE(AndroidMotionEventGetRawX(&androidInputEvent, 0), 0.0f, Mathematics::MathF::GetZeroTolerance());
    ASSERT_APPROXIMATE(AndroidMotionEventGetRawY(&androidInputEvent, 0), 0.0f, Mathematics::MathF::GetZeroTolerance());
    ASSERT_APPROXIMATE(AndroidMotionEventGetX(&androidInputEvent, 0), 0.0f, Mathematics::MathF::GetZeroTolerance());
    ASSERT_APPROXIMATE(AndroidMotionEventGetY(&androidInputEvent, 0), 0.0f, Mathematics::MathF::GetZeroTolerance());
    ASSERT_APPROXIMATE(AndroidMotionEventGetPressure(&androidInputEvent, 0), 0.0f, Mathematics::MathF::GetZeroTolerance());
    ASSERT_APPROXIMATE(AndroidMotionEventGetSize(&androidInputEvent, 0), 0.0f, Mathematics::MathF::GetZeroTolerance());
    ASSERT_APPROXIMATE(AndroidMotionEventGetTouchMajor(&androidInputEvent, 0), 0.0f, Mathematics::MathF::GetZeroTolerance());
    ASSERT_APPROXIMATE(AndroidMotionEventGetTouchMinor(&androidInputEvent, 0), 0.0f, Mathematics::MathF::GetZeroTolerance());
    ASSERT_APPROXIMATE(AndroidMotionEventGetToolMajor(&androidInputEvent, 0), 0.0f, Mathematics::MathF::GetZeroTolerance());
    ASSERT_APPROXIMATE(AndroidMotionEventGetToolMinor(&androidInputEvent, 0), 0.0f, Mathematics::MathF::GetZeroTolerance());
    ASSERT_APPROXIMATE(AndroidMotionEventGetOrientation(&androidInputEvent, 0), 0.0f, Mathematics::MathF::GetZeroTolerance());
    ASSERT_APPROXIMATE(AndroidMotionEventGetAxisValue(&androidInputEvent, AndroidMotionEventAxis::X, 0), 0.0f, Mathematics::MathF::GetZeroTolerance());
    ASSERT_EQUAL(AndroidMotionEventGetHistorySize(&androidInputEvent), 0u);
    ASSERT_EQUAL(AndroidMotionEventGetHistoricalEventTime(&androidInputEvent, 0), 0);
    ASSERT_APPROXIMATE(AndroidMotionEventGetHistoricalRawX(&androidInputEvent, 0, 0), 0.0f, Mathematics::MathF::GetZeroTolerance());
    ASSERT_APPROXIMATE(AndroidMotionEventGetHistoricalRawY(&androidInputEvent, 0, 0), 0.0f, Mathematics::MathF::GetZeroTolerance());
    ASSERT_APPROXIMATE(AndroidMotionEventGetHistoricalX(&androidInputEvent, 0, 0), 0.0f, Mathematics::MathF::GetZeroTolerance());
    ASSERT_APPROXIMATE(AndroidMotionEventGetHistoricalY(&androidInputEvent, 0, 0), 0.0f, Mathematics::MathF::GetZeroTolerance());
    ASSERT_APPROXIMATE(AndroidMotionEventGetHistoricalPressure(&androidInputEvent, 0, 0), 0.0f, Mathematics::MathF::GetZeroTolerance());
    ASSERT_APPROXIMATE(AndroidMotionEventGetHistoricalSize(&androidInputEvent, 0, 0), 0.0f, Mathematics::MathF::GetZeroTolerance());
    ASSERT_APPROXIMATE(AndroidMotionEventGetHistoricalTouchMajor(&androidInputEvent, 0, 0), 0.0f, Mathematics::MathF::GetZeroTolerance());
    ASSERT_APPROXIMATE(AndroidMotionEventGetHistoricalTouchMinor(&androidInputEvent, 0, 0), 0.0f, Mathematics::MathF::GetZeroTolerance());
    ASSERT_APPROXIMATE(AndroidMotionEventGetHistoricalToolMajor(&androidInputEvent, 0, 0), 0.0f, Mathematics::MathF::GetZeroTolerance());
    ASSERT_APPROXIMATE(AndroidMotionEventGetHistoricalToolMinor(&androidInputEvent, 0, 0), 0.0f, Mathematics::MathF::GetZeroTolerance());
    ASSERT_APPROXIMATE(AndroidMotionEventGetHistoricalOrientation(&androidInputEvent, 0, 0), 0.0f, Mathematics::MathF::GetZeroTolerance());
    ASSERT_APPROXIMATE(AndroidMotionEventGetHistoricalAxisValue(&androidInputEvent, AndroidMotionEventAxis::X, 0, 0), 0.0f, Mathematics::MathF::GetZeroTolerance());
}
