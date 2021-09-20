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

#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "CoreTools/Helper/SharedPtrMacro.h"

#include <vector>

 
EXPORT_SHARED_PTR(CoreTools, FileBufferImpl, CORE_TOOLS_DEFAULT_DECLARE);
namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE FileBuffer final
    {
    public:
    public:
        void Swap(FileBuffer& rhs) noexcept;

    public:
        TYPE_DECLARE(FileBuffer);
        using ClassShareType = CoreTools::CopyUnsharedClasses;
        ~FileBuffer() noexcept = default;
        FileBuffer(const FileBuffer& rhs);
        FileBuffer& operator=(const FileBuffer& rhs);
        FileBuffer(FileBuffer&& rhs) noexcept;
        FileBuffer& operator=(FileBuffer&& rhs) noexcept;
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
        using FileBufferImplPtr = std::shared_ptr<ImplType>;

    private:
        FileBufferImplPtr impl;
    };

    CORE_TOOLS_SHARED_PTR_DECLARE(FileBuffer);
}

#endif  // CORE_TOOLS_FILE_MANAGER_FILE_BUFFER_H
