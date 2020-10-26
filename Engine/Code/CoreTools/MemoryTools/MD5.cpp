//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/20 10:06)

#include "CoreTools/CoreToolsExport.h"

#include "MD5.h"
#include "MD5Context.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#include <array>
#include <iomanip>
#include <sstream>
#include <vector>

using std::array;
using std::hex;
using std::setfill;
using std::setw;
using std::string;
using std::stringstream;
using std::uppercase;
using std::vector;

CoreTools::MD5::MD5(DisableNotThrow disableNotThrow)
    : m_MD5Context{ disableNotThrow }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, MD5)

void CoreTools::MD5::MessageDigestAlgorithm5(uint8_t const* buffer, uint32_t length, uint8_t* digest)
{
    CORE_TOOLS_CLASS_IS_VALID_1;
    CORE_TOOLS_ASSERTION_0(digest != nullptr, "返回的缓冲区为空！");

    m_MD5Context.MD5Init();

    m_MD5Context.MD5Update(buffer, length);

    return m_MD5Context.MD5Final(digest);
}

const string CoreTools::MD5::MessageDigestAlgorithm5(uint8_t const* buffer, uint32_t length)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    array<uint8_t, sm_DigestSize> digest{};

    MessageDigestAlgorithm5(buffer, length, digest.data());

    return GetHexDigestWithLowercase(digest.data());
}

const string CoreTools::MD5::MessageDigestAlgorithm5(const string& source)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    m_MD5Context.MD5Init();

    if (!source.empty())
    {
        vector<char> buffer{ source.begin(), source.end() };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
        m_MD5Context.MD5Update(reinterpret_cast<const uint8_t*>(buffer.data()), boost::numeric_cast<uint32_t>(buffer.size()));
#include STSTEM_WARNING_POP
    }
    else
    {
        m_MD5Context.MD5Update(nullptr, 0);
    }

    array<uint8_t, sm_DigestSize> digest{};

    m_MD5Context.MD5Final(digest.data());

    return GetHexDigestWithLowercase(digest.data());
}

const string CoreTools::MD5::GetHexDigestWithUppercase(const uint8_t* digest)
{
    if (digest != nullptr)
    {
        stringstream ss{};

        for (auto i = 0; i < sm_DigestSize; ++i)
        {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
            ss << hex << uppercase << setw(2) << setfill('0')
               << static_cast<int>(digest[i]);
#include STSTEM_WARNING_POP
        }

        return ss.str();
    }
    else
    {
        return string{};
    }
}

const string CoreTools::MD5::GetHexDigestWithLowercase(const uint8_t* digest)
{
    if (digest != nullptr)
    {
        stringstream ss{};

        for (auto i = 0; i < sm_DigestSize; ++i)
        {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
            ss << hex << setw(2) << setfill('0')
               << static_cast<int>(digest[i]);
#include STSTEM_WARNING_POP
        }

        return ss.str();
    }
    else
    {
        return string{};
    }
}

int CoreTools::MD5::GetDigestSize() noexcept
{
    return sm_DigestSize;
}
