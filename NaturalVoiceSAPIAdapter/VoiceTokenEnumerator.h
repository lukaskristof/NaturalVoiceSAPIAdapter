﻿// VoiceTokenEnumerator.h: CVoiceTokenEnumerator 的声明

#pragma once
#include "resource.h"       // 主符号

#include "pch.h"
#include <optional>
#include "VoiceToken.h"
#include "TokenEnumerator.h"

#include "NaturalVoiceSAPIAdapter_i.h"


using namespace ATL;

// CVoiceTokenEnumerator

class ATL_NO_VTABLE CVoiceTokenEnumerator :
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CVoiceTokenEnumerator, &CLSID_VoiceTokenEnumerator>,
	public TokenEnumerator
{
public:
	CVoiceTokenEnumerator()
	{
	}

DECLARE_GET_CONTROLLING_UNKNOWN()
DECLARE_REGISTRY_RESOURCEID(107)

DECLARE_NOT_AGGREGATABLE(CVoiceTokenEnumerator)

BEGIN_COM_MAP(CVoiceTokenEnumerator)
	COM_INTERFACE_ENTRY(IEnumSpObjectTokens)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct() noexcept;

	void FinalRelease()
	{
	}


private:
	typedef std::map<std::string, std::shared_ptr<DataKeyData>> TokenMap;
	static void EnumLocalVoices(TokenMap& tokens, ErrorMode errorMode);
	static void EnumLocalVoicesInFolder(TokenMap& tokens, LPCWSTR basepath, ErrorMode errorMode);
	static void EnumEdgeVoices(TokenMap& tokens, DWORD langFlags, const std::vector<std::wstring>& languages,
		ErrorMode errorMode);
	static void EnumAzureVoices(TokenMap& tokens, DWORD langFlags, const std::vector<std::wstring>& languages,
		const std::wstring& key, const std::wstring& region, ErrorMode errorMode);
};

OBJECT_ENTRY_AUTO(__uuidof(VoiceTokenEnumerator), CVoiceTokenEnumerator)
