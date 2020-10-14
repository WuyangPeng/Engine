//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.1 (2020/10/13 17:20)

#ifndef CORE_TOOLS_FILE_MANAGER_C_READ_FILE_MANAGER_IMPL_H
#define CORE_TOOLS_FILE_MANAGER_C_READ_FILE_MANAGER_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "CFileManagerImpl.h"
#include "ReadFileManagerInterface.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"

// һ����ʾ���ݸ�_tfopen_s��ʾ�Ӵ���˳���ȡ�����Ż����档
// ���ó�Ա����WriteToFile��PutCharacter��PutString����������

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE CReadFileManagerImpl final : public CFileManagerImpl, public ReadFileManagerInterface
    {
    public:
        using ClassType = CReadFileManagerImpl;
        using ParentType = CFileManagerImpl;
        using InterfaceType = ReadFileManagerInterface;

    public:
        explicit CReadFileManagerImpl(const String& fileName);

        CLASS_INVARIANT_FINAL_DECLARE;

        [[nodiscard]] int GetFileByteSize() const final;

        // ���ҽ����������ֽ�������data�Ĵ�С�������ǳɹ��ġ������׳�Error�쳣��
        void Read(size_t itemSize, void* data) final;
        void Read(size_t itemSize, size_t itemsNumber, void* data) final;

    private:
        // ��ֹ�������³�Ա����
        size_t WriteToFile(size_t itemSize, size_t itemsNumber, const void* data) noexcept(g_Assert < 4 || g_CoreToolsAssert < 4) final;
        bool PutCharacter(int character) noexcept(g_Assert < 4 || g_CoreToolsAssert < 4) final;
        bool PutString(const std::string& str) noexcept(g_Assert < 4 || g_CoreToolsAssert < 4) final;
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_C_READ_FILE_MANAGER_IMPL_H