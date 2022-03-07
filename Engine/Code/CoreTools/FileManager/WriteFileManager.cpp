///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/09 1:50)

#include "CoreTools/CoreToolsExport.h"

#include "WriteFileManager.h"
#include "Detail/FileManagerFactory.h"
#include "Detail/WriteFileManagerInterface.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

#include <array>

using std::array;
using std::string;

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

void CoreTools::WriteFileManager::SaveStdString(const string& name)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    constexpr auto alignedLength = 4;

    auto length = boost::numeric_cast<int32_t>(name.size());
    Write(sizeof(int32_t), &length);

    if (0 < length)
    {
        Write(sizeof(char), length, name.c_str());

        // �ַ�����д���ĸ��ֽڵı�����
        auto padding = (length % alignedLength);
        if (0 < padding)
        {
            constexpr array<char, alignedLength> zero{};
            padding = alignedLength - padding;

            Write(sizeof(char), padding, zero.data());
        }
    }
}
