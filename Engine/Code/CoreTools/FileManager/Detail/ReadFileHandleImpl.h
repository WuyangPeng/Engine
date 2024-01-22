/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/10 21:40)

#ifndef CORE_TOOLS_FILE_MANAGER_READ_FILE_HANDLE_IMPL_H
#define CORE_TOOLS_FILE_MANAGER_READ_FILE_HANDLE_IMPL_H

#include "FileHandleImpl.h"
#include "ReadFileManagerInterface.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE ReadFileHandleImpl final : public FileHandleImpl, public ReadFileManagerInterface
    {
    public:
        using ClassType = ReadFileHandleImpl;
        using ParentType = FileHandleImpl;
        using InterfaceType = ReadFileManagerInterface;

        using String = System::String;

    public:
        explicit ReadFileHandleImpl(const String& fileName);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD int GetFileByteSize() const override;

        void Read(size_t itemSize, void* data) override;
        void Read(size_t itemSize, size_t itemsNumber, void* data) override;

    private:
        // ��ֹ�������³�Ա����
        void WriteToFile(size_t itemSize, size_t itemsNumber, const void* data) noexcept(gAssert < 4 || gCoreToolsAssert < 4) override;
        void AppendToFile(size_t itemSize, size_t itemsNumber, const void* data) noexcept(gAssert < 4 || gCoreToolsAssert < 4) override;
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_READ_FILE_HANDLE_IMPL_H