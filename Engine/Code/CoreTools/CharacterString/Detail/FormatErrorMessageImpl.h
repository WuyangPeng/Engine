///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/12 14:07)

#ifndef CORE_TOOLS_CHARACTER_STRING_FORMAT_ERROR_MESSAGE_IMPL_H
#define CORE_TOOLS_CHARACTER_STRING_FORMAT_ERROR_MESSAGE_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/DynamicLink/Using/LoadLibraryUsing.h"
#include "System/Helper/UnicodeUsing.h"
#include "System/Windows/Fwd/WindowsFlagsFwd.h"
#include "System/Windows/Using/WindowsUsing.h"
#include "CoreTools/Base/BaseFwd.h"

#include <memory>
#include <string>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE FormatErrorMessageImpl final
    {
    public:
        using ClassType = FormatErrorMessageImpl;
        using WindowError = System::WindowError;

    public:
        explicit FormatErrorMessageImpl(WindowError lastError) noexcept;
        ~FormatErrorMessageImpl() noexcept;

        FormatErrorMessageImpl(const FormatErrorMessageImpl& rhs) = delete;
        FormatErrorMessageImpl& operator=(const FormatErrorMessageImpl& rhs) = delete;
        FormatErrorMessageImpl(FormatErrorMessageImpl&& rhs) noexcept = delete;
        FormatErrorMessageImpl& operator=(FormatErrorMessageImpl&& rhs) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

        NODISCARD System::String GetErrorMessage() const;

    private:
        using Local = System::WindowsHLocal;
        using DynamicLinkModule = System::DynamicLinkModule;
        using ConstDynamicLinkModule = System::ConstDynamicLinkModule;
        using LoadingLibrarySharedPtr = std::shared_ptr<LoadingLibrary>;

    private:
        void InitMessage() noexcept;
        void AgainInitMessage() noexcept;
        void InitNetworkMessage(ConstDynamicLinkModule module) noexcept;
        void LoadedModuleSucceed(ConstDynamicLinkModule module) noexcept;
        void LoadedModuleFailure() noexcept;
        void ReleaseMemory() noexcept;

    private:
        WindowError lastError;
        Local errorMessage;
    };
}

#endif  // CORE_TOOLS_CHARACTER_STRING_FORMAT_ERROR_MESSAGE_IMPL_H
