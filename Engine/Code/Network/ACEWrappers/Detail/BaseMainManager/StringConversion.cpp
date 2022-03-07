///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/22 17:56)

#include "Network/NetworkExport.h"

#ifdef NETWORK_USE_ACE

    #include "StringConversion.h"
    #include "CoreTools/CharacterString/StringConversion.h"
    #include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

using std::string;

Network::StringConversion::StringConversion() noexcept
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, StringConversion)

string Network::StringConversion::ACEStringConversionMultiByte(const ACEString& character)
{
    #ifdef NETWORK_USES_ACE_WCHAR

    return CoreTools::StringConversion::WideCharConversionMultiByte(character);

    #else  // !NETWORK_USES_ACE_WCHAR

    return character;

    #endif  // NETWORK_USES_ACE_WCHAR
}

#endif  // NETWORK_USE_ACE
