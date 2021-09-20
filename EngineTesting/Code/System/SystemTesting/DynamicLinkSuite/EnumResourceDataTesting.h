///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.2 (2021/03/30 13:05)

#ifndef SYSTEM_TESTING_SYSTEM_OUTPUT_SUITE_ENUM_RESOURCE_DATA_TESTING_H
#define SYSTEM_TESTING_SYSTEM_OUTPUT_SUITE_ENUM_RESOURCE_DATA_TESTING_H

#include "System/DynamicLink/Using/LoadLibraryUsing.h"
#include "System/SystemOutput/Fwd/SystemOutputFlagsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <random>
#include <vector>

namespace System
{
    class EnumResourceDataTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = EnumResourceDataTesting;
        using ParentType = UnitTest;

    public:
        explicit EnumResourceDataTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

    private:
        using PrimaryLanguageFlagsCollection = std::vector<PrimaryLanguage>;
        using SubLanguageFlagsCollection = std::vector<SubLanguage>;
        using TypeFlagsCollection = std::vector<const DynamicLinkCharType*>;
        using NameFlagsCollection = std::vector<const DynamicLinkCharType*>;

        NODISCARD static NameFlagsCollection CreateNameFlags();
        NODISCARD bool RandomShuffleFlags();
        void DataTest();

    private:
        PrimaryLanguageFlagsCollection primaryLanguageFlags;
        SubLanguageFlagsCollection subLanguageFlags;
        TypeFlagsCollection typeFlags;
        NameFlagsCollection nameFlags;
        size_t maxSize;
        std::default_random_engine randomEngine;
    };
}

#endif  // SYSTEM_TESTING_SYSTEM_OUTPUT_SUITE_ENUM_RESOURCE_DATA_TESTING_H