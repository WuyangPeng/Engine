///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/19 12:01)

#include "GenerateRandomNameTesting.h"
#include "CoreTools/FileManager/GenerateRandomName.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

CoreTools::GenerateRandomNameTesting::GenerateRandomNameTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, GenerateRandomNameTesting)

void CoreTools::GenerateRandomNameTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::GenerateRandomNameTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(StringTest);
    ASSERT_NOT_THROW_EXCEPTION_0(WStringTest);
    ASSERT_NOT_THROW_EXCEPTION_0(TStringTest);
}

void CoreTools::GenerateRandomNameTesting::StringTest()
{
    constexpr auto length = 10;
    const auto extensionName = "tmp"s;

    const auto name = GenerateRandomName::GetName(length, extensionName);

    ASSERT_EQUAL(name.size(), length + extensionName.size() + 1);
    ASSERT_EQUAL(name.find(extensionName), name.size() - extensionName.size());
}

void CoreTools::GenerateRandomNameTesting::WStringTest()
{
    constexpr auto length = 11;
    const auto extensionName = L"tmp"s;

    const auto name = GenerateRandomName::GetName(length, extensionName);

    if (name.find(extensionName) != std::string::npos)
    {
        ASSERT_EQUAL(name.find(extensionName), name.size() - extensionName.size());
    }

    ASSERT_EQUAL(name.size(), length + extensionName.size() + 1);
}

void CoreTools::GenerateRandomNameTesting::TStringTest()
{
    constexpr auto length = 9;
    const auto extensionName = SYSTEM_TEXT("tmp"s);

    const auto name = GenerateRandomName::GetName(length, extensionName);

    ASSERT_EQUAL(name.size(), length + extensionName.size() + 1);
    ASSERT_EQUAL(name.find(extensionName), name.size() - extensionName.size());
}
