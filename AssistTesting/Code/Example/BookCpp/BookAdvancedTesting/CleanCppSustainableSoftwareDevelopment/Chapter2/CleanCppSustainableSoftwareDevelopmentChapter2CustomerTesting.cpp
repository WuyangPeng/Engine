///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.1.2 (2021/04/11 13:40)

#include "CleanCppSustainableSoftwareDevelopmentChapter2CustomerTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h"
#include "Example/BookCpp/CleanCppSustainableSoftwareDevelopment/Chapter2/Customer.h"
#include "Example/BookCpp/CleanCppSustainableSoftwareDevelopment/Helper/CleanCppSustainableSoftwareDevelopmentClassInvariantMacro.h"

using namespace std::literals;

BookAdvanced::CleanCppSustainableSoftwareDevelopment::CleanCppSustainableSoftwareDevelopmentChapter2CustomerTesting::CleanCppSustainableSoftwareDevelopmentChapter2CustomerTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_CLASS_IS_VALID_CONST_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookAdvanced::CleanCppSustainableSoftwareDevelopment, CleanCppSustainableSoftwareDevelopmentChapter2CustomerTesting)

void BookAdvanced::CleanCppSustainableSoftwareDevelopment::CleanCppSustainableSoftwareDevelopmentChapter2CustomerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookAdvanced::CleanCppSustainableSoftwareDevelopment::CleanCppSustainableSoftwareDevelopmentChapter2CustomerTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(Customer1Test);
    ASSERT_NOT_THROW_EXCEPTION_0(Customer2Test);
    ASSERT_NOT_THROW_EXCEPTION_0(Customer3Test);
    ASSERT_NOT_THROW_EXCEPTION_0(Customer4Test);
}

void BookAdvanced::CleanCppSustainableSoftwareDevelopment::CleanCppSustainableSoftwareDevelopmentChapter2CustomerTesting::Customer1Test()
{
    Customer customer{};
    const auto forename = "forename"s;

    ASSERT_EQUAL(customer.Main1(forename), forename);
}

void BookAdvanced::CleanCppSustainableSoftwareDevelopment::CleanCppSustainableSoftwareDevelopmentChapter2CustomerTesting::Customer2Test()
{
    const Customer customer{};

    customer.Main2();
}

void BookAdvanced::CleanCppSustainableSoftwareDevelopment::CleanCppSustainableSoftwareDevelopmentChapter2CustomerTesting::Customer3Test() noexcept
{
    const Customer customer{};

    customer.Main3();
}

void BookAdvanced::CleanCppSustainableSoftwareDevelopment::CleanCppSustainableSoftwareDevelopmentChapter2CustomerTesting::Customer4Test() noexcept
{
    const Customer customer{};

    customer.Main4();
}
