///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/08 14:42)

#ifndef CORE_TOOLS_FILE_MANAGER_C_WRITE_FILE_MANAGER_IMPL_H
#define CORE_TOOLS_FILE_MANAGER_C_WRITE_FILE_MANAGER_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "CFileManagerImpl.h"
#include "WriteFileManagerInterface.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"

namespace CoreTools
{
    // һ����ʾ���ݸ�_tfopen_s��ʾ�Ӵ���˳���ȡ�����Ż����档�����ӳ���ReadFromFile����������
    class CORE_TOOLS_HIDDEN_DECLARE CWriteFileManagerImpl final : public CFileManagerImpl, public WriteFileManagerInterface
    {
    public:
        using ClassType = CWriteFileManagerImpl;
        using ParentType = CFileManagerImpl;
        using InterfaceType = WriteFileManagerInterface;
        using String = System::String;

    public:
        explicit CWriteFileManagerImpl(const String& fileName, bool addition);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD int GetFileByteSize() const final;

        // ���ҽ���д����ֽ�������data�Ĵ�С�������ǳɹ��ġ������׳�Error�쳣��
        void Write(size_t itemSize, const void* data) final;
        void Write(size_t itemSize, size_t itemsNumber, const void* data) final;

#ifdef SYSTEM_BIG_ENDIAN
    private:
        NODISCARD size_t WriteToFileWithBigEndian(size_t itemSize, size_t itemsNumber, const void* data);
        NODISCARD size_t WriteToFileSwap2ByteOrder(size_t itemsNumber, const void* data);
        NODISCARD size_t WriteToFileSwap4ByteOrder(size_t itemsNumber, const void* data);
        NODISCARD size_t WriteToFileSwap8ByteOrder(size_t itemsNumber, const void* data);
#endif  // SYSTEM_BIG_ENDIAN

    private:
        // ��ֹ�������³�Ա����
        size_t ReadFromFile(MAYBE_UNUSED size_t itemSize, MAYBE_UNUSED size_t itemsNumber, MAYBE_UNUSED void* data) noexcept(gAssert < 4 || gCoreToolsAssert < 4) final;
        int GetCharacter() noexcept(gAssert < 4 || gCoreToolsAssert < 4) final;
        bool UnGetCharacter(MAYBE_UNUSED int character) noexcept(gAssert < 4 || gCoreToolsAssert < 4) final;
        std::string GetString(MAYBE_UNUSED int count) noexcept(gAssert < 4 || gCoreToolsAssert < 4) final;
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_C_WRITE_FILE_MANAGER_IMPL_H