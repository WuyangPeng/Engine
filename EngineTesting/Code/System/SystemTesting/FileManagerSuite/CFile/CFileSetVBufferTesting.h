///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 17:11)

#ifndef SYSTEM_FILE_MANAGER_SUITE_C_FILE_SET_V_BUFFER_TESTING_H
#define SYSTEM_FILE_MANAGER_SUITE_C_FILE_SET_V_BUFFER_TESTING_H

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
        void DoRunUnitTest() override;
        void MainTest();

        void SetVBufferTest();

        void DoSetVBufferTest(FILE* file);
    };
}

#endif  // SYSTEM_FILE_MANAGER_SUITE_C_FILE_SET_V_BUFFER_TESTING_H