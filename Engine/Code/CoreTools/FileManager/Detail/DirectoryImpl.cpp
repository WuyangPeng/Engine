///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.2.3 (2021/09/03 14:03)

#include "CoreTools/CoreToolsExport.h"

#include "DirectoryImpl.h"
#include "System/DynamicLink/Using/LoadLibraryUsing.h"
#include "System/Helper/PragmaWarning/Format.h"
#include "System/Windows/WindowsSystem.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

#include <array>

using std::array;

CoreTools::DirectoryImpl::DirectoryImpl(const String& directoryName)
    : m_DirectoryName{}
{
    array<System::TChar, System::g_MaxPath> systemCurrentDirectory{};
    const auto result = System::GetSystemCurrentDirectory(System::g_MaxPath, systemCurrentDirectory.data());
    if (0 < result && directoryName != systemCurrentDirectory.data())
    {
        m_DirectoryName = systemCurrentDirectory.data();
        if (!System::SetSystemCurrentDirectory(directoryName.c_str()))
        {
            THROW_EXCEPTION((Error::Format(SYSTEM_TEXT("���õ�ǰĿ¼��%1%��ʧ�ܣ�"s)) % directoryName).str());
        }
    }

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::DirectoryImpl::~DirectoryImpl() noexcept
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;

    if (!m_DirectoryName.empty())
    {
        if (!System::SetSystemCurrentDirectory(m_DirectoryName.c_str()))
        {
            LOG_SINGLETON_ENGINE_APPENDER(Error, CoreTools)
                << SYSTEM_TEXT("���õ�ǰĿ¼")
                << m_DirectoryName
                << SYSTEM_TEXT("ʧ�ܣ�")
                << LOG_SINGLETON_TRIGGER_ASSERT;
        }
    }
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, DirectoryImpl)