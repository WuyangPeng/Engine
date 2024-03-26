/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 11:17)

#ifndef SYSTEM_FILE_MANAGER_SUITE_CREATE_FILE_WITH_SECURITY_FLAGS_TESTING_H
#define SYSTEM_FILE_MANAGER_SUITE_CREATE_FILE_WITH_SECURITY_FLAGS_TESTING_H

#include "CreateFileWithAttributesTestingBase.h"

namespace System
{
    class CreateFileWithSecurityFlagsTesting final : public CreateFileWithAttributesTestingBase
    {
    public:
        using ClassType = CreateFileWithSecurityFlagsTesting;
        using ParentType = CreateFileWithAttributesTestingBase;

    public:
        explicit CreateFileWithSecurityFlagsTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        NODISCARD bool RandomShuffleFlags();
        void CreateFileTest();

        void DoCreateFileTest(size_t index);
        void CreateNewTest(size_t index, FileHandleCreationDisposition fileHandleCreationDisposition);
        void ExistingFileTest(size_t index, FileHandleCreationDisposition fileHandleCreationDisposition);
    };
}

#endif  // SYSTEM_FILE_MANAGER_SUITE_CREATE_FILE_WITH_SECURITY_FLAGS_TESTING_H