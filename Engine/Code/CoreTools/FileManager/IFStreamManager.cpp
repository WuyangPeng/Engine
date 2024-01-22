/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 00:09)

#include "CoreTools/CoreToolsExport.h"

#include "IFStreamManager.h"
#include "Detail/IFStreamManagerImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::IFStreamManager::IFStreamManager(const String& fileName)
    : impl{ fileName }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, IFStreamManager)

CoreTools::IFStreamManager::String CoreTools::IFStreamManager::GetFileContent() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->GetFileContent();
}

CoreTools::IFStreamManager::String CoreTools::IFStreamManager::BackupFile() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->BackupFile();
}

void CoreTools::IFStreamManager::SetSimplifiedChinese()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return impl->SetSimplifiedChinese();
}

CoreTools::IFStreamManager::IFileStream& CoreTools::IFStreamManager::GetFileStream() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return impl->GetFileStream();
}

CoreTools::IFStreamManager::FileContent CoreTools::IFStreamManager::GetFileContent(System::StringView separate) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->GetFileContent(separate);
}
