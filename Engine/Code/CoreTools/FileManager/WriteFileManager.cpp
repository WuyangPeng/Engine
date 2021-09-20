//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/14 14:56)

#include "CoreTools/CoreToolsExport.h"

#include "WriteFileManager.h"
#include "Detail/FileManagerFactory.h"
#include "Detail/WriteFileManagerInterface.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

#include <array>
#include "../Contract/Flags/ImplFlags.h"

using std::array;
using std::string;

CoreTools::WriteFileManager::WriteFileManager(const String& fileName)
    : impl{ CoreTools::ImplCreateUseFactory::Default,  fileName  }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, WriteFileManager)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, WriteFileManager, GetFileByteSize, int)

void CoreTools::WriteFileManager::Write(size_t itemSize, const void* data)
{
    

    return impl->Write(itemSize, data);
}

void CoreTools::WriteFileManager::Write(size_t itemSize, size_t itemsNumber, const void* data)
{
    

    return impl->Write(itemSize, itemsNumber, data);
}

void CoreTools::WriteFileManager::SaveStdString(const string& name)
{
    

    constexpr auto alignedLength = 4;

    auto length = boost::numeric_cast<int>(name.size());
    Write(sizeof(int), &length);

    if (0 < length)
    {
        Write(sizeof(char), length, name.c_str());

        // 字符串被写入四个字节的倍数。
        auto padding = (length % alignedLength);
        if (0 < padding)
        {
            constexpr array<char, alignedLength> zero{};
            padding = alignedLength - padding;

            Write(sizeof(char), padding, zero.data());
        }
    }
}
