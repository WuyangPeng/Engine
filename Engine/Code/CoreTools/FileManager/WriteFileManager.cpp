/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/01 10:52)

#include "CoreTools/CoreToolsExport.h"

#include "WriteFileManager.h"
#include "Flags/BufferIOFlags.h"
#include "Detail/FileManagerFactory.h"
#include "Detail/WriteFileManagerInterface.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#include <array>

CoreTools::WriteFileManager::WriteFileManager(const String& fileName, bool addition)
    : impl{ ImplCreateUseFactory::Default, fileName, addition }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, WriteFileManager)

int CoreTools::WriteFileManager::GetFileByteSize() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetFileByteSize();
}

void CoreTools::WriteFileManager::Write(size_t itemSize, const void* data)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->Write(itemSize, data);
}

void CoreTools::WriteFileManager::Write(size_t itemSize, size_t itemsNumber, const void* data)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->Write(itemSize, itemsNumber, data);
}

void CoreTools::WriteFileManager::SaveStdString(const std::string& name)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    const auto length = boost::numeric_cast<int32_t>(name.size());
    Write(sizeof(int32_t), &length);

    if (0 < length)
    {
        Write(sizeof(char), length, name.c_str());

        SaveAlignedString(length);
    }
}

void CoreTools::WriteFileManager::SaveAlignedString(int length)
{
    /// �ַ�����д���ĸ��ֽڵı�����
    if (auto padding = (length % alignedLength);
        0 < padding)
    {
        constexpr std::array<char, alignedLength> zero{};
        padding = alignedLength - padding;

        Write(sizeof(char), padding, zero.data());
    }
}
