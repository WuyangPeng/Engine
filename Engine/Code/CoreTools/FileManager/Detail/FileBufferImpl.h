/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/03/30 22:33)

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
