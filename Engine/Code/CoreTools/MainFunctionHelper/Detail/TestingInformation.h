///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/29 22:09)

#ifndef CORE_TOOLS_MAIN_FUNCTION_HELPER_TESTING_INFORMATION_H
#define CORE_TOOLS_MAIN_FUNCTION_HELPER_TESTING_INFORMATION_H

#include "CoreTools/CoreToolsDll.h"

#include <map>
#include <string>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE TestingInformation final
    {
    public:
        using ClassType = TestingInformation;

    public:
        TestingInformation() noexcept;

        CLASS_INVARIANT_DECLARE;

        void Insert(const std::string& suiteName, const std::string& testingName, int testLoopCount);

        NODISCARD int GetLoopCount(const std::string& suiteName, const std::string& testingName) const;

    private:
        using TestingContainer = std::map<std::string, int>;
        using SuiteContainer = std::map<std::string, TestingContainer>;

    private:
        SuiteContainer suiteContainer;
    };
}

#endif  // CORE_TOOLS_MAIN_FUNCTION_HELPER_TESTING_INFORMATION_H