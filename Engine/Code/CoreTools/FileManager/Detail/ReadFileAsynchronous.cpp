/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 00:05)

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
