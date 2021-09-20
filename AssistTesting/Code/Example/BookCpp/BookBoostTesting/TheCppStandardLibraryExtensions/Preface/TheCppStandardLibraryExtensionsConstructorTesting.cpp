///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.1.1 (2021/03/20 20:24)

#include "TheCppStandardLibraryExtensionsConstructorTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h"
#include "Mathematics/Base/MathDetail.h"
#include "Example/BookCpp/TheCppStandardLibraryExtensions/Helper/TheCppStandardLibraryExtensionsClassInvariantMacro.h"
#include "Example/BookCpp/TheCppStandardLibraryExtensions/Preface/Constructor.h"

BookBoost::TheCppStandardLibraryExtensions::TheCppStandardLibraryExtensionsConstructorTesting::TheCppStandardLibraryExtensionsConstructorTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    THE_CPP_STANDARD_LIBRARY_EXTENSIONS_CLASS_IS_VALID_CONST_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookBoost::TheCppStandardLibraryExtensions, TheCppStandardLibraryExtensionsConstructorTesting)

void BookBoost::TheCppStandardLibraryExtensions::TheCppStandardLibraryExtensionsConstructorTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookBoost::TheCppStandardLibraryExtensions::TheCppStandardLibraryExtensionsConstructorTesting::MainTest() noexcept
{
    const Constructor constructor{};

    constructor.Main();
}
