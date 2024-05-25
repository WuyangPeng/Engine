/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.9 (2024/05/04 23:44)

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