/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/12 18:03)

#ifndef SYSTEM_THREADING_SUITE_INIT_ONCE_TESTING_BASE_H
#define SYSTEM_THREADING_SUITE_INIT_ONCE_TESTING_BASE_H

#include "System/Windows/Using/WindowsUsing.h"
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