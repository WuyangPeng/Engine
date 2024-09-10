/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.1.0 (2024/08/06 19:32)

#include "Framework/FrameworkExport.h"

#include "DirectoryDefaultName.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/MainFunctionHelper/Flags/Directory.h"

System::String Framework::DirectoryDefaultName::GetDefaultNullName()
{
    return SYSTEM_TEXT("");
}

System::String Framework::DirectoryDefaultName::GetSuffix()
{
    return SYSTEM_TEXT("/");
}

System::String Framework::DirectoryDefaultName::GetDefaultName(AnalysisDirectory analysisDirectory)
{
    switch (analysisDirectory)
    {
        case AnalysisDirectory::Resource:
        case AnalysisDirectory::Configuration:
        case AnalysisDirectory::BigEndian:
        case AnalysisDirectory::Shader:
        case AnalysisDirectory::Scene:
        case AnalysisDirectory::Texture:
        case AnalysisDirectory::Vertex:
        case AnalysisDirectory::Image:
            return GetDefaultKeyName(analysisDirectory);
        default:
            return GetDefaultNullName();
    }
}

#define DIRECTORY_DESCRIBE_JUDGE(describe)       \
    case Framework::AnalysisDirectory::describe: \
        return SYSTEM_TEXT(#describe)

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
            return GetDefaultNullName();
    }
}