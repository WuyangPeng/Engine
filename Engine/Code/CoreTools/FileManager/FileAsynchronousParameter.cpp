///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/22 14:08)

#include "CoreTools/CoreToolsExport.h"

#include "FileAsynchronousParameter.h"
#include "Detail/FileAsynchronousParameterImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::FileAsynchronousParameter::FileAsynchronousParameter(const String& fileName, bool binaryFile, const FileEventInterfaceSharedPtr& event)
    : impl{ fileName, binaryFile, event }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::FileAsynchronousParameter::FileAsynchronousParameter(const String& fileName, bool binaryFile, const ConstFileBufferSharedPtr& FileBuffer, bool append)
    : impl{ fileName, binaryFile, FileBuffer, append }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::FileAsynchronousParameter::FileAsynchronousParameter(const String& fileName, bool binaryFile, const FileEventInterfaceSharedPtr& event, const ConstFileBufferSharedPtr& FileBuffer, bool append)
    : impl{ fileName, binaryFile, event, FileBuffer, append }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, FileAsynchronousParameter)

CoreTools::FileAsynchronousParameter::String CoreTools::FileAsynchronousParameter::GetFileName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetFileName();
}

bool CoreTools::FileAsynchronousParameter::IsBinaryFile() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->IsBinaryFile();
}

CoreTools::FileEventInterfaceWeakPtr CoreTools::FileAsynchronousParameter::GetEvent() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetEvent();
}

CoreTools::ConstFileBufferSharedPtr CoreTools::FileAsynchronousParameter::GetFileBuffer() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetFileBuffer();
}

bool CoreTools::FileAsynchronousParameter::IsAppend() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->IsAppend();
}
