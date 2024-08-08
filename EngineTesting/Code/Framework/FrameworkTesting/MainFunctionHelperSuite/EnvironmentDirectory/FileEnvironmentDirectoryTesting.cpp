/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.1.0 (2024/08/08 22:38)

#include "FileEnvironmentDirectoryTesting.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

Framework::FileEnvironmentDirectoryTesting::FileEnvironmentDirectoryTesting(const OStreamShared& stream)
    : ParentType{ stream, SYSTEM_TEXT("FrameworkEngineDirectory"), true }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, FileEnvironmentDirectoryTesting)