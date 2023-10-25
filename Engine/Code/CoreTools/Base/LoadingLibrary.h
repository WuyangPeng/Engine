///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/23 10:47)

#ifndef CORE_TOOLS_BASE_LOADING_LIBRARY_H
#define CORE_TOOLS_BASE_LOADING_LIBRARY_H

#include "CoreTools/CoreToolsDll.h"

#include "System/DynamicLink/Fwd/DynamicLinkFlagsFwd.h"
#include "System/DynamicLink/Using/LoadLibraryUsing.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"

#include <string>

CORE_TOOLS_NON_COPY_EXPORT_IMPL(LoadingLibraryImpl);

namespace CoreTools
{
    /// @brief  加载动态库
    /// @invariant  impl != nullptr。
    class CORE_TOOLS_DEFAULT_DECLARE LoadingLibrary final
    {
    public:
        NON_COPY_TYPE_DECLARE(LoadingLibrary);

        using String = System::String;
        using LoadLibraryType = System::LoadLibraryType;
        using DynamicLinkModule = System::DynamicLinkModule;
        using DynamicLinkProcess = System::DynamicLinkProcess;

    public:
        LoadingLibrary(const String& fileName, LoadLibraryType flags);

        CLASS_INVARIANT_DECLARE;

        NODISCARD DynamicLinkModule GetLoadedModule() noexcept;
        NODISCARD DynamicLinkProcess GetProcessAddress(const std::string& procName);

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_BASE_LOADING_LIBRARY_H
