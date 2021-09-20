///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.3 (2021/04/26 22:39)

#include "Example/BookCpp/CppTemplateMetaprogramming/CppTemplateMetaprogrammingExport.h"

#include "Lambda.h"
#include "LambdaMain.h"
#include "Example/BookCpp/CppTemplateMetaprogramming/Helper/CppTemplateMetaprogrammingClassInvariantMacro.h"

#define OPEN_CHAPTER3_LAMBDA_ERROR1

#undef OPEN_CHAPTER3_LAMBDA_ERROR1

BookTemplate::CppTemplateMetaprogramming::LambdaMain::LambdaMain() noexcept
{
    CPP_TEMPLATE_METAPROGRAMMING_SELF_CLASS_IS_VALID_9;
}

void BookTemplate::CppTemplateMetaprogramming::LambdaMain::Main() const noexcept
{
    CPP_TEMPLATE_METAPROGRAMMING_CLASS_IS_VALID_CONST_9;

#ifdef OPEN_CHAPTER3_LAMBDA_ERROR1
    typedef TwoPointers1<int>::type Intstar2;
#endif  // OPEN_CHAPTER3_LAMBDA_ERROR1

    int* x{};

    MAYBE_UNUSED Twice5<AddPointerF5, int>::type p = &x;
    MAYBE_UNUSED Twice5<boost::add_pointer<_1>, int>::type q = &x;
}


