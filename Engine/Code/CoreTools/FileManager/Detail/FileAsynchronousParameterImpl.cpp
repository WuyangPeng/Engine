///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.3 (2023/03/02 10:37)

#include "CoreTools/CoreToolsExport.h"

#include "FileAsynchronousParameterImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

CoreTools::FileAsynchronousParameterImpl::FileAsynchronousParameterImpl(String fileName, bool binaryFile, const FileEventInterfaceSharedPtr& event) noexcept
    : FileAsynchronousParameterImpl{ std::move(fileName), binaryFile, event, FileBufferSharedPtr{}, false }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::FileAsynchronousParameterImpl::FileAsynchronousParameterImpl(String fileName, bool binaryFile, ConstFileBufferSharedPtr fileBuffer, bool append) noexcept
    : FileAsynchronousParameterImpl{ std::move(fileName), binaryFile, FileEventInterfaceSharedPtr{}, std::move(fileBuffer), append }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::FileAsynchronousParameterImpl::FileAsynchronousParameterImpl(String fileName, bool binaryFile, const FileEventInterfaceSharedPtr& event, ConstFileBufferSharedPtr fileBuffer, bool append) noexcept
    : fileName{ std::move(fileName) }, binaryFile{ binaryFile }, event{ event }, fileBuffer{ std::move(fileBuffer) }, append{ append }
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
        THROW_EXCEPTION(SYSTEM_TEXT("�ļ�������δ��ֵ��"))
    }

    return fileBuffer;
}

bool CoreTools::FileAsynchronousParameterImpl::IsAppend() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return append;
}
