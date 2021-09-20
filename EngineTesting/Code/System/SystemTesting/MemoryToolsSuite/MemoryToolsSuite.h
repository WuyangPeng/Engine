///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.2 (2021/04/20 11:05)

#ifndef SYSTEM_MEMORY_TOOLS_SUITE_H
#define SYSTEM_MEMORY_TOOLS_SUITE_H

#include "HeapTools/AllocateGenerateExceptionsTesting.h"
#include "HeapTools/AllocateHeapTesting.h"
#include "HeapTools/CompactHeapTesting.h"
#include "HeapTools/CreateHeapTesting.h"
#include "HeapTools/CurrentProcessHeapTesting.h"
#include "HeapTools/ReAllocateHeapTesting.h"
#include "HeapTools/ValidateHeapTesting.h"
#include "LocalTools/LocalMemoryAllocTesting.h"
#include "LocalTools/LocalMemorySizeTesting.h"
#include "MemoryHelper/FillMemoryTesting.h"
#include "MemoryHelper/GetWindowsStructDefaultSizeTesting.h"
#include "MemoryHelper/MallocMemoryTesting.h"
#include "MemoryHelper/MemoryCopyTesting.h"
#include "MemoryHelper/MemorySetTesting.h"
#include "ViewOfFile/CreateFileMappingTesting.h"
#include "ViewOfFile/OpenFileMappingTesting.h"
#include "ViewOfFile/ViewOfFileTesting.h"
#include "VirtualTools/AllocateVirtualOneStepTesting.h"
#include "VirtualTools/AllocateVirtualSeparationTesting.h"
#include "VirtualTools/VirtualProtectTesting.h"
#include "VirtualTools/VirtualQueryTesting.h"

#endif  // SYSTEM_MEMORY_TOOLS_SUITE_H