#ifndef __ioLocalChina_h__
#define __ioLocalChina_h__

#include "ioLocalParent.h"

#define SVC_CODE "LSAGA"

class ioLocalChina  : public ioLocalParent
{
protected:
	char m_szRegKey[MAX_PATH];
	char m_szStartURL[MAX_PATH*2];

public:
	virtual ioLocalManager::LocalType GetType();
	virtual const char *GetTextListFileName();
	virtual const char *GetMemTextList();

	virtual bool GetNewCmdLine( IN const char *szCmd, OUT char *szNewCmd, IN int iNewCmdSize );
	virtual bool IsRightGameServerID( const CString &rszGameServerID );

	virtual const char *GetRegKey();

	virtual DWORD GetResourceIDBack();
	virtual DWORD GetResourceIDChange();
	virtual DWORD GetResourceIDSetup();

	virtual DWORD GetResourceIDErrorBack();
	virtual DWORD GetResourceIDErrorExit();
	virtual DWORD GetResourceIDErrorSolution();

	virtual const char *GetErrorSolutionURL();
	virtual void  SetRegKey( const char *szReg );
	virtual void  SetStartURL( const char *szURL );

	virtual bool  IsLoginDlg();
	virtual bool  IsReadRegClientPath();
	virtual bool GetLoginResultPostData( OUT char *szError, IN int iErrorSize, const char *szURL, const char *szID, const char *szPW );


	virtual const char *GetFontName();

public:
	ioLocalChina(void);
	virtual ~ioLocalChina(void);
};

#endif // __ioLocalChina_h__