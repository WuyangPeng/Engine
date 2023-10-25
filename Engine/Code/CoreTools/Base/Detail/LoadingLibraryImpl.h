///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/23 10:47)

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
        LoadingLibraryImpl(const LoadingLibraryImpl& rhs) = delete;
        LoadingLibraryImpl& operator=(const LoadingLibraryImpl& rhs) = delete;
        LoadingLibraryImpl(LoadingLibraryImpl&& rhs) noexcept = delete;
        LoadingLibraryImpl& operator=(LoadingLibraryImpl&& rhs) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

        NODISCARD DynamicLinkModule GetLoadedModule() noexcept;
        NODISCARD DynamicLinkProcess GetProcessAddress(const std::string& processName);

    private:
        using DynamicLinkString = System::DynamicLinkString;

    private:
        DynamicLinkString fileName;
        DynamicLinkModule library;
    };
}

#endif  // CORE_TOOLS_BASE_LOADING_LIBRARY_IMPL_H
