// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ°æ±¾£º0.0.2.0 (2020/01/02 15:47)

#include "System/SystemExport.h"

#include "GetOpenGLFunction.h" 

std::string System
	::GetActualFunctionName(const char* functionName)
{
	if (functionName != nullptr)
	{
		const std::string actual{ functionName };
		if (1 < actual.size())
		{
			return std::string{ actual.begin() + 1,actual.end() };
		}
	}

	return "";
}
