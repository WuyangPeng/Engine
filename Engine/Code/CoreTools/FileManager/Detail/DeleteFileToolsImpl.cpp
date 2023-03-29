///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/23 15:36)

#include "CoreTools/CoreToolsExport.h"

#include "DeleteFileToolsImpl.h"
#include "System/FileManager/File.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/LogMacro.h"

CoreTools::DeleteFileToolsImpl::DeleteFileToolsImpl(const String& fileName)
    : fileName{ StringConversion::StandardConversionCFileString(fileName) }, deleted{ System::RemoveSystemFile(fileName) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::DeleteFileToolsImpl::~DeleteFileToolsImpl() noexcept
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;

    if (!deleted && !System::RemoveSystemFile(fileName))
    {
        LOG_SINGLETON_ENGINE_APPENDER(Error, CoreTools, SYSTEM_TEXT("删除文件"), fileName, SYSTEM_TEXT("失败"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
    }
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, DeleteFileToolsImpl)
