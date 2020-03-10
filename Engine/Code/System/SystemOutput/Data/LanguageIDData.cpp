// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 16:04)

#include "System/SystemExport.h"

#include "LanguageIDData.h"
#include "System/Helper/WindowsMacro.h"
#include "System/EnumOperator/EnumCastDetail.h"
#include "System/SystemOutput/Flags/SubLanguageFlags.h"
#include "System/SystemOutput/Flags/PrimaryLanguageFlags.h"

System::LanguageIDData
	::LanguageIDData(PrimaryLanguage primaryLanguage, SubLanguage subLanguage) noexcept
	:m_PrimaryLanguage{ primaryLanguage }, m_SubLanguage{ subLanguage }
{
}

System::LanguageIDData
	::LanguageIDData() noexcept
	:m_PrimaryLanguage{ PrimaryLanguage::Neutral }, m_SubLanguage{ SubLanguage::Neutral }
{
}

System::PrimaryLanguage System::LanguageIDData
	::GetPrimaryLanguage() const noexcept
{
	return m_PrimaryLanguage;
}

System::SubLanguage System::LanguageIDData
	::GetSubLanguage() const noexcept
{
	return m_SubLanguage;
}

System::WindowWord System::LanguageIDData
	::GetLanguageID() const noexcept
{
	return MakeLanguageID(EnumCastUnderlying<WindowWord>(m_PrimaryLanguage), EnumCastUnderlying<WindowWord>(m_SubLanguage));
}
