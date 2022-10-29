///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/08 23:36)

#ifndef CORE_TOOLS_FILE_MANAGER_FILE_BUFFER_H
#define CORE_TOOLS_FILE_MANAGER_FILE_BUFFER_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"
#include "CoreTools/Helper/SharedPtrMacro.h"

#include <vector>

CORE_TOOLS_DELAY_COPY_UNSHARED_EXPORT_IMPL(FileBuffer, FileBufferImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE FileBuffer final
    {
    public:
        DELAY_COPY_UNSHARED_TYPE_DECLARE(FileBuffer);

        using BufferType = std::vector<char>;
        using BufferTypeIter = BufferType::iterator;
        using BufferTypeConstIter = BufferType::const_iterator;

    public:
        explicit FileBuffer(size_t count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD const char* GetConstBuffer(int index) const;
        NODISCARD const char* GetBuffer(int index) const;
        NODISCARD char* GetBuffer(int index);

        NODISCARD const char* GetConstBufferBegin() const noexcept;
        NODISCARD const char* GetBufferBegin() const noexcept;
        NODISCARD char* GetBufferBegin();

        NODISCARD size_t GetSize() const noexcept;

        NODISCARD BufferTypeConstIter begin() const noexcept;
        NODISCARD BufferTypeConstIter end() const noexcept;

        NODISCARD BufferTypeIter begin();
        NODISCARD BufferTypeIter end();

        void CopyBuffer(BufferTypeConstIter begin, BufferTypeConstIter end);

    private:
        PackageType impl;
    };

    CORE_TOOLS_SHARED_PTR_DECLARE(FileBuffer);
}

#endif  // CORE_TOOLS_FILE_MANAGER_FILE_BUFFER_H
