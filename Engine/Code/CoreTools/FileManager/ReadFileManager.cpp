///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.3 (2023/03/02 11:06)

#include "CoreTools/CoreToolsExport.h"

#include "ReadFileManager.h"
#include "Detail/FileManagerFactory.h"
#include "Detail/ReadFileManagerInterface.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

#include <vector>

CoreTools::ReadFileManager::ReadFileManager(const String& fileName)
    : impl{ CoreTools::ImplCreateUseFactory::Default, fileName }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, ReadFileManager)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, ReadFileManager, GetFileByteSize, int)

void CoreTools::ReadFileManager::Read(size_t itemSize, void* data)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->Read(itemSize, data);
}

void CoreTools::ReadFileManager::Read(size_t itemSize, size_t itemsNumber, void* data)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->Read(itemSize, itemsNumber, data);
}

std::string CoreTools::ReadFileManager::LoadStdString()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    constexpr auto alignedLength = 4;

    int32_t length{ 0 };

    Read(sizeof(int32_t), &length);
    if (length <= 0)
    {
        return std::string{};
    }

    auto padding = (length % alignedLength);
    if (0 < padding)
    {
        padding = alignedLength - padding;
    }

    const auto numBytes = length + padding;
    std::vector<char> text(numBytes);
    Read(sizeof(char), numBytes, text.data());

    return std::string{ text.data(), boost::numeric_cast<size_t>(length) };
}
