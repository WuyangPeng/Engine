/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/01 09:51)

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
        LOG_SINGLETON_ENGINE_APPENDER(Error, CoreTools, SYSTEM_TEXT("ɾ���ļ�"), fileName, SYSTEM_TEXT("ʧ��"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
    }
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, DeleteFileToolsImpl)
