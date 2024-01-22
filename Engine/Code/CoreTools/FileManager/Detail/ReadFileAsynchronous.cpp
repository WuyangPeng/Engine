/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 00:05)

#include "CoreTools/CoreToolsExport.h"

#include "ReadFileAsynchronous.h"
#include "CoreTools/FileManager/FileManagerHelper.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::ReadFileAsynchronous::ReadFileAsynchronous() noexcept
    : ParentType{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, ReadFileAsynchronous)

void CoreTools::ReadFileAsynchronous::AsynchronousExecution(const FileAsynchronousParameter& fileAsynchronousParameter)
{
    const auto fileName = fileAsynchronousParameter.GetFileName();

    const auto fileBuffer = FileManagerHelper::LoadFromFile(fileName, fileAsynchronousParameter.IsBinaryFile());

    const auto event = fileAsynchronousParameter.GetEvent();

    if (const auto eventSharedPtr = event.lock(); eventSharedPtr)
    {
        eventSharedPtr->EventFunction(fileAsynchronousParameter, fileBuffer);
    }
}
