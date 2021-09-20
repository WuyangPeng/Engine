///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.2 (2021/03/31 20:03)

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
        using SeverityFlagsCollection = std::vector<Severity>;
        using FacilityFlagsCollection = std::vector<Facility>;

    private:
        SeverityFlagsCollection severityFlags;
        FacilityFlagsCollection facilityFlags;
        size_t maxSize;
        std::default_random_engine randomEngine;
    };
}

#endif  // SYSTEM_CHARACTER_STRING_SUITE_SOFTWARE_EXCEPTION_TESTING_H