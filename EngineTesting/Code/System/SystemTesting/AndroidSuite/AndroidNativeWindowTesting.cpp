///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/15 13:35)

#include "AndroidNativeWindowTesting.h"
#include "System/Android/AndroidNativeWindow.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::AndroidNativeWindowTesting::AndroidNativeWindowTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, AndroidNativeWindowTesting)

void System::AndroidNativeWindowTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::AndroidNativeWindowTesting::MainTest() noexcept
{
    // SystemAndroidTesting��Android�����Ĳ��ԡ�
}
