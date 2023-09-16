///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 11:03)

#include "SocketPrototypesTestingBase.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Helper/PragmaWarning/PropertyTree.h"
#include "System/Windows/Engineering.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <string>

System::SocketPrototypesTestingBase::SocketPrototypesTestingBase(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, SocketPrototypesTestingBase)

std::string System::SocketPrototypesTestingBase::GetConnectHostname() const
{
    SYSTEM_CLASS_IS_VALID_CONST_1;

    boost::property_tree::basic_ptree<std::string, std::string> mainTree{};

    read_json("Configuration/EnvironmentVariable.json", mainTree);

    return mainTree.get<std::string>("ConnectHostname");
}
