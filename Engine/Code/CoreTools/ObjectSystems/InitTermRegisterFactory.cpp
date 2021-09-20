//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.7.1.1 (2020/10/22 15:09)

#include "CoreTools/CoreToolsExport.h"

#include "InitTermRegisterFactory.h"

CoreTools::InitTermRegisterFactory::InitTermRegisterFactory(Factory initializa, Factory terminate)
{
    InitTerm::AddInitializer(initializa);
    InitTerm::AddTerminator(terminate);
}
