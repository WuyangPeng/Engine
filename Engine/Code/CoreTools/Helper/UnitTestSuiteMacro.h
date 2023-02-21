///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.2 (2023/02/16 23:34)

#ifndef CORE_TOOLS_HELPER_UNIT_TEST_SUITE_MACRO_H
#define CORE_TOOLS_HELPER_UNIT_TEST_SUITE_MACRO_H

// ��Ԫ���Կ������Ҫ�ĺ�
#include "CoreTools/Helper/UserMacro.h"

#define ADD_TEST(suite, testing) \
    AddTest<testing>((suite), (#suite), (#testing))

#define ADD_TEST_USE_PARAMETER_1(suite, testing, parameter) \
    AddTest<testing>((suite), (#suite), (#testing), (parameter))

#define ADD_TEST_USE_PARAMETER_2(suite, testing, parameter1, parameter2) \
    AddTest<testing>((suite), (#suite), (#testing), (parameter1), (parameter2))

#endif  // CORE_TOOLS_HELPER_UNIT_TEST_SUITE_MACRO_H
