///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.3 (2021/04/26 22:39)

#include "Example/BookCpp/CppTemplateMetaprogramming/CppTemplateMetaprogrammingExport.h"

#include "Dimensions.h"
#include "Quantity.h"
#include "Quantity2.h"
#include "QuantityMain.h"
#include "Example/BookCpp/CppTemplateMetaprogramming//Helper/CppTemplateMetaprogrammingCustomAssertMacro.h"
#include "Example/BookCpp/CppTemplateMetaprogramming/Helper/CppTemplateMetaprogrammingClassInvariantMacro.h"

#include <iostream>

#define OPEN_CHAPTER3_QUANTITY_ERROR1
#define OPEN_CHAPTER3_QUANTITY_ERROR2
#define OPEN_CHAPTER3_QUANTITY_ERROR3
#define OPEN_CHAPTER3_QUANTITY_ERROR4

#undef OPEN_CHAPTER3_QUANTITY_ERROR1
#undef OPEN_CHAPTER3_QUANTITY_ERROR2
#undef OPEN_CHAPTER3_QUANTITY_ERROR3
#undef OPEN_CHAPTER3_QUANTITY_ERROR4

BookTemplate::CppTemplateMetaprogramming::QuantityMain::QuantityMain() noexcept
{
    CPP_TEMPLATE_METAPROGRAMMING_SELF_CLASS_IS_VALID_9;
}

void BookTemplate::CppTemplateMetaprogramming::QuantityMain::Main() const noexcept
{
    CPP_TEMPLATE_METAPROGRAMMING_CLASS_IS_VALID_CONST_9;

    const Quantity<float, Length> l(1.0f);
    Quantity<float, Mass> m(2.0f);

#ifdef OPEN_CHAPTER3_QUANTITY_ERROR1
    m = l;  // 编译期错误
#endif  // OPEN_CHAPTER3_QUANTITY_ERROR1

    m = m;
}

void BookTemplate::CppTemplateMetaprogramming::QuantityMain::Test1() const noexcept
{
    Quantity<float, Length> len1(1.0f);
    const Quantity<float, Length> len2(2.0f);

    len1 = len1 + len2;  // OK

#ifdef OPEN_CHAPTER3_QUANTITY_ERROR2
    len1 = len2 + Quantity<float, Mass>(3.7f);
#endif  // OPEN_CHAPTER3_QUANTITY_ERROR2
}

void BookTemplate::CppTemplateMetaprogramming::QuantityMain::FF() const
{
    const Quantity<float, Mass> m(5.0f);
    const Quantity<float, Acceleration> a(9.8f);
    std::cout << "force = " << (m * a).value();
}

void BookTemplate::CppTemplateMetaprogramming::QuantityMain::Bogus(MAYBE_UNUSED Quantity<float, Mass> m, MAYBE_UNUSED Quantity<float, Acceleration> a) const noexcept
{
#ifdef OPEN_CHAPTER3_QUANTITY_ERROR3
    Quantity<float, Force> f = m * a;
#endif  // OPEN_CHAPTER3_QUANTITY_ERROR3
}

void BookTemplate::CppTemplateMetaprogramming::QuantityMain::BadQuantityBogus2(BadQuantity<float, Mass> m, BadQuantity<float, Acceleration> a) const noexcept
{
    // Should yield a force, not a mass!
    const BadQuantity<float, Mass> bogus = m * a;
}

void BookTemplate::CppTemplateMetaprogramming::QuantityMain::BadQuantityTest1() const noexcept
{
    BadQuantity<float, Length> len1(1.0f);
    const BadQuantity<float, Length> len2(2.0f);

    len1 = len1 + len2;  // OK
}

void BookTemplate::CppTemplateMetaprogramming::QuantityMain::Bogus2(Quantity<float, Mass> m, Quantity<float, Acceleration> a) const noexcept
{
#ifdef OPEN_CHAPTER3_QUANTITY_ERROR4
    // Should yield a force, not a mass!
    Quantity<float, Mass> bogus1 = m * a;
#endif  // OPEN_CHAPTER3_QUANTITY_ERROR4

    const Quantity<float, Force> bogus = m * a;
}

void BookTemplate::CppTemplateMetaprogramming::QuantityMain::Main3()
{
    const Quantity<float, Mass> m(5.0f);
    const Quantity<float, Acceleration> a(9.8f);
    const Quantity<float, Force> f = m * a;

    const Quantity<float, Mass> m2 = f / a;
    MAYBE_UNUSED const float rounding_error = std::abs((m2 - m).value());

    CPP_TEMPLATE_METAPROGRAMMING_ASSERTION_0(rounding_error < .001, "rounding_error < .001");
}

void BookTemplate::CppTemplateMetaprogramming::QuantityMain::Main2()
{
    const Quantity2<float, Mass> m(5.0f);
    const Quantity2<float, Acceleration> a(9.8f);
    const Quantity2<float, Force> f = m * a;

    const Quantity2<float, Mass> m2 = f / a;
    MAYBE_UNUSED const float rounding_error = std::abs((m2 - m).value());

    CPP_TEMPLATE_METAPROGRAMMING_ASSERTION_0(rounding_error < .001, "rounding_error < .001");
}
