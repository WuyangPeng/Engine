/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/12 14:47)

#ifndef CORE_TOOLS_MAIN_FUNCTION_HELPER_TESTING_INFORMATION_HELPER_H
#define CORE_TOOLS_MAIN_FUNCTION_HELPER_TESTING_INFORMATION_HELPER_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <string>

CORE_TOOLS_NON_COPY_EXPORT_IMPL(TestingInformationHelperImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE TestingInformationHelper final
    {
    public:
        NON_COPY_TYPE_DECLARE(TestingInformationHelper);

    public:
        NODISCARD static TestingInformationHelper Create();

    private:
        explicit TestingInformationHelper(DisableNotThrow disableNotThrow);

    public:
        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetLoopCount(const std::string& suiteName, const std::string& testingName) const;

        NODISCARD bool IsPrintRun() const noexcept;

        NODISCARD int GetRandomSeed() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_MAIN_FUNCTION_HELPER_TESTING_INFORMATION_HELPER_H