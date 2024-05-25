/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.9 (2024/04/23 12:37)

#include "ParamTypeTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

CoreTools::ParamTypeTesting::ParamTypeTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, ParamTypeTesting)

void CoreTools::ParamTypeTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::ParamTypeTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_2(ParamTypeTest, 0, ""s);
}

void CoreTools::ParamTypeTesting::ParamTypeTest(ParamType<int>::type integer, ParamType<std::string>::type characterString) noexcept
{
    System::UnusedFunction(integer, characterString);
}
