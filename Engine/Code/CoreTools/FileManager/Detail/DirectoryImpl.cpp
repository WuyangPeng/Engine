/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/01 09:51)

#include "CoreTools/CoreToolsExport.h"

#include "DirectoryImpl.h"
#include "System/DynamicLink/Using/LoadLibraryUsing.h"
#include "System/Helper/PragmaWarning/Format.h"
#include "System/Windows/WindowsSystem.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

System::String CoreTools::DirectoryImpl::GetDirectoryName(const String& directoryName)
{
    DirectoryType systemCurrentDirectory{};

    if (const auto result = System::GetSystemCurrentDirectory(System::gMaxPath, systemCurrentDirectory.data());
        0 < result && directoryName != systemCurrentDirectory.data())
    {
        String directoryResult{ systemCurrentDirectory.data() };
        if (!System::SetSystemCurrentDirectory(directoryName.c_str()))
        {
            THROW_EXCEPTION((Error::Format(SYSTEM_TEXT("���õ�ǰĿ¼��%1%��ʧ�ܣ�"s)) % directoryName).str())
        }

        return directoryResult;
    }

    return String{};
}

CoreTools::DirectoryImpl::DirectoryImpl(const String& directoryName)
    : directoryName{ GetDirectoryName(directoryName) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::DirectoryImpl::~DirectoryImpl() noexcept
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;

    if (!directoryName.empty() &&
        !System::SetSystemCurrentDirectory(directoryName.c_str()))
    {
        LOG_SINGLETON_ENGINE_APPENDER(Error, CoreTools, SYSTEM_TEXT("���õ�ǰĿ¼"), directoryName, SYSTEM_TEXT("ʧ�ܣ�"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
    }
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, DirectoryImpl)
