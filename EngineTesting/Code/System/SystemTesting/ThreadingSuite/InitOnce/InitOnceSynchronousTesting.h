///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/01 14:31)

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

        static WindowsBool SYSTEM_WINAPI InitHandleFunction(InitOncePtr initOnce, WindowsVoidPtr parameter, WindowsVoidPtr* context) noexcept;
    };
}

#endif  // SYSTEM_THREADING_SUITE_INIT_ONCE_SYNCHRONOUS_TESTING_H