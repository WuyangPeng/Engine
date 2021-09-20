// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/05 15:30)

#ifndef CORE_TOOLS_TESTING_STREAM_MANAGER_TESTING_H
#define CORE_TOOLS_TESTING_STREAM_MANAGER_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
	class StreamManagerTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(StreamManagerTesting);

	private:
		void MainTest();

		void IFStreamManageTest();
		void OFStreamManageTest();

		// IFStreamManage≤‚ ‘
		void IFStreamManageSucceedTest();
		void IFStreamManageBackupFileTest();
		void IFStreamManageDeleteBackupFileTest();

		// OFStreamManage≤‚ ‘
		void OFStreamManageMessageTest();
		void OFStreamManageSizeTest();

		void DoRunUnitTest() override;

	private:
		static const System::String sm_IFStreamFileName;
		static const System::String sm_IFStreamFileContent;
		static const System::String sm_OFStreamFileName;
		static const System::String sm_OFStreamFileContent;

		System::String m_BackupFile;
	};
}

#endif // CORE_TOOLS_TESTING_STREAM_MANAGER_TESTING_H
