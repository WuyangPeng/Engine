///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/15 12:46)

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