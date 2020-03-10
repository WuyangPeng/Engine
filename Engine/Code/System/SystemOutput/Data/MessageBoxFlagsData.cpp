// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 16:04)

#include "System/SystemExport.h"

#include "MessageBoxFlagsData.h"
#include "System/EnumOperator/EnumCastDetail.h"

System::MessageBoxType System::MessageBoxFlagsData
	::GetTypeFlag() const noexcept
{
	return m_TypeFlag;
}

System::MessageBoxIcon System::MessageBoxFlagsData
	::GetIconFlag() const noexcept
{
	return m_IconFlag;
}

System::MessageBoxDefault System::MessageBoxFlagsData
	::GetDefaultFlag() const noexcept
{
	return m_DefaultFlag;
}

System::MessageBoxMode System::MessageBoxFlagsData
	::GetModeFlag() const noexcept
{
	return m_ModeFlag;
}

System::MessageBoxMisc System::MessageBoxFlagsData
	::GetMiscFlag() const noexcept
{
	return m_MiscFlag;
}

System::WindowUInt System::MessageBoxFlagsData
	::GetFlag() const noexcept
{
	return EnumCastUnderlying(m_TypeFlag) | EnumCastUnderlying(m_IconFlag) | EnumCastUnderlying(m_DefaultFlag) |
		   EnumCastUnderlying(m_ModeFlag) | EnumCastUnderlying(m_MiscFlag);
}
