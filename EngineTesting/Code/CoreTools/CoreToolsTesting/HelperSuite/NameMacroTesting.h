///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/24 15:23)

#ifndef CORE_TOOLS_HELPER_SUITE_NAME_MACRO_TESTING_H
#define CORE_TOOLS_HELPER_SUITE_NAME_MACRO_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class NameMacroTesting final : public UnitTest
    {
    public:
        using ClassType = NameMacroTesting;
        using ParentType = UnitTest;

    public:
        explicit NameMacroTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void BaseTest();
        void ImplTest();
        void FinalTest();

    private:
        std::string name;
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_NAME_MACRO_TESTING_H