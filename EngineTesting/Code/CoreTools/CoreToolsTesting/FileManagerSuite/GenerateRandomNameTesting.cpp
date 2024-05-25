/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.9 (2024/05/04 23:44)

#include "GenerateRandomNameTestingDetail.h"
#include "CoreTools/FileManager/GenerateRandomName.h"
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

    ASSERT_NOT_THROW_EXCEPTION_3(ResultTest<std::string>, length, name, extensionName);
}

void CoreTools::GenerateRandomNameTesting::WStringTest()
{
    constexpr auto length = 11;
    const auto extensionName = L"tmp"s;

    const auto name = GenerateRandomName::GetName(length, extensionName);

    ASSERT_NOT_THROW_EXCEPTION_3(ResultTest<std::wstring>, length, name, extensionName);
}

void CoreTools::GenerateRandomNameTesting::TStringTest()
{
    constexpr auto length = 9;
    const auto extensionName = SYSTEM_TEXT("tmp"s);

    const auto name = GenerateRandomName::GetName(length, extensionName);

    ASSERT_NOT_THROW_EXCEPTION_3(ResultTest<String>, length, name, extensionName);
}
