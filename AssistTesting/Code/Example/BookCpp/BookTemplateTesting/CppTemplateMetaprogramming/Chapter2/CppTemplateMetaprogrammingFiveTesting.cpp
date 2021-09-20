///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.1.2 (2021/03/29 20:21)

#include "CppTemplateMetaprogrammingFiveTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h"
#include "Mathematics/Base/MathDetail.h"
#include "Example/BookCpp/CppTemplateMetaprogramming/Chapter2/Five.h"
#include "Example/BookCpp/CppTemplateMetaprogramming/Helper/CppTemplateMetaprogrammingClassInvariantMacro.h"

#include <type_traits>

BookTemplate::CppTemplateMetaprogramming::CppTemplateMetaprogrammingFiveTesting::CppTemplateMetaprogrammingFiveTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CPP_TEMPLATE_METAPROGRAMMING_CLASS_IS_VALID_CONST_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookTemplate::CppTemplateMetaprogramming, CppTemplateMetaprogrammingFiveTesting)

void BookTemplate::CppTemplateMetaprogramming::CppTemplateMetaprogrammingFiveTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookTemplate::CppTemplateMetaprogramming::CppTemplateMetaprogrammingFiveTesting::MainTest() noexcept
{
    static_assert(Five::value == 5);
    static_assert(std::is_same_v<Five::value_type, int>);
}
