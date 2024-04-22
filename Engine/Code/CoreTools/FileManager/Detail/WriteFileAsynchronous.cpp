/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/01 10:47)

#include "CoreTools/CoreToolsExport.h"

#include "WriteFileAsynchronous.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/FileManager/FileManagerHelper.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::WriteFileAsynchronous::WriteFileAsynchronous() noexcept
    : ParentType{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, WriteFileAsynchronous)

void CoreTools::WriteFileAsynchronous::AsynchronousExecution(const FileAsynchronousParameter& fileAsynchronousParameter)
{
    const auto fileName = fileAsynchronousParameter.GetFileName();

    const auto fileBuffer = fileAsynchronousParameter.GetFileBuffer();

    if (fileAsynchronousParameter.IsAppend())
    {
        FileManagerHelper::AppendToFile(fileName, fileAsynchronousParameter.IsBinaryFile(), boost::numeric_cast<int>(fileBuffer->GetSize()), fileBuffer->GetBufferBegin());
    }
    else
    {
        FileManagerHelper::SaveIntoFile(fileName, fileAsynchronousParameter.IsBinaryFile(), boost::numeric_cast<int>(fileBuffer->GetSize()), fileBuffer->GetBufferBegin());
    }

    const auto event = fileAsynchronousParameter.GetEvent();

    if (const auto eventSharedPtr = event.lock();
        eventSharedPtr != nullptr)
    {
        eventSharedPtr->EventFunction(fileAsynchronousParameter, *fileBuffer);
    }
}
