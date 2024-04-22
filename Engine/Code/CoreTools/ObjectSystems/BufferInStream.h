/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/11 22:10)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_IN_STREAM_H
#define CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_IN_STREAM_H

#include "CoreTools/CoreToolsDll.h"

#include "InTopLevel.h"
#include "CoreTools/FileManager/FileManagerFwd.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "CoreTools/Helper/ExportMacro.h"

CORE_TOOLS_NON_COPY_EXPORT_IMPL(BufferInStreamImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE BufferInStream final
    {
    public:
        NON_COPY_TYPE_DECLARE(BufferInStream);

    public:
        explicit BufferInStream(const ConstFileBufferSharedPtr& bufferInformation, int startPoint = 0);

        CLASS_INVARIANT_DECLARE;

        NODISCARD InTopLevel GetTopLevel() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_IN_STREAM_H
