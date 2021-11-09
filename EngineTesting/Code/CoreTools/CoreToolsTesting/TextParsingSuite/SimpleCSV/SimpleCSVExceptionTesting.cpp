///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.4 (2021/10/01 22:43)

#include "SimpleCSVExceptionTesting.h"
#include "System/Windows/Flags/PlatformErrorFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/ExcelConversionCSV.h"
#include "CoreTools/TextParsing/SimpleCSV/Flags/CSVExceptionFlags.h"
#include "CoreTools/TextParsing/SimpleCSV/SimpleCSVException.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

CoreTools::SimpleCSVExceptionTesting::SimpleCSVExceptionTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, SimpleCSVExceptionTesting)

void CoreTools::SimpleCSVExceptionTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::SimpleCSVExceptionTesting::MainTest()
{
    ASSERT_THROW_EXCEPTION_0(ThrowSimpleCSVExceptionTest);
    ASSERT_THROW_EXCEPTION_0(ThrowSimpleCSVLastErrorExceptionTest);
    ASSERT_THROW_EXCEPTION_0(ThrowSimpleCSVExceptionMultiByteTest);
    ASSERT_THROW_EXCEPTION_0(ThrowSimpleCSVLastErrorExceptionMultiByteTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SimpleCSVExceptionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SimpleCSVLastErrorExceptionTest);
}

void CoreTools::SimpleCSVExceptionTesting::ThrowSimpleCSVExceptionTest()
{
    THROW_SIMPLE_CSV_EXCEPTION(SimpleCSV::CSVExceptionType::CellAddress, SYSTEM_TEXT("测试抛出CSV异常。"s));
}

void CoreTools::SimpleCSVExceptionTesting::ThrowSimpleCSVLastErrorExceptionTest()
{
    THROW_LAST_ERROR_SIMPLE_CSV_EXCEPTION(System::WindowError::NoAccess, SimpleCSV::CSVExceptionType::CellAddress, SYSTEM_TEXT("测试抛出CSV异常。"s));
}

void CoreTools::SimpleCSVExceptionTesting::ThrowSimpleCSVExceptionMultiByteTest()
{
    THROW_SIMPLE_CSV_EXCEPTION(SimpleCSV::CSVExceptionType::CellAddress, "测试抛出CSV异常。"s);
}

void CoreTools::SimpleCSVExceptionTesting::ThrowSimpleCSVLastErrorExceptionMultiByteTest()
{
    THROW_LAST_ERROR_SIMPLE_CSV_EXCEPTION(System::WindowError::NoAccess, SimpleCSV::CSVExceptionType::CellAddress, "测试抛出CSV异常。"s);
}

void CoreTools::SimpleCSVExceptionTesting::SimpleCSVExceptionTest()
{
    LastError lastError{};
    const auto errorMessage = SYSTEM_TEXT("测试抛出CSV异常。"s);
    constexpr auto csvType = SimpleCSV::CSVExceptionType::CellAddress;
    const auto functionDescribed = CORE_TOOLS_FUNCTION_DESCRIBED;
    SimpleCSV::SimpleCSVException simpleCSVException{ functionDescribed, lastError, csvType, errorMessage };

    ASSERT_UNEQUAL(simpleCSVException.GetError().find(errorMessage), System::String::npos);
    ASSERT_ENUM_EQUAL(csvType, simpleCSVException.GetErrorCode());
    ASSERT_EQUAL_DO_NOT_USE_MESSAGE(simpleCSVException.GetFunctionDescribed(), functionDescribed);
}

void CoreTools::SimpleCSVExceptionTesting::SimpleCSVLastErrorExceptionTest()
{
    const auto errorMessage = SYSTEM_TEXT("测试抛出CSV异常。"s);
    constexpr auto csvType = SimpleCSV::CSVExceptionType::CellAddress;
    const auto functionDescribed = CORE_TOOLS_FUNCTION_DESCRIBED;
    constexpr auto lastError = System::WindowError::NoAccess;
    SimpleCSV::SimpleCSVException simpleCSVException{ functionDescribed, lastError, csvType, errorMessage };

    ASSERT_UNEQUAL(simpleCSVException.GetError().find(errorMessage), System::String::npos);
    ASSERT_ENUM_EQUAL(csvType, simpleCSVException.GetErrorCode());
    ASSERT_EQUAL_DO_NOT_USE_MESSAGE(simpleCSVException.GetFunctionDescribed(), functionDescribed);
}
