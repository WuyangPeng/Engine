///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.1.1 (2021/03/21 12:22)

#include "ModernCppDesignCTAssertTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h"
#include "Mathematics/Base/MathDetail.h"
#include "Example/BookCpp/ModernCppDesign/Helper/ModernCppDesignClassInvariantMacro.h"
#include "Example/BookCpp/ModernCppDesign/Preface/CTAssert.h"

#define OPEN_CTASSERT_FALSE
#undef OPEN_CTASSERT_FALSE

BookAdvanced::ModernCppDesign::ModernCppDesignCTAssertTesting::ModernCppDesignCTAssertTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    MODERN_CPP_DESIGN_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookAdvanced::ModernCppDesign, ModernCppDesignCTAssertTesting)

void BookAdvanced::ModernCppDesign::ModernCppDesignCTAssertTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookAdvanced::ModernCppDesign::ModernCppDesignCTAssertTesting::MainTest() noexcept
{
    CTAssert<true> ctAssert{};

#ifdef OPEN_CTASSERT_FALSE
    CTAssert<false> ctAssert1{};
#endif // OPEN_CTASSERT_FALSE
}
