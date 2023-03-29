///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/23 15:36)

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
            THROW_EXCEPTION((Error::Format(SYSTEM_TEXT("设置当前目录“%1%”失败！"s)) % directoryName).str())
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
            LOG_SINGLETON_ENGINE_APPENDER(Error, CoreTools, SYSTEM_TEXT("设置当前目录"), directoryName, SYSTEM_TEXT("失败！"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
        }
    }
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, DirectoryImpl)
