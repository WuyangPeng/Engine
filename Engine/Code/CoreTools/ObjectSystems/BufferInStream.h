//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/21 10:40)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_IN_STREAM_H
#define CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_IN_STREAM_H

#include "CoreTools/CoreToolsDll.h"

#include "InTopLevel.h"
#include "CoreTools/FileManager/FileManagerFwd.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <boost/noncopyable.hpp>

CORE_TOOLS_EXPORT_SHARED_PTR(BufferInStreamImpl);
EXPORT_NONCOPYABLE_CLASS(CORE_TOOLS);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE BufferInStream final : private boost::noncopyable
    {
    public:
        NON_COPY_CLASSES_TYPE_DECLARE(BufferInStream);

    public:
        explicit BufferInStream(const ConstFileBufferSharedPtr& bufferInformation, int startPoint = 0);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] const InTopLevel GetTopLevel() const noexcept;

    private:
        IMPL_TYPE_DECLARE(BufferInStream);
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_IN_STREAM_H
