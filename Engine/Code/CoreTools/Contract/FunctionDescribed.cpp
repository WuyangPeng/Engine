//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.1 (2020/10/10 15:14)

#include "CoreTools/CoreToolsExport.h"

#include "FunctionDescribed.h"

CoreTools::FunctionDescribed::FunctionDescribed(const char* currentFunction, const char* fileName, int line) noexcept
    : m_CurrentFunction{ currentFunction }, m_FileName{ fileName }, m_Line{ line }
{
}

const char* CoreTools::FunctionDescribed::GetCurrentFunction() const noexcept
{
    return m_CurrentFunction;
}

const char* CoreTools::FunctionDescribed::GetFileName() const noexcept
{
    return m_FileName;
}

int CoreTools::FunctionDescribed::GetLine() const noexcept
{
    return m_Line;
}
