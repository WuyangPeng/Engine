///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.2 (2021/04/09 21:20)

#ifndef CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_CHAPTER2_MONEY_TEST_H
#define CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_CHAPTER2_MONEY_TEST_H

#include "Example/BookCpp/CleanCppSustainableSoftwareDevelopment/CleanCppSustainableSoftwareDevelopmentDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace BookAdvanced
{
    namespace CleanCppSustainableSoftwareDevelopment
    {
        class CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_DEFAULT_DECLARE MoneyTest final : public CoreTools::UnitTest
        {
        public:
            using ClassType = MoneyTest;
            using ParentType = UnitTest;

        public:
            explicit MoneyTest(const OStreamShared& stream);

            CLASS_INVARIANT_FINAL_DECLARE;

        private:
            void DoRunUnitTest() final;
            void MainTest();

        public:
            void GivenTwoMoneyObjectsWithDifferentBalance_TheInequalityComparison_Works();
            void CreateMoneyObjectWithParameter_GetBalanceAsString_ReturnsCorrectString() noexcept;

            void GivenTwoMoneyObjectsWithDifferentBalance_TestAllComparisonOperators();
        };
    }
}

#endif  // CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_CHAPTER2_MONEY_TEST_H
