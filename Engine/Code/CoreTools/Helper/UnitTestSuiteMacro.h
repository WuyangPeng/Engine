///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.2 (2023/02/16 23:34)

#ifndef CORE_TOOLS_HELPER_UNIT_TEST_SUITE_MACRO_H
#define CORE_TOOLS_HELPER_UNIT_TEST_SUITE_MACRO_H

// 单元测试框架所需要的宏
#include "CoreTools/Helper/UserMacro.h"

#define ADD_TEST(suite, testing) \
    AddTest<testing>((suite), (#suite), (#testing))

#define ADD_TEST_USE_PARAMETER_1(suite, testing, parameter) \
    AddTest<testing>((suite), (#suite), (#testing), (parameter))

#define ADD_TEST_USE_PARAMETER_2(suite, testing, parameter1, parameter2) \
    AddTest<testing>((suite), (#suite), (#testing), (parameter1), (parameter2))

#endif  // CORE_TOOLS_HELPER_UNIT_TEST_SUITE_MACRO_H
