///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.2 (2023/02/13 20:06)

#ifndef CORE_TOOLS_HELPER_SUITE_RTTI_MACRO_TESTING_H
#define CORE_TOOLS_HELPER_SUITE_RTTI_MACRO_TESTING_H

#include "RttiMacroBaseTesting.h"

namespace CoreTools
{
    class RttiMacroTesting : public RttiMacroBaseTesting
    {
    public:
        using ClassType = RttiMacroTesting;
        using ParentType = RttiMacroBaseTesting;

    public:
        explicit RttiMacroTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;
        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;

    protected:
        NODISCARD const char* GetRttiName() const noexcept;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void RttiTest();
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_RTTI_MACRO_TESTING_H