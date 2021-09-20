///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.3 (2021/05/21 10:40)

#ifndef SYSTEM_FILE_MANAGE_SUITE_CREATE_FILE_WITH_DEFAULT_ATTRIBUTES_TESTING_H
#define SYSTEM_FILE_MANAGE_SUITE_CREATE_FILE_WITH_DEFAULT_ATTRIBUTES_TESTING_H

#include "System/FileManager/Fwd/FileFlagsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <random>
#include <vector>

namespace System
{
    class CreateFileWithDefaultAttributesTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = CreateFileWithDefaultAttributesTesting;
        using ParentType = UnitTest;

    public:
        explicit CreateFileWithDefaultAttributesTesting(const OStreamShared& stream);

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

    private:
        FileHandleDesiredAccessFlagsCollection fileHandleDesiredAccessFlags;
        FileHandleShareModeFlagsCollection fileHandleShareModeFlags;
        FileHandleCreationDispositionFlagsCollection fileHandleCreationDispositionFlags;
        std::default_random_engine randomEngine;
        size_t maxSize;
    };
}

#endif  // SYSTEM_FILE_MANAGE_SUITE_CREATE_FILE_WITH_DEFAULT_ATTRIBUTES_TESTING_H