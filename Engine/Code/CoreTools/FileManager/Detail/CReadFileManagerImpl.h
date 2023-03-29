///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.4 (2023/03/23 15:21)

#ifndef CORE_TOOLS_FILE_MANAGER_C_READ_FILE_MANAGER_IMPL_H
#define CORE_TOOLS_FILE_MANAGER_C_READ_FILE_MANAGER_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "CFileManagerImpl.h"
#include "ReadFileManagerInterface.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"

/// һ����ʾ���ݸ�_tfopen_s��ʾ�Ӵ���˳���ȡ�����Ż����档
/// ���ó�Ա����WriteToFile��PutCharacter��PutString����������
namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE CReadFileManagerImpl final : public CFileManagerImpl, public ReadFileManagerInterface
    {
    public:
        using ClassType = CReadFileManagerImpl;
        using ParentType = CFileManagerImpl;
        using InterfaceType = ReadFileManagerInterface;
        using String = System::String;

    public:
        explicit CReadFileManagerImpl(const String& fileName);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD int GetFileByteSize() const override;

        // ���ҽ����������ֽ�������data�Ĵ�С�������ǳɹ��ġ������׳�Error�쳣��
        void Read(size_t itemSize, void* data) override;
        void Read(size_t itemSize, size_t itemsNumber, void* data) override;

    private:
        // ��ֹ�������³�Ա����
        size_t WriteToFile(size_t itemSize, size_t itemsNumber, const void* data) noexcept(gAssert < 4 || gCoreToolsAssert < 4) override;
        bool PutCharacter(int character) noexcept(gAssert < 4 || gCoreToolsAssert < 4) override;
        bool PutString(const std::string& str) noexcept(gAssert < 4 || gCoreToolsAssert < 4) override;
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_C_READ_FILE_MANAGER_IMPL_H