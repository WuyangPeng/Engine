///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 13:40)

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

    private:
        MaskContainer masks;
    };
}

#endif  // SYSTEM_SECURITY_SUITE_RESOURCE_MANAGER_MAP_GENERIC_MASK_TESTING_H