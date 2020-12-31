//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/23 18:26)

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

        [[nodiscard]] int GetLoopCount(const std::string& suiteName, const std::string& testingName) const;

        [[nodiscard]] bool IsPrintRun() const noexcept;

        [[nodiscard]] int GetRandomSeed() const noexcept;

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
        TestingInformation m_TestingInformation;
        FileContainer m_File;
        bool m_IsPrintRun;
        int m_RandomSeed;
    };
}

#endif  // CORE_TOOLS_MAIN_FUNCTION_HELPER_TESTING_INFORMATION_HELPER_IMPL_H