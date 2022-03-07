///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/09 1:38)

#include "CoreTools/CoreToolsExport.h"

#include "DirectoryImpl.h"
#include "System/DynamicLink/Using/LoadLibraryUsing.h"
#include "System/Helper/PragmaWarning/Format.h"
#include "System/Windows/WindowsSystem.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

#include <array>

using std::array;

System::String CoreTools::DirectoryImpl::GetDirectoryName(const String& directoryName)
{
    array<System::TChar, System::g_MaxPath> systemCurrentDirectory{};
    const auto result = System::GetSystemCurrentDirectory(System::g_MaxPath, systemCurrentDirectory.data());
    if (0 < result && directoryName != systemCurrentDirectory.data())
    {
        String directoryResult{ systemCurrentDirectory.data() };
        if (!System::SetSystemCurrentDirectory(directoryName.c_str()))
        {
            THROW_EXCEPTION((Error::Format(SYSTEM_TEXT("设置当前目录“%1%”失败！"s)) % directoryName).str());
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
            LOG_SINGLETON_ENGINE_APPENDER(Error, CoreTools)
                << SYSTEM_TEXT("设置当前目录")
                << directoryName
                << SYSTEM_TEXT("失败！")
                << LOG_SINGLETON_TRIGGER_ASSERT;
        }
    }
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, DirectoryImpl)
