// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.1 (2020/01/13 15:19)

#ifndef SYSTEM_THREADING_SUITE_SIGNAL_OBJECT_AND_WAIT_TESTING_H
#define SYSTEM_THREADING_SUITE_SIGNAL_OBJECT_AND_WAIT_TESTING_H

#include "System/Threading/Using/MutexUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class SignalObjectAndWaitTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = SignalObjectAndWaitTesting;
        using ParentType = UnitTest;

    public:
        explicit SignalObjectAndWaitTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void SignalObjectAndWaitTest();
        void WaitForEventTest(WindowsHandle eventHandle);
        void WaitForMutexTest(WindowsHandle eventHandle);
    };
}

#endif  // SYSTEM_THREADING_SUITE_SIGNAL_OBJECT_AND_WAIT_TESTING_H