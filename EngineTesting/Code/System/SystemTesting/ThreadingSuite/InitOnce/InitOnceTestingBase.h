///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/01 14:31)

#ifndef SYSTEM_THREADING_SUITE_INIT_ONCE_TESTING_BASE_H
#define SYSTEM_THREADING_SUITE_INIT_ONCE_TESTING_BASE_H

#include "System/Helper/WindowsMacro.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class InitOnceTestingBase : public CoreTools::UnitTest
    {
    public:
        using ClassType = InitOnceTestingBase;
        using ParentType = UnitTest;

    public:
        explicit InitOnceTestingBase(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    protected:
        static constexpr auto threadCount = 12;

    protected:
        void CloseEventTest();
        void SetEventHandle(WindowsHandle handle);
        void SetEventHandleNull() noexcept;
        NODISCARD int GetEnterInitHandleFunctionCount() const noexcept;
        NODISCARD WindowsVoidPtr GetEnterInitHandleFunctionCountPtr() noexcept;
        void SetEnterInitHandleFunctionCount(int aEnterInitHandleFunctionCount) noexcept;

    private:
        WindowsHandle eventHandle;
        int enterInitHandleFunctionCount;
    };
}

#endif  // SYSTEM_THREADING_SUITE_INIT_ONCE_TESTING_BASE_H