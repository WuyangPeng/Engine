///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.1 (2021/03/02 22:00)

#include "Example/BookCpp/ExtendedSTL/ExtendedSTLExport.h"

#include "Balance.h"
#include "BalanceDeclaration.h"
#include "Example/BookCpp/ExtendedSTL/Helper/ExtendedSTLClassInvariantMacro.h"

BookStandardLibrary::ExtendedSTL::Balance::Balance() noexcept
{
    EXTENDED_STL_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(BookStandardLibrary::ExtendedSTL, Balance)

void BookStandardLibrary::ExtendedSTL::Balance::Main() const noexcept
{
    EXTENDED_STL_CLASS_IS_VALID_CONST_9;

    const NonCopyable nonCopyable{};
}
