///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.1.1 (2021/03/06 21:40)

#include "TheCppStandardLibraryPlaceholderTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "Example/BookCpp/TheCppStandardLibrary/Helper/TheCppStandardLibraryClassInvariantMacro.h"

BookStandardLibrary::TheCppStandardLibrary::TheCppStandardLibraryPlaceholderTesting::TheCppStandardLibraryPlaceholderTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    THE_CPP_STANDARD_LIBRARY_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookStandardLibrary::TheCppStandardLibrary, TheCppStandardLibraryPlaceholderTesting)

void BookStandardLibrary::TheCppStandardLibrary::TheCppStandardLibraryPlaceholderTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookStandardLibrary::TheCppStandardLibrary::TheCppStandardLibraryPlaceholderTesting::MainTest() noexcept
{
}
