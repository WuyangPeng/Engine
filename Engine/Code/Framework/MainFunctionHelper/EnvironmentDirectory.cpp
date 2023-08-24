///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/08 19:37)

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
