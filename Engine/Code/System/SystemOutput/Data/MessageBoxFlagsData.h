// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.2.0.0 (2020/05/08 23:36)

#ifndef SYSTEM_SYSTEM_OUTPUT_MESSAGE_BOX_FLAGS_DATA_H
#define SYSTEM_SYSTEM_OUTPUT_MESSAGE_BOX_FLAGS_DATA_H

#include "System/SystemDll.h"

#include "System/Helper/EnumCast.h"
#include "System/Window/Using/WindowUsing.h"
#include "System/SystemOutput/Fwd/SystemOutputFlagsFwd.h"

namespace System
{
	class SYSTEM_DEFAULT_DECLARE MessageBoxFlagsData
	{
	public:
		using ClassType = MessageBoxFlagsData;

	public:
		constexpr MessageBoxFlagsData(MessageBoxType messageBoxType, MessageBoxIcon messageBoxIcon, MessageBoxDefault messageBoxDefault, MessageBoxMode messageBoxMode, MessageBoxMisc messageBoxMisc) noexcept
			:m_Type{ messageBoxType }, m_Icon{ messageBoxIcon }, m_Default{ messageBoxDefault }, m_Mode{ messageBoxMode }, m_Misc{ messageBoxMisc }
		{
		}

		constexpr auto GetMessageBoxType() const noexcept
		{
			return m_Type;
		}

		constexpr auto GetMessageBoxIcon() const noexcept
		{			
			return m_Icon;			
		}

		constexpr auto GetMessageBoxDefault() const noexcept
		{
			return m_Default;
		}

		constexpr auto GetMessageBoxMode() const noexcept
		{
			return m_Mode;
		}

		constexpr auto GetMessageBoxMisc() const noexcept
		{
			return m_Misc;
		}

		constexpr WindowUInt GetFlag() const noexcept
		{
			return EnumCastUnderlying(m_Type) | EnumCastUnderlying(m_Icon) | EnumCastUnderlying(m_Default) |
				   EnumCastUnderlying(m_Mode) | EnumCastUnderlying(m_Misc);		
		} 

	private:
		MessageBoxType m_Type;
		MessageBoxIcon m_Icon;
		MessageBoxDefault m_Default;
		MessageBoxMode m_Mode;
		MessageBoxMisc m_Misc;
	};
}

#endif // SYSTEM_SYSTEM_OUTPUT_MESSAGE_BOX_FLAGS_DATA_H