/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/01 10:51)

#include "CoreTools/CoreToolsExport.h"

#include "IFileStreamManager.h"
#include "Detail/IFileStreamManagerImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::IFileStreamManager::IFileStreamManager(const String& fileName)
    : impl{ fileName }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, IFileStreamManager)

CoreTools::IFileStreamManager::String CoreTools::IFileStreamManager::GetFileContent() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->GetFileContent();
}

CoreTools::IFileStreamManager::String CoreTools::IFileStreamManager::BackupFile() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->BackupFile();
}

void CoreTools::IFileStreamManager::SetSimplifiedChinese()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return impl->SetSimplifiedChinese();
}

CoreTools::IFileStreamManager::IFileStream& CoreTools::IFileStreamManager::GetFileStream() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return impl->GetFileStream();
}

CoreTools::IFileStreamManager::FileContent CoreTools::IFileStreamManager::GetFileContent(System::StringView separate) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->GetFileContent(separate);
}
