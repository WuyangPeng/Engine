///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.5 (2022/12/13 15:51)

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
        void DoRunUnitTest() final;
        void MainTest();

        NODISCARD bool RandomShuffleFlags();
        void CreateFileTest();

        void DoCreateFileTest(size_t index);
        void CreateNewTest(size_t index, FileHandleCreationDisposition fileHandleCreationDisposition);
        void ExistingFileTest(size_t index, FileHandleCreationDisposition fileHandleCreationDisposition);
    };
}

#endif  // SYSTEM_FILE_MANAGER_SUITE_CREATE_FILE_WITH_SECURITY_FLAGS_TESTING_H