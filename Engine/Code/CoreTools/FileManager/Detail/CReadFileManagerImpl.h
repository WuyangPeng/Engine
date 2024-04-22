/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/03/30 22:29)

#ifndef CORE_TOOLS_FILE_MANAGER_C_READ_FILE_MANAGER_IMPL_H
#define CORE_TOOLS_FILE_MANAGER_C_READ_FILE_MANAGER_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "CFileManagerImpl.h"
#include "ReadFileManagerInterface.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"

/// 调用成员函数WriteToFile、PutCharacter和PutString将产生错误。
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

        /// 当且仅当读出的字节数等于data的大小，操作是成功的。
        /// 否则抛出Error异常。
        void Read(size_t itemSize, void* data) override;
        void Read(size_t itemSize, size_t itemsNumber, void* data) override;

    private:
        /// 禁止调用以下成员函数
        size_t WriteToFile(size_t itemSize, size_t itemsNumber, const void* data) noexcept(gAssert < 4) override;
        bool PutCharacter(int character) noexcept(gAssert < 4) override;
        bool PutString(const std::string& str) noexcept(gAssert < 4) override;
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_C_READ_FILE_MANAGER_IMPL_H