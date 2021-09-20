///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.6.0.0 (2020/12/28 20:47)

#include "Example/BookCpp/CppPrimerPlus/CppPrimerPlusExport.h"

#include "BookConvention.h"
#include "Example/BookCpp/CppPrimerPlus/Helper/CppPrimerPlusClassInvariantMacro.h"

#include <iostream>

BookPrimary::CppPrimerPlus::BookConvention::BookConvention() noexcept
{
    CPP_PRIMER_PLUS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(BookPrimary::CppPrimerPlus, BookConvention)

int BookPrimary::CppPrimerPlus::BookConvention::Main()
{
    using namespace std;

    cout << "What's up, Doc!\n";

    return 0;
}
