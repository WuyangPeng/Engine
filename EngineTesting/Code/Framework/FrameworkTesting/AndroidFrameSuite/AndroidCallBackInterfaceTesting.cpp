///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/13 20:28)

#include "AndroidCallBackInterfaceTesting.h"
#include "System/Android/Flags/AndroidInputFlags.h"
#include "System/Android/Flags/AndroidNativeAppGlueFlags.h"
#include "CoreTools/Contract/Noexcept.h"
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
