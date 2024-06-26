/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/03/28 16:47)

#include "CoreTools/CoreToolsExport.h"

#include "LoadingLibraryImpl.h"
#include "System/DynamicLink/DynamicLink.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/LogMacro.h"

CoreTools::LoadingLibraryImpl::LoadingLibraryImpl(const String& fileName, LoadLibraryType flags)
    : fileName{ StringConversion::StandardConversionDynamicLinkString(fileName) },
      library{ LoadDynamicLibrary(fileName.c_str(), flags) }
{
    if (library == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("���أ�"s) + fileName + SYSTEM_TEXT("����̬���ӿ�ʧ�ܡ�"s))
    }

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::LoadingLibraryImpl::~LoadingLibraryImpl() noexcept
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;

    if (!System::FreeDynamicLibrary(library))
    {
        LOG_SINGLETON_ENGINE_APPENDER(Error, CoreTools, SYSTEM_TEXT("�ͷ��Ѽ��صģ�"), fileName, SYSTEM_TEXT("����̬���ӿ�ʧ�ܡ�"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
    }
}

#ifdef OPEN_CLASS_INVARIANT

bool CoreTools::LoadingLibraryImpl::IsValid() const noexcept
{
    return library != nullptr;
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
        THROW_EXCEPTION(SYSTEM_TEXT("��ȡ������"s) + StringConversion::MultiByteConversionStandard(processName) + SYSTEM_TEXT("����ַʧ��ʧ�ܡ�"s))
    }
}