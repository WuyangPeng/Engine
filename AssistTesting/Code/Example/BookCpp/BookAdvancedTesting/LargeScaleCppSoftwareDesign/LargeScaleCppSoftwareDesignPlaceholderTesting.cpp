///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.1.1 (2021/03/21 12:34)

#include "LargeScaleCppSoftwareDesignPlaceholderTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "Example/BookCpp/LargeScaleCppSoftwareDesign/Helper/LargeScaleCppSoftwareDesignClassInvariantMacro.h"

BookAdvanced::LargeScaleCppSoftwareDesign::LargeScaleCppSoftwareDesignPlaceholderTesting::LargeScaleCppSoftwareDesignPlaceholderTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    LARGE_SCALE_CPP_SOFTWARE_DESIGN_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookAdvanced::LargeScaleCppSoftwareDesign, LargeScaleCppSoftwareDesignPlaceholderTesting)

void BookAdvanced::LargeScaleCppSoftwareDesign::LargeScaleCppSoftwareDesignPlaceholderTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookAdvanced::LargeScaleCppSoftwareDesign::LargeScaleCppSoftwareDesignPlaceholderTesting::MainTest() noexcept
{
}
