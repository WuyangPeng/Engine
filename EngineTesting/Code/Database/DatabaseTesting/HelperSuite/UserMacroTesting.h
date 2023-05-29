///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.10 (2023/05/25 14:44)

#ifndef DATABASE_TESTING_HELPER_SUITE_USER_MACRO_TESTING_H
#define DATABASE_TESTING_HELPER_SUITE_USER_MACRO_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Database
{
    class UserMacroTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = UserMacroTesting;
        using ParentType = UnitTest;

    public:
        explicit UserMacroTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void DoRunUnitTest() override;

        void CloseDatabaseMaxTest();
        void MacroExistTest() noexcept;
    };
}

#endif  // DATABASE_TESTING_HELPER_SUITE_USER_MACRO_TESTING_H