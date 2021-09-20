///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.1.4 (2021/06/12 13:13)

#include "SystematicReuseWithACEAndFrameworksPlaceholderTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "Example/BookOperatingSystem/SystematicReuseWithACEAndFrameworks/Helper/SystematicReuseWithACEAndFrameworksClassInvariantMacro.h"

BookACE::CppNetworkProgramming::SystematicReuseWithACEAndFrameworksPlaceholderTesting::SystematicReuseWithACEAndFrameworksPlaceholderTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEMATIC_REUSE_WITH_ACE_AND_FRAMEWORKS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookACE::CppNetworkProgramming, SystematicReuseWithACEAndFrameworksPlaceholderTesting)

void BookACE::CppNetworkProgramming::SystematicReuseWithACEAndFrameworksPlaceholderTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookACE::CppNetworkProgramming::SystematicReuseWithACEAndFrameworksPlaceholderTesting::MainTest() noexcept
{
}
