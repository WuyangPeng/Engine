///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.5 (2022/12/13 14:54)

#ifndef SYSTEM_FILE_MANAGER_SUITE_CREATE_FILE_WITH_OTHER_FLAGS_TESTING_H
#define SYSTEM_FILE_MANAGER_SUITE_CREATE_FILE_WITH_OTHER_FLAGS_TESTING_H

#include "CreateFileWithAttributesTestingBase.h"

namespace System
{
    class CreateFileWithOtherFlagsTesting final : public CreateFileWithAttributesTestingBase
    {
    public:
        using ClassType = CreateFileWithOtherFlagsTesting;
        using ParentType = CreateFileWithAttributesTestingBase;

    public:
        explicit CreateFileWithOtherFlagsTesting(const OStreamShared& stream);

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

#endif  // SYSTEM_FILE_MANAGER_SUITE_CREATE_FILE_WITH_OTHER_FLAGS_TESTING_H