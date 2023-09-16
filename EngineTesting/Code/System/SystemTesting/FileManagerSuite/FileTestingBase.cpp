///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 17:16)

#include "System/FileManager/File.h"
#include "System/SystemTesting/FileManagerSuite/FileTestingBase.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::FileTestingBase::FileTestingBase(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, FileTestingBase)

void System::FileTestingBase::IsFileHandleValidTest(WindowsHandle handle)
{
    ASSERT_TRUE(IsFileHandleValid(handle));
}

void System::FileTestingBase::CloseFile(WindowsHandle handle)
{
    ASSERT_TRUE(CloseSystemFile(handle));
}

void System::FileTestingBase::RemoveFile(const String& fileName)
{
    ASSERT_TRUE(RemoveSystemFile(fileName));
}