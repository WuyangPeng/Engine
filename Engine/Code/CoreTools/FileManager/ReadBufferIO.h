//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.1 (2020/10/13 20:29)

#ifndef CORE_TOOLS_FILE_MANAGER_READ_BUFFERIO_H
#define CORE_TOOLS_FILE_MANAGER_READ_BUFFERIO_H

#include "CoreTools/CoreToolsDll.h"

#include "FileBuffer.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <boost/noncopyable.hpp>
#include <string>

CORE_TOOLS_EXPORT_SHARED_PTR(ReadBufferIOImpl);
EXPORT_NONCOPYABLE_CLASS(CORE_TOOLS);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE ReadBufferIO final : private boost::noncopyable
    {
    public:
        NON_COPY_CLASSES_TYPE_DECLARE(ReadBufferIO);

    public:
        explicit ReadBufferIO(const ConstFileBufferSharedPtr& fileBuffer);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] std::string GetText(int length) const;

        [[nodiscard]] int GetBytesTotal() const;
        [[nodiscard]] int GetBytesProcessed() const noexcept;

        void IncrementBytesProcessed(int bytesNumber) noexcept(g_Assert < 2 || g_CoreToolsAssert < 2);
        void Read(size_t itemSize, void* data);
        void Read(size_t itemSize, size_t itemsNumber, void* data);

    private:
        IMPL_TYPE_DECLARE(ReadBufferIO);
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_READ_BUFFERIO_H
