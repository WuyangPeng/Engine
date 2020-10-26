//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/26 9:54)

#ifndef CORE_TOOLS_MAIN_FUNCTION_HELPER_TESTING_INFORMATION_HELPER_H
#define CORE_TOOLS_MAIN_FUNCTION_HELPER_TESTING_INFORMATION_HELPER_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <string>

CORE_TOOLS_EXPORT_SHARED_PTR(TestingInformationHelperImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE TestingInformationHelper final
    {
    public:
        NON_COPY_CLASSES_TYPE_DECLARE(TestingInformationHelper);

    public:
        explicit TestingInformationHelper(DisableNotThrow disableNotThrow);
        ~TestingInformationHelper() noexcept = default;
        TestingInformationHelper(const TestingInformationHelper& rhs) = delete;
        TestingInformationHelper& operator=(const TestingInformationHelper& rhs) = delete;
        TestingInformationHelper(TestingInformationHelper&& rhs) noexcept;
        TestingInformationHelper& operator=(TestingInformationHelper&& rhs) noexcept;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] int GetLoopCount(const std::string& suiteName, const std::string& testingName) const;

        [[nodiscard]] bool IsPrintRun() const noexcept;

        [[nodiscard]] int GetRandomSeed() const noexcept;

    private:
        IMPL_TYPE_DECLARE(TestingInformationHelper);
    };
}

#endif  // CORE_TOOLS_MAIN_FUNCTION_HELPER_TESTING_INFORMATION_HELPER_H