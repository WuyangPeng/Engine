///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/09 1:43)

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

    auto fileBuffer = FileManagerHelper::LoadFromFile(fileName, fileAsynchronousParameter.IsBinaryFile());

    auto event = fileAsynchronousParameter.GetEvent();

    auto eventSharedPtr = event.lock();

    if (eventSharedPtr)
    {
        eventSharedPtr->EventFunction(fileAsynchronousParameter, fileBuffer);
    }
}
