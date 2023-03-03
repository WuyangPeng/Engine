///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.3 (2023/02/27 10:38)

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

        using String = System::String;
        using WindowError = System::WindowError;

    public:
        explicit FormatErrorMessageImpl(WindowError lastError) noexcept;
        ~FormatErrorMessageImpl() noexcept;

        FormatErrorMessageImpl(const FormatErrorMessageImpl& rhs) = delete;
        FormatErrorMessageImpl& operator=(const FormatErrorMessageImpl& rhs) = delete;
        FormatErrorMessageImpl(FormatErrorMessageImpl&& rhs) noexcept = delete;
        FormatErrorMessageImpl& operator=(FormatErrorMessageImpl&& rhs) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

        NODISCARD String GetErrorMessage() const;

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
        void ReleaseMemory() noexcept;

        static void LoadedModuleFailure() noexcept;

    private:
        WindowError lastError;
        Local errorMessage;
    };
}

#endif  // CORE_TOOLS_CHARACTER_STRING_FORMAT_ERROR_MESSAGE_IMPL_H
