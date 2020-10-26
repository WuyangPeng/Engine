//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.0 (2020/10/19 16:44)

#ifndef CORE_TOOLS_MEMORY_TOOLS_MD5_H
#define CORE_TOOLS_MEMORY_TOOLS_MD5_H

#include "CoreTools/CoreToolsDll.h"

#include "MD5Context.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <boost/noncopyable.hpp>
#include <string>

EXPORT_NONCOPYABLE_CLASS(CORE_TOOLS);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE MD5 final : private boost::noncopyable
    {
    public:
        using ClassType = MD5;

    public:
        explicit MD5(DisableNotThrow disableNotThrow);

        CLASS_INVARIANT_DECLARE;

        // ���뱣֤digest��СΪ16
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
