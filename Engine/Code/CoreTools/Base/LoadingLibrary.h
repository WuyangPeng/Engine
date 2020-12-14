//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.1 (2020/10/12 11:28)

// �򿪶�̬���ӿ�
#ifndef CORE_TOOLS_BASE_LOADING_LIBRARY_H
#define CORE_TOOLS_BASE_LOADING_LIBRARY_H

#include "CoreTools/CoreToolsDll.h"

#include "System/DynamicLink/Fwd/DynamicLinkFlagsFwd.h"
#include "System/DynamicLink/Using/LoadLibraryUsing.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <boost/noncopyable.hpp>
#include <string>

CORE_TOOLS_EXPORT_SHARED_PTR(LoadingLibraryImpl);
EXPORT_NONCOPYABLE_CLASS(CORE_TOOLS);

namespace CoreTools
{
    /// @brief  ���ض�̬��
    /// @invariant  m_Impl != nullptr��
    class CORE_TOOLS_DEFAULT_DECLARE LoadingLibrary final : private boost::noncopyable
    {
    public:
        NON_COPY_CLASSES_TYPE_DECLARE(LoadingLibrary);
        using String = System::String;
        using LoadLibraryType = System::LoadLibraryType;
        using DynamicLinkModule = System::DynamicLinkModule;
        using DynamicLinkProcess = System::DynamicLinkProcess;

    public:
        LoadingLibrary(const String& fileName, LoadLibraryType flags);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] DynamicLinkModule GetLoadedModule() noexcept;
        [[nodiscard]] DynamicLinkProcess GetProcessAddress(const std::string& procName);

    private:
        IMPL_TYPE_DECLARE(LoadingLibrary);
    };
}

#endif  // CORE_TOOLS_BASE_LOADING_LIBRARY_H
