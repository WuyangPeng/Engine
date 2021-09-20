///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.1.4 (2021/06/12 13:13)

#include "MasteringComplexityWithACEAndPatternsPlaceholderTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "Example/BookOperatingSystem/MasteringComplexityWithACEAndPatterns/Helper/MasteringComplexityWithACEAndPatternsClassInvariantMacro.h"

BookACE::CppNetworkProgramming::MasteringComplexityWithACEAndPatternsPlaceholderTesting::MasteringComplexityWithACEAndPatternsPlaceholderTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    MASTERING_COMPLEXITY_WITH_ACE_AND_PATTERNS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookACE::CppNetworkProgramming, MasteringComplexityWithACEAndPatternsPlaceholderTesting)

void BookACE::CppNetworkProgramming::MasteringComplexityWithACEAndPatternsPlaceholderTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookACE::CppNetworkProgramming::MasteringComplexityWithACEAndPatternsPlaceholderTesting::MainTest() noexcept
{
}
