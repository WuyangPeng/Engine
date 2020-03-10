// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 16:03)

#ifndef SYSTEM_SYSTEM_OUTPUT_LANGUAGE_ID_DATA_H
#define SYSTEM_SYSTEM_OUTPUT_LANGUAGE_ID_DATA_H

#include "System/SystemDll.h"

#include "System/Window/Using/WindowUsing.h"
#include "System/SystemOutput/Fwd/SystemOutputFlagsFwd.h"

namespace System
{
	class SYSTEM_DEFAULT_DECLARE LanguageIDData
	{
	public:
		using ClassType = LanguageIDData;

	public:
		LanguageIDData() noexcept;
		LanguageIDData(PrimaryLanguage primaryLanguage, SubLanguage subLanguage) noexcept;

		PrimaryLanguage GetPrimaryLanguage() const noexcept;
		SubLanguage GetSubLanguage() const noexcept;

		WindowWord GetLanguageID() const noexcept;

	private:
		PrimaryLanguage m_PrimaryLanguage;
		SubLanguage m_SubLanguage;
	};
}

#endif // SYSTEM_SYSTEM_OUTPUT_LANGUAGE_ID_DATA_H