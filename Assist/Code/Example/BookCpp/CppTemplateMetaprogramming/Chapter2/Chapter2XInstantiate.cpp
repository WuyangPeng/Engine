///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.2 (2021/04/08 23:04)

#include "Example/BookCpp/CppTemplateMetaprogramming/CppTemplateMetaprogrammingExport.h"

#include "Chapter2X.h"
#include "Chapter2XInstantiate.h"
#include "Example/BookCpp/CppTemplateMetaprogramming/Helper/CppTemplateMetaprogrammingClassInvariantMacro.h"

#define OPEN_CHAPTER2X_ERROR1
#define OPEN_CHAPTER2X_ERROR2

#undef OPEN_CHAPTER2X_ERROR1
#undef OPEN_CHAPTER2X_ERROR2

BookTemplate::CppTemplateMetaprogramming::Chapter2XInstantiate::Chapter2XInstantiate() noexcept
{
    CPP_TEMPLATE_METAPROGRAMMING_SELF_CLASS_IS_VALID_9;
}

void BookTemplate::CppTemplateMetaprogramming::Chapter2XInstantiate::Main() const noexcept
{
    CPP_TEMPLATE_METAPROGRAMMING_CLASS_IS_VALID_CONST_9;

    typedef Chapter2X<int&, char> T1;  // OK，尚未实例化

#ifdef OPEN_CHAPTER2X_ERROR1
    T1 x1;  // 错误：指向int&的指针不合法
#endif  // OPEN_CHAPTER2X_ERROR1

    typedef Chapter2X<int, char&> T2;
    T2 x2{};  // OK，声明合格

#ifdef OPEN_CHAPTER2X_ERROR2
    MAYBE_UNUSED int a = x2.f(nullptr);  // 错误：元素为char&的数组非法。
#endif  // OPEN_CHAPTER2X_ERROR2
}
