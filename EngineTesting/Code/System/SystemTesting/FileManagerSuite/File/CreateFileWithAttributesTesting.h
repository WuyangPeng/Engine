///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/15 12:14)

#ifndef SYSTEM_FILE_MANAGE_SUITE_CREATE_FILE_WITH_ATTRIBUTESTESTING_H
#define SYSTEM_FILE_MANAGE_SUITE_CREATE_FILE_WITH_ATTRIBUTESTESTING_H

#include "System/FileManager/Fwd/FileFlagsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <random>
#include <vector>

namespace System
{
    class CreateFileWithAttributesTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = CreateFileWithAttributesTesting;
        using ParentType = UnitTest;

    public:
        explicit CreateFileWithAttributesTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        NODISCARD bool RandomShuffleFlags();

        void CreateFileTest();

    private:
        using FileHandleDesiredAccessFlagsCollection = std::vector<FileHandleDesiredAccess>;
        using FileHandleShareModeFlagsCollection = std::vector<FileHandleShareMode>;
        using FileHandleCreationDispositionFlagsCollection = std::vector<FileHandleCreationDisposition>;
        using FileHandleAttributesFlagsCollection = std::vector<FileHandleAttributes>;
        using FileHandleOtherFlagsCollection = std::vector<FileHandleOther>;
        using FileHandleSecurityFlagsCollection = std::vector<FileHandleSecurity>;

    private:
        FileHandleDesiredAccessFlagsCollection fileHandleDesiredAccessFlags;
        FileHandleShareModeFlagsCollection fileHandleShareModeFlags;
        FileHandleCreationDispositionFlagsCollection fileHandleCreationDispositionFlags;
        FileHandleAttributesFlagsCollection fileHandleAttributesFlags;
        FileHandleOtherFlagsCollection fileHandleOtherFlags;
        FileHandleSecurityFlagsCollection fileHandleSecurityFlags;
        std::default_random_engine randomEngine;
        size_t maxSize;
    };
}

#endif  // SYSTEM_FILE_MANAGE_SUITE_CREATE_FILE_WITH_ATTRIBUTESTESTING_H