// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 16:03)

#ifndef SYSTEM_SYSTEM_OUTPUT_MESSAGE_BOX_FLAGS_DATA_H
#define SYSTEM_SYSTEM_OUTPUT_MESSAGE_BOX_FLAGS_DATA_H

#include "System/SystemDll.h"

#include "System/Window/Using/WindowUsing.h"
#include "System/SystemOutput/Fwd/SystemOutputFlagsFwd.h"

namespace System
{
	class SYSTEM_DEFAULT_DECLARE MessageBoxFlagsData
	{
	public:
		using ClassType = MessageBoxFlagsData;

	public:
		constexpr MessageBoxFlagsData(MessageBoxType typeFlag, MessageBoxIcon iconFlag, MessageBoxDefault defaultFlag, MessageBoxMode modeFlag, MessageBoxMisc miscFlag) noexcept
			:m_TypeFlag{ typeFlag }, m_IconFlag{ iconFlag }, m_DefaultFlag{ defaultFlag }, m_ModeFlag{ modeFlag }, m_MiscFlag{ miscFlag }
		{
		}

		MessageBoxType GetTypeFlag() const noexcept;
		MessageBoxIcon GetIconFlag() const noexcept;
		MessageBoxDefault GetDefaultFlag() const noexcept;
		MessageBoxMode GetModeFlag() const noexcept;
		MessageBoxMisc GetMiscFlag() const noexcept;

		WindowUInt GetFlag() const noexcept;

	private:
		MessageBoxType m_TypeFlag;
		MessageBoxIcon m_IconFlag;
		MessageBoxDefault m_DefaultFlag;
		MessageBoxMode m_ModeFlag;
		MessageBoxMisc m_MiscFlag;
	};
}

#endif // SYSTEM_SYSTEM_OUTPUT_MESSAGE_BOX_FLAGS_DATA_H