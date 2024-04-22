/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/13 20:39)

#ifndef CORE_TOOLS_HELPER_SUITE_RTTI_MACRO_FINAL_TESTING_H
#define CORE_TOOLS_HELPER_SUITE_RTTI_MACRO_FINAL_TESTING_H

#include "RttiMacroTesting.h"

namespace CoreTools
{
    class RttiMacroFinalTesting final : public RttiMacroTesting
    {
    public:
        using ClassType = RttiMacroFinalTesting;
        using ParentType = RttiMacroTesting;

    public:
        explicit RttiMacroFinalTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    protected:
        NODISCARD const char* GetFinalRttiName() const noexcept;

    private:
        void DoRunUnitTest() override;
        void MainTest() override;

        void RttiTest() override;

        CORE_TOOLS_RTTI_FINAL_DECLARE;
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_RTTI_MACRO_FINAL_TESTING_H