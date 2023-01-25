///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.0 (2023/01/11 19:27)

#include "WindowsSockExTestingBase.h"
#include "System/Helper/PragmaWarning/PropertyTree.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"

System::WindowsSockExTestingBase::WindowsSockExTestingBase(const OStreamShared& tream)
    : ParentType{ tream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, WindowsSockExTestingBase)

System::String System::WindowsSockExTestingBase::GetConnectHostname() const
{
    SYSTEM_CLASS_IS_VALID_CONST_1;

    boost::property_tree::basic_ptree<String, String> mainTree{};

    read_json("Configuration/EnvironmentVariable.json", mainTree);

    return mainTree.get<String>(SYSTEM_TEXT("ConnectHostname"));
}
