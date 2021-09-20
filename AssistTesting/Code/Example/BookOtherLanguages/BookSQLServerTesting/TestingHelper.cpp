// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨�����԰汾��0.0.0.1 (2019/09/29 21:49)

#include "TestingHelper.h"
#include "Testing.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

CMAIN_FUNCTION_HELPER_SUBCLASS_COMPLETE_DEFINE(BookSQLServer, TestingHelper, "�鼮 SQL Server")

void BookSQLServer::TestingHelper
	::AddSuites()
{
	AddBeginningMicrosoftSQLServer2008ProgrammingSuite();
	AddProfessionalMicrosoftSQLServer2008ProgrammingSuite();
	AddMicrosoftSQLServer2008AdministratorsPocketConsultantSuite();
}

void BookSQLServer::TestingHelper
	::AddBeginningMicrosoftSQLServer2008ProgrammingSuite()
{
	ADD_TEST_BEGIN(beginningMicrosoftSQLServer2008ProgrammingSuite, "SQL Server 2008 ������ž���");



	ADD_TEST_END(beginningMicrosoftSQLServer2008ProgrammingSuite);
}

void BookSQLServer::TestingHelper
	::AddProfessionalMicrosoftSQLServer2008ProgrammingSuite()
{
	ADD_TEST_BEGIN(professionalMicrosoftSQLServer2008ProgrammingSuite, "SQL Server 2008 �߼��������");



	ADD_TEST_END(professionalMicrosoftSQLServer2008ProgrammingSuite);
}

void BookSQLServer::TestingHelper
	::AddMicrosoftSQLServer2008AdministratorsPocketConsultantSuite()
{
	ADD_TEST_BEGIN(microsoftSQLServer2008AdministratorsPocketConsultantSuite, "SQL Server 2008 ����Ա�ر�ָ��");



	ADD_TEST_END(microsoftSQLServer2008AdministratorsPocketConsultantSuite);

}

