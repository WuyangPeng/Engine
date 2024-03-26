/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/13 11:17)

#ifndef SYSTEM_FILE_MANAGER_SUITE_CREATE_FILE_WITH_ATTRIBUTES_TESTING_H
#define SYSTEM_FILE_MANAGER_SUITE_CREATE_FILE_WITH_ATTRIBUTES_TESTING_H

#include "CreateFileWithAttributesTestingBase.h"

namespace System
{
    class CreateFileWithAttributesTesting final : public CreateFileWithAttributesTestingBase
    {
    public:
        using ClassType = CreateFileWithAttributesTesting;
        using ParentType = CreateFileWithAttributesTestingBase;

    public:
        explicit CreateFileWithAttributesTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        NODISCARD bool RandomShuffleFlags();

        void CreateFileTest();

        void DoCreateFileTest(size_t index);
        void ReadOnlyTest(FileHandleAttribute fileHandleAttribute);
        void CommonTest(size_t index, FileHandleAttribute fileHandleAttribute);
        void ExistingTest(size_t index, FileHandleAttribute fileHandleAttribute, FileHandleCreationDisposition fileHandleCreationDisposition);
        void DoExistingTest(size_t index, FileHandleAttribute fileHandleAttribute, FileHandleCreationDisposition fileHandleCreationDisposition);
        void NonExistentTest(size_t index, FileHandleAttribute fileHandleAttribute, FileHandleCreationDisposition fileHandleCreationDisposition);

    private:
        String onlyReadFile;
    };
}

#endif  // SYSTEM_FILE_MANAGER_SUITE_CREATE_FILE_WITH_ATTRIBUTES_TESTING_H