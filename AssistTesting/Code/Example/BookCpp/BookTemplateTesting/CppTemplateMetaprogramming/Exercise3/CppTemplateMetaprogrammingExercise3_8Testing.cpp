///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.1.3 (2021/05/09 11:53)

#include "CppTemplateMetaprogrammingExercise3_8Testing.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h"
#include "Mathematics/Base/MathDetail.h"
#include "Example/BookCpp/CppTemplateMetaprogramming/Chapter3/Dimensions.h"
#include "Example/BookCpp/CppTemplateMetaprogramming/Exercise3/Exercise3_8.h"
#include "Example/BookCpp/CppTemplateMetaprogramming/Helper/CppTemplateMetaprogrammingClassInvariantMacro.h"

BookTemplate::CppTemplateMetaprogramming::CppTemplateMetaprogrammingExercise3_8Testing::CppTemplateMetaprogrammingExercise3_8Testing(const OStreamShared& stream)
    : ParentType{ stream }
{
    CPP_TEMPLATE_METAPROGRAMMING_CLASS_IS_VALID_CONST_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookTemplate::CppTemplateMetaprogramming, CppTemplateMetaprogrammingExercise3_8Testing)

void BookTemplate::CppTemplateMetaprogramming::CppTemplateMetaprogrammingExercise3_8Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookTemplate::CppTemplateMetaprogramming::CppTemplateMetaprogrammingExercise3_8Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(QuantityTest);
}

void BookTemplate::CppTemplateMetaprogramming::CppTemplateMetaprogrammingExercise3_8Testing::QuantityTest()
{
    Quantity4<float, Mass> m(1.5f);
    const Quantity4<float, Acceleration> a(9.8f);
    const Quantity4<float, Mass, 10> m2(0.5f);

    m = m + m2;
    ASSERT_APPROXIMATE(m.Value(), 1.55f, Mathematics::FloatMath::sm_Epsilon);
    m = m - m2;
    ASSERT_APPROXIMATE(m.Value(), 1.5f, Mathematics::FloatMath::sm_Epsilon);

    const Quantity4<float, Force> f0(1.0f);
    const Quantity4<float, Force> f1 = f0 + a * m2;
    ASSERT_APPROXIMATE(f1.Value(), a.Value() * m2.Value() / 10 + f0.Value(), Mathematics::FloatMath::sm_Epsilon);

    const Quantity4<float, Acceleration> a2 = (f1 - f0) / m2;
    ASSERT_APPROXIMATE(a.Value(), a2.Value(), Mathematics::FloatMath::sm_Epsilon);

    const Quantity4<float, Force> f2 = f0 + m2 * a; 
    ASSERT_APPROXIMATE(f2.Value(), f1.Value(), Mathematics::FloatMath::sm_Epsilon);

    const Quantity4<float, Acceleration> a3 = (f2 - f0) / m2;
    ASSERT_APPROXIMATE(a.Value(), a3.Value(), Mathematics::FloatMath::sm_Epsilon);
}
