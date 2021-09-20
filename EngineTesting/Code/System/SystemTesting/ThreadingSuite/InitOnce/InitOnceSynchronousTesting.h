///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.3 (2021/05/06 16:03)

#ifndef SYSTEM_THREADING_SUITE_INIT_ONCE_SYNCHRONOUS_TESTING_H
#define SYSTEM_THREADING_SUITE_INIT_ONCE_SYNCHRONOUS_TESTING_H

#include "System/Helper/WindowsMacro.h"
#include "System/Threading/Using/InitOnceUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class InitOnceSynchronousTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = InitOnceSynchronousTesting;
        using ParentType = UnitTest;

    public:
        explicit InitOnceSynchronousTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void SynchronousTest();
        void ExecuteOnceTest(InitOncePtr initOnce);

        static WindowsBool SYSTEM_WINAPI InitHandleFunction(InitOncePtr initOnce, WindowsVoidPtr parameter, WindowsVoidPtr* context) noexcept;

    private:
        WindowsHandle eventHandle;
        int enterInitHandleFunctionCount;
    };
}

#endif  // SYSTEM_THREADING_SUITE_INIT_ONCE_SYNCHRONOUS_TESTING_H