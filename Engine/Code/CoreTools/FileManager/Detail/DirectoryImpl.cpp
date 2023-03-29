///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.4 (2023/03/23 15:36)

#include "CoreTools/CoreToolsExport.h"

#include "DirectoryImpl.h"
#include "System/DynamicLink/Using/LoadLibraryUsing.h"
#include "System/Helper/PragmaWarning/Format.h"
#include "System/Windows/WindowsSystem.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

#include <array>

System::String CoreTools::DirectoryImpl::GetDirectoryName(const String& directoryName)
{
    std::array<System::TChar, System::gMaxPath> systemCurrentDirectory{};

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

    if (!directoryName.empty())
    {
        if (!System::SetSystemCurrentDirectory(directoryName.c_str()))
        {
            LOG_SINGLETON_ENGINE_APPENDER(Error, CoreTools, SYSTEM_TEXT("���õ�ǰĿ¼"), directoryName, SYSTEM_TEXT("ʧ�ܣ�"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
        }
    }
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, DirectoryImpl)
