//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/14 14:54)

#include "CoreTools/CoreToolsExport.h"

#include "ReadFileManager.h"
#include "Detail/FileManagerFactory.h"
#include "Detail/ReadFileManagerInterface.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

#include "../Contract/Flags/ImplFlags.h"
#include <vector>

using std::string;
using std::vector;

CoreTools::ReadFileManager::ReadFileManager(const String& fileName)
    : impl{ CoreTools::ImplCreateUseFactory::Default, fileName }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, ReadFileManager)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, ReadFileManager, GetFileByteSize, int)

void CoreTools::ReadFileManager::Read(size_t itemSize, void* data)
{
    

    return impl->Read(itemSize, data);
}

void CoreTools::ReadFileManager::Read(size_t itemSize, size_t itemsNumber, void* data)
{
    

    return impl->Read(itemSize, itemsNumber, data);
}

const string CoreTools::ReadFileManager::LoadStdString()
{
    

    constexpr auto alignedLength = 4;

    auto length = 0;
    Read(sizeof(int), &length);
    if (length <= 0)
    {
        return string{};
    }

    auto padding = (length % alignedLength);
    if (0 < padding)
    {
        padding = alignedLength - padding;
    }

    const auto numBytes = length + padding;
    vector<char> text(numBytes);
    Read(sizeof(char), numBytes, text.data());

    return string{ text.data(), boost::numeric_cast<size_t>(length) };
}
