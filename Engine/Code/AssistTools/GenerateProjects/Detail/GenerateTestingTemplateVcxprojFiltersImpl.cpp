///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2022/04/29 13:41)

#include "AssistTools/AssistToolsExport.h"

#include "GenerateTestingTemplateVcxprojFiltersImpl.h"
#include "System/Helper/PragmaWarning.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"

using namespace std::literals;

const System::String AssistTools::GenerateTestingTemplateVcxprojFiltersImpl::extension{ SYSTEM_TEXT(".vcxproj.filters") };

AssistTools::GenerateTestingTemplateVcxprojFiltersImpl::GenerateTestingTemplateVcxprojFiltersImpl(const System::String& templateFileName, const System::String& projectName, const System::String& moduleName)
    : ParentType{ templateFileName, extension }, projectName{ projectName }, moduleName{ moduleName }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(AssistTools, GenerateTestingTemplateVcxprojFiltersImpl)

void AssistTools::GenerateTestingTemplateVcxprojFiltersImpl::GenerateTo(const System::String& resourceDirectory, const System::String& solutionName, const System::String& newModuleName) const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_1;

    VariableType newVariable{ { projectName, solutionName }, { moduleName, newModuleName } };

    return ParentType::Generate(resourceDirectory, solutionName + newModuleName + GetTesting(), newVariable);
}

/*
示例模板：
<?xml version="1.0" encoding="utf-8"?>
<Project ToolsVersion="4.0" xmlns="http://schemas.microsoft.com/developer/msbuild/2003">
  <ItemGroup>
    <Filter Include="源文件">
      <UniqueIdentifier>{4FC737F1-C7A5-4376-A066-2A32D752A2FF}</UniqueIdentifier>
      <Extensions>cpp;c;cc;cxx;def;odl;idl;hpj;bat;asm;asmx</Extensions>
    </Filter>
    <Filter Include="头文件">
      <UniqueIdentifier>{93995380-89BD-4b04-88EB-625FBE52EBFB}</UniqueIdentifier>
      <Extensions>h;hpp;hxx;hm;inl;inc;xsd</Extensions>
    </Filter>
    <Filter Include="资源文件">
      <UniqueIdentifier>{67DA6AB6-F800-4c08-8B7A-83BB121AAD01}</UniqueIdentifier>
      <Extensions>rc;ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe;resx;tiff;tif;png;wav;mfcribbon-ms</Extensions>
    </Filter>
    <Filter Include="配置">
      <UniqueIdentifier>{20621c5d-3c14-4e4e-80d1-8381d6b954a6}</UniqueIdentifier>
    </Filter>
    <Filter Include="Testing">
      <UniqueIdentifier>{14aff28c-7dbd-470a-ae32-d6e06e7c1c0a}</UniqueIdentifier>
    </Filter>
  </ItemGroup>
  <ItemGroup>
    <None Include="Configuration\EnvironmentVariable.json">
      <Filter>配置</Filter>
    </None>
    <None Include="Configuration\Log.json">
      <Filter>配置</Filter>
    </None>
    <None Include="Resource\Update.txt">
      <Filter>资源文件</Filter>
    </None>
    <None Include="Configuration\Testing.json">
      <Filter>配置</Filter>
    </None>
  </ItemGroup>
  <ItemGroup>
    <ClCompile Include="..\..\..\Code\%ProjectName%Testing\%ProjectName%%ModuleName%Testing\TestingHelper.cpp">
      <Filter>源文件</Filter>
    </ClCompile>
    <ClCompile Include="..\..\..\Code\%ProjectName%Testing\%ProjectName%%ModuleName%Testing\TestingLib.cpp">
      <Filter>源文件</Filter>
    </ClCompile>
    <ClCompile Include="..\..\..\Code\%ProjectName%Testing\%ProjectName%%ModuleName%Testing\TestingMain.cpp">
      <Filter>源文件</Filter>
    </ClCompile>
  </ItemGroup>
  <ItemGroup>
    <ClInclude Include="..\..\..\Code\%ProjectName%Testing\%ProjectName%%ModuleName%Testing\TestingHelper.h">
      <Filter>头文件</Filter>
    </ClInclude>
    <ClInclude Include="..\..\..\Code\%ProjectName%Testing\%ProjectName%%ModuleName%Testing\Testing.h">
      <Filter>头文件</Filter>
    </ClInclude>
  </ItemGroup>
</Project>
*/