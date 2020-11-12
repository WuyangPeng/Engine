///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/10/31 2:07)

#include "CoreTools/CoreToolsExport.h"

#include "LoadingLibraryImpl.h"
#include "System/DynamicLink/DynamicLink.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/LogMacro.h"

using std::string;

CoreTools::LoadingLibraryImpl::LoadingLibraryImpl(const String& fileName, LoadLibraryType flags)
    : m_FileName{ StringConversion::StandardConversionDynamicLinkString(fileName) },
      m_Library{ System::LoadDynamicLibrary(m_FileName.c_str(), flags) }
{
    if (m_Library == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("加载（"s) + m_FileName + SYSTEM_TEXT("）动态链接库失败。"s));
    }

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::LoadingLibraryImpl::~LoadingLibraryImpl() noexcept
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;

    if (!System::FreeDynamicLibrary(m_Library))
    {
        LOG_SINGLETON_ENGINE_APPENDER(Error, CoreTools)
            << SYSTEM_TEXT("释放已加载的（")
            << m_FileName
            << SYSTEM_TEXT("）动态链接库失败。")
            << LOG_SINGLETON_TRIGGER_ASSERT;
    }
}
#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::LoadingLibraryImpl::IsValid() const noexcept
{
    if (m_Library != nullptr)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

CoreTools::LoadingLibraryImpl::DynamicLinkModule CoreTools::LoadingLibraryImpl::GetLoadedModule() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return m_Library;
}

CoreTools::LoadingLibraryImpl::DynamicLinkProcess CoreTools::LoadingLibraryImpl::GetProcessAddress(const string& processName)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    auto process = System::GetProcessAddress(m_Library, processName.c_str());

    if (process != nullptr)
    {
        return process;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("获取函数（"s) + StringConversion::MultiByteConversionStandard(processName) + SYSTEM_TEXT("）地址失败失败。"s));
    }
}