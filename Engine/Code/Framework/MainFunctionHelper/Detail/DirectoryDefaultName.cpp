///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/13 14:40)

#include "Framework/FrameworkExport.h"

#include "DirectoryDefaultName.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/MainFunctionHelper/Flags/Directory.h"

using namespace std::literals;

System::String Framework::DirectoryDefaultName::GetDefaultNullName()
{
    return SYSTEM_TEXT(""s);
}

System::String Framework::DirectoryDefaultName::GetSuffix()
{
    return SYSTEM_TEXT("/"s);
}

System::String Framework::DirectoryDefaultName::GetDefaultName(AnalysisDirectory analysisDirectory)
{
    switch (analysisDirectory)
    {
        case Framework::AnalysisDirectory::Resource:
        case Framework::AnalysisDirectory::Configuration:
        case Framework::AnalysisDirectory::BigEndian:
        case Framework::AnalysisDirectory::Shader:
        case Framework::AnalysisDirectory::Scene:
        case Framework::AnalysisDirectory::Texture:
        case Framework::AnalysisDirectory::Vertex:
        case Framework::AnalysisDirectory::Image:
            return GetDefaultKeyName(analysisDirectory);
        default:
            return DirectoryDefaultName::GetDefaultNullName();
    }
}

#define DIRECTORY_DESCRIBE_JUDGE(describe)       \
    case Framework::AnalysisDirectory::describe: \
        return SYSTEM_TEXT(SYSTEM_CONCATENATOR(#describe, s))

System::String Framework::DirectoryDefaultName::GetDefaultKeyName(AnalysisDirectory analysisDirectory)
{
    switch (analysisDirectory)
    {
        DIRECTORY_DESCRIBE_JUDGE(Resource);
        DIRECTORY_DESCRIBE_JUDGE(Configuration);
        DIRECTORY_DESCRIBE_JUDGE(LittleEndian);
        DIRECTORY_DESCRIBE_JUDGE(BigEndian);
        DIRECTORY_DESCRIBE_JUDGE(Shader);
        DIRECTORY_DESCRIBE_JUDGE(Scene);
        DIRECTORY_DESCRIBE_JUDGE(Texture);
        DIRECTORY_DESCRIBE_JUDGE(Vertex);
        DIRECTORY_DESCRIBE_JUDGE(Image);
        DIRECTORY_DESCRIBE_JUDGE(Directory);
        DIRECTORY_DESCRIBE_JUDGE(Default);
        DIRECTORY_DESCRIBE_JUDGE(OpenGL);
        DIRECTORY_DESCRIBE_JUDGE(DirectX);
        default:
            return DirectoryDefaultName::GetDefaultNullName();
    }
}
