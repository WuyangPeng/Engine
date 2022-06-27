///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/27 11:19)

#include "AndroidCallBackTesting.h"
#include "System/Android/AndroidInputKeyEvent.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Framework/AndroidFrame/AndroidCallBackDetail.h"
#include "Framework/MiddleLayer/MiddleLayerInterface.h"

Framework::AndroidCallBackTesting::AndroidCallBackTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, AndroidCallBackTesting)

void Framework::AndroidCallBackTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::AndroidCallBackTesting::MainTest() noexcept
{
}
