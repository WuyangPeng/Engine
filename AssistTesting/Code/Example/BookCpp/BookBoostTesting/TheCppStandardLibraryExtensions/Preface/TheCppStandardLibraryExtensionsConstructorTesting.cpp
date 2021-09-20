///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.1.1 (2021/03/20 20:24)

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
