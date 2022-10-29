///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.3 (2022/10/29 19:54)

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
        using FileHandleDesiredAccessFlagsContainer = std::vector<FileHandleDesiredAccess>;
        using FileHandleShareModeFlagsContainer = std::vector<FileHandleShareMode>;
        using FileHandleCreationDispositionFlagsContainer = std::vector<FileHandleCreationDisposition>;

    private:
        FileHandleDesiredAccessFlagsContainer fileHandleDesiredAccessFlags;
        FileHandleShareModeFlagsContainer fileHandleShareModeFlags;
        FileHandleCreationDispositionFlagsContainer fileHandleCreationDispositionFlags;
        std::default_random_engine randomEngine;
        size_t maxSize;
    };
}

#endif  // SYSTEM_FILE_MANAGE_SUITE_CREATE_FILE_WITH_DEFAULT_ATTRIBUTES_TESTING_H