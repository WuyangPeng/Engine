// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ°æ±¾£º0.0.2.1 (2020/01/19 10:42)

#include "CoreTools/CoreToolsExport.h"

#include "CaseInsensitiveString.h" 
#include "StringConversion.h"

#include <iostream>

using std::ostream;
using std::string;
using std::wstring;

std::ostream& CoreTools
	::operator<<(std::ostream& os, const CaseInsensitiveString& str)
{
	return os << string{ str.c_str(), str.size() };
}

std::ostream& CoreTools
	::operator<<(std::ostream& os, const CaseInsensitiveWString& str)
{
	return os << StringConversion::WideCharConversionMultiByte(wstring{ str.c_str(), str.size() });
}
