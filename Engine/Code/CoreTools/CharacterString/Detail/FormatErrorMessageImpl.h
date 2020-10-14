//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.1 (2020/10/12 13:47)

// ��ʽ��Windows������Ϣ�ڲ��ӿ���
#ifndef CORE_TOOLS_CHARACTER_STRING_FORMAT_ERROR_MESSAGE_IMPL_H
#define CORE_TOOLS_CHARACTER_STRING_FORMAT_ERROR_MESSAGE_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/DynamicLink/Using/LoadLibraryUsing.h"
#include "System/Helper/UnicodeUsing.h"
#include "System/Window/Fwd/WindowFlagsFwd.h"
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

        FormatErrorMessageImpl(const FormatErrorMessageImpl&) = delete;
        FormatErrorMessageImpl& operator=(const FormatErrorMessageImpl&) = delete;
        FormatErrorMessageImpl(FormatErrorMessageImpl&&) noexcept = delete;
        FormatErrorMessageImpl& operator=(FormatErrorMessageImpl&&) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] const System::String GetErrorMessage() const;

    private:
        using Local = System::WindowHLocal;
        using DynamicLinkModule = System::DynamicLinkModule;
        using LoadingLibraryPtr = std::shared_ptr<LoadingLibrary>;

    private:
        void InitMessage() noexcept;
        void AgainInitMessage() noexcept;
        void InitNetworkMessage(DynamicLinkModule module) noexcept;
        void LoadedModuleSucceed(DynamicLinkModule module) noexcept;
        void LoadedModuleFailure() noexcept;
        void ReleaseMemory() noexcept;

    private:
        WindowError m_LastError;
        Local m_ErrorMessage;
    };
}

#endif  // CORE_TOOLS_CHARACTER_STRING_FORMAT_ERROR_MESSAGE_IMPL_H
