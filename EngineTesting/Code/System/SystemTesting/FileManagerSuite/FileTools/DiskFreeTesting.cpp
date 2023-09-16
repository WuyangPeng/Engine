///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 17:16)

#include "DiskFreeTesting.h"
#include "System/FileManager/FileTools.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::DiskFreeTesting::DiskFreeTesting(const OStreamShared& stream)
    : ParentType{ stream }, diskName{ SYSTEM_TEXT("C:") }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, DiskFreeTesting)

void System::DiskFreeTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::DiskFreeTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(DiskFreeSpaceTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DiskFreeSpaceWindowsULargeIntegerTest);
}

void System::DiskFreeTesting::DiskFreeSpaceTest()
{
    WindowsDWord sectorsPerCluster{ 0 };
    WindowsDWord bytesPerSector{ 0 };
    WindowsDWord numberOfFreeClusters{ 0 };
    WindowsDWord totalNumberOfClusters{ 0 };

    ASSERT_TRUE(GetDiskFreeSpaceWithRoot(diskName.c_str(), &sectorsPerCluster, &bytesPerSector, &numberOfFreeClusters, &totalNumberOfClusters));
    ASSERT_LESS(0u, sectorsPerCluster);
    ASSERT_LESS(0u, bytesPerSector);
    ASSERT_LESS(0u, numberOfFreeClusters);
    ASSERT_LESS(0u, totalNumberOfClusters);
}

void System::DiskFreeTesting::DiskFreeSpaceWindowsULargeIntegerTest()
{
    WindowsULargeInteger freeBytesAvailableToCaller{};
    WindowsULargeInteger totalNumberOfBytes{};
    WindowsULargeInteger totalNumberOfFreeBytes{};

    ASSERT_TRUE(GetDiskFreeSpaceWithRoot(diskName.c_str(), &freeBytesAvailableToCaller, &totalNumberOfBytes, &totalNumberOfFreeBytes));

    ASSERT_LESS(0u, freeBytesAvailableToCaller.QuadPart);
    ASSERT_LESS(0u, totalNumberOfBytes.QuadPart);
    ASSERT_LESS(0u, totalNumberOfFreeBytes.QuadPart);
}
