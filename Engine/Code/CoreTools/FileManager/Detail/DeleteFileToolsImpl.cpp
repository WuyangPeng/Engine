///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/09 1:38)

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
        LOG_SINGLETON_ENGINE_APPENDER(Error, CoreTools)
            << SYSTEM_TEXT("ɾ���ļ�")
            << fileName
            << SYSTEM_TEXT("ʧ��")
            << LOG_SINGLETON_TRIGGER_ASSERT;
    }
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, DeleteFileToolsImpl)
