/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/12 18:02)

#ifndef SYSTEM_THREADING_SUITE_INIT_ONCE_SYNCHRONOUS_TESTING_H
#define SYSTEM_THREADING_SUITE_INIT_ONCE_SYNCHRONOUS_TESTING_H

#include "InitOnceTestingBase.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Threading/Using/InitOnceUsing.h"

namespace System
{
    class InitOnceSynchronousTesting final : public InitOnceTestingBase
    {
    public:
        using ClassType = InitOnceSynchronousTesting;
        using ParentType = InitOnceTestingBase;

    public:
        explicit InitOnceSynchronousTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void SynchronousTest();
        void ExecuteOnceTest(InitOncePtr initOnce);
        void CreateThreadTest();

        static WindowsBool SYSTEM_WIN_API InitHandleFunction(InitOncePtr initOnce, WindowsVoidPtr parameter, WindowsVoidPtr* context) noexcept;
    };
}

#endif  // SYSTEM_THREADING_SUITE_INIT_ONCE_SYNCHRONOUS_TESTING_H