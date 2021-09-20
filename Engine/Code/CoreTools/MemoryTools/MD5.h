//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.7.1.1 (2020/10/19 16:44)

#ifndef CORE_TOOLS_MEMORY_TOOLS_MD5_H
#define CORE_TOOLS_MEMORY_TOOLS_MD5_H

#include "CoreTools/CoreToolsDll.h"

#include "MD5Context.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <string>

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE MD5 final
    {
    public:
        using ClassType = MD5;

    public:
        explicit MD5(DisableNotThrow disableNotThrow);
        ~MD5() noexcept = default;
        MD5(const MD5& rhs) noexcept = delete;
        MD5& operator=(const MD5& rhs) noexcept = delete;
        MD5(MD5&& rhs) noexcept = delete;
        MD5& operator=(MD5&& rhs) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

        // 必须保证digest大小为16
        void MessageDigestAlgorithm5(uint8_t const* buffer, uint32_t length, uint8_t* digest);

        [[nodiscard]] const std::string MessageDigestAlgorithm5(const std::string& source);

        [[nodiscard]] const std::string MessageDigestAlgorithm5(uint8_t const* buffer, uint32_t length);

        [[nodiscard]] static const std::string GetHexDigestWithUppercase(const uint8_t* digest);
        [[nodiscard]] static const std::string GetHexDigestWithLowercase(const uint8_t* digest);

        [[nodiscard]] static int GetDigestSize() noexcept;

    private:
        static constexpr auto sm_DigestSize = 16;

        MD5Context m_MD5Context;
    };

}
#endif  // CORE_TOOLS_MEMORY_TOOLS_MD5_H
