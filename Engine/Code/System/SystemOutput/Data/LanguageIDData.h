// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.2.0.0 (2020/05/08 23:28)

#ifndef SYSTEM_SYSTEM_OUTPUT_LANGUAGE_ID_DATA_H
#define SYSTEM_SYSTEM_OUTPUT_LANGUAGE_ID_DATA_H

#include "System/SystemDll.h"

#include "System/Helper/EnumCast.h"
#include "System/Helper/WindowsMacro.h"
#include "System/SystemOutput/Flags/SubLanguageFlags.h"
#include "System/SystemOutput/Flags/PrimaryLanguageFlags.h"

namespace System
{
	class SYSTEM_DEFAULT_DECLARE LanguageIDData
	{
	public:
		using ClassType = LanguageIDData;

	public:
		constexpr LanguageIDData() noexcept 
			:m_PrimaryLanguage{ PrimaryLanguage::Neutral }, m_SubLanguage{ SubLanguage::Neutral }
		{
		}

		constexpr LanguageIDData(PrimaryLanguage primaryLanguage, SubLanguage subLanguage) noexcept
			:m_PrimaryLanguage{ primaryLanguage }, m_SubLanguage{ subLanguage }
		{
		}

		constexpr auto GetPrimaryLanguage() const noexcept
		{
			return m_PrimaryLanguage;
		}

		constexpr auto GetSubLanguage() const noexcept
		{
			return m_SubLanguage;
		}

		constexpr auto GetLanguageID() const noexcept
		{
			return MakeLanguageID(EnumCastUnderlying<WindowWord>(m_PrimaryLanguage), EnumCastUnderlying<WindowWord>(m_SubLanguage));
		}

	private:
		PrimaryLanguage m_PrimaryLanguage;
		SubLanguage m_SubLanguage;
	};
}

#endif // SYSTEM_SYSTEM_OUTPUT_LANGUAGE_ID_DATA_H