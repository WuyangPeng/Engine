// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/11 13:46)

#include "Network/NetworkExport.h"

#ifdef NETWORK_USE_ACE

#include "StringConversion.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"  

using std::string;

Network::StringConversion
	::StringConversion()
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, StringConversion)

string Network::StringConversion
	::ACEStringConversionMultiByte(const ACEString& character)
{
#ifdef NETWORK_USES_ACE_WCHAR

	return CoreTools::StringConversion::WideCharConversionMultiByte(character);

#else // !NETWORK_USES_ACE_WCHAR

	return character;

#endif // NETWORK_USES_ACE_WCHAR
}

#endif // NETWORK_USE_ACE

