///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/23 15:22)

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
        explicit FileBufferImpl(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD const char* GetBuffer(int index) const;
        NODISCARD char* GetBuffer(int index);

        NODISCARD const char* GetBufferBegin() const noexcept;
        NODISCARD char* GetBufferBegin() noexcept;

        NODISCARD int GetSize() const;

        NODISCARD BufferTypeConstIter begin() const noexcept;
        NODISCARD BufferTypeConstIter end() const noexcept;

        NODISCARD BufferTypeIter begin() noexcept;
        NODISCARD BufferTypeIter end() noexcept;

        void CopyBuffer(const BufferTypeConstIter& begin, const BufferTypeConstIter& end);

    private:
        BufferType buffer;
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_FILE_BUFFER_IMPL_H
