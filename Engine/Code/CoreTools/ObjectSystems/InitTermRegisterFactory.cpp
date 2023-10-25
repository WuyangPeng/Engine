///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/09/20 15:44)

#include "CoreTools/CoreToolsExport.h"

#include "InitTermRegisterFactory.h"

CoreTools::InitTermRegisterFactory::InitTermRegisterFactory(Factory initializer, Factory terminate)
{
    InitTerm::AddInitializer(initializer);
    InitTerm::AddTerminator(terminate);
}
