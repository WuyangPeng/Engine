///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.2 (2021/04/08 23:04)

#include "Example/BookCpp/CppTemplateMetaprogramming/CppTemplateMetaprogrammingExport.h"

#include "IterSwap.h"
#include "System/Helper/PragmaWarning.h"

#include <algorithm>

void BookTemplate::CppTemplateMetaprogramming::F(int* p1, int* p2) noexcept
{
    IterSwap3(p1, p2);  // error: int* has no member `value_type'
}

void BookTemplate::CppTemplateMetaprogramming::Foo(int* i1, int* i2) noexcept
{
    if (i1 != nullptr && i2 != nullptr)
    {
        std::swap(*i1, *i2);
    }
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
BookTemplate::CppTemplateMetaprogramming::Proxy& BookTemplate::CppTemplateMetaprogramming::Proxy::operator=(bool x) noexcept
{
    if (x)
        bytes[pos / 8] |= (1u << (pos % 8));
    else
        bytes[pos / 8] &= ~(1u << (pos % 8));
    return *this;
}

BookTemplate::CppTemplateMetaprogramming::Proxy::operator bool() const noexcept
{
    return bytes[pos / 8] & (1u << (pos % 8));
}
#include STSTEM_WARNING_POP