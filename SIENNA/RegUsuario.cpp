// RegUsuario.cpp: archivo de implementaci�n
//

#include "stdafx.h"
#include "SIENNA.h"
#include "RegUsuario.h"
#include "afxdialogex.h"


// Cuadro de di�logo de CRegUsuario

IMPLEMENT_DYNAMIC(CRegUsuario, CDialog)

CRegUsuario::CRegUsuario(CWnd* pParent /*=NULL*/)
	: CDialog(CRegUsuario::IDD, pParent)
{

}

CRegUsuario::~CRegUsuario()
{
}

void CRegUsuario::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CRegUsuario, CDialog)
END_MESSAGE_MAP()


// Controladores de mensajes de CRegUsuario
