/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/05/04 23:44)

#ifndef CORE_TOOLS_TESTING_GENERATE_RANDOM_NAME_TESTING_DETAIL_H
#define CORE_TOOLS_TESTING_GENERATE_RANDOM_NAME_TESTING_DETAIL_H

#include "GenerateRandomNameTesting.h"
#include "CoreTools/Helper/AssertMacro.h"

template <typename T>
void CoreTools::GenerateRandomNameTesting::ResultTest(int length, const T& name, const T& extensionName)
{
    ASSERT_EQUAL(name.size(), length + extensionName.size() + 1);
    ASSERT_EQUAL(name.find(extensionName), name.size() - extensionName.size());
}

#endif  // CORE_TOOLS_TESTING_GENERATE_RANDOM_NAME_TESTING_DETAIL_H