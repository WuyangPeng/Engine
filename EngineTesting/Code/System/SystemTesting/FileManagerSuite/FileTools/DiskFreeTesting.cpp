///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.3 (2021/05/24 14:51)

#include "DiskFreeTesting.h"
#include "System/FileManager/FileTools.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

System::DiskFreeTesting::DiskFreeTesting(const OStreamShared& stream)
    : ParentType{ stream }
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
}

void System::DiskFreeTesting::DiskFreeSpaceTest()
{
    WindowsDWord sectorsPerCluster{ 0 };
    WindowsDWord bytesPerSector{ 0 };
    WindowsDWord numberOfFreeClusters{ 0 };
    WindowsDWord totalNumberOfClusters{ 0 };
    const auto diskName = SYSTEM_TEXT("C:"s);

    ASSERT_TRUE(GetDiskFreeSpaceWithRoot(diskName.c_str(), &sectorsPerCluster, &bytesPerSector, &numberOfFreeClusters, &totalNumberOfClusters));
    ASSERT_LESS(0u, sectorsPerCluster);
    ASSERT_LESS(0u, bytesPerSector);
    ASSERT_LESS(0u, numberOfFreeClusters);
    ASSERT_LESS(0u, totalNumberOfClusters);

    WindowsULargeInteger freeBytesAvailableToCaller{};
    WindowsULargeInteger totalNumberOfBytes{};
    WindowsULargeInteger totalNumberOfFreeBytes{};

    ASSERT_TRUE(GetDiskFreeSpaceWithRoot(diskName.c_str(), &freeBytesAvailableToCaller, &totalNumberOfBytes, &totalNumberOfFreeBytes));

    ASSERT_LESS(0u, freeBytesAvailableToCaller.QuadPart);
    ASSERT_LESS(0u, totalNumberOfBytes.QuadPart);
    ASSERT_LESS(0u, totalNumberOfFreeBytes.QuadPart);
}
