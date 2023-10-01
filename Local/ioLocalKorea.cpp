#include "../stdafx.h"
#include ".\iolocalkorea.h"
#include "../resource.h"
#include "../util/HttpManager.h"
#include "../MainFrm.h"
#include <strsafe.h>
#include "../StringManager/Safesprintf.h"
//#include "stringmanager\iostringmanager.h"
#include "../StringManager\ioStringManager.h"

#include "../curl/curl.h"
#include "../cJson/cJSON.h"
#include "../Util/ioEncrypted.h"
#include <Windows.h>
#include <string>


ioLocalKorea::ioLocalKorea(void)
{

}

ioLocalKorea::~ioLocalKorea(void)
{
}

ioLocalManager::LocalType ioLocalKorea::GetType()
{
	return ioLocalManager::LCT_KOREA;
}

const char * ioLocalKorea::GetTextListFileName()
{
	return "text.txt";
}

const char * ioLocalKorea::GetMemTextList()
{
	return "|EXE_CMainFrame::OnCreate_1|\r\n\r\n�ν�Ʈ�簡�� �̹� ���� �� �Դϴ�.\r\n\r\n     ��ø� ��ٷ� �ּ���.\r\n\r\n\r\n\r\n  ��ð� ������ �������������\r\n\r\n   �������� �ٽ� ������ �ּ���.|"
		   "|EXE_CMainFrame::OnCreate_2|�ν�Ʈ�簡 ������Ʈ ���Դϴ�. ��ø� ��ٷ� �ּ���.|"
		   "|EXE_CMainFrame::ParseCmdAndStart_1|���ڰ��� �߸��Ǿ����ϴ�.\r\n����� �ٽ� �̿��� �ּ���.(%1)\r\n(������ȣ:104)|"
		   "|EXE_CMainFrame::ParseCmdAndStart_2|���۵����Ͱ��� �߸��Ǿ����ϴ�.\r\n����� �ٽ� �̿��� �ּ���.(%1/%2)\r\n(������ȣ:106)|"
		   "|EXE_CMainFrame::SetupAndStart_1|���Ӱ� ������ �������� �߸��Ǿ����ϴ�.\r\n����� �ٽ� �̿��� �ּ���.(%1)\r\n(������ȣ:105)|"
		   "|EXE_CSetupAndStart::SetupAndStartGame_1|���ڰ��� ����Ǿ����ϴ�.\r\n����� �ٽ� �̿��� �ּ���.(%1)\r\n(������ȣ:101)|"
		   "|EXE_CSetupAndStart::SetupAndStartGame_2|�ڵ�������Ʈ ��ġ�� �����Ͽ����ϴ�.\r\n����� �ٽ� �̿��� �ּ���.(%1:%2)\r\n(������ȣ:102)|"
		   "|EXE_CSetupAndStart::SetupAndStartGame_3|��ġ�������� ��ġ�� �����Ͽ����ϴ�.\r\n����� �ٽ� �̿��� �ּ���.(%1:%2)\r\n(������ȣ:103)|"
		   "|EXE_CSetupAndStart::SetupAndStartGame_4|�������� ������ ���ų� ������ ȥ���մϴ�.\r\n����� �ٽ� �̿��� �ּ���.(%1)\r\n(������ȣ:107)|"
		   "|EXE_ioErrorDlg::ShowErrorDlg_2|--- �ý��� ��� ---\r\n%1\r\n\r\n--- ���� ���� ---\r\n%2|"
		   "|EXE_SetupFolderDlg::OnBnClickedChangeFolder_1|�ν�Ʈ�簡�� ��ġ�� ������ ������ �ּ���.|"
		   "|EXE_SetupFolderDlg::OnBnClickedChangeFolder_2|��ġ ��θ��� ��� �ֽ��ϴ�.\r\n\r\n     �ٽ� ������ �ּ���.|"
		   "|EXE_SetupFolderDlg::OnBnClickedChangeFolder_3|��ġ ��δ� 100�ڸ� ���� �� �����ϴ�.\r\n\r\n              �ٽ� ������ �ּ���.|"
		   "|EXE_SetupFolderDlg::OnBnClickedChangeFolder_4|������ ���� �� ���� ����Դϴ�.\r\n\r\n       �ٽ� ������ �ּ���.|"
		   "|EXE_SetupFolderDlg::OnBnClickedSetup_1|�ν�Ʈ�簡 ��ġ �غ����Դϴ�. ��ø� ��ٷ��ּ���.|"
		   "|EXE_ioLocalKorea::GetLoginResultPostData_1|�α��� ���� ������ �Դϴ�(-1).|"
		   "|EXE_ioLocalKorea::GetLoginResultPostData_2|���̵� �Ǵ� �н����� ���� ���� �߽��ϴ�(-2).|"
		   "|EXE_ioLocalKorea::GetLoginResultPostData_3|���̵� �Ǵ� �н����尡 Ʋ���ϴ�(-3).|"
		   "|EXE_ioLocalKorea::GetLoginResultPostData_4|ä�θ� ȸ��(-4).|"
		   "|EXE_ioLocalKorea::GetLoginResultPostData_5|�������� ���� ���� �ʿ��մϴ�(-5).|"
		   "|EXE_ioLocalKorea::GetLoginResultPostData_6|�˴ٿ��� ��� ����(0�� ~ 6��) �Դϴ�(-6).|"
		   "|EXE_ioLocalKorea::GetLoginResultPostData_7|������ �˴ٿ��� ��� �����Դϴ�(-7).|"
		   "|EXE_ioLocalKorea::GetLoginResultPostData_8|���� ���� �� �Դϴ�(-8).|"
		   "|EXE_ioLocalKorea::GetLoginResultPostData_9|���� ���·� ���� ���� �Ұ� �Դϴ�(-9).|"
		   "|EXE_ioLocalKorea::GetLoginResultPostData_10|�������� ���Ӽ��� �����ϴ�(-10).|"
		   "|EXE_ioLocalKorea::GetLoginResultPostData_11|Ǯ ���� ���·� ���� ���� �Ұ�(-11).|"
		   "|EXE_ioLocalKorea::GetLoginResultPostData_12|���� ����(-12)|"
		   "|EXE_ioLocalKorea::GetLoginResultPostData_13|���� ����(-13)|"
		   "|EXE_ioLocalKorea::GetLoginResultPostData_14|�α��� ���̺� ���� ���� �����ϴ�(-14).|"
		   "|EXE_ioLocalKorea::GetLoginResultPostData_15|���� ���� ���� zone Ÿ�� �Դϴ�(-15).|"
		   "|EXE_ioLocalKorea::GetLoginResultPostData_16|���̵� Ȥ�� ��й�ȣ�� ��ϴ� �ٽ� �Է����ּ���.|";
}

bool ioLocalKorea::GetNewCmdLine( IN const char *szCmd, OUT char *szNewCmd, IN int iNewCmdSize )
{
	StringCbCopy( szNewCmd, iNewCmdSize, szCmd );
	return true;
}

bool ioLocalKorea::IsRightGameServerID( const CString &rszGameServerID )
{
	return true;
}

const char * ioLocalKorea::GetRegKey()
{
	return "Software\\SP2Client\\";
}

DWORD ioLocalKorea::GetResourceIDBack()
{
	return IDB_BACK;
}

DWORD ioLocalKorea::GetResourceIDChange()
{
	return IDB_CHANGEBTN;
}

DWORD ioLocalKorea::GetResourceIDSetup()
{
	return IDB_SETUPBTN;
}

DWORD ioLocalKorea::GetResourceIDErrorBack()
{
	return IDB_ERROR_BACK;
}

DWORD ioLocalKorea::GetResourceIDErrorExit()
{
	return IDB_EXITBTN;
}

DWORD ioLocalKorea::GetResourceIDErrorSolution()
{
	return IDB_SOLUTIONBTN;
}

const char * ioLocalKorea::GetErrorSolutionURL()
{
	return "http://www.lostsaga.com/common/rgfaq.asp?errnumber=%d";
}

void ioLocalKorea::SetRegKey( const char *szReg )
{
	// ��
}

void ioLocalKorea::SetStartURL( const char *szURL )
{
	// ��
}

bool ioLocalKorea::IsLoginDlg()
{
#ifdef SRC_KOR
	return true;
#endif
	return false;
}

#ifdef USE_NEW_LOGIN
static size_t WriteCallback(void* buffer, size_t size, size_t nmemb, void* param)
{
	std::string& text = *static_cast<std::string*>(param);
	size_t totalsize = size * nmemb;
	text.append(static_cast<char*>(buffer), totalsize);
	return totalsize;
}

void GetLocalIP(OUT char* szLocalIP, IN int iSize)
{
	char szHost[MAX_PATH] = "";
	gethostname(szHost, MAX_PATH);

	HOSTENT* pHost = gethostbyname(szHost);
	if (!pHost)
	{
		StringCbPrintf(szLocalIP, iSize, "%d.%d.%d.%d", 127, 0, 0, 1);
	}
	else
	{
		StringCbPrintf(szLocalIP, iSize, "%d.%d.%d.%d", (BYTE)pHost->h_addr_list[0][0],
			(BYTE)pHost->h_addr_list[0][1],
			(BYTE)pHost->h_addr_list[0][2],
			(BYTE)pHost->h_addr_list[0][3]);
	}
}



bool ioLocalKorea::GetLoginResultPostData(OUT char* szError, IN int iErrorSize, const char* szURL, const char* szID, const char* szPW) {

	bool bResult = false;

	char postData[MAX_PATH] = { 0, };
	std::string result;
	CURL* curl;
	CURLcode res;
	curl_global_init(CURL_GLOBAL_DEFAULT);
	curl = curl_easy_init();
	if (curl) {
		curl_easy_setopt(curl, CURLOPT_URL, szURL);
		curl_easy_setopt(curl, CURLOPT_POST, 1L);
		
		
		std::string mainkey = "losaapi";//base key
		std::string apikey = "";//secret key
		std::string bearerToken = "Authorization: Bearer " + mainkey + apikey;

		struct curl_slist* headers = NULL;
		headers = curl_slist_append(headers, bearerToken.c_str());
		curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

		strcpy(postData, "username=");
		strcat(postData, szID);
		strcat(postData, "&");
		strcat(postData, "password=");
		strcat(postData, szPW);
	

		long httpCode(0);
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postData);
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &result);
		curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
		res = curl_easy_perform(curl);
		curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &httpCode);
		curl_easy_cleanup(curl);

		if (CURLE_OK != res) {
			SafeSprintf(szError, sizeof(char) * MAX_PATH, "CURL error");
			bResult = false;
		}else if (httpCode == 200) {
			cJSON* json_object = cJSON_Parse(result.c_str());

			cJSON* AppName = cJSON_GetObjectItem(json_object, "AppName");
			cJSON* name = cJSON_GetObjectItem(json_object, "userID");
			cJSON* encodeKey = cJSON_GetObjectItem(json_object, "encodeKey");
			cJSON* serverID = cJSON_GetObjectItem(json_object, "serverID");
			cJSON* clientIP = cJSON_GetObjectItem(json_object, "clientIP");
			cJSON* message = cJSON_GetObjectItem(json_object, "message");

			char encode[256];
			char encid[256];
			char encodeip[256];
			char encip[256];
			char loginKey[MAX_PATH] = { 0 };
			char szLocalIP[MAX_PATH] = "";

			GetLocalIP(szLocalIP, sizeof(szLocalIP));

			
			ioEncrypted::Encode15("111111111111111", "111111111111111", encode);
			ioEncrypted::Encode15(name->valuestring, encodeKey->valuestring, encid);
			ioEncrypted::Encode15(clientIP->valuestring, szLocalIP, encodeip);
			ioEncrypted::Encode15(szLocalIP, encodeKey->valuestring, encip);

			
			sprintf_s(szError, sizeof(loginKey),
				"%s  EDEW3940FVDP4950,10,20,30,1,autoupgrade_info.ini,1000,0,1,0,?%s%s?0?%s%s?%s?2010,7,15,1?10201?", AppName->valuestring,
				encode, encid, encodeip, encip, serverID->valuestring); //don't remove all space
		

			bResult = true;
		}
		else {
			cJSON* json_object = cJSON_Parse(result.c_str());
	
			cJSON* message = cJSON_GetObjectItem(json_object, "message");
			SafeSprintf(szError, sizeof(char) * MAX_PATH, message->valuestring);
			bResult = false;
		}
		
	}
	curl_global_cleanup();

	return bResult;
}
#else

bool ioLocalKorea::GetLoginResultPostData(OUT char* szError, IN int iErrorSize, const char* szURL, const char* szID, const char* szPW)
{
	bool bResult = false;

	// ��
	char szData[MAX_PATH] = { 0, };
	char szReturn[2048] = { 0, };
	char szTemp[2048] = { 0, };

	strcpy(szData, "userID=");
	strcat(szData, szID);
	strcat(szData, "&");
	strcat(szData, "userPWD=");
	strcat(szData, szPW);

	if (g_HttpMgr.GetResultPostData(szURL, szData, szReturn, 1024, true))
	{
		char pos[2048] = { 0, };
		memcpy(pos, szReturn, sizeof(szReturn));
		//�α��� �α� ���� ��ũ��Ʈ ����
		strtok(pos, "?");
		int iSize = strlen(pos) - 1;
		int nResult = atoi(pos + iSize);
		if (nResult == 0)
		{
			SafeSprintf(szError, sizeof(char) * MAX_PATH, STR(16));
			bResult = false;
		}
		else if (nResult == 1)
		{
			strcpy_s(szError, sizeof(szReturn), szReturn + 2 + iSize);
			bResult = true;
		}
		else if (nResult < 16)
		{
			int index = abs(nResult);
			SafeSprintf(szError, sizeof(char) * MAX_PATH, STR(index));
			bResult = false;
		}
	}

	return bResult;
}
#endif

const char * ioLocalKorea::GetFontName()
{
	return "����";
}



