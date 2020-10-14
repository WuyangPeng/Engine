//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.1 (2020/10/12 11:23)

// �򿪶�̬���ӿ�
#ifndef CORE_TOOLS_BASE_LOADING_LIBRARY_IMPL_H
#define CORE_TOOLS_BASE_LOADING_LIBRARY_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/DynamicLink/Fwd/DynamicLinkFlagsFwd.h"
#include "System/DynamicLink/Using/LoadLibraryUsing.h"
#include "System/Helper/UnicodeUsing.h"

#include <string>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE LoadingLibraryImpl final
    {
    public:
        using ClassType = LoadingLibraryImpl;
        using String = System::String;
        using LoadLibraryType = System::LoadLibraryType;
        using DynamicLinkModule = System::DynamicLinkModule;
        using DynamicLinkProcess = System::DynamicLinkProcess;

    public:
        LoadingLibraryImpl(const String& fileName, LoadLibraryType flags);
        ~LoadingLibraryImpl() noexcept;
        LoadingLibraryImpl(const LoadingLibraryImpl&) = delete;
        LoadingLibraryImpl& operator=(const LoadingLibraryImpl&) = delete;
        LoadingLibraryImpl(LoadingLibraryImpl&&) noexcept = delete;
        LoadingLibraryImpl& operator=(LoadingLibraryImpl&&) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] DynamicLinkModule GetLoadedModule() noexcept;
        [[nodiscard]] DynamicLinkProcess GetProcessAddress(const std::string& processName);

    private:
        using DynamicLinkString = System::DynamicLinkString;

    private:
        DynamicLinkString m_FileName;
        DynamicLinkModule m_Library;
    };
}

#endif  // CORE_TOOLS_BASE_LOADING_LIBRARY_IMPL_H
