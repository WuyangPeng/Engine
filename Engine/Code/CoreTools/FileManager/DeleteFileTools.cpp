//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.1 (2020/10/14 14:20)

#include "CoreTools/CoreToolsExport.h"

#include "DeleteFileTools.h"
#include "Detail/DeleteFileToolsImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::make_shared;

CoreTools::DeleteFileTools::DeleteFileTools(const String& fileName)
    : m_Impl{ make_shared<ImplType>(fileName) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(CoreTools, DeleteFileTools)
