///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.4 (2023/03/23 15:42)

#include "CoreTools/CoreToolsExport.h"

#include "WriteFileManager.h"
#include "Detail/FileManagerFactory.h"
#include "Detail/WriteFileManagerInterface.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

#include <array>

CoreTools::WriteFileManager::WriteFileManager(const String& fileName, bool addition)
    : impl{ CoreTools::ImplCreateUseFactory::Default, fileName, addition }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, WriteFileManager)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, WriteFileManager, GetFileByteSize, int)

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
        constexpr auto alignedLength = 4;

        Write(sizeof(char), length, name.c_str());

        // �ַ�����д���ĸ��ֽڵı�����
        if (auto padding = (length % alignedLength); 0 < padding)
        {
            constexpr std::array<char, alignedLength> zero{};
            padding = alignedLength - padding;

            Write(sizeof(char), padding, zero.data());
        }
    }
}
