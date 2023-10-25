///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/20 15:44)

#include "CoreTools/CoreToolsExport.h"

#include "InitTermRegisterFactory.h"

CoreTools::InitTermRegisterFactory::InitTermRegisterFactory(Factory initializer, Factory terminate)
{
    InitTerm::AddInitializer(initializer);
    InitTerm::AddTerminator(terminate);
}
