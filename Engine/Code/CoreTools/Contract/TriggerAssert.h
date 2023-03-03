///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.3 (2023/02/23 13:35)

#ifndef CORE_TOOLS_CONTRACT_TRIGGER_ASSERT_H
#define CORE_TOOLS_CONTRACT_TRIGGER_ASSERT_H

#include "CoreTools/CoreToolsDll.h"

#include "System/SystemOutput/Fwd/SystemOutputFlagsFwd.h"
#include "CoreTools/Helper/CustomAssertMacro.h"
#include "CoreTools/Contract/ContractFwd.h"

#include <boost/format/format_fwd.hpp>

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE TriggerAssert final
    {
    public:
        using ClassType = TriggerAssert;
        using Format = boost::format;
        using DialogBoxCommand = System::DialogBoxCommand;

    public:
        template <typename... Types>
        explicit TriggerAssert(TriggerAssertCheck triggerAssertCheck, const FunctionDescribed& functionDescribed, const std::string& message, Types&&... arguments);

        TriggerAssert() noexcept = delete;
        ~TriggerAssert() noexcept = default;
        TriggerAssert(const TriggerAssert& rhs) noexcept = delete;
        TriggerAssert& operator=(const TriggerAssert& rhs) noexcept = delete;
        TriggerAssert(TriggerAssert&& rhs) noexcept = delete;
        TriggerAssert& operator=(TriggerAssert&& rhs) noexcept = delete;

    private:
        template <typename Type, typename... Types>
        void Process(const FunctionDescribed& functionDescribed, Format& format, Type&& argument, Types&&... arguments);
        void Process(const FunctionDescribed& functionDescribed, const Format& format);

        NODISCARD std::string GenerateMessagePrefix(const FunctionDescribed& functionDescribed);
        NODISCARD static std::string GenerateMessagePrefix(const FunctionDescribed& functionDescribed, const std::string& triggerAssertCheckMessage);

#ifdef CORE_TOOLS_USE_ASSERT_WRITE_TO_OUTPUT_WINDOW

        static void WriteToOutputDebug(const std::string& message) noexcept;

#endif  // CORE_TOOLS_USE_ASSERT_WRITE_TO_OUTPUT_WINDOW

#ifdef CORE_TOOLS_USE_ASSERT_WRITE_TO_MESSAGE_BOX

        void JudgeUserSelection(const std::string& message) const;
        void JudgeSelection(DialogBoxCommand selection, const std::string& message) const;
        NODISCARD static std::string GetMessageBoxTitle();

#endif  // CORE_TOOLS_USE_ASSERT_WRITE_TO_MESSAGE_BOX

        NODISCARD static std::string GetDebugPrompt();
        NODISCARD static std::string GetMessagePrefix();
        NODISCARD static std::string GetTriggerAssertCheckInvariant();
        NODISCARD static std::string GetTriggerAssertCheckAssertion();

    private:
        TriggerAssertCheck triggerAssertCheck;
    };
}

#endif  // CORE_TOOLS_CONTRACT_TRIGGER_ASSERT_H
