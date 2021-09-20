///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.6.0.1 (2020/12/31 23:06)

#include "Example/BookCpp/CppProgramming/CppProgrammingExport.h"

#include "Example/BookCpp/CppProgramming/Helper/CppProgrammingClassInvariantMacro.h"
#include "Hello.h"

// hello.cpp - Script 1.1
// 这是一个示例C++文件。

#include <iostream>

BookPrimary::CppProgramming::Hello::Hello() noexcept
{
    CPP_PROGRAMMING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(BookPrimary::CppProgramming, Hello)

int BookPrimary::CppProgramming::Hello::Main() const
{
    CPP_PROGRAMMING_CLASS_IS_VALID_CONST_9;

    // Say hello
    std::cout << "hello, World!";
    std::cout << "hello, World! How are you doing on this fine Sunday afternoon?";

    return 0;
}
