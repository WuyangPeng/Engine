///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.3 (2022/10/29 19:52)

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
        using FileHandleDesiredAccessFlagsContainer = std::vector<FileHandleDesiredAccess>;
        using FileHandleShareModeFlagsContainer = std::vector<FileHandleShareMode>;
        using FileHandleCreationDispositionFlagsContainer = std::vector<FileHandleCreationDisposition>;
        using FileHandleAttributesFlagsContainer = std::vector<FileHandleAttributes>;
        using FileHandleOtherFlagsContainer = std::vector<FileHandleOther>;
        using FileHandleSecurityFlagsContainer = std::vector<FileHandleSecurity>;

    private:
        FileHandleDesiredAccessFlagsContainer fileHandleDesiredAccessFlags;
        FileHandleShareModeFlagsContainer fileHandleShareModeFlags;
        FileHandleCreationDispositionFlagsContainer fileHandleCreationDispositionFlags;
        FileHandleAttributesFlagsContainer fileHandleAttributesFlags;
        FileHandleOtherFlagsContainer fileHandleOtherFlags;
        FileHandleSecurityFlagsContainer fileHandleSecurityFlags;
        std::default_random_engine randomEngine;
        size_t maxSize;
    };
}

#endif  // SYSTEM_FILE_MANAGE_SUITE_CREATE_FILE_WITH_ATTRIBUTESTESTING_H