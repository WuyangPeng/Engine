///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/13 19:47)

#include "WindowNameTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Framework/WindowRegister/WindowName.h"

using namespace std::literals;

namespace Framework
{
    using TestingType = WindowName;
}

Framework::WindowNameTesting::WindowNameTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, WindowNameTesting)

void Framework::WindowNameTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::WindowNameTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(NameTest);
}

void Framework::WindowNameTesting::NameTest()
{
    const auto className = SYSTEM_TEXT("className"s);
    const auto menuName = SYSTEM_TEXT("menuName"s);

    TestingType name{ className, menuName };

    ASSERT_EQUAL(name.GetWindowClassName(), className);
    ASSERT_EQUAL(name.GetWindowMenuName(), menuName);
}
