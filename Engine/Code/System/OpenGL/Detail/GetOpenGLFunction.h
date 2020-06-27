// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.2.0.0 (2020/05/07 23:43)

#ifndef SYSTEM_OPENGL_GET_OPENGL_FUNCTION_H
#define SYSTEM_OPENGL_GET_OPENGL_FUNCTION_H

#include "System/Helper/ConfigMacro.h"
#include "System/Helper/Noexcept.h"

#include <string>
#include <cassert>

extern "C"
{
	void* GetOpenGLFunctionPointer(const char* glFunction) noexcept;
}

namespace System
{
	std::string GetActualFunctionName(const char* functionName);

	template<typename Function>
	void ActualGetFunction(const char* functionName, Function& function)
	{
		const auto actual = GetActualFunctionName(functionName);

		function = static_cast<Function>(GetOpenGLFunctionPointer(actual.c_str()));

		assert(function);
	}

	template<typename Function>
	void GetFunction(const char* functionName, Function& function) noexcept
	{
		using ActualFunction = void(*)(const char* functionName, Function& function);

		NoexceptNoReturn<const char*, Function&, ActualFunction>(ActualGetFunction<Function>, functionName, function);
	}

	template<typename Function>
	void ActualGetFunctionSuffix(const char* functionName, Function& functionSuffix, Function& function, bool allowOverride)
	{
		const auto actual = GetActualFunctionName(functionName);
		functionSuffix = static_cast<Function>(GetOpenGLFunctionPointer(actual.c_str()));

		assert(functionSuffix);

		if (allowOverride && function == nullptr)
		{
			function = functionSuffix;
		}
	}

	template<typename Function>
	void GetFunctionSuffix(const char* functionName, Function& functionSuffix, Function& function, bool allowOverride) noexcept
	{
		using ActualFunction = void(*)(const char* functionName, Function& functionSuffix, Function& function, bool allowOverride);

		NoexceptNoReturn<const char*, Function&, Function&, bool, ActualFunction>(ActualGetFunctionSuffix<Function>, functionName, functionSuffix, function, allowOverride);
	}
}

#endif // SYSTEM_OPENGL_GET_OPENGL_FUNCTION_H
