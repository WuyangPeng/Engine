///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.3 (2023/03/02 11:01)

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