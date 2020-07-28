// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.2 (2020/01/22 17:41)

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
		// ���HTTP�汾Ϊ1.1����߰汾������֤�ɹ���
		void CheckHttpVersionsOK();

	private:
		InternetHandle m_UrlInternet;
	};
}

#endif // CORE_TOOLS_OPEN_URL_INTERNET_H
