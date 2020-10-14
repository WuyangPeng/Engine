//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/13 18:10)

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
        BufferType m_Buffer;
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_FILE_BUFFER_IMPL_H
