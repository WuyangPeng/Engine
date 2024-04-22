/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/08 15:56)

#include "PragmaWarningTesting.h"
#include "System/Helper/Platform.h"
#include "System/Helper/PragmaWarning.h"
#include "System/Helper/PragmaWarning/ACE.h"
#include "System/Helper/PragmaWarning/ActiveMQ.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "System/Helper/PragmaWarning/Any.h"
#include "System/Helper/PragmaWarning/AsioConnect.h"
#include "System/Helper/PragmaWarning/AsioIpTcp.h"
#include "System/Helper/PragmaWarning/AsioPlaceholders.h"
#include "System/Helper/PragmaWarning/AsioPost.h"
#include "System/Helper/PragmaWarning/Bind.h"
#include "System/Helper/PragmaWarning/CallTraits.h"
#include "System/Helper/PragmaWarning/Chrono.h"
#include "System/Helper/PragmaWarning/EngineDisable.h"
#include "System/Helper/PragmaWarning/ExecutorWorkGuard.h"
#include "System/Helper/PragmaWarning/Format.h"
#include "System/Helper/PragmaWarning/Freeglut.h"
#include "System/Helper/PragmaWarning/Gregorian.h"
#include "System/Helper/PragmaWarning/Hiredis.h"
#include "System/Helper/PragmaWarning/IteratorFacade.h"
#include "System/Helper/PragmaWarning/LexicalCast.h"
#include "System/Helper/PragmaWarning/LimitTraits.h"
#include "System/Helper/PragmaWarning/ListInserter.h"
#include "System/Helper/PragmaWarning/MathConstants.h"
#include "System/Helper/PragmaWarning/Miniz.h"
#include "System/Helper/PragmaWarning/Mongocxx.h"
#include "System/Helper/PragmaWarning/MultiIndex.h"
#include "System/Helper/PragmaWarning/Mutex.h"
#include "System/Helper/PragmaWarning/Mysql.h"
#include "System/Helper/PragmaWarning/MysqlxXdevapi.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Helper/PragmaWarning/OpenXLSX.h"
#include "System/Helper/PragmaWarning/Operators.h"
#include "System/Helper/PragmaWarning/PolymorphicCast.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "System/Helper/PragmaWarning/PosixTime.h"
#include "System/Helper/PragmaWarning/PropertyTree.h"
#include "System/Helper/PragmaWarning/ProtoBuf.inl"
#include "System/Helper/PragmaWarning/PtrVector.h"
#include "System/Helper/PragmaWarning/PugiXml.h"
#include "System/Helper/PragmaWarning/RecursiveMutex.h"
#include "System/Helper/PragmaWarning/Spirit.h"
#include "System/Helper/PragmaWarning/Thread.h"
#include "System/Helper/PragmaWarning/Timer.h"
#include "System/Helper/PragmaWarning/TypeIndex.h"
#include "System/Helper/PragmaWarning/TypeTraits.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include SYSTEM_WARNING_PUSH

#include SYSTEM_WARNING_DISABLE(4100)
#include SYSTEM_WARNING_DISABLE(4101)
#include SYSTEM_WARNING_DISABLE(4200)
#include SYSTEM_WARNING_DISABLE(4239)
#include SYSTEM_WARNING_DISABLE(4244)
#include SYSTEM_WARNING_DISABLE(4456)
#include SYSTEM_WARNING_DISABLE(4458)
#include SYSTEM_WARNING_DISABLE(4459)
#include SYSTEM_WARNING_DISABLE(4505)
#include SYSTEM_WARNING_DISABLE(4996)

#include SYSTEM_WARNING_DISABLE(6001)
#include SYSTEM_WARNING_DISABLE(6054)
#include SYSTEM_WARNING_DISABLE(6201)
#include SYSTEM_WARNING_DISABLE(6246)
#include SYSTEM_WARNING_DISABLE(6255)
#include SYSTEM_WARNING_DISABLE(6258)
#include SYSTEM_WARNING_DISABLE(6262)
#include SYSTEM_WARNING_DISABLE(6285)
#include SYSTEM_WARNING_DISABLE(6294)
#include SYSTEM_WARNING_DISABLE(6313)
#include SYSTEM_WARNING_DISABLE(6320)
#include SYSTEM_WARNING_DISABLE(6326)
#include SYSTEM_WARNING_DISABLE(6330)
#include SYSTEM_WARNING_DISABLE(6340)
#include SYSTEM_WARNING_DISABLE(6385)
#include SYSTEM_WARNING_DISABLE(6386)
#include SYSTEM_WARNING_DISABLE(6387)
#include SYSTEM_WARNING_DISABLE(6388)

#include SYSTEM_WARNING_DISABLE(26051)
#include SYSTEM_WARNING_DISABLE(26052)

#include SYSTEM_WARNING_DISABLE(26110)
#include SYSTEM_WARNING_DISABLE(26135)

#include SYSTEM_WARNING_DISABLE(26400)
#include SYSTEM_WARNING_DISABLE(26401)
#include SYSTEM_WARNING_DISABLE(26402)
#include SYSTEM_WARNING_DISABLE(26403)
#include SYSTEM_WARNING_DISABLE(26408)
#include SYSTEM_WARNING_DISABLE(26409)

#include SYSTEM_WARNING_DISABLE(26414)
#include SYSTEM_WARNING_DISABLE(26415)
#include SYSTEM_WARNING_DISABLE(26416)
#include SYSTEM_WARNING_DISABLE(26418)

#include SYSTEM_WARNING_DISABLE(26426)
#include SYSTEM_WARNING_DISABLE(26429)

#include SYSTEM_WARNING_DISABLE(26430)
#include SYSTEM_WARNING_DISABLE(26432)
#include SYSTEM_WARNING_DISABLE(26433)
#include SYSTEM_WARNING_DISABLE(26434)
#include SYSTEM_WARNING_DISABLE(26435)
#include SYSTEM_WARNING_DISABLE(26436)
#include SYSTEM_WARNING_DISABLE(26437)
#include SYSTEM_WARNING_DISABLE(26438)
#include SYSTEM_WARNING_DISABLE(26439)

#include SYSTEM_WARNING_DISABLE(26440)
#include SYSTEM_WARNING_DISABLE(26443)
#include SYSTEM_WARNING_DISABLE(26444)
#include SYSTEM_WARNING_DISABLE(26445)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26447)

#include SYSTEM_WARNING_DISABLE(26451)
#include SYSTEM_WARNING_DISABLE(26455)
#include SYSTEM_WARNING_DISABLE(26456)
#include SYSTEM_WARNING_DISABLE(26457)
#include SYSTEM_WARNING_DISABLE(26459)

#include SYSTEM_WARNING_DISABLE(26460)
#include SYSTEM_WARNING_DISABLE(26461)
#include SYSTEM_WARNING_DISABLE(26462)
#include SYSTEM_WARNING_DISABLE(26465)
#include SYSTEM_WARNING_DISABLE(26466)
#include SYSTEM_WARNING_DISABLE(26467)

#include SYSTEM_WARNING_DISABLE(26471)
#include SYSTEM_WARNING_DISABLE(26472)
#include SYSTEM_WARNING_DISABLE(26473)
#include SYSTEM_WARNING_DISABLE(26474)
#include SYSTEM_WARNING_DISABLE(26475)
#include SYSTEM_WARNING_DISABLE(26476)
#include SYSTEM_WARNING_DISABLE(26477)

#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26482)
#include SYSTEM_WARNING_DISABLE(26485)
#include SYSTEM_WARNING_DISABLE(26486)
#include SYSTEM_WARNING_DISABLE(26487)
#include SYSTEM_WARNING_DISABLE(26488)
#include SYSTEM_WARNING_DISABLE(26489)

#include SYSTEM_WARNING_DISABLE(26490)
#include SYSTEM_WARNING_DISABLE(26491)
#include SYSTEM_WARNING_DISABLE(26492)
#include SYSTEM_WARNING_DISABLE(26493)
#include SYSTEM_WARNING_DISABLE(26494)
#include SYSTEM_WARNING_DISABLE(26495)
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26497)
#include SYSTEM_WARNING_DISABLE(26498)

#include SYSTEM_WARNING_DISABLE(26812)
#include SYSTEM_WARNING_DISABLE(26814)
#include SYSTEM_WARNING_DISABLE(26815)
#include SYSTEM_WARNING_DISABLE(26817)
#include SYSTEM_WARNING_DISABLE(26818)
#include SYSTEM_WARNING_DISABLE(26819)
#include SYSTEM_WARNING_DISABLE(26826)

#include SYSTEM_WARNING_DISABLE(28182)
#include SYSTEM_WARNING_DISABLE(28251)
#include SYSTEM_WARNING_DISABLE(28301)

System::PragmaWarningTesting::PragmaWarningTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, PragmaWarningTesting)

void System::PragmaWarningTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

SYSTEM_DEPRECATED("disable4996")
void Disable4996Test() noexcept
{
}

void System::PragmaWarningTesting::MainTest() noexcept
{
    Disable4996Test();
}

#include SYSTEM_WARNING_POP