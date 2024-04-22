/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/03/29 23:07)

#include "CoreTools/CoreToolsExport.h"

#include "FormatErrorMessageImpl.h"
#include "System/CharacterString/FormatErrorMessage.h"
#include "System/DynamicLink/Flags/LoadLibraryFlags.h"
#include "System/DynamicLink/LoadLibrary.h"
#include "System/MemoryTools/LocalTools.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/LogMacro.h"

CoreTools::FormatErrorMessageImpl::FormatErrorMessageImpl(WindowError lastError) noexcept
    : lastError{ lastError }, errorMessage{ nullptr }
{
    InitMessage();

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

void CoreTools::FormatErrorMessageImpl::InitMessage() noexcept
{
    if (!FormatErrorMessage(errorMessage, lastError))
    {
        AgainInitMessage();
    }
}

void CoreTools::FormatErrorMessageImpl::AgainInitMessage() noexcept
{
    const ConstDynamicLinkModule dynamicLinkModule{ LoadDynamicLibrary(DYNAMIC_LINK_TEXT("netmsg.dll"), System::LoadLibraryType::DoNotResolveDllReferences) };

    InitNetworkMessage(dynamicLinkModule);
}

void CoreTools::FormatErrorMessageImpl::InitNetworkMessage(ConstDynamicLinkModule module) noexcept
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

void CoreTools::FormatErrorMessageImpl::LoadedModuleSucceed(ConstDynamicLinkModule module) noexcept
{
    if (!FormatErrorMessage(errorMessage, module, lastError))
    {
        LOG_SINGLETON_ENGINE_APPENDER(Error, CoreTools, SYSTEM_TEXT("��ȡ������롮"), EnumCastUnderlying(lastError), SYSTEM_TEXT("������������ʧ�ܡ�"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
    }
}

void CoreTools::FormatErrorMessageImpl::LoadedModuleFailure() noexcept
{
    LOG_SINGLETON_ENGINE_APPENDER(Error, CoreTools, SYSTEM_TEXT("��netmsg.dllʧ��"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
}

CoreTools::FormatErrorMessageImpl::~FormatErrorMessageImpl() noexcept
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;

    ReleaseMemory();
}

void CoreTools::FormatErrorMessageImpl::ReleaseMemory() noexcept
{
    if (errorMessage != nullptr && !System::LocalMemoryFree(errorMessage))
    {
        LOG_SINGLETON_ENGINE_APPENDER(Error, CoreTools, SYSTEM_TEXT("�ͷ�ָ���ı����ڴ����ʧ�ܡ�"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
    }
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, FormatErrorMessageImpl)

System::String CoreTools::FormatErrorMessageImpl::GetErrorMessage() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    if (errorMessage != nullptr)
    {
        return static_cast<System::TChar*>(errorMessage);
    }
    else
    {
        return SYSTEM_TEXT("δ�������������������������");
    }
}
