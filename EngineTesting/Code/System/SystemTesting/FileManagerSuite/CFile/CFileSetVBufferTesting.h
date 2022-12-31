///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.5 (2022/12/12 18:53)

#ifndef SYSTEM_FILE_MANAGER_SUITE_CFILE_SETV_BUFFER_TESTING_H
#define SYSTEM_FILE_MANAGER_SUITE_CFILE_SETV_BUFFER_TESTING_H

#include "CFileTestingBase.h"

namespace System
{
    class CFileSetVBufferTesting final : public CFileTestingBase
    {
    public:
        using ClassType = CFileSetVBufferTesting;
        using ParentType = CFileTestingBase;

    public:
        explicit CFileSetVBufferTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void SetVBufferTest();

        void DoSetVBufferTest(FILE* file);
    };
}

#endif  // SYSTEM_FILE_MANAGER_SUITE_CFILE_SETV_BUFFER_TESTING_H