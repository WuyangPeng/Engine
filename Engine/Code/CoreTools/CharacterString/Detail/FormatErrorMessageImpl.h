///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.2.2 (2021/08/27 17:53)

#ifndef CORE_TOOLS_CHARACTER_STRING_FORMAT_ERROR_MESSAGE_IMPL_H
#define CORE_TOOLS_CHARACTER_STRING_FORMAT_ERROR_MESSAGE_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/DynamicLink/Using/LoadLibraryUsing.h"
#include "System/Helper/UnicodeUsing.h"
#include "System/Windows/Fwd/WindowsFlagsFwd.h"
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

        NODISCARD const System::String GetErrorMessage() const;

    private:
        using Local = System::WindowsHLocal;
        using DynamicLinkModule = System::DynamicLinkModule;
        using LoadingLibrarySharedPtr = std::shared_ptr<LoadingLibrary>;

    private:
        void InitMessage() noexcept;
        void AgainInitMessage() noexcept;
        void InitNetworkMessage(DynamicLinkModule module) noexcept;
        void LoadedModuleSucceed(DynamicLinkModule module) noexcept;
        void LoadedModuleFailure() noexcept;
        void ReleaseMemory() noexcept;

    private:
        WindowError lastError;
        Local errorMessage;
    };
}

#endif  // CORE_TOOLS_CHARACTER_STRING_FORMAT_ERROR_MESSAGE_IMPL_H
