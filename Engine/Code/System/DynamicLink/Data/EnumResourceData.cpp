// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 14:48)

#include "System/SystemExport.h"

#include "EnumResourceData.h" 
#include "System/Helper/WindowsMacro.h"
#include "System/EnumOperator/EnumCastDetail.h"

System::EnumResourceData
	::EnumResourceData(const DynamicLinkCharType* type, const DynamicLinkCharType* name, WindowWord language) noexcept
	:m_Type{ type }, m_Name{ name }, m_Language{ language }
{
}

const System::DynamicLinkCharType* System::EnumResourceData
	::GetType() const noexcept
{
	return m_Type;
}

const System::DynamicLinkCharType* System::EnumResourceData
	::GetName() const noexcept
{
	return m_Name;
}

const System::LanguageIDData System::EnumResourceData
	::GetLanguage() const noexcept
{
	const auto primaryLanguage = GetPrimaryLanguageID(m_Language);
	const auto subLanguage = GetSubLanguageID(m_Language);

	return LanguageIDData{ UnderlyingCastEnum<PrimaryLanguage>(primaryLanguage), UnderlyingCastEnum<SubLanguage>(subLanguage) };
}

