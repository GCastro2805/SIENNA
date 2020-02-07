// Registro.cpp: archivo de implementación
//

#include "stdafx.h"
#include "SIENNA.h"
#include "Registro.h"
#include "afxdialogex.h"


// Cuadro de diálogo de CRegistro

IMPLEMENT_DYNAMIC(CRegistro, CDialog)

CRegistro::CRegistro(CWnd* pParent /*=NULL*/)
	: CDialog(CRegistro::IDD, pParent)
{

}

CRegistro::~CRegistro()
{
}

void CRegistro::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CRegistro, CDialog)
END_MESSAGE_MAP()


// Controladores de mensajes de CRegistro
