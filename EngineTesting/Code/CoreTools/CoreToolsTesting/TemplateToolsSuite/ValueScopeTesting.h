/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/04/23 11:08)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_SUITE_VALUE_SCOPE_TESTING_H
#define CORE_TOOLS_TEMPLATE_TOOLS_SUITE_VALUE_SCOPE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class ValueScopeTesting final : public UnitTest
    {
    public:
        using ClassType = ValueScopeTesting;
        using ParentType = UnitTest;

    public:
        explicit ValueScopeTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        static constexpr auto value0 = 313;
        static constexpr auto value1 = 201;
        static constexpr auto value2 = 33;
        static constexpr auto value3 = 20;
        static constexpr auto value4 = 10;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void ValueScope0Test();
        void ValueScope1Test();
        void ValueScope2Test();
        void ValueScope3Test();
        void ValueScope4Test();

        void DoValueScope0Test(int& value);
        void DoValueScope1Test(int& value);
        void DoValueScope2Test(int& value);
        void DoValueScope3Test(std::string& value);
        void DoValueScope4Test(std::string& value);
        void DoValueScope5Test(std::string& value);

    private:
        std::string original0;
        std::string original1;
        std::string rebel;
        std::string matthew;
        std::string sarah;
        std::string result;
    };
}

#endif  // CORE_TOOLS_TEMPLATE_TOOLS_SUITE_VALUE_SCOPE_TESTING_H
