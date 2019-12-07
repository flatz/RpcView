#include "internalRpcUtils.h"
#include <codecvt>
#include <list>
#include <locale>
#include <sstream>


//--------------------------------------------------------------------------
BOOL __fastcall isStandardCharacter(_In_ const WCHAR wc)
{
	BOOL	bResult	= FALSE;

	if( ((wc >= L'a') && 
		(wc <= L'z'))

		||

		((wc >= L'A') &&
		(wc <= L'Z'))

		||

		((wc >= L'0') &&
		(wc <= L'9')) )
	{
		bResult = TRUE;
	}

	return (bResult);
}


//-------------------------------------------------------------------------
std::string narrow(
	_In_	const std::wstring& ws)
{
	std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
	return std::string(converter.to_bytes(ws));
}


//-------------------------------------------------------------------------
VOID displayPtrLevel(
	_In_	const UINT uPtrLevel, 
	_Inout_	std::ostringstream& oss)
{
	for(UINT i=0; i<uPtrLevel; i++)
	{
		oss<<"*";
	}
}


//----------------------------------------------------------------------------
VOID displayErrorMessage(
	_Inout_ std::ostringstream& oss, 
	_In_	PCHAR message)
{
	oss<< "/* [ERROR] : "<< message << "*/";
}

