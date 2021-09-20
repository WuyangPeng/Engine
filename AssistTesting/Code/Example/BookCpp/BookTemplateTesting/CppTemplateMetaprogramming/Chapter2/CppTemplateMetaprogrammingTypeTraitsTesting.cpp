///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.1.2 (2021/03/29 20:21)

#include "CppTemplateMetaprogrammingTypeTraitsTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h"
#include "Mathematics/Base/MathDetail.h"
#include "Example/BookCpp/CppTemplateMetaprogramming/Chapter2/TypeTraits.h"
#include "Example/BookCpp/CppTemplateMetaprogramming/Helper/CppTemplateMetaprogrammingClassInvariantMacro.h"

#include <type_traits>

BookTemplate::CppTemplateMetaprogramming::CppTemplateMetaprogrammingTypeTraitsTesting::CppTemplateMetaprogrammingTypeTraitsTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CPP_TEMPLATE_METAPROGRAMMING_CLASS_IS_VALID_CONST_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookTemplate::CppTemplateMetaprogramming, CppTemplateMetaprogrammingTypeTraitsTesting)

void BookTemplate::CppTemplateMetaprogramming::CppTemplateMetaprogrammingTypeTraitsTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookTemplate::CppTemplateMetaprogramming::CppTemplateMetaprogrammingTypeTraitsTesting::MainTest() noexcept
{
    static_assert(std::is_same_v<TypeTraits<int>::has_trivial_default_constructor, FalseType>);
    static_assert(std::is_same_v<TypeTraits<int>::has_trivial_copy_constructor, FalseType>);
    static_assert(std::is_same_v<TypeTraits<int>::has_trivial_assignment_operator, FalseType>);
    static_assert(std::is_same_v<TypeTraits<int>::has_trivial_destructor, FalseType>);
    static_assert(std::is_same_v<TypeTraits<int>::is_POD_type, FalseType>);

    static_assert(std::is_same_v<TypeTraits<char>::has_trivial_default_constructor, TrueType>);
    static_assert(std::is_same_v<TypeTraits<char>::has_trivial_copy_constructor, TrueType>);
    static_assert(std::is_same_v<TypeTraits<char>::has_trivial_assignment_operator, TrueType>);
    static_assert(std::is_same_v<TypeTraits<char>::has_trivial_destructor, TrueType>);
    static_assert(std::is_same_v<TypeTraits<char>::is_POD_type, TrueType>);
}
