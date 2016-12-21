// Copyright 2001-2016 Crytek GmbH / Crytek Group. All rights reserved.

#pragma once

#include <CryCore/StaticInstanceList.h>

#include "Schematyc/Utils/EnumFlags.h"
#include "Schematyc/Utils/PreprocessorUtils.h"
#include "Schematyc/Utils/TypeUtils.h"

#define SCHEMATYC_REGISTER_UNIT_TEST(function, name) static Schematyc::CUnitTestRegistrar SCHEMATYC_PP_JOIN_XY(schematycUnitTestRegistrar, __COUNTER__)(function, name);

namespace Schematyc
{
enum class EUnitTestResultFlags
{
	Success       = 0,
	CriticalError = BIT(0),
	FatalError    = BIT(1)
};

typedef CEnumFlags<EUnitTestResultFlags> UnitTestResultFlags;

typedef UnitTestResultFlags (*           UnitTestFunctionPtr)();

class CUnitTestRegistrar : public CStaticInstanceList<CUnitTestRegistrar>
{
public:

	CUnitTestRegistrar(UnitTestFunctionPtr pFuntion, const char* szName);

	static void RunUnitTests();

private:

	UnitTestFunctionPtr m_pFuntion;
	const char*         m_szName;
};
}
