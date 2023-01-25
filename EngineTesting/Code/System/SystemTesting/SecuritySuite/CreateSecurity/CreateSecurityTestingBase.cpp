///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.0 (2023/01/25 13:46)

#include "CreateSecurityTestingBase.h"
#include "System/Security/Flags/CreateSecurityFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::CreateSecurityTestingBase::CreateSecurityTestingBase(const OStreamShared& stream)
    : ParentType{ stream },
      securityRequestedInformations{ SecurityRequestedInformation::Owner,
                                     SecurityRequestedInformation::Group,
                                     SecurityRequestedInformation::Dacl,
                                     SecurityRequestedInformation::Label }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, CreateSecurityTestingBase)
