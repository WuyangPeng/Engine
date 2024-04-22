/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/12 14:44)

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