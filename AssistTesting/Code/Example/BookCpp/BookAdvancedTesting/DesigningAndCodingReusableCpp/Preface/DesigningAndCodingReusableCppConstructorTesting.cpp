///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.1.1 (2021/03/20 20:24)

#include "DesigningAndCodingReusableCppConstructorTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h"
#include "Mathematics/Base/MathDetail.h"
#include "Example/BookCpp/DesigningAndCodingReusableCpp/Helper/DesigningAndCodingReusableCppClassInvariantMacro.h"
#include "Example/BookCpp/DesigningAndCodingReusableCpp/Preface/Constructor.h"

BookAdvanced::DesigningAndCodingReusableCpp::DesigningAndCodingReusableCppConstructorTesting::DesigningAndCodingReusableCppConstructorTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    DESIGNING_AND_CODING_REUSABLE_CPP_CLASS_IS_VALID_CONST_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookAdvanced::DesigningAndCodingReusableCpp, DesigningAndCodingReusableCppConstructorTesting)

void BookAdvanced::DesigningAndCodingReusableCpp::DesigningAndCodingReusableCppConstructorTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookAdvanced::DesigningAndCodingReusableCpp::DesigningAndCodingReusableCppConstructorTesting::MainTest() noexcept
{
    const Constructor constructor{};

    constructor.Main();
}
