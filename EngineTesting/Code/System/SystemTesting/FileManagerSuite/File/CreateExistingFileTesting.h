///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.5 (2022/12/12 23:38)

#ifndef SYSTEM_FILE_MANAGER_SUITE_CREATE_EXISTING_FILE_TESTING_H
#define SYSTEM_FILE_MANAGER_SUITE_CREATE_EXISTING_FILE_TESTING_H

#include "System/SystemTesting/FileManagerSuite/FileTestingBase.h"

namespace System
{
    class CreateExistingFileTesting final : public FileTestingBase
    {
    public:
        using ClassType = CreateExistingFileTesting;
        using ParentType = FileTestingBase;

    public:
        explicit CreateExistingFileTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void CreateExistingFileTest();

    private:
        String existingFileName;
    };
}

#endif  // SYSTEM_FILE_MANAGER_SUITE_CREATE_EXISTING_FILE_TESTING_H