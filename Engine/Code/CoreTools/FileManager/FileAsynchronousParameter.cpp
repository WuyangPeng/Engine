///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/09 1:47)

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

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, FileAsynchronousParameter, GetFileName, System::String)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, FileAsynchronousParameter, GetEvent, CoreTools::FileEventInterfaceWeakPtr)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, FileAsynchronousParameter, IsBinaryFile, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, FileAsynchronousParameter, GetFileBuffer, CoreTools::ConstFileBufferSharedPtr)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, FileAsynchronousParameter, IsAppend, bool)