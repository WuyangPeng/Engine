///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/12 14:31)
///	����汾��0.7.2.2 (2021/08/26 20:47)

#include "CoreTools/CoreToolsExport.h"

#include "LoadingLibraryImpl.h"
#include "System/DynamicLink/DynamicLink.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/LogMacro.h"

using std::string;
using namespace std::literals;

CoreTools::LoadingLibraryImpl::LoadingLibraryImpl(const String& fileName, LoadLibraryType flags)
    : fileName{ StringConversion::StandardConversionDynamicLinkString(fileName) },
      library{ System::LoadDynamicLibrary(fileName.c_str(), flags) }
{
    if (library == nullptr)
    {
        const auto errorMessage = SYSTEM_TEXT("���أ�"s) + fileName + SYSTEM_TEXT("����̬���ӿ�ʧ�ܡ�"s);
        THROW_EXCEPTION(errorMessage);
    }

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::LoadingLibraryImpl::~LoadingLibraryImpl() noexcept
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;

    if (!System::FreeDynamicLibrary(library))
    {
        LOG_SINGLETON_ENGINE_APPENDER(Error, CoreTools)
            << SYSTEM_TEXT("�ͷ��Ѽ��صģ�")
            << fileName
            << SYSTEM_TEXT("����̬���ӿ�ʧ�ܡ�")
            << LOG_SINGLETON_TRIGGER_ASSERT;
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

CoreTools::LoadingLibraryImpl::DynamicLinkProcess CoreTools::LoadingLibraryImpl::GetProcessAddress(const string& processName)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    const auto process = System::GetProcessAddress(library, processName.c_str());

    if (process != nullptr)
    {
        return process;
    }
    else
    {
        const auto errorMessage = SYSTEM_TEXT("��ȡ������"s) + StringConversion::MultiByteConversionStandard(processName) + SYSTEM_TEXT("����ַʧ��ʧ�ܡ�"s);
        THROW_EXCEPTION(errorMessage);
    }
}