// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.2 (2020/01/22 17:41)

#ifndef CORE_TOOLS_OPEN_URL_INTERNET_H
#define CORE_TOOLS_OPEN_URL_INTERNET_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "System/Network/Using/WindowsInternetUsing.h"

#include <boost/noncopyable.hpp>
#include <string>

namespace CoreTools
{
	class CORE_TOOLS_HIDDEN_DECLARE OpenUrlInternet : private boost::noncopyable
	{
	public:
		using ClassType = OpenUrlInternet;
		using InternetHandle = System::InternetHandle;

	public:
		explicit OpenUrlInternet(InternetHandle internet, const System::String& url, const System::String& header);
		~OpenUrlInternet();
		OpenUrlInternet(const OpenUrlInternet&) noexcept = delete;
		OpenUrlInternet& operator=(const OpenUrlInternet&) noexcept = delete;
		OpenUrlInternet(OpenUrlInternet&&) noexcept = delete;
		OpenUrlInternet& operator=(OpenUrlInternet&&) noexcept = delete;

		CLASS_INVARIANT_DECLARE;

		InternetHandle GetInternet() const noexcept;

	private:
		// 如果HTTP版本为1.1或更高版本，则验证成功。
		void CheckHttpVersionsOK();

	private:
		InternetHandle m_UrlInternet;
	};
}

#endif // CORE_TOOLS_OPEN_URL_INTERNET_H
