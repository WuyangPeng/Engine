/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 17:08)

#include "AndroidInputMotionEventFacadeTesting.h"
#include "System/Android/AndroidInputMotionEventFacade.h"
#include "System/Android/Flags/AndroidInputFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Base/MathDetail.h"

System::AndroidInputMotionEventFacadeTesting::AndroidInputMotionEventFacadeTesting(const OStreamShared& stream)
    : ParentType{ stream }, androidInputEvent{}
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, AndroidInputMotionEventFacadeTesting)

void System::AndroidInputMotionEventFacadeTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::AndroidInputMotionEventFacadeTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(AndroidInputMotionEventTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AndroidInputMotionEventPointerIndexTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AndroidInputMotionEventHistoricalTest);
}

void System::AndroidInputMotionEventFacadeTesting::AndroidInputMotionEventTest()
{
    const AndroidInputMotionEventFacade androidInputMotionEvent{ &androidInputEvent };

    ASSERT_EQUAL(androidInputMotionEvent.GetAction(), AndroidMotionEventAction::Mask);
    ASSERT_EQUAL(androidInputMotionEvent.GetFlags(), AndroidMotionEventFlag::WindowIsObscured);
    ASSERT_EQUAL(androidInputMotionEvent.GetMetaState(), AndroidMeta::None);
    ASSERT_EQUAL(androidInputMotionEvent.GetButtonState(), AndroidMotionEventButton::Primary);
    ASSERT_EQUAL(androidInputMotionEvent.GetEdgeFlags(), AndroidMotionEventEdgeFlag::None);
    ASSERT_EQUAL(androidInputMotionEvent.GetDownTime(), 0);
    ASSERT_EQUAL(androidInputMotionEvent.GetEventTime(), 0);
    ASSERT_APPROXIMATE_FLOAT_ZERO(androidInputMotionEvent.GetXOffset());
    ASSERT_APPROXIMATE_FLOAT_ZERO(androidInputMotionEvent.GetYOffset());
    ASSERT_APPROXIMATE_FLOAT_ZERO(androidInputMotionEvent.GetXPrecision());
    ASSERT_APPROXIMATE_FLOAT_ZERO(androidInputMotionEvent.GetYPrecision());
    ASSERT_EQUAL(androidInputMotionEvent.GetPointerCount(), 0u);
}

void System::AndroidInputMotionEventFacadeTesting::AndroidInputMotionEventPointerIndexTest()
{
    const AndroidInputMotionEventFacade androidInputMotionEvent{ &androidInputEvent };
    constexpr auto pointerIndex = 0;

    ASSERT_EQUAL(androidInputMotionEvent.GetPointerId(pointerIndex), 0);
    ASSERT_EQUAL(androidInputMotionEvent.GetToolType(pointerIndex), AndroidMotionEventToolType::Unknown);
    ASSERT_APPROXIMATE_FLOAT_ZERO(androidInputMotionEvent.GetRawX(pointerIndex));
    ASSERT_APPROXIMATE_FLOAT_ZERO(androidInputMotionEvent.GetRawY(pointerIndex));
    ASSERT_APPROXIMATE_FLOAT_ZERO(androidInputMotionEvent.GetX(pointerIndex));
    ASSERT_APPROXIMATE_FLOAT_ZERO(androidInputMotionEvent.GetY(pointerIndex));
    ASSERT_APPROXIMATE_FLOAT_ZERO(androidInputMotionEvent.GetPressure(pointerIndex));
    ASSERT_APPROXIMATE_FLOAT_ZERO(androidInputMotionEvent.GetSize(pointerIndex));
    ASSERT_APPROXIMATE_FLOAT_ZERO(androidInputMotionEvent.GetTouchMajor(pointerIndex));
    ASSERT_APPROXIMATE_FLOAT_ZERO(androidInputMotionEvent.GetTouchMinor(pointerIndex));
    ASSERT_APPROXIMATE_FLOAT_ZERO(androidInputMotionEvent.GetToolMajor(pointerIndex));
    ASSERT_APPROXIMATE_FLOAT_ZERO(androidInputMotionEvent.GetToolMinor(pointerIndex));
    ASSERT_APPROXIMATE_FLOAT_ZERO(androidInputMotionEvent.GetOrientation(pointerIndex));
    ASSERT_APPROXIMATE_FLOAT_ZERO(androidInputMotionEvent.GetAxisValue(AndroidMotionEventAxis::X, pointerIndex));
}

void System::AndroidInputMotionEventFacadeTesting::AndroidInputMotionEventHistoricalTest()
{
    const AndroidInputMotionEventFacade androidInputMotionEvent{ &androidInputEvent };
    constexpr auto pointerIndex = 0;
    constexpr auto historyIndex = 0;

    ASSERT_EQUAL(androidInputMotionEvent.GetHistorySize(), 0u);
    ASSERT_EQUAL(androidInputMotionEvent.GetHistoricalEventTime(historyIndex), 0);
    ASSERT_APPROXIMATE_FLOAT_ZERO(androidInputMotionEvent.GetHistoricalRawX(pointerIndex, historyIndex));
    ASSERT_APPROXIMATE_FLOAT_ZERO(androidInputMotionEvent.GetHistoricalRawY(pointerIndex, historyIndex));
    ASSERT_APPROXIMATE_FLOAT_ZERO(androidInputMotionEvent.GetHistoricalX(pointerIndex, historyIndex));
    ASSERT_APPROXIMATE_FLOAT_ZERO(androidInputMotionEvent.GetHistoricalY(pointerIndex, historyIndex));
    ASSERT_APPROXIMATE_FLOAT_ZERO(androidInputMotionEvent.GetHistoricalPressure(pointerIndex, historyIndex));
    ASSERT_APPROXIMATE_FLOAT_ZERO(androidInputMotionEvent.GetHistoricalSize(pointerIndex, historyIndex));
    ASSERT_APPROXIMATE_FLOAT_ZERO(androidInputMotionEvent.GetHistoricalTouchMajor(pointerIndex, historyIndex));
    ASSERT_APPROXIMATE_FLOAT_ZERO(androidInputMotionEvent.GetHistoricalTouchMinor(pointerIndex, historyIndex));
    ASSERT_APPROXIMATE_FLOAT_ZERO(androidInputMotionEvent.GetHistoricalToolMajor(pointerIndex, historyIndex));
    ASSERT_APPROXIMATE_FLOAT_ZERO(androidInputMotionEvent.GetHistoricalToolMinor(pointerIndex, historyIndex));
    ASSERT_APPROXIMATE_FLOAT_ZERO(androidInputMotionEvent.GetHistoricalOrientation(pointerIndex, historyIndex));
    ASSERT_APPROXIMATE_FLOAT_ZERO(androidInputMotionEvent.GetHistoricalAxisValue(AndroidMotionEventAxis::X, pointerIndex, historyIndex));
}
