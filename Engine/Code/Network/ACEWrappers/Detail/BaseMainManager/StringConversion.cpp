/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 17:30)

#include "Network/NetworkExport.h"

#include "StringConversion.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

#ifdef NETWORK_USE_ACE

Network::StringConversion::StringConversion() noexcept
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, StringConversion)

std::string Network::StringConversion::ACEStringConversionMultiByte(const ACEString& character)
{
    #ifdef NETWORK_USES_ACE_WCHAR

    return CoreTools::StringConversion::WideCharConversionMultiByte(character);

    #else  // !NETWORK_USES_ACE_WCHAR

    return character;

    #endif  // NETWORK_USES_ACE_WCHAR
}

#endif  // NETWORK_USE_ACE
