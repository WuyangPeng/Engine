///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.3 (2022/10/29 19:55)

#ifndef SYSTEM_FILE_MANAGE_SUITE_CREATE_FILE_WITH_SECURITY_FLAGS_TESTING_H
#define SYSTEM_FILE_MANAGE_SUITE_CREATE_FILE_WITH_SECURITY_FLAGS_TESTING_H

#include "System/FileManager/Fwd/FileFlagsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <random>
#include <vector>

namespace System
{
    class CreateFileWithSecurityFlagsTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = CreateFileWithSecurityFlagsTesting;
        using ParentType = UnitTest;

    public:
        explicit CreateFileWithSecurityFlagsTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        NODISCARD bool RandomShuffleFlags();
        void CreateFileTest();

    private:
        using FileHandleDesiredAccessFlagsContainer = std::vector<FileHandleDesiredAccess>;
        using FileHandleShareModeFlagsContainer = std::vector<FileHandleShareMode>;
        using FileHandleCreationDispositionFlagsContainer = std::vector<FileHandleCreationDisposition>;
        using FileHandleSecurityFlagsContainer = std::vector<FileHandleSecurity>;

    private:
        FileHandleDesiredAccessFlagsContainer fileHandleDesiredAccessFlags;
        FileHandleShareModeFlagsContainer fileHandleShareModeFlags;
        FileHandleCreationDispositionFlagsContainer fileHandleCreationDispositionFlags;
        FileHandleSecurityFlagsContainer fileHandleSecurityFlags;
        std::default_random_engine randomEngine;
        size_t maxSize;
    };
}

#endif  // SYSTEM_FILE_MANAGE_SUITE_CREATE_FILE_WITH_SECURITY_FLAGS_TESTING_H