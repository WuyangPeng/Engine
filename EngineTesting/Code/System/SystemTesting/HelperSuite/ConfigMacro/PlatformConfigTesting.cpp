///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/15 0:57)

#include "PlatformConfigTesting.h"
#include "System/Helper/ConfigMacro.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::PlatformConfigTesting::PlatformConfigTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, PlatformConfigTesting)

void System::PlatformConfigTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::PlatformConfigTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(PlatformTest);
    ASSERT_NOT_THROW_EXCEPTION_0(Win32Test);
}

void System::PlatformConfigTesting::PlatformTest()
{
    auto& stream = GetStream();

    stream << "平台是：" << TCRE_SYSTEM_PLATFORM << "\n";
}

void System::PlatformConfigTesting::Win32Test() noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    static_assert(WIN32_LEAN_AND_MEAN == 1);

    WIN32;
    __WIN32__;
    NOMINMAX;

#endif  // SYSTEM_PLATFORM_WIN32
}