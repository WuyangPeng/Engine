///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/08 23:25)

#ifndef CORE_TOOLS_FILE_MANAGER_FILE_BUFFER_IMPL_H
#define CORE_TOOLS_FILE_MANAGER_FILE_BUFFER_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include <vector>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE FileBufferImpl final
    {
    public:
        using ClassType = FileBufferImpl;
        using BufferType = std::vector<char>;
        using BufferTypeIter = BufferType::iterator;
        using BufferTypeConstIter = BufferType::const_iterator;

    public:
        explicit FileBufferImpl(size_t count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD const char* GetBuffer(int index) const;
        NODISCARD char* GetBuffer(int index);

        NODISCARD const char* GetBufferBegin() const noexcept;
        NODISCARD char* GetBufferBegin() noexcept;

        NODISCARD size_t GetSize() const noexcept;

        NODISCARD BufferTypeConstIter begin() const noexcept;
        NODISCARD BufferTypeConstIter end() const noexcept;

        NODISCARD BufferTypeIter begin() noexcept;
        NODISCARD BufferTypeIter end() noexcept;

    private:
        BufferType buffer;
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_FILE_BUFFER_IMPL_H
