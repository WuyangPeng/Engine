///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.3 (2021/09/04 10:05)

#include "CoreTools/CoreToolsExport.h"

#include "FileAsynchronousParameterImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

CoreTools::FileAsynchronousParameterImpl::FileAsynchronousParameterImpl(const String& fileName, bool binaryFile, const FileEventInterfaceSharedPtr& event)
    : FileAsynchronousParameterImpl{ fileName, binaryFile, event, FileBufferSharedPtr{}, false }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::FileAsynchronousParameterImpl::FileAsynchronousParameterImpl(const String& fileName, bool binaryFile, const ConstFileBufferSharedPtr& fileBuffer, bool append)
    : FileAsynchronousParameterImpl{ fileName, binaryFile, FileEventInterfaceSharedPtr{}, fileBuffer, append }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::FileAsynchronousParameterImpl::FileAsynchronousParameterImpl(const String& fileName, bool binaryFile, const FileEventInterfaceSharedPtr& event, const ConstFileBufferSharedPtr& fileBuffer, bool append)
    : fileName{ fileName }, binaryFile{ binaryFile }, event{ event }, fileBuffer{ fileBuffer }, append{ append }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, FileAsynchronousParameterImpl)

System::String CoreTools::FileAsynchronousParameterImpl::GetFileName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return fileName;
}

CoreTools::FileEventInterfaceWeakPtr CoreTools::FileAsynchronousParameterImpl::GetEvent() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return event;
}

bool CoreTools::FileAsynchronousParameterImpl::IsBinaryFile() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return binaryFile;
}

CoreTools::ConstFileBufferSharedPtr CoreTools::FileAsynchronousParameterImpl::GetFileBuffer() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    if (!fileBuffer)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("文件缓存区未赋值。"));
    }

    return fileBuffer;
}

bool CoreTools::FileAsynchronousParameterImpl::IsAppend() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return append;
}
