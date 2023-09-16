///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/31 17:16)

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