///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/17 19:48)

#include "CoreTools/CoreToolsExport.h"

#include "LoadingLibraryImpl.h"
#include "System/DynamicLink/DynamicLink.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/LogMacro.h"

using namespace std::literals;

CoreTools::LoadingLibraryImpl::LoadingLibraryImpl(const String& fileName, LoadLibraryType flags)
    : fileName{ StringConversion::StandardConversionDynamicLinkString(fileName) },
      library{ LoadDynamicLibrary(fileName.c_str(), flags) }
{
    if (library == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("加载（"s) + fileName + SYSTEM_TEXT("）动态链接库失败。"s))
    }

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::LoadingLibraryImpl::~LoadingLibraryImpl() noexcept
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;

    if (!System::FreeDynamicLibrary(library))
    {
        LOG_SINGLETON_ENGINE_APPENDER(Error, CoreTools, SYSTEM_TEXT("释放已加载的（"), fileName, SYSTEM_TEXT("）动态链接库失败。"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
    }
}

#ifdef OPEN_CLASS_INVARIANT

bool CoreTools::LoadingLibraryImpl::IsValid() const noexcept
{
    if (library != nullptr)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

CoreTools::LoadingLibraryImpl::DynamicLinkModule CoreTools::LoadingLibraryImpl::GetLoadedModule() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return library;
}

CoreTools::LoadingLibraryImpl::DynamicLinkProcess CoreTools::LoadingLibraryImpl::GetProcessAddress(const std::string& processName)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    if (const auto process = System::GetProcessAddress(library, processName.c_str()); process != nullptr)
    {
        return process;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("获取函数（"s) + StringConversion::MultiByteConversionStandard(processName) + SYSTEM_TEXT("）地址失败失败。"s))
    }
}