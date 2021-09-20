///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.1.4 (2021/06/12 13:13)

#include "TheACEProgrammersGuidePlaceholderTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "Example/BookOperatingSystem/TheACEProgrammersGuide/Helper/TheACEProgrammersGuideClassInvariantMacro.h"

BookACE::TheACEProgrammersGuide::TheACEProgrammersGuidePlaceholderTesting::TheACEProgrammersGuidePlaceholderTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    THE_ACE_PROGRAMMERS_GUIDE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookACE::TheACEProgrammersGuide, TheACEProgrammersGuidePlaceholderTesting)

void BookACE::TheACEProgrammersGuide::TheACEProgrammersGuidePlaceholderTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookACE::TheACEProgrammersGuide::TheACEProgrammersGuidePlaceholderTesting::MainTest() noexcept
{
}
