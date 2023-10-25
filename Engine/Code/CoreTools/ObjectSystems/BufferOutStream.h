///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/09/20 15:24)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_OUT_STREAM_H
#define CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_OUT_STREAM_H

#include "CoreTools/CoreToolsDll.h"

#include "ObjectSystemsFwd.h"
#include "CoreTools/FileManager/FileManagerFwd.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "CoreTools/Helper/ExportMacro.h"

CORE_TOOLS_NON_COPY_EXPORT_IMPL(BufferOutStreamImpl);

// дobjects���ڴ�顣������ʧ��ʱ���׳�Error�쳣��
namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE BufferOutStream final
    {
    public:
        NON_COPY_TYPE_DECLARE(BufferOutStream);

    public:
        explicit BufferOutStream(const OutTopLevel& topLevel);

        CLASS_INVARIANT_DECLARE;

        NODISCARD ConstFileBufferSharedPtr GetBufferOutStreamInformation() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_OUT_STREAM_H
