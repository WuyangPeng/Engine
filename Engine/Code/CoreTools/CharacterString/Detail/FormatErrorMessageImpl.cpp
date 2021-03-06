//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/12 13:47)

#include "CoreTools/CoreToolsExport.h"

#include "FormatErrorMessageImpl.h"
#include "System/CharacterString/FormatErrorMessage.h"
#include "System/DynamicLink/Flags/LoadLibraryFlags.h"
#include "System/DynamicLink/LoadLibrary.h"
#include "System/MemoryTools/LocalTools.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/LogMacro.h"

using std::make_shared;
using namespace std::literals;

CoreTools::FormatErrorMessageImpl::FormatErrorMessageImpl(WindowError lastError) noexcept
    : m_LastError{ lastError }, m_ErrorMessage{ nullptr }
{
    InitMessage();

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

// private
void CoreTools::FormatErrorMessageImpl::InitMessage() noexcept
{
    if (!System::FormatErrorMessage(m_ErrorMessage, m_LastError))
    {
        AgainInitMessage();
    }
}

// private
void CoreTools::FormatErrorMessageImpl::AgainInitMessage() noexcept
{
    auto dynamicLinkModule = System::LoadDynamicLibrary(DYNAMIC_LINK_TEXT("netmsg.dll"), System::LoadLibraryType::DontResolveDllReferences);

    InitNetworkMessage(dynamicLinkModule);
}

// private
void CoreTools::FormatErrorMessageImpl::InitNetworkMessage(DynamicLinkModule module) noexcept
{
    if (module != nullptr)
    {
        LoadedModuleSucceed(module);
    }
    else
    {
        LoadedModuleFailure();
    }
}

// private
void CoreTools::FormatErrorMessageImpl::LoadedModuleSucceed(DynamicLinkModule module) noexcept
{
    if (!System::FormatErrorMessage(m_ErrorMessage, module, m_LastError))
    {
        LOG_SINGLETON_ENGINE_APPENDER(Error, CoreTools)
            << SYSTEM_TEXT("获取错误代码‘")
            << EnumCastUnderlying(m_LastError)
            << SYSTEM_TEXT("’的文字描述失败。")
            << LOG_SINGLETON_TRIGGER_ASSERT;
    }
}

// private
void CoreTools::FormatErrorMessageImpl::LoadedModuleFailure() noexcept
{
    LOG_SINGLETON_ENGINE_APPENDER(Error, CoreTools)
        << SYSTEM_TEXT("打开netmsg.dll失败")
        << LOG_SINGLETON_TRIGGER_ASSERT;
}

CoreTools::FormatErrorMessageImpl::~FormatErrorMessageImpl() noexcept
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;

    ReleaseMemory();
}

// private
void CoreTools::FormatErrorMessageImpl::ReleaseMemory() noexcept
{
    if (m_ErrorMessage != nullptr && !System::LocalMemoryFree(m_ErrorMessage))
    {
        LOG_SINGLETON_ENGINE_APPENDER(Error, CoreTools)
            << SYSTEM_TEXT("释放指定的本地内存对象失败。")
            << LOG_SINGLETON_TRIGGER_ASSERT;
    }
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, FormatErrorMessageImpl)

const System::String CoreTools::FormatErrorMessageImpl::GetErrorMessage() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    if (m_ErrorMessage != nullptr)
    {
        return static_cast<System::TChar*>(m_ErrorMessage);
    }
    else
    {
        return SYSTEM_TEXT("未发现这个错误代码的文字描述。"s);
    }
}
