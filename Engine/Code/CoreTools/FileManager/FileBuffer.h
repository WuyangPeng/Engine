/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/03/30 22:55)

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
        explicit FileBuffer(int count);

        CLASS_INVARIANT_DECLARE;

        NODISCARD const char* GetConstBuffer(int index) const;
        NODISCARD const char* GetBuffer(int index) const;
        NODISCARD char* GetBuffer(int index);

        NODISCARD const char* GetConstBufferBegin() const noexcept;
        NODISCARD const char* GetBufferBegin() const noexcept;
        NODISCARD char* GetBufferBegin();

        NODISCARD int GetSize() const;

        NODISCARD BufferTypeConstIter begin() const noexcept;
        NODISCARD BufferTypeConstIter end() const noexcept;

        NODISCARD BufferTypeIter begin();
        NODISCARD BufferTypeIter end();

        void CopyBuffer(const BufferTypeConstIter& begin, const BufferTypeConstIter& end);

    private:
        PackageType impl;
    };

    CORE_TOOLS_SHARED_PTR_DECLARE(FileBuffer);
}

#endif  // CORE_TOOLS_FILE_MANAGER_FILE_BUFFER_H
