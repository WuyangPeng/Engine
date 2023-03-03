///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.2 (2023/02/18 18:15)

#ifndef CORE_TOOLS_HELPER_SUITE_USER_MACRO_TESTING_H
#define CORE_TOOLS_HELPER_SUITE_USER_MACRO_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class UserMacroTesting final : public UnitTest
    {
    public:
        using ClassType = UserMacroTesting;
        using ParentType = UnitTest;

    public:
        explicit UserMacroTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void IsValidTest() noexcept(!gOpenClassInvariant);
        void CloseSystemMaxTest();
        void MacroExistTest() noexcept(!gOpenClassInvariant);
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_USER_MACRO_TESTING_H