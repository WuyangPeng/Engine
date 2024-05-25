/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/16 15:03)

#ifndef CORE_TOOLS_EXCEPTION_SUITE_LAST_ERROR_TESTING_H
#define CORE_TOOLS_EXCEPTION_SUITE_LAST_ERROR_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <System/Windows/Flags/PlatformErrorFlags.h>

namespace CoreTools
{
    class LastErrorTesting final : public UnitTest
    {
    public:
        using ClassType = LastErrorTesting;
        using ParentType = UnitTest;

        using WindowError = System::WindowError;

    public:
        explicit LastErrorTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void LastErrorTest();

        void DoLastError0(WindowError fileNotFound);
        void DoLastError1();
    };
}

#endif  // CORE_TOOLS_EXCEPTION_SUITE_LAST_ERROR_TESTING_H
