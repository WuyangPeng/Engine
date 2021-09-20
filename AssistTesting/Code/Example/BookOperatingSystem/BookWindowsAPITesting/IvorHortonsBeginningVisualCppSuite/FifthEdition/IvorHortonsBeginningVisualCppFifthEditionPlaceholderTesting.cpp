///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.1.3 (2021/05/23 23:58)

#include "IvorHortonsBeginningVisualCppFifthEditionPlaceholderTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "Example/BookOperatingSystem/IvorHortonsBeginningVisualCppFifthEdition/Helper/IvorHortonsBeginningVisualCppFifthEditionClassInvariantMacro.h"

BookWindowsAPI::IvorHortonsBeginningVisualCpp::IvorHortonsBeginningVisualCppFifthEditionPlaceholderTesting::IvorHortonsBeginningVisualCppFifthEditionPlaceholderTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookWindowsAPI::IvorHortonsBeginningVisualCpp, IvorHortonsBeginningVisualCppFifthEditionPlaceholderTesting)

void BookWindowsAPI::IvorHortonsBeginningVisualCpp::IvorHortonsBeginningVisualCppFifthEditionPlaceholderTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookWindowsAPI::IvorHortonsBeginningVisualCpp::IvorHortonsBeginningVisualCppFifthEditionPlaceholderTesting::MainTest() noexcept
{
}
