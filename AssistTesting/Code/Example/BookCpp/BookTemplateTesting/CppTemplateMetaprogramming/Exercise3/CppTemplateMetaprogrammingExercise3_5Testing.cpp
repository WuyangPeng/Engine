///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.1.3 (2021/05/07 23:22)

#include "CppTemplateMetaprogrammingExercise3_5Testing.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h"
#include "Mathematics/Base/MathDetail.h"
#include "Example/BookCpp/CppTemplateMetaprogramming/Chapter3/Dimensions.h"
#include "Example/BookCpp/CppTemplateMetaprogramming/Chapter3/Quantity2.h"
#include "Example/BookCpp/CppTemplateMetaprogramming/Exercise3/Exercise3_5.h"
#include "Example/BookCpp/CppTemplateMetaprogramming/Helper/CppTemplateMetaprogrammingClassInvariantMacro.h"

#define OPEN_EXERCISE3_QUANTITY_ERROR1

#undef OPEN_EXERCISE3_QUANTITY_ERROR1

BookTemplate::CppTemplateMetaprogramming::CppTemplateMetaprogrammingExercise3_5Testing::CppTemplateMetaprogrammingExercise3_5Testing(const OStreamShared& stream)
    : ParentType{ stream }
{
    CPP_TEMPLATE_METAPROGRAMMING_CLASS_IS_VALID_CONST_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookTemplate::CppTemplateMetaprogramming, CppTemplateMetaprogrammingExercise3_5Testing)

void BookTemplate::CppTemplateMetaprogramming::CppTemplateMetaprogrammingExercise3_5Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookTemplate::CppTemplateMetaprogramming::CppTemplateMetaprogrammingExercise3_5Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(QuantityTest);
}

void BookTemplate::CppTemplateMetaprogramming::CppTemplateMetaprogrammingExercise3_5Testing::QuantityTest()
{
#ifdef OPEN_EXERCISE3_QUANTITY_ERROR1
    const Quantity2<float, Mass> m2(5.0f);
    const Quantity2<float, Acceleration> a2(9.8f);

    Quantity2<float, Force> f2 = m2 * a2;

    f2 = f2 + m2 * a2;
#endif  // OPEN_EXERCISE3_QUANTITY_ERROR1

    Quantity3<float, Mass> m(1.5f);
    const Quantity3<float, Acceleration> a(9.8f);
    const Quantity3<float, Mass> m2(0.5f);
    m = m + m2;
    Quantity3<float, Force> f(1.0f);
    f = f + m * a;
    std::cout << "f = " << f << "\n";
    const Quantity3<float, Acceleration> a2 = f / m;
}
