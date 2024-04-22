/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/11 22:21)

#include "CoreTools/CoreToolsExport.h"

#include "InitTermRegisterFactory.h"

CoreTools::InitTermRegisterFactory::InitTermRegisterFactory(Factory initializer, Factory terminate)
{
    InitTerm::AddInitializer(initializer);
    InitTerm::AddTerminator(terminate);
}
