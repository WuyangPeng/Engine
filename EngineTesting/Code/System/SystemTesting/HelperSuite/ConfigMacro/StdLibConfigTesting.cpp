///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.2 (2022/09/14 14:50)

#include "StdLibConfigTesting.h"
#include "System/Helper/ConfigMacro.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::StdLibConfigTesting::StdLibConfigTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, StdLibConfigTesting)

void System::StdLibConfigTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::StdLibConfigTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(StdLibTest);
}

void System::StdLibConfigTesting::StdLibTest()
{
    auto& stream = GetStream();

    stream << "标准库版本是：" << TCRE_CPPLIB_VERSION << "\n";
    stream << "标准库是：" << TCRE_SYSTEM_STDLIB << "\n";
}

void System::StdLibConfigTesting::DinkumwareTest() noexcept
{
#ifdef TCRE_USE_DINKUMWARE

    static_assert(TCRE_DINKUMWARE_STDLIB == _CPPLIB_VER);

#endif  // TCRE_USE_DINKUMWARE
}