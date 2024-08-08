/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.1.0 (2024/08/08 22:38)

#include "FileEnvironmentDirectoryTesting.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

Framework::FileEnvironmentDirectoryTesting::FileEnvironmentDirectoryTesting(const OStreamShared& stream)
    : ParentType{ stream, SYSTEM_TEXT("FrameworkEngineDirectory"), true }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, FileEnvironmentDirectoryTesting)