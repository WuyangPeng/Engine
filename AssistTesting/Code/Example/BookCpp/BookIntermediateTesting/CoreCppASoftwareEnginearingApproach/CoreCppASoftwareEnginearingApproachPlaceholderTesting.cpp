///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.0.0 (2021/01/24 16:55)

#include "CoreCppASoftwareEnginearingApproachPlaceholderTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "Example/BookCpp/CoreCppASoftwareEnginearingApproach/Helper/CoreCppASoftwareEnginearingApproachClassInvariantMacro.h"

BookIntermediate::CoreCppASoftwareEnginearingApproach::CoreCppASoftwareEnginearingApproachPlaceholderTesting::CoreCppASoftwareEnginearingApproachPlaceholderTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_CPP_A_SOFTWARE_ENGINEARING_APPROACH_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookIntermediate::CoreCppASoftwareEnginearingApproach, CoreCppASoftwareEnginearingApproachPlaceholderTesting)

void BookIntermediate::CoreCppASoftwareEnginearingApproach::CoreCppASoftwareEnginearingApproachPlaceholderTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookIntermediate::CoreCppASoftwareEnginearingApproach::CoreCppASoftwareEnginearingApproachPlaceholderTesting::MainTest() noexcept
{
}
