///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.1.1 (2021/03/20 20:24)

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
