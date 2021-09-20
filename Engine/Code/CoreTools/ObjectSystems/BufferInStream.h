//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.7.1.1 (2020/10/21 10:40)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_IN_STREAM_H
#define CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_IN_STREAM_H

#include "CoreTools/CoreToolsDll.h"

#include "InTopLevel.h"
#include "CoreTools/FileManager/FileManagerFwd.h"
#include "CoreTools/Helper/ExportMacro.h"

 #include "CoreTools/Helper/Export/NonCopyMacro.h"

CORE_TOOLS_NON_COPY_EXPORT_IMPL(BufferInStreamImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE BufferInStream final 
    {
    public:
        NON_COPY_TYPE_DECLARE(BufferInStream);

    public:
        explicit BufferInStream(const ConstFileBufferSharedPtr& bufferInformation, int startPoint = 0);
        ~BufferInStream() noexcept = default;
        BufferInStream(const BufferInStream& rhs) noexcept = delete;
        BufferInStream& operator=(const BufferInStream& rhs) noexcept = delete;
        BufferInStream(BufferInStream&& rhs) noexcept = delete;
        BufferInStream& operator=(BufferInStream&& rhs) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] const InTopLevel GetTopLevel() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_IN_STREAM_H
