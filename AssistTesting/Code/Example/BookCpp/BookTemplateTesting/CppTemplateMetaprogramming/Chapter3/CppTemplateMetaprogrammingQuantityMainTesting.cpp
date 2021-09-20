///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.1.3 (2021/05/05 21:50)

#include "CppTemplateMetaprogrammingQuantityMainTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h"
#include "Example/BookCpp/CppTemplateMetaprogramming/Chapter3/Dimensions.h"
#include "Example/BookCpp/CppTemplateMetaprogramming/Chapter3/QuantityMain.h"
#include "Example/BookCpp/CppTemplateMetaprogramming/Helper/CppTemplateMetaprogrammingClassInvariantMacro.h"

BookTemplate::CppTemplateMetaprogramming::CppTemplateMetaprogrammingQuantityMainTesting::CppTemplateMetaprogrammingQuantityMainTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CPP_TEMPLATE_METAPROGRAMMING_CLASS_IS_VALID_CONST_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookTemplate::CppTemplateMetaprogramming, CppTemplateMetaprogrammingQuantityMainTesting)

void BookTemplate::CppTemplateMetaprogramming::CppTemplateMetaprogrammingQuantityMainTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookTemplate::CppTemplateMetaprogramming::CppTemplateMetaprogrammingQuantityMainTesting::MainTest()
{
    QuantityMain quantityMain{};

    quantityMain.Main();
    quantityMain.Test1();
    quantityMain.FF();

    const Quantity<float, Mass> m1{ 1.0f };
    const Quantity<float, Acceleration> a1{ 1.0f };
    quantityMain.Bogus(m1, a1);

    const BadQuantity<float, Mass> m2{ 1.0f };
    const BadQuantity<float, Acceleration> a2{ 1.0f };
    quantityMain.BadQuantityBogus2(m2, a2);
    quantityMain.BadQuantityTest1();

    const Quantity<float, Mass> m3{ 1.0f };
    const Quantity<float, Acceleration> a3{ 1.0f };
    quantityMain.Bogus2(m3, a3);

    quantityMain.Main3();
    quantityMain.Main2();
}
