///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.2 (2021/04/07 23:38)

#ifndef CPP_TEMPLATE_METAPROGRAMMING_CHAPTER2_APPLY_FG_H
#define CPP_TEMPLATE_METAPROGRAMMING_CHAPTER2_APPLY_FG_H

#include "Example/BookCpp/CppTemplateMetaprogramming/CppTemplateMetaprogrammingDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookTemplate
{
    namespace CppTemplateMetaprogramming
    {
        template <class X, class Blob>
        X ApplyFg(X x, Blob blob)
        {
            return blob.f(blob.g(x));
        }

        template <class X, class UnaryOp1, class UnaryOp2>
        X ApplyFg(X x, UnaryOp1 f, UnaryOp2 g)
        {
            return f(g(x));
        }

        float Log2(float) noexcept;
    }
}

#endif  // CPP_TEMPLATE_METAPROGRAMMING_CHAPTER2_APPLY_FG_H
