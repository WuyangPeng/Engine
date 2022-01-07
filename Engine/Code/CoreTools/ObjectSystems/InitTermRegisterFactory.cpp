///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/24 23:08)

#include "CoreTools/CoreToolsExport.h"

#include "InitTermRegisterFactory.h"

CoreTools::InitTermRegisterFactory::InitTermRegisterFactory(Factory initializa, Factory terminate)
{
    InitTerm::AddInitializer(initializa);
    InitTerm::AddTerminator(terminate);
}
