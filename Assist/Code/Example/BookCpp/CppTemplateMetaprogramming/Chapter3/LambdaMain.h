///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.3 (2021/05/04 22:36)

#ifndef CPP_TEMPLATE_METAPROGRAMMING_CHAPTER3_LAMBDA_MAIN_H
#define CPP_TEMPLATE_METAPROGRAMMING_CHAPTER3_LAMBDA_MAIN_H

#include "Example/BookCpp/CppTemplateMetaprogramming/CppTemplateMetaprogrammingDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookTemplate
{
    namespace CppTemplateMetaprogramming
    {
        class CPP_TEMPLATE_METAPROGRAMMING_DEFAULT_DECLARE LambdaMain final
        {
        public:
            using ClassType = LambdaMain;

        public:
            LambdaMain() noexcept;

            CLASS_INVARIANT_DECLARE;

            void Main() const noexcept;
        };
    }
}

#endif  // CPP_TEMPLATE_METAPROGRAMMING_CHAPTER3_LAMBDA_MAIN_H
