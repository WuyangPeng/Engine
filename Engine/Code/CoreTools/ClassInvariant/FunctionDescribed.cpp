// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ°æ±¾£º0.0.2.1 (2020/01/18 18:07)

#include "CoreTools/CoreToolsExport.h"

#include "FunctionDescribed.h"

CoreTools::FunctionDescribed
	::FunctionDescribed(const char* currentFunction, const char* fileName, int line) noexcept
	:m_CurrentFunction{ currentFunction }, m_FileName{ fileName }, m_Line{ line }
{
}

const char* CoreTools::FunctionDescribed
	::GetCurrentFunction() const noexcept
{
	return m_CurrentFunction;
}

const char* CoreTools::FunctionDescribed
	::GetFileName() const noexcept
{
	return m_FileName;
}

int CoreTools::FunctionDescribed
	::GetLine() const noexcept
{
	return m_Line;
}

