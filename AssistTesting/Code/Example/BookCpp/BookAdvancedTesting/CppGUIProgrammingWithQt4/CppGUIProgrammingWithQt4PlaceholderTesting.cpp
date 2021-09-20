///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.1.1 (2021/03/20 20:10)

#include "CppGUIProgrammingWithQt4PlaceholderTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "Example/BookCpp/CppGUIProgrammingWithQt4/Helper/CppGUIProgrammingWithQt4ClassInvariantMacro.h"

BookAdvanced::CppGUIProgrammingWithQt4::CppGUIProgrammingWithQt4PlaceholderTesting::CppGUIProgrammingWithQt4PlaceholderTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CPP_GUI_PROGRAMMING_WITH_QT4_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookAdvanced::CppGUIProgrammingWithQt4, CppGUIProgrammingWithQt4PlaceholderTesting)

void BookAdvanced::CppGUIProgrammingWithQt4::CppGUIProgrammingWithQt4PlaceholderTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookAdvanced::CppGUIProgrammingWithQt4::CppGUIProgrammingWithQt4PlaceholderTesting::MainTest() noexcept
{
}
