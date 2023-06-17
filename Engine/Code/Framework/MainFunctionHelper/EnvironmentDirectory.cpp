///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/13 14:40)

#include "Framework/FrameworkExport.h"

#include "EnvironmentDirectory.h"
#include "Detail/EnvironmentDirectoryImpl.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

Framework::EnvironmentDirectory::EnvironmentDirectory(const String& engineEnvironment, const String& engineDirectory)
    : impl{ engineEnvironment, engineDirectory }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, EnvironmentDirectory)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, EnvironmentDirectory, GetEngineEnvironment, System::String)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, EnvironmentDirectory, GetEngineDirectory, System::String)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Framework, EnvironmentDirectory, GetDirectory, UpperDirectory, System::String)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Framework, EnvironmentDirectory, GetPath, RenderingAnalysisDirectory, System::String)

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
