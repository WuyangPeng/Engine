/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 13:24)

#ifndef SYSTEM_SECURITY_SUITE_ACCESSES_GRANTED_FILE_MAP_TESTING_H
#define SYSTEM_SECURITY_SUITE_ACCESSES_GRANTED_FILE_MAP_TESTING_H

#include "AccessesGrantedTestingBase.h"

namespace System
{
    class AccessesGrantedFileMapTesting final : public AccessesGrantedTestingBase
    {
    public:
        using ClassType = AccessesGrantedFileMapTesting;
        using ParentType = AccessesGrantedTestingBase;

    public:
        explicit AccessesGrantedFileMapTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void FileMapGenericMaskTest();

        void DoFileMapGenericMaskTest(FileHandleDesiredAccess fileHandleDesiredAccess, AccessGenericMask accessGenericMask);

    private:
        MaskContainer masks;
    };
}

#endif  // SYSTEM_SECURITY_SUITE_ACCESSES_GRANTED_FILE_MAP_TESTING_H