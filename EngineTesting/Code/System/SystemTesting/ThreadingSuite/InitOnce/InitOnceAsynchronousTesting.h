///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.3 (2021/05/06 20:13)

#ifndef SYSTEM_THREADING_SUITE_INIT_ONCE_ASYNCHRONOUS_TESTING_H
#define SYSTEM_THREADING_SUITE_INIT_ONCE_ASYNCHRONOUS_TESTING_H

#include "System/Helper/WindowsMacro.h"
#include "System/Threading/Using/InitOnceUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class InitOnceAsynchronousTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = InitOnceAsynchronousTesting;
        using ParentType = UnitTest;

    public:
        explicit InitOnceAsynchronousTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void AsynchronousTest();
        void BeginInitializeTest(InitOncePtr initOnce);
        WindowsHandle OpenEventHandleAsync(InitOncePtr initOnce);

    private:
        WindowsHandle eventHandle;
        int enterInitHandleFunctionCount;
    };
}

#endif  // SYSTEM_THREADING_SUITE_INIT_ONCE_ASYNCHRONOUS_TESTING_H