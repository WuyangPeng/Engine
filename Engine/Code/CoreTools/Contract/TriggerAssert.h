//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/10 13:06)

#ifndef CORE_TOOLS_CONTRACT_TRIGGER_ASSERT_H
#define CORE_TOOLS_CONTRACT_TRIGGER_ASSERT_H

#include "CoreTools/CoreToolsDll.h"

#include "ContractFwd.h"
#include "System/SystemOutput/Fwd/SystemOutputFlagsFwd.h"
#include "CoreTools/Helper/CustomAssertMacro.h"

#include <boost/noncopyable.hpp>
#include <array>

EXPORT_NONCOPYABLE_CLASS(CORE_TOOLS);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE TriggerAssert final : private boost::noncopyable
    {
    public:
        using ClassType = TriggerAssert;
        using DialogBoxCommand = System::DialogBoxCommand;

    public:
        TriggerAssert(TriggerAssertCheck triggerAssertCheck, const FunctionDescribed& functionDescribed, const char* format, va_list arguments);
        TriggerAssert(TriggerAssertCheck triggerAssertCheck, const FunctionDescribed& functionDescribed, const char* format, ...);

    private:
        void Process(const FunctionDescribed& functionDescribed, const char* format, va_list arguments);

        void GenerateMessagePrefix(const FunctionDescribed& functionDescribed, const char* triggerAssertCheck) noexcept;
        void AppendUserArguments(const char* format, va_list arguments) noexcept;

#ifdef CORE_TOOLS_USE_ASSERT_WRITE_TO_OUTPUT_WINDOW
        void WriteToOutputDebug() noexcept;
#endif  // CORE_TOOLS_USE_ASSERT_WRITE_TO_OUTPUT_WINDOW

#ifdef CORE_TOOLS_USE_ASSERT_WRITE_TO_MESSAGE_BOX
        void JudgeUserSelection();
        void JudgeSelection(DialogBoxCommand selection);
#endif  // CORE_TOOLS_USE_ASSERT_WRITE_TO_MESSAGE_BOX

        static size_t GetDebugPromptLength() noexcept;
        static size_t GetMaxPrefixBytes() noexcept;

    private:
        static constexpr size_t sm_MaxMessageBytes{ 1024u };
        static const char* sm_DebugPrompt;
        static const char* sm_MessagePrefix;
        static const char* sm_TriggerAssertCheckInvariant;
        static const char* sm_TriggerAssertCheckAssertion;

#ifdef CORE_TOOLS_USE_ASSERT_WRITE_TO_MESSAGE_BOX
        static const char* sm_MessageBoxTitle;
#endif  // CORE_TOOLS_USE_ASSERT_WRITE_TO_MESSAGE_BOX

    private:
        TriggerAssertCheck m_TriggerAssertCheck;
        std::array<char, sm_MaxMessageBytes> m_Message;
    };
}

#endif  // CORE_TOOLS_CONTRACT_TRIGGER_ASSERT_H
