/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/01 10:51)

#ifndef CORE_TOOLS_FILE_MANAGER_GENERATE_RANDOM_NAME_DETAIL_H
#define CORE_TOOLS_FILE_MANAGER_GENERATE_RANDOM_NAME_DETAIL_H

#include "GenerateRandomName.h"
#include "System/Helper/PragmaWarning/NumericCast.h"

#include <random>

template <typename T>
requires(std::is_same_v<T, std::string> || std::is_same_v<T, std::wstring>)
T CoreTools::GenerateRandomName::GetName(int length, const T& letters, const T& extensionName)
{
    std::random_device randomDevice{};
    std::default_random_engine generator{ randomDevice() };
    std::uniform_int_distribution distribution{ 0, boost::numeric_cast<int>(letters.size() - 1) };

    T result{};
    for (auto i = 0; i < length; ++i)
    {
        result += letters.at(distribution(generator));
    }

    return result + extensionName;
}

#endif  // CORE_TOOLS_FILE_MANAGER_GENERATE_RANDOM_NAME_DETAIL_H