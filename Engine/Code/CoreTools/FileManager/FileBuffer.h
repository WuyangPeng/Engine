//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.1 (2020/10/13 10:34)

#ifndef CORE_TOOLS_FILE_MANAGER_FILE_BUFFER_H
#define CORE_TOOLS_FILE_MANAGER_FILE_BUFFER_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include <vector>

CORE_TOOLS_EXPORT_SHARED_PTR(FileBufferImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE FileBuffer final
    {
    public:
        COPY_UNSHARE_CLASSES_TYPE_DECLARE(FileBuffer, = default);
        using BufferType = std::vector<char>;
        using BufferTypeIter = BufferType::iterator;
        using BufferTypeConstIter = BufferType::const_iterator;

    public:
        explicit FileBuffer(size_t count);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] const char* GetBuffer(int index) const;
        [[nodiscard]] char* GetBuffer(int index);

        [[nodiscard]] const char* GetBufferBegin() const noexcept;
        [[nodiscard]] char* GetBufferBegin() noexcept;

        [[nodiscard]] size_t GetSize() const noexcept;

        [[nodiscard]] BufferTypeConstIter begin() const noexcept;
        [[nodiscard]] BufferTypeConstIter end() const noexcept;

        [[nodiscard]] BufferTypeIter begin() noexcept;
        [[nodiscard]] BufferTypeIter end() noexcept;

    private:
        IMPL_TYPE_DECLARE(FileBuffer);
    };

    using FileBufferSharedPtr = std::shared_ptr<FileBuffer>;
    using ConstFileBufferSharedPtr = std::shared_ptr<const FileBuffer>;
}

#endif  // CORE_TOOLS_FILE_MANAGER_FILE_BUFFER_H
