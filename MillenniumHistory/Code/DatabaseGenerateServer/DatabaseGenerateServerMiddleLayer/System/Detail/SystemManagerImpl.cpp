///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	ǧ��ʷ�߰汾��0.9.0.11 (2023/06/06 22:13)

#include "DatabaseGenerateServer/DatabaseGenerateServerMiddleLayer/DatabaseGenerateServerMiddleLayerExport.h"

#include "DatabaseGenerateServer/DatabaseGenerateServerMiddleLayer/Helper/DatabaseGenerateServerMiddleLayerClassInvariantMacro.h"
#include "SystemManagerImpl.h"

DatabaseGenerateServerMiddleLayer::SystemManagerImpl::SystemManagerImpl(const System::String& directory)
    : ancientBooksContainer{ directory }
{
    DATABASE_GENERATE_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

CLASS_INVARIANT_STUB_DEFINE(DatabaseGenerateServerMiddleLayer, SystemManagerImpl)