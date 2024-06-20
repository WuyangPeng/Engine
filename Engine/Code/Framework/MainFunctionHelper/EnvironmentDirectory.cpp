/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 15:11)

#include "Framework/FrameworkExport.h"

#include "EnvironmentDirectory.h"
#include "Detail/EnvironmentDirectoryImpl.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

Framework::EnvironmentDirectory::EnvironmentDirectory(const String& engineEnvironment, const String& engineDirectory)
    : impl{ engineEnvironment, engineDirectory }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, EnvironmentDirectory)

Framework::EnvironmentDirectory::String Framework::EnvironmentDirectory::GetEngineEnvironment() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return impl->GetEngineEnvironment();
}

Framework::EnvironmentDirectory::String Framework::EnvironmentDirectory::GetEngineDirectory() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return impl->GetEngineDirectory();
}

Framework::EnvironmentDirectory::String Framework::EnvironmentDirectory::GetDirectory(UpperDirectory analysisDirectory) const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return impl->GetDirectory(analysisDirectory);
}

Framework::EnvironmentDirectory::String Framework::EnvironmentDirectory::GetServerConfigurationDirectory() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return impl->GetServerConfigurationDirectory();
}

Framework::EnvironmentDirectory::String Framework::EnvironmentDirectory::GetPath(RenderingAnalysisDirectory analysisDirectory) const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return impl->GetPath(analysisDirectory);
}

System::String Framework::EnvironmentDirectory::GetPath(RenderingDirectory renderingDirectory, RenderingAnalysisDirectory analysisDirectory) const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return impl->GetPath(renderingDirectory, analysisDirectory);
}

System::String Framework::EnvironmentDirectory::GetPath(EndianDirectory endianDirectory, RenderingDirectory renderingDirectory, RenderingAnalysisDirectory analysisDirectory) const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return impl->GetPath(endianDirectory, renderingDirectory, analysisDirectory);
}
