/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 13:15)

#ifndef SYSTEM_SECURITY_SUITE_ENLISTMENT_MAP_GENERIC_MASK_TESTING_H
#define SYSTEM_SECURITY_SUITE_ENLISTMENT_MAP_GENERIC_MASK_TESTING_H

#include "System/FileManager/Fwd/FileFlagsFwd.h"
#include "System/Security/Fwd/SecurityFlagsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <map>

namespace System
{
    class EnlistmentMapGenericMaskTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = EnlistmentMapGenericMaskTesting;
        using ParentType = UnitTest;

    public:
        explicit EnlistmentMapGenericMaskTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        using MaskContainer = std::map<FileHandleDesiredAccess, AccessGenericMask>;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void EnlistmentMapGenericMaskTest();
        void DoEnlistmentMapGenericMaskTest(FileHandleDesiredAccess fileHandleDesiredAccess, AccessGenericMask accessGenericMask);

    private:
        MaskContainer masks;
    };
}

#endif  // SYSTEM_SECURITY_SUITE_ENLISTMENT_MAP_GENERIC_MASK_TESTING_H