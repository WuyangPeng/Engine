///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.1 (2021/03/12 21:17)

#include "Example/BookCpp/CrossPlatformDevelopmentInCpp/CrossPlatformDevelopmentInCppExport.h"

#include "HelloWorld.h"
#include "Example/BookCpp/CrossPlatformDevelopmentInCpp/Helper/CrossPlatformDevelopmentInCppClassInvariantMacro.h"

#include <iostream>

using namespace std;

BookAdvanced::CrossPlatformDevelopmentInCpp::HelloWorld::HelloWorld() noexcept
{
    CROSS_PLATFORM_DEVELOPMENT_IN_CPP_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(BookAdvanced::CrossPlatformDevelopmentInCpp, HelloWorld)

int BookAdvanced::CrossPlatformDevelopmentInCpp::HelloWorld::Main() const
{
    CROSS_PLATFORM_DEVELOPMENT_IN_CPP_CLASS_IS_VALID_CONST_9;

    cout << "Hello\nWorld";

    return 0;
}
