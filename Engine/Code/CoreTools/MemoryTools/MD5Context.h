//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.7.1.1 (2020/10/19 16:45)

#ifndef CORE_TOOLS_MEMORY_TOOLS_MD5_CONTEXT_H
#define CORE_TOOLS_MEMORY_TOOLS_MD5_CONTEXT_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
 
#include "CoreTools/Helper/Export/NonCopyMacro.h"

CORE_TOOLS_NON_COPY_EXPORT_IMPL(MD5ContextImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE MD5Context final  
    {
    public:
        NON_COPY_TYPE_DECLARE(MD5Context);

    public:
        explicit MD5Context(DisableNotThrow disableNotThrow);
        ~MD5Context() noexcept = default;
        MD5Context(const MD5Context& rhs) noexcept = delete;
        MD5Context& operator=(const MD5Context& rhs) noexcept = delete;
        MD5Context(MD5Context&& rhs) noexcept = delete;
        MD5Context& operator=(MD5Context&& rhs) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

        void MD5Init();

        // �����ε���MD5Update���ڶԶ��������и���
        void MD5Update(uint8_t const* buffer, uint32_t length) noexcept(g_Assert < 2 || g_CoreToolsAssert < 2);

        void MD5Final(uint8_t* digest);

    private:
        PackageType impl;
    };
}
#endif  // CORE_TOOLS_MEMORY_TOOLS_MD5_CONTEXT_H
