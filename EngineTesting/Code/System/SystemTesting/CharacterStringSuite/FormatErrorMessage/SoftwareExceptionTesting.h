///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.3 (2022/10/14 1:15)

#ifndef SYSTEM_CHARACTER_STRING_SUITE_SOFTWARE_EXCEPTION_TESTING_H
#define SYSTEM_CHARACTER_STRING_SUITE_SOFTWARE_EXCEPTION_TESTING_H

#include "System/Windows/Fwd/WindowsFlagsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <random>
#include <vector>

namespace System
{
    class SoftwareExceptionTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = SoftwareExceptionTesting;
        using ParentType = UnitTest;

    public:
        explicit SoftwareExceptionTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void RandomShuffleFlags();
        bool MakeSoftwareExceptionTest();

    private:
        using SeverityFlagsContainer = std::vector<Severity>;
        using FacilityFlagsContainer = std::vector<Facility>;

    private:
        SeverityFlagsContainer severityFlags;
        FacilityFlagsContainer facilityFlags;
        size_t maxSize;
        std::default_random_engine randomEngine;
    };
}

#endif  // SYSTEM_CHARACTER_STRING_SUITE_SOFTWARE_EXCEPTION_TESTING_H