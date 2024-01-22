/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 09:35)

#ifndef CORE_TOOLS_MAIN_FUNCTION_HELPER_TESTING_INFORMATION_HELPER_IMPL_H
#define CORE_TOOLS_MAIN_FUNCTION_HELPER_TESTING_INFORMATION_HELPER_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "TestingInformation.h"
#include "System/Helper/PragmaWarning/PropertyTree.h"
#include "CoreTools/Contract/ContractFwd.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE TestingInformationHelperImpl final
    {
    public:
        using ClassType = TestingInformationHelperImpl;

    public:
        explicit TestingInformationHelperImpl(DisableNotThrow disableNotThrow);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetLoopCount(const std::string& suiteName, const std::string& testingName) const;

        NODISCARD bool IsPrintRun() const noexcept;

        NODISCARD int GetRandomSeed() const noexcept;

    private:
        using FileContainer = std::vector<std::string>;
        using Tree = boost::property_tree::ptree;

    private:
        void Analysis();
        void AnalysisFile();
        void AnalysisJson();
        void AnalysisInformation(Tree& tree);
        void AnalysisTestingInformation();

    private:
        TestingInformation testingInformation;
        FileContainer file;
        bool isPrintRun;
        int randomSeed;
    };
}

#endif  // CORE_TOOLS_MAIN_FUNCTION_HELPER_TESTING_INFORMATION_HELPER_IMPL_H