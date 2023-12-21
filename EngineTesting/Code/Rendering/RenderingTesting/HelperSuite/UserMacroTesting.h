/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.2 (2023/12/08 16:08)

#ifndef RENDERING_HELPER_SUITE_USER_MACRO_TESTING_H
#define RENDERING_HELPER_SUITE_USER_MACRO_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Rendering
{
    class UserMacroTesting final : public CoreTools::UnitTest
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

        void CloseCoreToolsMaxTest();
        void MacroExistTest();
    };
}

#endif  // RENDERING_HELPER_SUITE_USER_MACRO_TESTING_H