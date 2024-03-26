/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/13 13:16)

#ifndef SYSTEM_SECURITY_SUITE_RESOURCE_MANAGER_MAP_GENERIC_MASK_TESTING_H
#define SYSTEM_SECURITY_SUITE_RESOURCE_MANAGER_MAP_GENERIC_MASK_TESTING_H

#include "System/FileManager/Fwd/FileFlagsFwd.h"
#include "System/Security/Fwd/SecurityFlagsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <map>

namespace System
{
    class ResourceManagerMapGenericMaskTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = ResourceManagerMapGenericMaskTesting;
        using ParentType = UnitTest;

    public:
        explicit ResourceManagerMapGenericMaskTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        using MaskContainer = std::map<FileHandleDesiredAccess, AccessGenericMask>;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void ResourceManagerMapGenericMaskTest();
        void DoResourceManagerMapGenericMaskTest(FileHandleDesiredAccess fileHandleDesiredAccess, AccessGenericMask accessGenericMask);

    private:
        MaskContainer masks;
    };
}

#endif  // SYSTEM_SECURITY_SUITE_RESOURCE_MANAGER_MAP_GENERIC_MASK_TESTING_H