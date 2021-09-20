///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.1.1 (2021/03/20 20:24)

#include "CrossPlatformDevelopmentInCppOperatingSystemInterfaceTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h"
#include "Example/BookCpp/CrossPlatformDevelopmentInCpp/Helper/CrossPlatformDevelopmentInCppClassInvariantMacro.h"
#include "Example/BookCpp/CrossPlatformDevelopmentInCpp/Preface/OperatingSystemInterface.h"

BookAdvanced::CrossPlatformDevelopmentInCpp::CrossPlatformDevelopmentInCppOperatingSystemInterfaceTesting::CrossPlatformDevelopmentInCppOperatingSystemInterfaceTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CROSS_PLATFORM_DEVELOPMENT_IN_CPP_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookAdvanced::CrossPlatformDevelopmentInCpp, CrossPlatformDevelopmentInCppOperatingSystemInterfaceTesting)

void BookAdvanced::CrossPlatformDevelopmentInCpp::CrossPlatformDevelopmentInCppOperatingSystemInterfaceTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookAdvanced::CrossPlatformDevelopmentInCpp::CrossPlatformDevelopmentInCppOperatingSystemInterfaceTesting::MainTest()
{
    const OperatingSystemInterface operatingSystemInterface{};

    ASSERT_EQUAL(operatingSystemInterface.Main(), 0);
}
 