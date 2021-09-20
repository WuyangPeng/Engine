///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.3 (2021/05/04 22:36)

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
