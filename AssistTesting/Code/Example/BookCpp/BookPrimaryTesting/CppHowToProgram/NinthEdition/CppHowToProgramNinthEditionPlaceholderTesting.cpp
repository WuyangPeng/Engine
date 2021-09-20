///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.6.0.1 (2021/01/02 22:59)

#include "CppHowToProgramNinthEditionPlaceholderTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "Example/BookCpp/CppHowToProgramNinthEdition/Helper/CppHowToProgramNinthEditionClassInvariantMacro.h"

BookPrimary::CppHowToProgram::CppHowToProgramNinthEditionPlaceholderTesting::CppHowToProgramNinthEditionPlaceholderTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CPP_HOW_TO_PROGRAM_NINTH_EDITION_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookPrimary::CppHowToProgram, CppHowToProgramNinthEditionPlaceholderTesting)

void BookPrimary::CppHowToProgram::CppHowToProgramNinthEditionPlaceholderTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookPrimary::CppHowToProgram::CppHowToProgramNinthEditionPlaceholderTesting::MainTest() noexcept
{
}
