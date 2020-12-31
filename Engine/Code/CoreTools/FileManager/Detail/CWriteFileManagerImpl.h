//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.1 (2020/10/13 17:22)

#ifndef CORE_TOOLS_FILE_MANAGER_C_WRITE_FILE_MANAGER_IMPL_H
#define CORE_TOOLS_FILE_MANAGER_C_WRITE_FILE_MANAGER_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "CFileManagerImpl.h"
#include "WriteFileManagerInterface.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"

// һ����ʾ���ݸ�_tfopen_s��ʾ�Ӵ���˳���ȡ�����Ż����档�����ӳ���ReadFromFile����������

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE CWriteFileManagerImpl final : public CFileManagerImpl, public WriteFileManagerInterface
    {
    public:
        using ClassType = CWriteFileManagerImpl;
        using ParentType = CFileManagerImpl;
        using InterfaceType = WriteFileManagerInterface;

    public:
        explicit CWriteFileManagerImpl(const String& fileName);

        CLASS_INVARIANT_FINAL_DECLARE;

        [[nodiscard]] int GetFileByteSize() const final;

        // ���ҽ���д����ֽ�������data�Ĵ�С�������ǳɹ��ġ������׳�Error�쳣��
        void Write(size_t itemSize, const void* data) final;
        void Write(size_t itemSize, size_t itemsNumber, const void* data) final;

#ifdef SYSTEM_BIG_ENDIAN
    private:
        [[nodiscard]] size_t WriteToFileWithBigEndian(size_t itemSize, size_t itemsNumber, const void* data) noexcept;
        [[nodiscard]] size_t WriteToFileSwap2ByteOrder(size_t itemsNumber, const void* data) noexcept;
        [[nodiscard]] size_t WriteToFileSwap4ByteOrder(size_t itemsNumber, const void* data) noexcept;
        [[nodiscard]] size_t WriteToFileSwap8ByteOrder(size_t itemsNumber, const void* data) noexcept;
#endif  // SYSTEM_BIG_ENDIAN

    private:
        // ��ֹ�������³�Ա����
        size_t ReadFromFile(size_t itemSize, size_t itemsNumber, void* data) noexcept(g_Assert < 4 || g_CoreToolsAssert < 4) final;
        int GetCharacter() noexcept(g_Assert < 4 || g_CoreToolsAssert < 4) final;
        bool UnGetCharacter(int character) noexcept(g_Assert < 4 || g_CoreToolsAssert < 4) final;
        std::string GetString(int count) noexcept(g_Assert < 4 || g_CoreToolsAssert < 4) final;
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_C_WRITE_FILE_MANAGER_IMPL_H