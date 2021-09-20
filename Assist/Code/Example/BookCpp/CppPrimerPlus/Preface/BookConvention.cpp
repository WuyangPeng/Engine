///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.6.0.0 (2020/12/28 20:47)

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
