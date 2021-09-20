///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.1.2 (2021/04/13 23:25)

#include "CppTemplateMetaprogrammingExercise3_0Testing.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h"
#include "Mathematics/Base/MathDetail.h"
#include "Example/BookCpp/CppTemplateMetaprogramming/Exercise3/Exercise3_0.h"
#include "Example/BookCpp/CppTemplateMetaprogramming/Helper/CppTemplateMetaprogrammingClassInvariantMacro.h"

#define OPEN_EXERCISE3_BINARY_ERROR1
#define OPEN_EXERCISE3_BINARY_ERROR2

#undef OPEN_EXERCISE3_BINARY_ERROR1
#undef OPEN_EXERCISE3_BINARY_ERROR2

BookTemplate::CppTemplateMetaprogramming::CppTemplateMetaprogrammingExercise3_0Testing::CppTemplateMetaprogrammingExercise3_0Testing(const OStreamShared& stream)
    : ParentType{ stream }
{
    CPP_TEMPLATE_METAPROGRAMMING_CLASS_IS_VALID_CONST_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookTemplate::CppTemplateMetaprogramming, CppTemplateMetaprogrammingExercise3_0Testing)

void BookTemplate::CppTemplateMetaprogramming::CppTemplateMetaprogrammingExercise3_0Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookTemplate::CppTemplateMetaprogramming::CppTemplateMetaprogrammingExercise3_0Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BinaryTest);
}

void BookTemplate::CppTemplateMetaprogramming::CppTemplateMetaprogrammingExercise3_0Testing::BinaryTest()
{
    std::cout << Exercise3Binary1<101010>::value << "\n";
    std::cout << Exercise3Binary2<101010>::value << "\n";

#ifdef OPEN_EXERCISE3_BINARY_ERROR1
    std::cout << Exercise3Binary1<121010>::value << "\n";
#endif  // OPEN_EXERCISE3_BINARY_ERROR1

#ifdef OPEN_EXERCISE3_BINARY_ERROR2
    std::cout << Exercise3Binary2<121010>::value << "\n";
#endif  // OPEN_EXERCISE3_BINARY_ERROR2
}
