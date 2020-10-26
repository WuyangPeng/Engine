//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/21 10:41)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_OUT_STREAM_H
#define CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_OUT_STREAM_H

#include "CoreTools/CoreToolsDll.h"

#include "ObjectSystemsFwd.h"
#include "CoreTools/FileManager/FileManagerFwd.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <boost/noncopyable.hpp>

CORE_TOOLS_EXPORT_SHARED_PTR(BufferOutStreamImpl);
EXPORT_NONCOPYABLE_CLASS(CORE_TOOLS);

namespace CoreTools
{
    // 写objects到内存块。当操作失败时，抛出Error异常。
    class CORE_TOOLS_DEFAULT_DECLARE BufferOutStream final : private boost::noncopyable
    {
    public:
        NON_COPY_CLASSES_TYPE_DECLARE(BufferOutStream);

    public:
        explicit BufferOutStream(const OutTopLevel& topLevel);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] FileBufferSharedPtr GetBufferOutStreamInformation() const noexcept;

    private:
        IMPL_TYPE_DECLARE(BufferOutStream);
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_OUT_STREAM_H
