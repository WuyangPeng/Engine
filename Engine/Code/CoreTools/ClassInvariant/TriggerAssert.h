// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/18 18:05)

#ifndef CORE_TOOLS_CLASS_INVARIANT_TRIGGER_ASSERT_H
#define CORE_TOOLS_CLASS_INVARIANT_TRIGGER_ASSERT_H

#include "CoreTools/CoreToolsDll.h"

#include "ClassInvariantFwd.h"
#include "System/SystemOutput/Fwd/SystemOutputFlagsFwd.h"
#include "CoreTools/Helper/CustomAssertMacro.h"

#include <boost/noncopyable.hpp>
#include <array>

EXPORT_NONCOPYABLE_CLASS(CORE_TOOLS);

namespace CoreTools
{
	class CORE_TOOLS_DEFAULT_DECLARE TriggerAssert : private boost::noncopyable
	{
	public:
		using ClassType = TriggerAssert;
		using DialogBoxCommand = System::DialogBoxCommand;

	public:
		TriggerAssert(TriggerAssertCheck triggerAssertCheck, const FunctionDescribed& functionDescribed, const char* format, va_list arguments);
		TriggerAssert(TriggerAssertCheck triggerAssertCheck, const FunctionDescribed& functionDescribed, const char* format, ...);

	private:
		void Process(const FunctionDescribed& functionDescribed, const char* format, va_list arguments);

		void GenerateMessagePrefix(const FunctionDescribed& functionDescribed, const char* triggerAssertCheck);
		void AppendUserArguments(const char* format, va_list arguments);

#ifdef CORE_TOOLS_USE_ASSERT_WRITE_TO_OUTPUT_WINDOW
		void WriteToOutputDebug();
#endif // CORE_TOOLS_USE_ASSERT_WRITE_TO_OUTPUT_WINDOW

#ifdef CORE_TOOLS_USE_ASSERT_WRITE_TO_MESSAGE_BOX
		void JudgeUserSelection();
		void JudgeSelection(DialogBoxCommand selection);
#endif // CORE_TOOLS_USE_ASSERT_WRITE_TO_MESSAGE_BOX			

	private:
		static constexpr size_t sm_MaxMessageBytes{ 1024 };
		static const char* sm_DebugPrompt;
		static const size_t sm_DebugPromptLength;
		static const char* sm_MessagePrefix;
		static const size_t sm_MaxPrefixBytes;
		static const char* sm_TriggerAssertCheckInvariant;
		static const char* sm_TriggerAssertCheckAssertion;

#ifdef CORE_TOOLS_USE_ASSERT_WRITE_TO_MESSAGE_BOX
		static const char* sm_MessageBoxTitle;
#endif // CORE_TOOLS_USE_ASSERT_WRITE_TO_MESSAGE_BOX

	private:
		TriggerAssertCheck m_TriggerAssertCheck;
		std::array<char, sm_MaxMessageBytes> m_Message;
	};
}

#endif // CORE_TOOLS_CLASS_INVARIANT_TRIGGER_ASSERT_H
