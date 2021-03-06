//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/13 10:34)

#ifndef CORE_TOOLS_FILE_MANAGER_FILE_BUFFER_H
#define CORE_TOOLS_FILE_MANAGER_FILE_BUFFER_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/SharedPtrMacro.h"

#include <vector>

CORE_TOOLS_EXPORT_SHARED_PTR(FileBufferImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE FileBuffer final
    {
    public:
        COPY_UNSHARE_CLASSES_TYPE_DECLARE(FileBuffer, DESTRUCTOR_DEFAULT);
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

    CORE_TOOLS_SHARED_PTR_DECLARE(FileBuffer);
}

#endif  // CORE_TOOLS_FILE_MANAGER_FILE_BUFFER_H
