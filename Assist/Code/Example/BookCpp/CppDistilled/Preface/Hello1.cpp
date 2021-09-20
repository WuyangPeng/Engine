///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.6.0.1 (2020/12/31 23:06)

// hello.cpp - Script 1.1
// 这是一个示例C++文件。

#include "Example/BookCpp/CppDistilled/CppDistilledExport.h"

#include "Example/BookCpp/CppDistilled/Helper/CppDistilledClassInvariantMacro.h"
#include "Hello1.h"

// 传统上的第一段程序
#include <iostream>

BookPrimary::CppDistilled::Hello1::Hello1() noexcept
{
    CPP_DISTILLED_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(BookPrimary::CppDistilled, Hello1)

int BookPrimary::CppDistilled::Hello1::Main() const
{
    CPP_DISTILLED_CLASS_IS_VALID_CONST_9;

    using namespace std;

    cout << "HELLO, WORLD!" << endl;

    return 0;
}
