///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/25 16:24)

#ifndef DATABASE_TESTING_HELPER_SUITE_USER_MACRO_TESTING_H
#define DATABASE_TESTING_HELPER_SUITE_USER_MACRO_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Database
{
    class UserMacroTesting : public CoreTools::UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(UserMacroTesting);

    private:
        void MainTest() noexcept;

        void DoRunUnitTest() override;
    };
}

#endif  // DATABASE_TESTING_HELPER_SUITE_USER_MACRO_TESTING_H