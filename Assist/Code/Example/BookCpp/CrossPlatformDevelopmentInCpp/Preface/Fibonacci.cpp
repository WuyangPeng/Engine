///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.1 (2021/03/12 21:17)

#include "Example/BookCpp/CrossPlatformDevelopmentInCpp/CrossPlatformDevelopmentInCppExport.h"

#include "Fibonacci.h"
#include "Example/BookCpp/CrossPlatformDevelopmentInCpp/Helper/CrossPlatformDevelopmentInCppClassInvariantMacro.h"

BookAdvanced::CrossPlatformDevelopmentInCpp::Fibonacci::Fibonacci() noexcept
{
    CROSS_PLATFORM_DEVELOPMENT_IN_CPP_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(BookAdvanced::CrossPlatformDevelopmentInCpp, Fibonacci)

int BookAdvanced::CrossPlatformDevelopmentInCpp::Fibonacci::F(const int n) const noexcept
{
    CROSS_PLATFORM_DEVELOPMENT_IN_CPP_CLASS_IS_VALID_CONST_9;

    if (!n || n == 1)
        return n;

    return (F(n - 1) + F(n - 2));
}