// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.2 (2020/01/22 17:48)

#include "CoreTools/CoreToolsExport.h"

#include "DownloadingFilesImpl.h"  
#include "InternetConnection.h"
#include "OpenUrlInternet.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "System/Network/WindowsInternet.h"
#include "System/Network/Flags/WindowsInternetFlags.h"
#include "CoreTools/FileManager/OFStreamManager.h" 
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/CharacterString/CaseInsensitiveStringDetail.h"
#include "CoreTools/MemoryTools/SubclassSmartPointerDetail.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"  

#include <vector>
#include <array>

using std::array;
using std::vector;
using std::string;

CoreTools::DownloadingFilesImpl
	::DownloadingFilesImpl(const System::String& url, bool restart, const DownloadingFilesEventSharedPointer& downloadingFilesEvent)
	:m_Url{ url }, m_Restart{ restart }, m_DownloadingFilesEvent{ downloadingFilesEvent }
{
	Download();

	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, DownloadingFilesImpl)

// private
void CoreTools::DownloadingFilesImpl
	::Download()
{
	// �����ļ� 
	// Ҫ���¼����ļ����봫�ݸ����¼��ء�

	// Ҫָ���ڶ�ȡÿ��������֮����õĸ��º�����ָ��downloadingFilesEvent��
	// �������Ҫ���¹��ܣ���ô�õ���������Ĭ��ΪDownloadingFilesEventSmartPointer()��

	CheckUrl();
	CheckInternetAttemptConnect();

	InternetConnection internetConnection{ SYSTEM_TEXT("downloader") };

	System::String fileName = GetFileName();
	OFStreamManager manager{ fileName, !m_Restart };
	manager.SetSimplifiedChinese();
	auto fileLength = static_cast<uint32_t>(manager.GetOFStreamSize());

	System::String header{ SYSTEM_TEXT("Range:bytes=") + System::ToString(fileLength) + SYSTEM_TEXT("-") };

	OpenUrlInternet openUrlInternet{ internetConnection.GetInternet(), m_Url, header };

	System::WindowDWord contentLength{ 79 };
	System::WindowDWord length{ sizeof(contentLength) };
	auto infoLevel = System::QueryInfo::Number | System::QueryInfo::ContentLength;

	if (!System::GetHttpQueryInfo(openUrlInternet.GetInternet(), infoLevel, &contentLength, &length, nullptr))
	{
		THROW_EXCEPTION(SYSTEM_TEXT("δ�ҵ��ļ������ݳ��ȡ�"));
	}

	// ��������ļ�������У�δ��ɣ���������ء�	

	constexpr int bufferSize{ 256 };
	array<char, bufferSize> buffer{ };

	if (fileLength != contentLength && 0 < contentLength)
	{
		int total{ 0 };
		System::WindowDWord numberOfBytesRead{ 0 };

		do
		{
			if (!System::ReadFileInternet(openUrlInternet.GetInternet(), buffer.data(), bufferSize, &numberOfBytesRead))
			{
				THROW_EXCEPTION(SYSTEM_TEXT("����ʱ��������"));
			}

			string writeToDisk{ buffer.data() };
			manager << StringConversion::MultiByteConversionStandard(writeToDisk);

			total += numberOfBytesRead;

			auto downloadingFilesEvent = m_DownloadingFilesEvent.lock();

			if (downloadingFilesEvent && 0 < numberOfBytesRead)
			{
				downloadingFilesEvent->Update(fileName, contentLength, total + fileLength);
			}

		} while (0 < numberOfBytesRead);
	}
	else
	{
		auto downloadingFilesEvent = m_DownloadingFilesEvent.lock();

		if (downloadingFilesEvent)
		{
			downloadingFilesEvent->Update(fileName, fileLength, fileLength);
		}
	}
}

void CoreTools::DownloadingFilesImpl
	::CheckUrl()
{
	CaseInsensitiveTString caseInsensitiveTString{ m_Url.c_str() };

	if (caseInsensitiveTString.find(SYSTEM_TEXT("http")) != 0)
	{
		THROW_EXCEPTION(SYSTEM_TEXT("������ HTTP url"));
	}
}

void CoreTools::DownloadingFilesImpl
	::CheckInternetAttemptConnect()
{
	// �鿴�Ƿ���Internet���ӿ��á�
	if (!System::IsInternetAttemptConnect())
	{
		THROW_EXCEPTION(SYSTEM_TEXT("�޷����ӡ�"));
	}
}

System::String CoreTools::DownloadingFilesImpl
	::GetFileName() const
{
	vector<System::String> fileName;

	split(fileName, m_Url, boost::is_any_of(SYSTEM_TEXT("/")), boost::token_compress_on);

	if (fileName.empty())
	{
		return SYSTEM_TEXT("error");
	}
	else
	{
		return fileName[fileName.size() - 1];
	}
}
