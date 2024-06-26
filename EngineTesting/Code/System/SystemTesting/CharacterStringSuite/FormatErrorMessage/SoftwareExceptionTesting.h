/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/11 14:04)

#ifndef SYSTEM_CHARACTER_STRING_SUITE_SOFTWARE_EXCEPTION_TESTING_H
#define SYSTEM_CHARACTER_STRING_SUITE_SOFTWARE_EXCEPTION_TESTING_H

#include "System/Windows/Fwd/WindowsFlagsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <random>
#include <vector>

namespace System
{
    class SoftwareExceptionTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = SoftwareExceptionTesting;
        using ParentType = UnitTest;

    public:
        explicit SoftwareExceptionTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void RandomShuffleFlags();
        bool MakeSoftwareExceptionTest();
        void DoMakeSoftwareExceptionTest(size_t index);

    private:
        using SeverityContainer = std::vector<Severity>;
        using FacilityContainer = std::vector<Facility>;

    private:
        SeverityContainer severities;
        FacilityContainer facilities;
        size_t maxSize;
        std::default_random_engine randomEngine;
    };
}

#endif  // SYSTEM_CHARACTER_STRING_SUITE_SOFTWARE_EXCEPTION_TESTING_H