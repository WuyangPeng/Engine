//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.7.1.1 (2020/10/21 10:41)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_OUT_STREAM_H
#define CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_OUT_STREAM_H

#include "CoreTools/CoreToolsDll.h"

#include "ObjectSystemsFwd.h"
#include "CoreTools/FileManager/FileManagerFwd.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
CORE_TOOLS_NON_COPY_EXPORT_IMPL(BufferOutStreamImpl);

namespace CoreTools
{
    // 写objects到内存块。当操作失败时，抛出Error异常。
    class CORE_TOOLS_DEFAULT_DECLARE BufferOutStream final
    {
    public:
        NON_COPY_TYPE_DECLARE(BufferOutStream);

    public:
        explicit BufferOutStream(const OutTopLevel& topLevel);
        ~BufferOutStream() noexcept = default;
        BufferOutStream(const BufferOutStream& rhs) noexcept = delete;
        BufferOutStream& operator=(const BufferOutStream& rhs) noexcept = delete;
        BufferOutStream(BufferOutStream&& rhs) noexcept = delete;
        BufferOutStream& operator=(BufferOutStream&& rhs) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] FileBufferSharedPtr GetBufferOutStreamInformation() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_OUT_STREAM_H
