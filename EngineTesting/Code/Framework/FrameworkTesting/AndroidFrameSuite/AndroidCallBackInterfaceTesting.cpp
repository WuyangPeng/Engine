///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/14 13:56)

#include "AndroidCallBackInterfaceTesting.h"
#include "System/Android/Flags/AndroidNativeAppGlueFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Framework/AndroidFrame/AndroidCallBackInterface.h"

Framework::AndroidCallBackInterfaceTesting::AndroidCallBackInterfaceTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, AndroidCallBackInterfaceTesting)

void Framework::AndroidCallBackInterfaceTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::AndroidCallBackInterfaceTesting::MainTest() noexcept
{
}
