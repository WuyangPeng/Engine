//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.1 (2020/10/14 10:10)

#include "CoreTools/CoreToolsExport.h"

#include "CommonCopyFileTools.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::CommonCopyFileTools::CommonCopyFileTools(const String& inFileName, const String& outFileName)
    : ParentType{}, m_InFile{ inFileName }, m_OutFile{ outFileName }, m_Buffer(m_InFile.GetFileByteSize())
{
    m_InFile.Read(m_Buffer.size(), m_Buffer.data());
    m_OutFile.Write(m_Buffer.size(), m_Buffer.data());

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CommonCopyFileTools)
