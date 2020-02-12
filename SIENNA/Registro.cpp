// Registro.cpp: archivo de implementación
//

#include "stdafx.h"
#include "SIENNA.h"
#include "Registro.h"
#include "afxdialogex.h"

#include "lmaxw2013.hpp"


// Cuadro de diálogo de CRegistro

IMPLEMENT_DYNAMIC(CRegistro, CDialog)

char buffer[200] = "";

CRegistro::CRegistro(CWnd* pParent /*=NULL*/)
	: CDialog(CRegistro::IDD, pParent)
	, bShiftTab(false)
	, iFoco(0)
	, iControles(6)
	, sTexto(_T(""))
{

}

CRegistro::~CRegistro()
{
}

void CRegistro::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_USUARIO, m_usuario);
	DDX_Control(pDX, IDC_EDIT_CLAVE, m_clave);
	DDX_Control(pDX, IDC_EDIT_CONFCLAVE, m_confClave);
	DDX_Control(pDX, IDC_EDIT_NOMBRE, m_nombre);
	DDX_Control(pDX, IDC_EDIT_DIRECCION, m_direccion);
	DDX_Control(pDX, IDC_EDIT_TELEFONO, m_telefono);
	DDX_Control(pDX, IDC_EDIT_CELULAR, m_celular);
}


BEGIN_MESSAGE_MAP(CRegistro, CDialog)
END_MESSAGE_MAP()


// Controladores de mensajes de CRegistro




BOOL CRegistro::PreTranslateMessage(MSG* pMsg)
{
	// TODO: Agregue aquí su código especializado o llame a la clase base
	CString sTxt;


	bShiftTab = false;

	if (pMsg->message == WM_SYSKEYDOWN) // Teclas virtuales 
	{
		if (GetKeyState(VK_MENU) & 0x8000 || pMsg->wParam == VK_F10) //ELIMINO  ALT  
			pMsg->wParam = VK_SHIFT;
	}

	if (pMsg->message == WM_KEYDOWN)
	{
		if (pMsg->wParam == VK_RETURN || pMsg->wParam == VK_TAB)
		{
			if (iFoco <= iControles)		//número de controles
			{
				if (validarControl())
				{
					iFoco++;
					asignarFoco();
				}
				else
				{
					if (!bShiftTab)
					{
						sTxt = CString(buffer);
						AfxMessageBox((sTxt));
					}
				}
				return TRUE;
			}
			else
			{
				iFoco = 0;
				if (pMsg->wParam != VK_RETURN) iFoco++;
				asignarFoco();
				return TRUE;
			}
		}
	}
	return CDialog::PreTranslateMessage(pMsg);
}


bool CRegistro::validarControl()
{
	bool bValorRegresa = true; 
	CString sTexto2;
	std::string email1;

	switch (iFoco)
	{
		case 0:

			m_usuario.GetWindowTextW(sTexto);
			sTexto.Trim();

			if (sTexto.IsEmpty())
			{
				sprintf_s(buffer, 200, "%s\n", "DEBE CAPTURAR UN USUARIO");
				bValorRegresa = false;
			}
			else
			{
				if (sTexto.GetLength() < 10)
				{
					sprintf_s(buffer, 200, "%s", "USUARIO NO VÁLIDO");
					bValorRegresa = false;
				}
				else
				{
					if (is_email_valid() == false)
					{
						sprintf_s(buffer, 200, "%s", "MAIL NO VÁLIDO");
						bValorRegresa = false;
					}
				}
			}
			break;
		case 1:
			m_clave.GetWindowTextW(sTexto);
			sTexto.Trim();
			if (sTexto.GetLength() < 10)
			{
				sprintf_s(buffer, 200, "%s", "CLAVE DEBE TENER UN TAMAÑO DE 10 O MAS");
				bValorRegresa = false;
			}
			break;
		case 2:
			m_clave.GetWindowTextW(sTexto);
			m_confClave.GetWindowTextW(sTexto2);

			sTexto.Trim();
			sTexto2.Trim();

			if (sTexto2.Compare(sTexto) != 0)
			{ 
				sprintf_s(buffer, 200, "%s", "CLAVE ES DIFERENTE A LA CAPTURADA");
				bValorRegresa = false;
			}
			break;
	}
	return(bValorRegresa);
}


void CRegistro::asignarFoco()
{
	switch (iFoco)
	{
		case 1:
			m_clave.SetFocus();
			break;
		case 2:
			m_confClave.SetFocus();
			break;
		case 3:
			m_nombre.SetFocus();
			break;
		case 4:
			m_direccion.SetFocus();
			break;
		case 5:
			m_telefono.SetFocus();
			break;
		case 6:
			m_celular.SetFocus();
			break;
		default:
			iFoco = 0;
			m_usuario.SetFocus();
			break;
	}
}


bool CRegistro::is_email_valid(void)
{
	const std::regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");

	CT2CA pszConvertedAnsiString(sTexto);
	std::string strStd(pszConvertedAnsiString);

	return std::regex_match(strStd, pattern);
}


