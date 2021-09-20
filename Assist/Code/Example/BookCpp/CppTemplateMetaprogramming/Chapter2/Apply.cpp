///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.2 (2021/04/08 23:04)

#include "Example/BookCpp/CppTemplateMetaprogramming/CppTemplateMetaprogrammingExport.h"

#include "Apply.h"
#include "ApplyFg.h"
#include "Example/BookCpp/CppTemplateMetaprogramming/Helper/CppTemplateMetaprogrammingClassInvariantMacro.h"

#include <functional>

BookTemplate::CppTemplateMetaprogramming::Apply::Apply() noexcept
{
    CPP_TEMPLATE_METAPROGRAMMING_SELF_CLASS_IS_VALID_9;
}

void BookTemplate::CppTemplateMetaprogramming::Apply::Main() const
{
    CPP_TEMPLATE_METAPROGRAMMING_CLASS_IS_VALID_CONST_9;

    MAYBE_UNUSED const float a = ApplyFg(5.0f, std::negate<float>(), Log2);
    MAYBE_UNUSED const float b = ApplyFg(3.14f, Log2, std::negate<float>());
}
