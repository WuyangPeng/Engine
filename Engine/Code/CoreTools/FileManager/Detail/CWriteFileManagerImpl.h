/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/10 21:38)

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

        using String = System::String;

    public:
        explicit CWriteFileManagerImpl(const String& fileName, bool addition);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD int GetFileByteSize() const override;

        // ���ҽ���д����ֽ�������data�Ĵ�С�������ǳɹ��ġ������׳�Error�쳣��
        void Write(size_t itemSize, const void* data) override;
        void Write(size_t itemSize, size_t itemsNumber, const void* data) override;

#ifdef SYSTEM_BIG_ENDIAN

    private:
        NODISCARD size_t WriteToFileWithBigEndian(size_t itemSize, size_t itemsNumber, const void* data);
        NODISCARD size_t WriteToFileSwap2ByteOrder(size_t itemsNumber, const void* data);
        NODISCARD size_t WriteToFileSwap4ByteOrder(size_t itemsNumber, const void* data);
        NODISCARD size_t WriteToFileSwap8ByteOrder(size_t itemsNumber, const void* data);

#endif  // SYSTEM_BIG_ENDIAN

    private:
        // ��ֹ�������³�Ա����
        size_t ReadFromFile(size_t itemSize, size_t itemsNumber, void* data) noexcept(gAssert < 4 || gCoreToolsAssert < 4) override;
        int GetCharacter() noexcept(gAssert < 4 || gCoreToolsAssert < 4) override;
        bool UnGetCharacter(int character) noexcept(gAssert < 4 || gCoreToolsAssert < 4) override;
        std::string GetString(int count) noexcept(gAssert < 4 || gCoreToolsAssert < 4) override;
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_C_WRITE_FILE_MANAGER_IMPL_H