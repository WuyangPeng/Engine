/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/01 09:51)

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

    if (!directoryName.empty() &&
        !System::SetSystemCurrentDirectory(directoryName.c_str()))
    {
        LOG_SINGLETON_ENGINE_APPENDER(Error, CoreTools, SYSTEM_TEXT("设置当前目录"), directoryName, SYSTEM_TEXT("失败！"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
    }
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, DirectoryImpl)
